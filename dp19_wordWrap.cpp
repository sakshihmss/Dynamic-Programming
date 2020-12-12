void wordWrap(vector<int> &l, int n, int M)
{
	// l is the array containing the length of the words
	// n is the size of l
	// M is the maximum number of characters allowed in a line
	int extras[n+1][n+1];
	//extras[i][j] contains the number of extra spaces 
	// if words from i to j are put in the same line
	int lc[n+1][n+1]; 
	//lc[i][j] contains cost of a line if words from i to j are put in the same line
	int c[n+1];
	//total cost of optimal arrangement of words from 1 to i
	int p[n+1];
	//contains line breaks
	for(int i=1;i<=n;i++)
	{
		extras[i][i] = M - l[i-1];
		for(int j=i+1;j<=n;j++)
		{
			extras[i][j] = extras[i][j-1] - l[j-1] - 1;
		}
	}

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(extras[i][j] < 0)
				lc[i][j] = INT_MAX;
			else if(j == n && extras[i][j] >= 0)
				lc[i][j] = 0;
			else
				lc[i][j] = extras[i][j]*extras[i][j];
		}
	}

	c[0] = 0;
	for(int j=1;j<=n;j++)
	{
		c[j] = INT_MAX;
		for(int i=1;i<=j;i++)
		{
			if(c[i-1] != INT_MAX && lc[i][j] != INT_MAX && (c[i-1] + lc[i][j] < c[j]))
			{
				c[j] = c[i-1] + lc[i][j];
				p[j] = i;
			}
		}
	}
	return;
}