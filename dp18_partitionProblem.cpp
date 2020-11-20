int partitionProblem(vector<int> &A)
{
	int n = A.size();
	int total_sum = 0;
	for(int i=0;i<n;i++)
		total_sum += A[i];
	if(total_sum%2 != 0)
		return 0;
	int sum = total_sum/2;
	int dp[sum+1][n+1];
	dp[0][0] = 1;
	for(int i=1;i<=sum;i++)
		dp[i][0] = 0;
	for(int i=1;i<=n;i++)
		dp[0][i] = 1;
	for(int i=1;i<=sum;i++)
	{
		for(int j=1;j<=n;j++)
		{
		    dp[i][j] = dp[i][j-1];
			if(A[j-1] <= i)
				dp[i][j] = dp[i-A[j-1]][j-1] || dp[i][j];
		}
	}
	return dp[sum][n];
}