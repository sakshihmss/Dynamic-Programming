int count(vector<int> &coins, int N)
{
	int m = coins.size();
	int dp[m+1][N+1];
	dp[0][0] = 1;
	for(int j=1;j<=N;j++)
	{
		dp[0][j] = 0;
	}
	for(int i=1;i<=m;i++)
	{
		dp[i][0] = 1;
	}
	for(int j=1;j<=N;j++)
	{
		for(int i=1;i<=m;i++)
		{
			int x = j-coins[i-1] >= 0 ? dp[i][j-coins[i-1]] : 0;
			int y = dp[i-1][j];
			dp[i][j] = x + y;
		}
	}
	return dp[m][N];
}