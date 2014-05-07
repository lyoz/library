// Verify: Live Archive 4513
// (Regionals 2009, Europe-Southwestern, Problem J)

struct SuffixArray{
	string s;
	vi sa,lcp;
	struct Comp{
		const vi& rank;
		int k;
		Comp(const vi& rank,int k):rank(rank),k(k){}
		bool operator()(int i,int j){
			if(rank[i]!=rank[j])
				return rank[i]<rank[j];
			int a=i+k<rank.size()?rank[i+k]:-1;
			int b=j+k<rank.size()?rank[j+k]:-1;
			return a<b;
		}
	};
	SuffixArray(const string& s):s(s){
		Build();
		LCP();
	}
	void Build(){
		int n=s.size();
		sa.resize(n+1);
		vi rank(n+1);
		rep(i,n+1){
			sa[i]=i;
			rank[i]=i==n?-1:s[i];
		}
		for(int i=1;i<=n;i<<=1){
			Comp comp(rank,i);
			sort(all(sa),comp);
			vi temp(n+1);
			repi(j,1,n+1)
				temp[sa[j]]=temp[sa[j-1]]+comp(sa[j-1],sa[j]);
			swap(rank,temp);
		}
	}
	void LCP(){
		int n=s.size();
		lcp.resize(n);
		vi rank(n+1);
		rep(i,n+1)
			rank[sa[i]]=i;
		for(int i=0,h=0;i<n;i++){
			if(h>0) h--;
			for(int j=sa[rank[i]-1];j+h<n && i+h<n;h++)
				if(s[j+h]!=s[i+h])
					break;
			lcp[rank[i]-1]=h;
		}
	}
};
