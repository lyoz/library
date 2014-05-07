// Verify: PKU 3974

int LongestPalindrome(const string& _s)
{
	int n=_s.size();
	string s(2*n+1,'.');
	rep(i,n)
		s[i*2+1]=_s[i];
	n=s.size();
	
	vi rad(n);
	for(int i=0,j=0;i<n;){
		for(;0<=i-j && i+j<n && s[i-j]==s[i+j];j++)
			;
		rad[i]=j;
		
		int k=1;
		for(;0<=i-k && i+k<n && rad[i-k]<rad[i]-k;k++)
			rad[i+k]=rad[i-k];
		
		j=max(rad[i]-k,0);
		i+=k;
	}
	
	return *max_element(all(rad))-1;
}
