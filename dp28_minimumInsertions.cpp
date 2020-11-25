int minimumInsertions(string s)
{
	int n = s.length();
	int dp[n][n];
	for(int i=0;i<n;i++)
		dp[i][i] = 0;
	for(int i=0;i<n-1;i++)
		dp[i][i+1] = s[i] == s[i+1] ? 0:1;
	for(int L=3;L<=n;L++)
	{
		for(int i=0;i<n-L+1;i++)
		{
			int j = i+L-1;
			if(s[i] == s[j]) dp[i][j] = dp[i+1][j-1];
			else
				dp[i][j] = min(dp[i][j-1], dp[i+1][j]) + 1;
		}
	}
	return dp[0][n-1];
}