int edit(string str1, string str2)
{
	int m = str1.length();
	int n = str2.length();
	int dp[m+1][n+1];
	memset(dp, 0, sizeof(dp));

	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(i==0 && j==0) dp[i][j] = 0;
			else if(i==0)
			{
				dp[i][j] = dp[i][j-1]+1;
			}
			else if(j==0)
			{
				dp[i][j] = dp[i-1][j]+1;
			}
			else if(str1[i-1] == str2[j-1])
			{
				dp[i][j] = dp[i-1][j-1];
			}
			else
			{
				dp[i][j] = min(min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]) + 1;
			}
		}
	}
	return dp[m][n];
}