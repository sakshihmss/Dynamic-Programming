// you can use includes, for example:
// #include <algorithm>
#include<bits/stdc++.h>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
long long int maxCollect(vector<int> &A, int start, int end, int L)
{
    if(start == -1 || end == -1 || start > end)
        return -1;
    if(end-start+1 < L)
        return -1;
    long long int maxSum = -1;
    long long int sum = 0;
    for(int i=start;i<start+L;i++)
        sum += A[i];
    int j = start+L;
    int i = start;
    while(j <= end+1)
    {
        maxSum = max(maxSum, sum);
        if(i <= end)
            sum -= A[i];
        if(j <= end)
            sum += A[j];
        i++;
        j++;
    }
    return maxSum%(1000000007);
}

int solution(vector<int> &A, int K, int L) {
    // write your code in C++14 (g++ 6.2.0)
    int n = A.size();
    if(K+L > n)
        return -1;
    long long int leftSum[n];
    long long int rightSum[n];
    long long int sum = 0;
    for(int i=0;i<n;i++)
    {
        sum += A[i];
        if(i < L-1)
        {
            leftSum[i] = INT_MIN;
        }
        else
        {
            leftSum[i] = max(sum, leftSum[i-1]);
            sum -= A[i-L+1];
        }
    }
    long long int rightSum[n];
    sum =0;
    for(int i = n-1;i>=0;i--){
        sum += A[i];
       if(i>n-L+1){
           rightSum[i]=INT_MIN;
           
       }
       else{
           rightsum[i] = max(sum,rightSum[i+1]);
           sum -= A[i+L-1];
       }
    }
    long long int currSum = 0;
    for(int i=0;i<K;i++)
        currSum += A[i];
    int j = K;
    int i = 0;
    int start1 = 0;
    int end1 = -1;
    int start2 = K;
    int end2 = n-1;
    long long int ret = -1;
    while(j <= n)
    {
        //long long int leftSum = maxCollect(A, start1, end1, L);
        //long long int rightSum = maxCollect(A, start2, end2, L);
        long long int left = leftSum[i-1];
        long long int right = rightSum[j];
        //long long int finalSum = max(leftSum, rightSum);
        long long int finalSum = max(left, right);
        if(finalSum != -1)
            ret = max(ret, (currSum%1000000007 + finalSum%1000000007)%(1000000007));
        end1 += 1;
        start2 += 1;
        if(i < n)
            currSum -= A[i];
        if(j < n)
            currSum += A[j];
        i++;
        j++;
    }
    return ret%(1000000007);
}
