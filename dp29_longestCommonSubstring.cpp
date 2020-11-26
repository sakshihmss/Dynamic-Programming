int lcs(string X, string Y)
{
	int m = X.length();
	int n = Y.length();
	int dp[m+1][n+1]; //dp[i][j] //length of longest common suffixes of X[0....m-1] and Y[0.....n-1] 
	int res = 0;
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(i==0 || j==0)
				dp[i][j] = 0;
			if(X[i-1] == Y[j-1])
			{
				dp[i][j] = dp[i-1][j-1] + 1;
				res = max(res, dp[i][j]);
			}
			else
				dp[i][j] = 0;
		}
	}
	return res;
}