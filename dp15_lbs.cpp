int lis(vector<int> &A, int index)
{
	int n = A.size();
	int dp[n];
	dp[0] = 1;
	for(int i=1;i<n;i++)
	{
		dp[i] = 1;
		for(int j=0;j<i;j++)
		{
			if(A[j] < A[i])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	return dp[index];
}

int lds(vector<int> &A, int index)
{
	int n = A.size();
	int dp[n];
	dp[n-1] = 1;
	for(int i=n-2;i>=0;i--)
	{
		dp[i] = 1;
		for(int j=n-1;j>i;j--)
		{
			if(A[j] < A[i])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	return dp[index];
}

int lbs(vector<int> &A)
{
	int n = A.size();
	int dp[n];
	for(int i=0;i<n;i++)
		dp[i] = lis(A, i) + lds(A, i) - 1;
	int ret = 1;
	for(int i=0;i<n;i++)
		ret = max(ret, dp[i]);
	return ret;
}