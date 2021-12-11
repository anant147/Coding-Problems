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

int sumSubarrayMins(vector<int>& nums)
{
	int n = nums.size();

	int left[n], right[n];

	int i;

	stack<pair<int, int>> st1, st2;

	for (i=0;i<n;i++)
	{
		int cnt = 1;

		while ( !st1.empty() && (st1.top().first >= nums[i]))
		{
			cnt = cnt + st1.top().second;
			st1.pop();
		}

		st1.push(make_pair(nums[i], cnt));
		left[i] = cnt;
	}

	for (i=n-1;i>=0;i--)
	{
		int cnt = 1;

		while (!st2.empty() && (st2.top().first >= nums[i]))
		{
			cnt = cnt + st2.top().second;
			st2.pop();
		}

		st2.push(make_pair(nums[i], cnt));
		right[i] = cnt;
	}

	int result = 0;

	for (i = 0;i<n;i++)
	{
		result = result + (nums[i] * left[i] * right[i]); 
	}

	return result;
}

int sumSubarrayMaxs(vector<int>& nums)
{
	int n = nums.size();

	int left[n], right[n];

	int i;

	stack<pair<int, int>> st1, st2;

	for (i=0;i<n;i++)
	{
		int cnt = 1;

		while ( !st1.empty() && (st1.top().first <= nums[i]))
		{
			cnt = cnt + st1.top().second;
			st1.pop();
		}

		st1.push(make_pair(nums[i], cnt));
		left[i] = cnt;
	}

	for (i=n-1;i>=0;i--)
	{
		int cnt = 1;

		while (!st2.empty() && (st2.top().first <= nums[i]))
		{
			cnt = cnt + st2.top().second;
			st2.pop();
		}

		st2.push(make_pair(nums[i], cnt));
		right[i] = cnt;
	}

	int result = 0;

	for (i = 0;i<n;i++)
	{
		result = result + (nums[i] * left[i] * right[i]); 
	}

	return result;
}

int getSum(vector<int>& nums)
{  
	if (nums.size() <=1)
		return 0;

	int minsum = sumSubarrayMins(nums);
	int maxsum = sumSubarrayMaxs(nums);

	cout<<" minsum = "<<minsum<<endl;
	cout<<" maxsum = "<<maxsum<<endl;

	return maxsum - minsum;
}

int main()
{
	cout<<" cohesity2 . Sum of (max element - min element) of every contiguous subarray "<<endl;

	// example 1
	vector<int> nums = {2,5,2};

	cout<<" printing the nums vector :- "<<endl;
	for (int i=0;i<nums.size();i++)
		cout<<nums[i]<<" ";
	cout<<endl;

	int answer = getSum(nums);

	cout<<" answer = "<<answer<<endl;
}