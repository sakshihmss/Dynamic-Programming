int _lis(vector<int> &A, int n, int *max_ref)
{
	if(n == 1)
		return 1;
	int res, max_ending_here = 1;

	for(int i=1;i<n;i++)
	{
		res = _lis(A, i, max_ref);
		if(A[i-1] < A[n-1])
			max_ending_here = max(max_ending_here, res+1);
	}

	*max_ref = max(max_ending_here, *max_ref);
	return max_ending_here;
}

int lis(vector<int> &A)
{
	int n = A.size();
	int max = 1;
	_lis(A, n, &max);
	return max;
}