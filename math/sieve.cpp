// Verify: LOJ 1197

// [0,n)
vi Sieve(int n)
{
	vi isp(n);
	repi(i,2,n) isp[i]=i;
	for(int i=2;i*i<n;i++) if(isp[i])
		for(int j=i*i;j<n;j+=i)
			isp[j]=0;
	return isp;
}

// [a,b)
vl SegmentedSieve(ll a,ll b)
{
	const vi isp=Sieve(sqrt(b)+1);
	vl isp2(b-a);
	rep(i,b-a) if(a+i>=2) isp2[i]=a+i;
	rep(i,isp.size()) if(isp[i])
		for(ll j=max((a+i-1)/i,2ll)*i;j<b;j+=i)
			isp2[j-a]=0;
	return isp2;
}
