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

int wiggleMaxLength(vector<int>& nums)
{
	int i,j,k,u,v,x,y,z;

	int n = nums.size();

	if (n<=1)
		return 1;
	else if (n==2)
	{
		if (nums[0] == nums[1])
			return 1;
		else
			return 2;
	}

	vector<int> higcnt, lowcnt;
	higcnt.resize(n,1);
	lowcnt.resize(n,1);

	for (i=0;i<n;i++)
	{
		for (j=i+1;j<n;j++)
		{
			if (nums[i] < nums[j])
			{
				if (higcnt[j] < (1+lowcnt[i]))
					higcnt[j] = 1 + lowcnt[i];
			}
			else if (nums[i] > nums[j])
			{
				if (lowcnt[j] < (1+higcnt[i]))
					lowcnt[j] = 1+higcnt[i];
			}
		}
	}

	int maxim = 0;

	for (i=0;i<n;i++)
	{
		if (maxim < lowcnt[i])
			maxim = lowcnt[i];

		if (maxim < higcnt[i])
			maxim = higcnt[i];
	}

	return maxim;
}

int main()
{
	cout<<" 376. Wiggle Subsequence "<<endl;

	// example 1
	// vector<int> nums = {1,7,4,9,2,5};

	// example 2
	// vector<int> nums = {1,17,5,10,13,15,10,5,16,8};

	// example 3
	vector<int> nums = {1,2,3,4,5,6,7,8,9};

	cout<<" printing the nums vector :- "<<endl;

	for (int i=0;i<nums.size();i++)
		cout<<nums[i]<<" ";
	cout<<endl;

	int answer = wiggleMaxLength(nums);

	cout<<" answer = "<<answer<<endl;
}