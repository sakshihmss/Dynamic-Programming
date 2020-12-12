int bellmanFord(vector<vector<int>> &graph, int V, int E, int src)
{
	//graph[i] represents ith edge (from u to v) with weight w (u, v, w)
	//check negative weight cycle
	int dp[V]; //dp[i] contains distance of every vertex from source
	for(int i=0;i<V;i++)
	{
		dp[i] = INT_MAX;
	}
	dp[src] = 0;
	for(int i=0;i<V-1;i++)
	{
		for(int j=0;j<E;j++)
		{
			dp[graph[j][1]] = min(dp[graph[j][1]], dp[graph[j][0]] + graph[j][2]);
		}
	}
	for(int i=0;i<E;i++)
	{
		 if(dp[graph[j][0]]!=INT_MAX && dp[graph[j][1]] > dp[graph[j][0]] + graph[j][2])
		 	return 1;
	}
	return 0; //return 0 if there is no weight cycle 
}