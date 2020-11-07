int edit(string str1, string str2, int m, int n)
{
	if(m==0 && n==0) return 0;
	if(m==0) return n;
	if(n==0) return m;
	if(str1[m-1] == str2[n-1]) return edit(str1, str2, m-1, n-1);
	else 
		return min(min(edit(str1, str2, m-1, n-1), edit(str1, str2, m-1, n)), edit(str1, str2, m, n-1)) + 1;
}