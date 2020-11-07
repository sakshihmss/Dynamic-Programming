int count(vector<int> &coins, int m, int n)
{
	int dp[n+1];
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for(int i=0;i<m;i++)
	{
		for(int j=coins[i];j<=n;j++)
		{
			dp[j] += dp[j-coins[i]];
		}
	}
	return dp[n];
}