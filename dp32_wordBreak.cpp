bool isPresent(string s, vector<string> &dict)
{
	unordered_map<string, int> temp;
	for(int i=0;i<dict.size();i++)
	{
		temp[dict[i]] = 1;
	}
	if(temp.find(s) != temp.end())
		return true;
	return false;
}

bool wordBreak(string s, vector<string> &dict)
{
	int n = s.length();
	int dp[n];
	memset(dp, 0, sizeof(dp));
	for(int i=0;i<n;i++)
	{
		if(isPresent(s.substr(0, i+1), dict)) dp[i] = 1;
		else
		{
			for(int j=0;j<i;j++)
			{
				if(dp[j] == 1 && isPresent(s.substr(j+1, i-j), dict))
				{
					dp[i] = 1;
					break;
				}
			}
		}
	}
	return dp[n-1];
}