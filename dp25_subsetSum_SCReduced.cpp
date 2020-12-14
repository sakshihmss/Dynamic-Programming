int subsetSum(vector<int>&arr, int sum)
{
	int n = arr.size();
	int dp[sum+1];
	//dp[i] means the sum i is possible for the given array or not
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for(int i=0;i<n;i++)
	{
		for(int j=arr[i];j<=sum;j++)
		{
			dp[j] = dp[j] || dp[j-arr[i]]; 
		}
	}
	return dp[sum];
}