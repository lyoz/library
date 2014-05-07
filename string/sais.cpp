// Verify: UVA 1227(5.436s), SPOJ 6409(0.51s), POJ 1743, POJ 3261

enum{LTYPE,STYPE};

inline bool IsLMS(const vector<bool>& ts,int i)
{
	return i>0 && ts[i]==STYPE && ts[i-1]==LTYPE;
}

template<typename T>
void InitBucket(const T* s,int n,int* bucket,int bsize,bool inclusive)
{
	fill(bucket,bucket+bsize,0);
	rep(i,n)
		bucket[s[i]]++;
	for(int i=0,sum=0;i<bsize;i++){
		sum+=bucket[i];
		bucket[i]=inclusive?sum:sum-bucket[i];
	}
}

template<typename T>
void InduceSAL(const T* s,int* sa,int n,int* bucket,int bsize)
{
	InitBucket(s,n,bucket,bsize,false);
	rep(i,n){
		int j=sa[i]-1;
		if(j>=0 && s[j]>=s[j+1])
			sa[bucket[s[j]]++]=j;
	}
}

template<typename T>
void InduceSAS(const T* s,int* sa,int n,int* bucket,int bsize)
{
	InitBucket(s,n,bucket,bsize,true);
	per(i,n){
		int j=sa[i]-1;
		if(j>=0 && s[j]<=s[j+1])
			sa[--bucket[s[j]]]=j;
	}
}

// s[0..n-1]: 入力文字列，n>=2かつs[n-1]=0であること
// sa[0..n-1]: 接尾辞配列．
// asize: アルファベットサイズ，s[n-1]を除き1以上asize以下
template<typename T>
void SAIS(const T* s,int* sa,int n,int asize)
{
	vector<bool> ts(n,STYPE);
	per(i,n-1)
		if(s[i]>s[i+1] || (s[i]==s[i+1] && ts[i+1]==LTYPE))
			ts[i]=LTYPE;
	
	fill(sa,sa+n,-1);
	
	int* bucket=new int[asize+1];
	InitBucket(s,n,bucket,asize+1,true);
	per(i,n) if(IsLMS(ts,i))
		sa[--bucket[s[i]]]=i;
	InduceSAL(s,sa,n,bucket,asize+1);
	InduceSAS(s,sa,n,bucket,asize+1);
	delete[] bucket;
	
	int n1=0;
	rep(i,n) if(IsLMS(ts,sa[i]))
		sa[n1++]=sa[i];
	fill(sa+n1,sa+n,-1);
	
	int name=0,prev=-1;
	rep(i,n1){
		int cur=sa[i];
		bool diff=prev==-1;
		for(int j=0;!diff;j++){
			if(j>0 && IsLMS(ts,cur+j))
				break;
			if(s[cur+j]!=s[prev+j])
				diff=true;
		}
		if(diff)
			name++;
		sa[n1+cur/2]=name-1;
		prev=cur;
	}
	for(int i=n1,j=n1;i<n;i++)
		if(sa[i]>=0)
			sa[j++]=sa[i];
	fill(sa+n1+n1,sa+n,-1);
	
	int *sa1=sa,*s1=sa+n1;
	if(name==n1)
		rep(i,n1) sa1[s1[i]]=i;
	else
		SAIS(s1,sa1,n1,name);
	
	n1=0;
	rep(i,n) if(IsLMS(ts,i))
		s1[n1++]=i;
	rep(i,n1)
		sa1[i]=s1[sa1[i]];
	fill(sa+n1,sa+n,-1);
	
	bucket=new int[asize+1];
	InitBucket(s,n,bucket,asize+1,true);
	per(i,n1){
		int j=sa1[i]; sa1[i]=-1;
		sa[--bucket[s[j]]]=j;
	}
	InduceSAL(s,sa,n,bucket,asize+1);
	InduceSAS(s,sa,n,bucket,asize+1);
	delete[] bucket;
}

// nはsとsaのサイズ，lcpのサイズはn-1
template<typename T>
void LCP(const T* s,const int* sa,int n,int* lcp)
{
	vi rank(n);
	rep(i,n) rank[sa[i]]=i;
	for(int i=0,h=0;i<n-1;i++){
		if(h>0) h--;
		for(int j=sa[rank[i]-1];;h++)
			if(s[j+h]!=s[i+h])
				break;
		lcp[rank[i]-1]=h;
	}
}
