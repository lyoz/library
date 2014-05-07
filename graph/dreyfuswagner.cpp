// Verify: AOJ 1040

int DreyfusWagner(const vvi& _dist,const vi& ts)
{
	int n=_dist.size();
	vvi dist=_dist;
	rep(k,n) rep(i,n) rep(j,n)
		dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
	
	int tsize=ts.size();
	vvi dp(1<<tsize,vi(n,INFTY));
	rep(i,tsize) rep(j,n)
		dp[1<<i][j]=dist[ts[i]][j];
	rep(i,1<<tsize){
		for(int j=i;j;j=i&(j-1)) rep(k,n)
			dp[i][k]=min(dp[i][k],dp[j][k]+dp[i^j][k]);
		rep(j,n) rep(k,n)
			dp[i][j]=min(dp[i][j],dp[i][k]+dist[k][j]);
	}
	return *min_element(all(dp.back()));
}
