int palindromePartioning(string s)
{
	int n = s.length();
	int dp[n];
	int P[n][n];
	for(int i=0;i<n;i++)
	{
		P[i][i] = 1;
	}
	for(int L=2;L<=n;L++)
	{
		for(int i=0;i<=n-L+1;i++)
		{
			int j = i+L-1;
			if(L == 2)
				P[i][j] = s[i] == s[j];
			else
				P[i][j] = (s[i] == s[j]) && P[i+1][j-1];
		}
	}
	for(int i=0;i<n;i++)
	{
		if(P[0][i] == 1)
			dp[i] = 0;
		else
		{
			dp[i] = INT_MAX;
			for(int j=0;j<i;j++)
			{
				if(P[j+1][i] == 1)
					dp[i] = min(dp[i], dp[j]+1);
			}
		}
	}
	return dp[n-1];
}