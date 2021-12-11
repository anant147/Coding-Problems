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

void sortColors(vector<int>& nums)
{
	int i,j,k;

	int count0 = 0;
	int count1 = 0;
	int count2 = 0;

	int n = nums.size();

	for (i=0;i<n;i++)
	{
		if (nums[i]==0)
			count0++;
		else if (nums[i]==1)
			count1++;
		else if (nums[i]==2)
			count2++;
	}

	i=0;

	while (i<n)
	{
		while(count0>0 && i<n)
		{
			count0--;
			nums[i]=0;
			i++;
		}

		while (count1>0 && i<n)
		{
			count1--;
			nums[i]=1;
			i++;
		}

		while(count2>0 && i<n)
		{
			count2--;
			nums[i]=2;
			i++;
		}
	}

	// cout<<" printing the nums vector in function :-"<<endl;
	// for (i=0;i<n;i++)
	// 	cout<<nums[i]<<" ";
	// cout<<endl;
	// cout<<endl;
}

int main()
{
	cout<<" 75. Sort Colors "<<endl;

	// example 1
	// vector<int> nums = {2,0,2,1,1,0};

	// example 2
	// vector<int> nums = {2,0,1};

	// example 3
	// vector<int> nums = {0};

	// example 4
	vector<int> nums = {1};

	cout<<" printing the nums vector :- "<<endl;

	for (int i=0;i<nums.size();i++)
		cout<<nums[i]<<" ";
	cout<<endl;
	cout<<endl;

	sortColors(nums);
}