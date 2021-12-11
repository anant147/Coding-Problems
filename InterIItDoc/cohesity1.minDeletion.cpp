#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<unordered_map>
#include<queue>
#include<stack>
#include<cmath>
#include<cstring>
using namespace std;

int minval (int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

int findMinimumDeletion(vector<vector<int>>& dp, string s, int l, int r, int n)
{
	if (l>r)
		return 0;
	else if (l==r)
		return 1;

	if (dp[l][r] != -1)
		return dp[l][r];

	int res = 1 + findMinimumDeletion(dp, s, l+1, r, n);

	for (int i=l+1; i<=r;i++)
	{
		if (s[l] == s[i])
			res = minval (res, findMinimumDeletion(dp, s, l+1, i-1, n) + findMinimumDeletion(dp, s, i, r, n));
	}

	return dp[l][r] = res;
}

int main()
{
	cout<<" Minimum steps to delete a string by deleting substring comprising of same characters "<<endl;

	// string s = "abcddcba";
	// string s = "abc";
	string s = "aabbcc";
	cout<<" s = "<<s<<endl;

	int n = s.size();

	vector<vector<int>> dp;
	dp.resize(n, vector<int> (n,-1));

	cout<<" minimum steps = "<<findMinimumDeletion(dp, s,0,n-1, n)<<endl;

	cout<<" printing the dp vector :- "<<endl;
	int i,j;
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
			cout<<dp[i][j]<<" ";
		cout<<endl;
	}
}

















