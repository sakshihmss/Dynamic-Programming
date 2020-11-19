#define INF INT_MAX

vector<vector<int>> floydWarshall(vector<vector<int>> &graph)
{
	int n = graph.size();
	vector<vector<int>> ret;
	ret.resize(n, vector<int> (n));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			ret[i][j] = graph[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				ret[i][j] = min(ret[i][j], ret[i][k] + ret[k][j]);
			}
		}
	}
	return ret;
}