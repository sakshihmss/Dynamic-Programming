int optimalGameStrategy(vector<int> &coins)
{
	int n = coins.size();
	int dp[n][n];
	memset(dp, 0, sizeof(dp));
	for(int i=0;i<n;i++)
		dp[i][i] = coins[i];
	for(int i=0;i<n-1;i++)
	{
		dp[i][i+1] = max(coins[i], coins[i+1]);
	}
	for(int L=3;L<=n;L++)
	{
		for(int i=0;i<n-L+1;i++)
		{
			int j = i+L-1;
			dp[i][j] = max(coins[i] + min(dp[i+1][j-1], dp[i+2][j]), coins[j] + min(dp[i][j-2], dp[i+1][j-1]));
		}
	}
	return dp[0][n-1];
}