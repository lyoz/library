// Verify: UVa 741, SPOJ 1874

string IBWT(const string& b,int k,int first)
{
	int n=b.size();
	
	vi cnt(k);
	rep(i,n) cnt[b[i]]++;
	rep(i,k-1) cnt[i+1]+=cnt[i];
	
	vi lf(n);
	per(i,n) lf[--cnt[b[i]]]=i;
	
	string res;
	for(int i=0,j=first;i<n;i++)
		res+=b[j=lf[j]];
	return res;
}
