int matrixChainMultiplication(vector<int> &A)
{
	int n = A.size();
	int dp[n][n];
	for(int i=1;i<n;i++)
	{
		dp[i][i] = 0;
	}
	for(int L=2;L<n;L++)
	{
		for(int i=1;i<n-L+1;i++)
		{
			int j=i+L-1;
			dp[i][j] = INT_MAX;
			for(int k=i;k<j;k++)
			{
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + A[i-1]*A[k]*A[j]);
			}
		}
	}
	return dp[1][n-1];
}