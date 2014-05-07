// Verify: PKU 1458

int LCS(const string& s1,const string& s2)
{
	vvi dp(2,vi(s2.size()+1));
	rep(i,s1.size()){
		rep(j,s2.size()){
			int ii=i+1,jj=j+1;
			if(s1[i]==s2[j])
				dp[ii&1][jj]=dp[(ii-1)&1][jj-1]+1;
			else
				dp[ii&1][jj]=max(dp[(ii-1)&1][jj-1],max(dp[(ii-1)&1][jj],dp[ii&1][jj-1]));
		}
	}
	return dp[s1.size()&1][s2.size()];
}
