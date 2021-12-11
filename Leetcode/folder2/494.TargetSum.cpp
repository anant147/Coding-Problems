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

int findTargetSumWays(vector<int>& nums, int target)
{
	int cnt = 0;
	int sum = 0;

	int i,j,k;

	int n = nums.size();

	for (i=0;i<n;i++)
	{
		sum = sum + nums[i];

		if (nums[i]==0)
			cnt++;
	}

	if (target > sum)
		return 0;

	if ((target + sum)%2 != 0)
		return 0;

	int s = (sum + target)/2;

	int dp[n+1][s+1];

	for (i=0;i<n+1;i++)
		dp[i][0] = 1;

	for (i=1;i<s+1;i++)
		dp[0][i] = 0;

	for (i=1;i<=n;i++)
	{
		for (j=1;j<=s;j++)
		{
			if (nums[i-1]==0)
				dp[i][j] = dp[i-1][j];
			else
			{
				if (j<nums[i-1])
					dp[i][j] = dp[i-1][j];
				else
					dp[i][j] = dp[i-1][j] + dp[i-1][j - nums[i-1]];
			}
		}
	}

	return pow(2,cnt) * dp[n][s];
}

int main()
{
	cout<<" 494. Target Sum "<<endl;

	// example 1
	vector<int> nums = {1, 1, 1, 1, 1};
	int target = 3;

	cout<<" printing the nums vector :- "<<endl;
	for (int i=0;i<nums.size();i++)
		cout<<nums[i]<<" ";
	cout<<endl;

	cout<<" target = "<<target<<endl;

	int answer = findTargetSumWays(nums, target);

	cout<<" answer = "<<answer<<endl;
}