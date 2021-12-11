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

int lengthOfLIS(vector<int>& nums)
{
	int i,j,k,u,v,x,y,z;

	int n = nums.size();

	if (n==0 || n==1)
		return n;

	vector<int>  count;

	count.resize(n,1);

	for (i=0;i<n;i++)
	{
		for (j=i+1;j<n;j++)
		{
			if (nums[i] < nums[j])
			{
				if (count[j] < (count[i]+1))
					count[j] = count[i] + 1;
			}
		}
	}

	int maxim = 0;

	for (i=0;i<count.size();i++)
	{
		if (maxim < count[i])
			maxim = count[i];
	}

	return maxim;
}

int main()
{
	cout<<" 300. Longest Increasing Subsequence "<<endl;

	// example 1
	vector<int> nums = {10,9,2,5,3,7,101,18};

	cout<<" printing the nums vector ;- "<<endl;
	for (int i=0;i<nums.size();i++)
		cout<<nums[i]<<" ";
	cout<<endl;
	cout<<endl;

	int answer = lengthOfLIS(nums);

	cout<<" answer = "<<answer<<endl;
}