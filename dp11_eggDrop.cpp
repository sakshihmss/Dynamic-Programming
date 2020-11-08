int eggDrop(int n, int k)
{
	// n eggs, k floors
	int dp[n+1][k+1];
	for(int i=0;i<=n;i++)
	{
		dp[i][0] = 0;
		dp[i][1] = 1;
	}
	for(int j=0;j<=k;j++)
		dp[1][j] = j;
	for(int i=2;i<=n;i++)
	{
		for(int j=2;j<=k;j++)
		{
			dp[i][j] = INT_MAX;
			for(int x=1;x<=j;x++)
			{
				dp[i][j] = min(dp[i][j], 1 + max(dp[i-1][x-1], dp[i][j-x]));
			}
		}
	}
	return dp[n][k];
}