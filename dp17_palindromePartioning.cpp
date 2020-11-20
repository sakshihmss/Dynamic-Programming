int palindromePartioning(string s)
{
	int n = s.length();
	int dp[n][n];
	int P[n][n];
	for(int i=0;i<n;i++)
	{
		P[i][i] = 1;
		dp[i][i] = 0;
	}
	//make an array to check isPalindrome
	for(int L=2;L<=n;L++)
	{
		for(int i=0;i<=n-L+1;i++)
		{
			int j = i+L-1;
			dp[i][j] = INT_MAX;
			if(L == 2)
				P[i][j] = s[i] == s[j];
			else
				P[i][j] = (s[i] == s[j]) && P[i+1][j-1];
			if(P[i][j] == 1)
				dp[i][j] = 0;
			else
			{
				for(int k=i;k<j;k++)
				{
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + 1);
				}
			}
		}
	}
	return dp[0][n-1];
}