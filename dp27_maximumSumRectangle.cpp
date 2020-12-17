int Kadane(vector<int> arr, int &start, int &end)
{
	int n = arr.size();
	int max_so_far = INT_MIN;
	int max_ending_here = 0;
	start = -1;
	end = -1;
	int local_start = 0;
	for(int j=0;j<n;j++)
	{
		max_ending_here += arr[j];

		if(max_ending_here < 0)
		{
			max_ending_here = 0;
			local_start = j+1;
		}
		else if(max_so_far < max_ending_here)
		{
			max_so_far = max_ending_here;
			end = j;
			start = local_start;
		}
	}

	if(end != -1)
		return max_so_far;

	max_so_far = arr[0];
	start = end = 0;
	for(int i=1;i<n;i++)
	{
		if(arr[i] > max_so_far)
		{
			max_so_far = arr[i];
			start = end = i;
		}
	}
	return max_so_far;
}

int maxSumRectangle(vector<vector<int>> &arr, int &left, int &right, int &top, int &bottom)
{
	int m = arr.size();
	int n = arr[0].size();
	int maxSum = INT_MIN;
	for(int i=0;i<n;i++)
	{
		vector<int> temp(m, 0);
		for(int j=i;j<n;j++)
		{
			for(int k=0;k<m;k++)
			{
				temp[k] += arr[k][j];
			}
			int temp_top = 0;
			int temp_bottom = 0;
			int sum = Kadane(temp, temp_top, temp_bottom);

			if(sum > maxSum)
			{
				maxSum = sum;
				left = i;
				right = j;
				top = temp_top;
				bottom = temp_bottom;
			}
		}
	}
	return maxSum;
}