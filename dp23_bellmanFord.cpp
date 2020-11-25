int bellmanFord(vector<vector<int>> &graph)
{
	//check ngative weight cycle
	int n = graph.size();
	int dp[n];
	for(int i=0;i<n;i++)
	{
		dp[i] = graph[0][i];
	}
	for(int i=1;i<n;i++)
	{
		dp[i] = INT_MAX;
		for(int j=0;j<n;j++)
		{
			dp[i] = min(dp[i], dp[j] + graph[j][i]);
		}
	}
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(dp[i] != INT_MAX && dp[i] + graph[i][j] < dp[j])
				return 1;
		}
	}
	return 0; //print 0 if there is no weight cycle 
}