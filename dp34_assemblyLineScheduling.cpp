int assemblyLineScheduling(vector<vector<int>> &a, vector<vector<int>> &t, vector<int> &e, vector<int> &x)
{
	//a[i][j] is the time taken at station S[i][j]
	//t[i][j] is the time t shift from line i at station j-1 to station j
	//e[0] denotes the entry time in line 0. Similarly, e[1]
	//x[0] denotes the exit time from line 0. Similarly, x[1]
	int n = a[0].size();
	int T1[n];
	int T2[n];
	T1[0] = e[0] + a[0][0];
	T2[0] = e[1] + a[1][0];

	for(int i=1;i<n;i++)
	{
		T1[i] = min(T1[i-1] + a[0][i], T2[i-1] + t[1][i] + a[0][i]);
		T2[i] = min(T2[i-1] + a[1][i], T1[i-1] + t[0][i] + a[1][i]);
	}

	return min(T1[n-1] + x[0], T2[n-1] + x[1]);
}