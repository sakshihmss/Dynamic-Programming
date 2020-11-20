int partitionProblem(vector<int> &A)
{
	int n = A.size();
	int total_sum = 0;
	for(int i=0;i<n;i++)
		total_sum += A[i];
	if(total_sum%2 != 0)
		return 0;
	int sum = total_sum/2;
	int dp[sum+1];
	memset(dp, 0, sizeof(dp));
	for(int i=0;i<n;i++)
	{
		for(int j=sum;j>=A[i];j--)
		{
			if(j == A[i] || dp[j-A[i]] == 1)
				dp[j] = 1;
		}
	}
	return dp[sum];
}