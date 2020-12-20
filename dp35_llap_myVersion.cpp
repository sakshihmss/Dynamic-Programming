int llap(vector<int> &set)
{
	//works only for sorted arrays
	int n = set.size();
	if(n<=2) return n;
	int dp[n][n];
	for(int i=0;i<n;i++)
	{
	    for(int j=0;j<n;j++)
	    {
	    	if(i == j) dp[i][j] = 1;
	        else dp[i][j] = 2;
	    }
	}
	int ret = 2;
	for(int j=n-2;j>=1;j--)
	{
		int i = j-1;
		int k = j+1;
		while(i>=0 && k<=n-1)
		{
			if(set[i] + set[k] < 2*set[j])
				k++;
			else if(set[i] + set[k] > 2*set[j])
				i--;
			else
			{
				dp[i][j] = dp[j][k] + 1;
				ret = max(ret, dp[i][j]);
				i--, k++;
			}	
		}
	}
	return ret;
}