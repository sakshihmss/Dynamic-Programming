int booleanParenthesization(vector<char> &symb, vector<char> &oper)
{
	int n = symb.size();
	int T[n][n], F[n][n];
	memset(T, 0, sizeof(T));
	memset(F, 0, sizeof(F));
	for(int i=0;i<n;i++)
	{
		T[i][i] = (symb[i] == 'T') ? 1:0;
		F[i][i] = (symb[i] == 'F') ? 1:0;
	}

	for(int L=2;L<=n;L++)
	{
		for(int i=0;i<n-L+1;i++)
		{
			int j = i+L-1;
			for(int k=i;k<j;k++)
			{
				int tik = T[i][k] + F[i][k];
				int tkj = T[k+1][j] + F[k+1][j];

				if(oper[k] == '&')
				{
					T[i][j] += T[i][k]*T[k+1][j];
					F[i][j] += tik*tkj - T[i][k]*T[k+1][j];
				}
				else if(oper[k] == '|')
				{
					T[i][j] += tik*tkj - F[i][k]*F[k+1][j];
					F[i][j] += F[i][k]*F[k+1][j];
				}
				else if(oper[k] == '^')
				{
					T[i][j] += T[i][k]*F[k+1][j] + F[i][k]*T[k+1][j];
					F[i][j] += T[i][k]*T[k+1][j] + F[i][k]*F[k+1][j];
				}

			}
		}
	}
	return T[0][n-1];
}