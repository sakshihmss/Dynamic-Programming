int minCost(vector<vector<int>> &A)
{
	int m = A.size();
	int n = A[0].size();
	int dp[m][n];
	dp[0][0] = A[0][0];
	for(int i=1;i<m;i++)
		dp[i][0] = dp[i-1][0] + A[i][0];
	for(int j=1;j<n;j++)
		dp[0][j] = dp[0][j-1] + A[0][j];
	for(int i=1;i<m;i++)
	{
		for(int j=1;j<n;j++)
		{
			dp[i][j] = min(min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]) + A[i][j];
		}
	}
	return dp[m-1][n-1];
}