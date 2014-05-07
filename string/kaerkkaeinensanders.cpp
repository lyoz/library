// Verify: [構築] LiveArchive 3451, POJ 1509, POJ 2774, POJ 3080, POJ 3261, POJ 3450,
//                SPOJ 6409 (0.76s), UVA 1223, UVA 1227, UVA 11512
//         [LCP]  LiveArchive 3451, POJ 2774, POJ 3080, POJ 3261, POJ 3450,
//                UVA 1223, UVA 1227, UVA 11512
//         [LCS]  POJ 3080, UVA 1227

template<typename C>
void RadixSort(const vi& src,vi& dst,const C& s,int ofs,int n,int asize)
{
	vi hist(asize+1);
	rep(i,n) hist[s[ofs+src[i]]]++;
	rep(i,asize) hist[i+1]+=hist[i];
	per(i,n) dst[--hist[s[ofs+src[i]]]]=src[i];
}

bool Less(int a1,int a2,int b1,int b2)
{
	return a1!=b1?a1<b1:a2<b2;
}
bool Less(int a1,int a2,int a3,int b1,int b2,int b3)
{
	return a1!=b1?a1<b1:Less(a2,a3,b2,b3);
}

// s[0..n-1]: 入力文字列．末尾に'\0'が3つ必要(s[n]=s[n+1]=s[n+2]=0)．
// sa[0..n-1]: 接尾辞配列．
// asize: アルファベットサイズ，s[i] \in [1,asize]
template<typename C>
void KaerkkaeinenSanders(const C& s,vi& sa,int asize)
{
	int n=sa.size();
	int n0=(n+2)/3,n1=(n+1)/3,n2=n/3,n02=n0+n2;
	vi s12(n02+3),sa12(n02);
	
	for(int i=0,j=0;i<n+(n0-n1);i++)
		if(i%3) s12[j++]=i;
	RadixSort(s12,sa12,s,2,n02,asize);
	RadixSort(sa12,s12,s,1,n02,asize);
	RadixSort(s12,sa12,s,0,n02,asize);
	
	int name=0,x=-1,y=-1,z=-1;
	rep(i,n02){
		int j=sa12[i];
		if(s[j]!=x || s[j+1]!=y || s[j+2]!=z)
			x=s[j],y=s[j+1],z=s[j+2],name++;
		if(j%3==1) s12[j/3]=name;
		else       s12[n0+j/3]=name;
	}
	
	if(name==n02) // unique
		rep(i,n02) sa12[s12[i]-1]=i;
	else{
		KaerkkaeinenSanders(s12,sa12,name);
		rep(i,n02) s12[sa12[i]]=i+1;
	}
	
	vi s0(n0),sa0(n0);
	for(int i=0,j=0;i<n02;i++)
		if(sa12[i]<n0) s0[j++]=3*sa12[i];
	RadixSort(s0,sa0,s,0,n0,asize);
	
	int i=0,j=n0-n1,k=0;
	while(i<n0 && j<n02){
		int p=sa0[i],q=sa12[j]<n0?sa12[j]*3+1:(sa12[j]-n0)*3+2;
		if(sa12[j]<n0?
			Less(s[p],s12[p/3],s[q],s12[n0+sa12[j]]):
			Less(s[p],s[p+1],s12[n0+p/3],s[q],s[q+1],s12[sa12[j]+1-n0]))
			sa[k++]=p,i++;
		else
			sa[k++]=q,j++;
	}
	for(;i<n0;k++,i++)
		sa[k]=sa0[i];
	for(;j<n02;k++,j++)
		sa[k]=sa12[j]<n0?sa12[j]*3+1:(sa12[j]-n0)*3+2;
}
void KaerkkaeinenSanders(const string& s,vi& sa)
{
	KaerkkaeinenSanders<string>(s+string(3,0),sa,127);
}
void KaerkkaeinenSanders(const char* s,vi& sa)
{
	KaerkkaeinenSanders<string>(s+string(3,0),sa,127);
}

// s[0..n-1] (s[n]=0), sa[0..n-1]
// lcp[0..n-1] (lcp[i]:s[sa[i-1]..]とs[sa[i]..]のLCP.lcp[0]=0)
template<typename C>
void LCP(const C& s,const vi& sa,vi& lcp)
{
	int n=sa.size();
	vi rank(n);
	rep(i,n) rank[sa[i]]=i;
	for(int i=0,h=0;i<n;i++){
		if(h>0) h--;
		if(rank[i]>0)
			for(int j=sa[rank[i]-1];;h++)
				if(s[j+h]!=s[i+h]) break;
		lcp[rank[i]]=h;
	}
}

// n: 文字列の数
// ls[0..n-1]: 各文字列の長さ
// LCSはs.substr(sa[res],lcp[res])で得られる．
// LCSが空の時res=0．lcp[res]=0でもある．
int LCS(int n,const vi& ls,const vi& sa,const vi& lcp)
{
	int m=sa.size();
	vi is(m);
	for(int i=0,j=0;i<n;i++){
		rep(k,ls[i]) is[j+k]=i;
		j+=ls[i];
		if(i<n-1) is[j++]=i;
	}
	int cnt=0,res=0;
	vi occ(n);
	deque<int> q;
	for(int i=n-1,j=n-1;i<m;i++){
		for(;j<m && cnt<n;j++){
			if(++occ[is[sa[j]]]==1) cnt++;
			while(!q.empty() && lcp[q.back()]>lcp[j]) q.pop_back();
			q.push_back(j);
		}
		if(cnt<n) break;
		if(q.front()==i) q.pop_front();
		assert(q.size());
		if(lcp[res]<lcp[q.front()])
			res=q.front();
		if(--occ[is[sa[i]]]==0) cnt--;
	}
	return res;
}
