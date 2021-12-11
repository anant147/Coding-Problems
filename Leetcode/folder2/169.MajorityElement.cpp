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

int majorityElement(vector<int>& nums)
{
	int i,j,k,u,v,x,y,z;

	int n = nums.size();

	int mjrElm;
	int count = 0;

	for (i=0;i<n;i++)
	{
		if (count==0)
		{
			mjrElm = nums[i];
			count++;
		}
		else if (nums[i]==mjrElm)
			count++;
		else
			count--;
	}

	count = 0;

	for (i=0;i<n;i++)
	{
		if (nums[i]==mjrElm)
			count++;
	}

	if (count > (n/2))
		return mjrElm;
	else
		return -1;
}

int main()
{
	cout<<" 169. Majority Element "<<endl;

	// example 1
	// vector<int> nums = {3,2,3};

	// example 2
	vector<int> nums = {2,2,1,1,1,2,2};

	cout<<" printing the nums vector :- "<<endl;
	int i,j;

	for (i=0;i<nums.size();i++)
		cout<<nums[i]<<" ";
	cout<<endl;

	int answer = majorityElement(nums);

	cout<<" answer = "<<answer<<endl;
}