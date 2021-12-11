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

int getMaximumValue(vector<int>& nums)
{
	int i,j,k;

	int maxval = (-1)*pow(2,sizeof(int)*8-1);

	for (i=0;i<nums.size();i++)
	{
		if (maxval < nums[i])
			maxval = nums[i];
	}

	return maxval;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int maxSubArray1(vector<int>& nums)
{
	int i,j,k,u,v,x,y,z;

	int n = nums.size();

	if (n==1)
		return nums[0];

	x = getMaximumValue(nums);

	if (x<=0)
		return x;

	int maxval1 = 0;
	int maxval2 = (-1)*pow(2,sizeof(int)*8-1);

	for (i=0;i<nums.size();i++)
	{
		maxval1 = maxval1 + nums[i];

		if (maxval2 < maxval1)
			maxval2 = maxval1;

		if (maxval1 < 0)
			maxval1 = 0;
	}

	return maxval2;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int max2(int a,int b)
{
	if (a>b)
		return a;
	else
		return b;
}

int max3(int a, int b, int c)
{
	return max2( a, max2(b,c));
}

int maxCrossingSum(vector<int>& nums, int st, int mid, int ed)
{
	int i,j,k,u,v,x,y,z;

	int left_sum = (-1)*pow(2,sizeof(int)*8-1);
	int sum = 0;

	for (i=mid;i>=st;i--)
	{
		sum = sum + nums[i];

		if (left_sum < sum)
			left_sum = sum;
	}

	sum = 0;
	int right_sum = (-1)*pow(2,sizeof(int)*8-1);

	for (i=mid+1;i<=ed;i++)
	{
		sum = sum + nums[i];

		if (right_sum < sum)
			right_sum = sum;
	}

	return max3( left_sum+right_sum, left_sum, right_sum);
}

int getMaxSubarraySum(vector<int>& nums, int st, int ed)
{
	if (st==ed)
		return nums[st];

	int mid = st + (ed-st)/2;

	return max3( getMaxSubarraySum(nums, st, mid), getMaxSubarraySum(nums, mid+1, ed), maxCrossingSum(nums, st, mid, ed));
}

int maxSubArray(vector<int>& nums)
{
	int i,x;

	int n = nums.size();

	if (n==1)
		return nums[0];

	x = getMaximumValue(nums);

	if (x <= 0)
		return x;

	return getMaxSubarraySum(nums,0,n-1);
}

int main()
{
	cout<<" 53. Maximum Subarray "<<endl;

	// example 1
	vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

	// // example 2
	// vector<int> nums = {1};

	// // example 3
	// vector<int> nums = {0};

	// // example 4
	// vector<int> nums = {-1};

	// // example 5
	// vector<int> nums = {-2147483647};

	int answer = maxSubArray(nums);

	cout<<" answer = "<<answer<<endl;

}