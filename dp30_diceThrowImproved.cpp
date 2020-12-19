int findWaysDiceThrow(int m, int n, int x)
{
	// n is the number of dice
	// 1 to m is the numbers on the faces of dice
	// x is the sum
	long long int dp[n+1][x+1];
	memset(dp, 0, sizeof(dp));

	dp[0][0] = 1;

	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=x;j++)
		{
			dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
			if(j-m-1 >= 0)
				dp[i][j] -= dp[i-1][j-m-1];
		}
	}
	return dp[n][x];
}