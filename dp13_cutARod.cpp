//Makes no sense in this problem
int cutARod(vector<int> &price)
{
	int n = price.size();
	int dp[n+1][n+1];
	for(int i=0;i<=n;i++)
		dp[i][i] = 0;
	for(int i=0;i<n;i++)
	{
		dp[i][i+1] = price[0];
	}
	for(int L=2;L<=n;L++)
	{
		for(int i=0;i<n-L+1;i++)
		{
			int j = i+L-1;
			dp[i][j] = price[j-i-1];
			for(int k=i;k<j;k++)
			{
				dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
	return dp[0][n];
}