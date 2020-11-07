int count(int N, vector<int> &coins, int m)
{
	if(N == 0) return 1;
	if(N < 0) return 0;
	if(m <= 0 && N > 1) return 0;
	return count(N, coins, m-1) + count(N-coins[m-1], coins, m);
}