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

int removeDuplicates(vector<int>& nums)
{
	int i,j,k,u;

	int n = nums.size();

	int count = 0;
	int val;

	i=0;
	j=0;

	while (i<n)
	{
		k = i;
		val = 0;

		while (nums[k]==nums[i] && k<n)
		{
			val++; k++;
		}

		if (val <=2)
		{
			count = count + val;
			u = val;

			while (u>0)
			{
				nums[j]=nums[i];
				j++;
				u--;
			}

		}
		else
		{
			count = count + 2;

			u = 2;

			while(u>0)
			{
				nums[j]=nums[i];
				j++;
				u--;
			}
		}

		i = k;
	}

	nums.assign(nums.begin(), nums.begin()+count);

	// int len = nums.size();

	// cout<<" len = "<<len<<endl;

	// cout<<" printing the nums vector in fuction :- "<<endl;
	// for (i=0;i<len;i++)
	// 	cout<<nums[i]<<" ";
	// cout<<endl;
	// cout<<endl;

	return count;
}

int main()
{
	cout<<" 80. Remove Duplicates from Sorted Array II "<<endl;

	// example 1
	vector<int> nums = {1,1,1,2,2,3};

	// example 2
	// vector<int> nums = {0,0,1,1,1,1,2,3,3};

	cout<<" printing the nums vector :- "<<endl;
	int i;
	for (i=0;i<nums.size();i++)
		cout<<nums[i]<<" ";
	cout<<endl;
	cout<<endl;

	int answer = removeDuplicates(nums);

	cout<<" answer = "<<answer<<endl;
}