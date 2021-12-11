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

int findDuplicate(vector<int>& nums)
{
	int i,j,k;

	int n = nums.size();

	sort(nums.begin(),nums.end());

	int count = 0;

	i = 0;
	while (i<n)
	{
		k = i;
		count = 0;

		while (k<n)
		{
			if (nums[i]==nums[k])
			{
				count++;
				k++;
			}
			else
				break;
		}

		if (count > 1)
			return nums[i];
		else
			i = k+1;
	}
}

int main()
{
	cout<<"  287. Find the Duplicate Number "<<endl;

	// example 1
	// vector<int> nums = {1,3,4,2,2};

	// example 2
	vector<int> nums = {3,1,3,4,2};

	// example 3
	// vector<int> nums = {1,1,2};

	// example 4
	// vector<int> nums = {1,1};

	cout<<" printing the nums vector :- "<<endl;
	for (int i=0;i<nums.size();i++)
		cout<<nums[i]<<" ";
	cout<<endl;
	cout<<endl;

	int answer = findDuplicate(nums);

	cout<<" answer = "<<answer<<endl;
}