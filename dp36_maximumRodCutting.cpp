int maximumRodCutting(int n)
{
	int dp[n+1];
	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;

	for(int L=3;L<=n;L++)
	{
		dp[L] = 1;
		for(int k=1;k<L;k++)
		{
			dp[L] = max(dp[L], k*dp[L-k], k*(L-k));
		}
	}
	return dp[n];
}