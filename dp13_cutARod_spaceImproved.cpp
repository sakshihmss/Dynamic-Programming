int cutARod(vector<int> &price)
{
	int n = price.size();
	int dp[n+1];
	dp[0] = 0;
	for(int i=1;i<=n;i++)
	{
		dp[i] = INT_MIN;
		for(int j=1;j<=i;j++)
		{
			dp[i] = max(dp[i], price[j-1] + dp[i-j]);
		}
	}
	return dp[n];
}