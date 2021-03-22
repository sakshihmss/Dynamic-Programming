class comp
{
	int operator() (const pair<int, int> &p1, const pair<int, int> &p2)
	{
		return p1.second < p2.second;
	}
};

void prim(vector<vector<int>> &adj, vector<vector<int>> &graph)
{
	//using adjacency list representation
	int V = adj.size();
	priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
	vector<bool> mstSet(V, 0);
	vector<int> key(V);
	vector<int> parent(V, -1);
	key[0] = 0;
	pq.push(make_pair(0, 0));
	for(int v=1;v<V;v++)
	{
		pq.push(make_pair(v, INT_MAX));
		key[v] = INT_MAX;
	}

	while(!pq.empty())
	{
		pair<int, int> tp = pq.top();
		int u = tp.first;
		int key_u = tp.second;
		mstSet[u] = true;
		for(int v:adj[u])
		{
			if(!mstSet[v] && key[v] > graph[u][v])
			{
				pq.erase(make_pair(v, key[v]));
				parent[v] = u;
				key[v] = graph[u][v];
				pq.push(make_pair(v, key[v]));
			}
		}
	}
	return;
}