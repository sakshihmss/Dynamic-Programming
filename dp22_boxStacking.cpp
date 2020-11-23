struct Box
{
	int h, w, d;
};

bool comp(Box b1, Box b2)
{
	return (b1.w*b1.d) >= (b2.w*b2.d);
}

int boxStacking(vector<int> &H, vector<int> &W, vector<int> &D)
{
	int n = H.size();
	Box vec[3*n]; //(H, W, D) for all three values (W <= D) always without the loss of generality
	int i = 0;
	int index = 0;
	while(i<n)
	{
		vec[index].h = H[i];
		vec[index].w = min(W[i], D[i]);
		vec[index].d = max(W[i], D[i]);
		index++;
		vec[index].h = W[i];
		vec[index].w = min(H[i], D[i]);
		vec[index].d = max(H[i], D[i]);
		index++;
		vec[index].h = D[i];
		vec[index].w = min(W[i], H[i]);
		vec[index].d = max(W[i], H[i]);
		index++;
		i++;
	}
	sort(vec,vec+3*n, comp);
	int dp[3*n];
	dp[0] = vec[0].h;
	for(int i=1;i<3*n;i++)
	{
		dp[i] = vec[i].h;
		for(int j=0;j<i;j++)
		{
			if(vec[i].w < vec[j].w && vec[i].d < vec[j].d)
				dp[i] = max(dp[i], vec[i].h + dp[j]);
		}
	}
	int ret = INT_MIN;
	for(int i=0;i<3*n;i++)
		ret = max(ret, dp[i]);
	return ret;
}