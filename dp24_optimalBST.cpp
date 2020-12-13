int optimalBST(vector<int> &keys, vector<int> &freq)
{
	//Keys are sorted here
	int n = keys.size();
	int dp[n][n];
	int sum[n];
	int root[n][n];
	sum[0] = freq[0];

	for(int i=1;i<n;i++)
		sum[i] = sum[i-1]+freq[i];

	for(int i=0;i<n;i++)
		dp[i][i] = freq[i];

	for(int L=2;L<=n;L++)
	{
		for(int i=0;i<=n-L+1;i++)
		{
			int j = i+L-1;
			dp[i][j] = INT_MAX;
			for(int k=i;k<=j;k++)
			{
				int cost = ((k > i) ? dp[i][k-1]:0) + ((k < j) ? dp[k+1][j]:0) + sum[j]-((i > 0) ? sum[i-1]:0);
				if(cost < dp[i][j])
				{
					dp[i][j] = cost;
					root[i][j] = k;
				}
			}
		}
	}
	return dp[0][n-1];
}