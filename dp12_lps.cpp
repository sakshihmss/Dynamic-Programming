int lcs(string str1, string str2)
{
	int m = str1.length();
	int dp[m+1][m+1];
	memset(dp, 0, sizeof(dp));
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=m;j++)
		{
			if(i==0 || j==0)
				dp[i][j] = 0;
			else
			{
				if(str1[i-1] == str2[j-1])
					dp[i][j] = dp[i-1][j-1] + 1;
				else
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	return dp[m][m];
}

int lps(string s1)
{
	string s2 s1;
	reverse(s1.begin(), s1.end());
	return lcs(s1, s2);
}