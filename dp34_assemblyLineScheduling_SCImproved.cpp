int assemblyLineScheduling(vector<vector<int>> &a, vector<vector<int>> &t, vector<int> &e, vector<int> &x)
{
	//a[i][j] is the time taken at station S[i][j]
	//t[i][j] is the time to shift from line i at station j-1 to station j
	//e[0] denotes the entry time in line 0. Similarly, e[1]
	//x[0] denotes the exit time from line 0. Similarly, x[1]
	int n = a[0].size();
	int x1;
	int x2;
	x1 = e[0] + a[0][0];
	x2 = e[1] + a[1][0];

	for(int i=1;i<n;i++)
	{
		int first = min(x1 + a[0][i], x2 + t[1][i] + a[0][i]);
		int second = min(x2 + a[1][i], x1 + t[0][i] + a[1][i]);

		x1 = first;
		x2 = second;
	}

	return min(x1 + x[0], x2 + x[1]);
}