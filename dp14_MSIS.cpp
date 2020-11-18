//Maximum Sum Increasing Subsequence
int msis(vector<int> &A)
{
	int n = A.size();
	int dp[n];
	dp[0] = A[0];
	for(int i=1;i<n;i++)
	{
		dp[i] = A[i];
		for(int j=0;j<i;j++)
		{
			if(A[j] < A[i])
			dp[i] = max(dp[i], dp[j] + A[i]);
		}
	}
	int ret = 0;
	for(int i=0;i<n;i++)
		ret = max(ret, dp[i]);
	return ret;
}