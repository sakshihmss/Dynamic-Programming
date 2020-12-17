int findWaysDiceThrow(int m, int n, int x)
{
	// n is the number of dice
	// 1 to m is the numbers on the faces of dice
	// x is the sum
	int dp[n+1][x+1];
	memset(dp, 0, sizef(dp));

	//for one dice
	for(int i=1;i<=m && i<=x;i++)
		dp[1][i] = 1;

	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=x;j++)
		{
			for(int k=1;k<=m;k++)
			{
				dp[i][j] += dp[i-1][j-k];
			}
		}
	}
	return dp[n][x];
}