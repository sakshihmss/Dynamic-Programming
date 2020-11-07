int binomialCoefficient(int n, int k)
{
	int dp[k+1];
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for(int i=1;i<=n;i++)
	{
		for(int j=min(i, k);j>0;j--)
		{
			dp[j] += dp[j-1];
		}
	}
	return dp[k];
}