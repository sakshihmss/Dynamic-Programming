int eggDrop(int n, int k)
{
	// n eggs, k floors
	if(k==0 || k==1) return k;
	if(n==1) return k;
	int minVal = INT_MAX;
	for(int x=1;x<=k;x++)
	{
		minVal = min(minVal, max(eggDrop(n-1, x-1), eggDrop(n, k-x)));
	}
	return minVal+1;
}