int llap(vector<int> &A)
{
	int n = A.size();
	int d[n];
	int dp[n];
	memset(d, 0, sizeof(d));
	dp[0] = 1;
	for(int i=1;i<n;i++)
	{
		dp[i] = 2;
	}
	
}