bool interleavedString(string A, string B, string C)
{
	int m = A.length();
	int n = B.length();
	int dp[m+1][n+1];
	memset(dp, 0, sizeof(dp));
	if(m+n != C.length())
		return false;
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(i==0 && j==0)
				dp[i][j] = 1;

			else if(i==0)
			{
				if(B[j-1] == C[j-1])
					dp[i][j] = dp[i][j-1];
			}
			else if(j==0)
			{
				if(A[i-1] == C[i-1])
					dp[i][j] = dp[i-1][j];
			}
			else if(A[i-1] == C[i+j-1] && B[j-1] != C[i+j-1])
			{
				dp[i][j] = dp[i-1][j];
			}
			else if(A[i-1] != C[i+j-1] && B[j-1] == C[i+j-1])
			{
				dp[i][j] = dp[i][j-1];
			}
			else if(A[i-1] == C[i+j-1] && B[j-1] == C[i+j-1])
			{
				dp[i][j] = dp[i][j-1]||dp[i-1][j];
			}
		}
	}
	return dp[m][n];
}