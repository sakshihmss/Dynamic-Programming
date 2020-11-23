bool comp(pair<int, int> &a, pair<int, int> &b)
{
	return a.first < b.first;
}

int buildingBridges(vector<pair<int, int>> &A)
{
	int n = A.size();
	int dp[n];
	dp[0] = 1;
	sort(A.begin(), A.end(), comp);
	for(int i=1;i<n;i++)
	{
		dp[i] = 1;
		for(int j=0;j<i;j++)
		{
			if(A[j].second <= A[i].first)
				dp[i] = max(dp[i], 1 + dp[j]);
		}
	}
	int ret = INT_MIN;
	for(int i=0;i<n;i++)
		ret = max(ret, dp[i]);
	return ret;
}