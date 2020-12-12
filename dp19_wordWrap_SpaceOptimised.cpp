void wordWrap(vector<int> &l, int n, int M)
{
	// l is the array containing the length of the words
	// n is the size of l
	// M is the maximum number of characters allowed in a line
	int currlen; //variable to store number of characters in current line
	int cost; //variable to store possible minimum cost of line
	int dp[n]; // dp[i] represents cost of line starting with word l[i]
	int ans[n]; // ans[i] stores last word in line starting with l[i]
	dp[n-1] = 0;
	ans[n-1] = n-1;

	for(int i=n-2;i>=0;i--)
	{
		currlen = -1;
		dp[i] = INT_MAX;
		for(int j=i;j<n;j++)
		{
			currlen += l[j] + 1;
			if(currlen > M)
				break;

			if(j == n-1)
				cost = 0;
			else
				cost = (M-currlen)*(M-currlen) + dp[j+1];

			if(cost < dp[i])
			{
				dp[i] = cost;
				ans[i] = j;
			}
		}
	}
	return;
}