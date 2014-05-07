// Verify: PKU 3903

int LIS(const vi& a)
{
	vi dp;
	rep(i,a.size()){
		int j=lower_bound(all(dp),a[i])-dp.begin();
		if(j==dp.size())
			dp.push_back(a[i]);
		else
			dp[j]=a[i];
	}
	return dp.size();
}
