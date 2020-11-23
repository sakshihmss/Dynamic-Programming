vector<pair<int, int>> wordWrap(vector<int> &l, int n, int M)
{
	// l is the array containing the length of each word
	// n is the size of l
	// M is the maximum length of line possible
	int extras[n+1][n+1]; //number of extra spaces if words from i to j are put in same line
	int lc[n+1][n+1]; //cost of a line which has words from i to j
	int c[n+1]; //total cost of optimal arrangement of words from 1 to i

	for(int i=1;i<=n;i++)
	{
		extras[i][i] = M-l[i-1];
		for(int j=i+1;j<=n;j++)
		{
			extras[i][j] = extras[i][j-1] - l[j-1] - 1;
		}
	}


}