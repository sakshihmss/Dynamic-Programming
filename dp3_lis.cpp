int lis(vector<int> &A)
{
	int n = A.size();
	if(n == 0)
		return 0;
	int dp[n];
	memset(dp, 0, sizeof(dp));
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(A[j] < A[i])
				dp[i] = max(dp[j]+1, dp[i]);
		}
	}
	int ans = INT_MIN;
	for(int i=0;i<n;i++)
		ans = max(ans, dp[i]);
	return ans+1;
}