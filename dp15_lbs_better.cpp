int lbs(vector<int> &A)
{
	int n = A.size();
	int lis[n];
	int lds[n];
	lis[0] = 1;
	lds[n-1] = 1;
	for(int i=1;i<n;i++)
	{
		lis[i] = 1;
		for(int j=0;j<i;j++)
		{
			if(A[j] < A[i])
				lis[i] = max(lis[i], lis[j] + 1);
		}
	}
	for(int i=n-2;i>=0;i--)
	{
		lds[i] = 1;
		for(int j=n-1;j>i;j--)
		{
			if(A[j] < A[i])
				lds[i] = max(lds[i], lds[j] + 1);
		}
	}
	int ret = 1;
	for(int i=0;i<n;i++)
		ret = max(ret, lis[i] + lds[i] - 1);
	return ret;
}