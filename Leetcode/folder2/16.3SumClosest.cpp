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

int absval(int a)
{
	if (a<0)
		return (-1)*a;
	else
		return a;
}

int binSearch(vector<int>& nums, int val, int low, int high)
{
	if (low==high)
	{
		if (nums[low] == val)
			return 0;
		else
			return -1;
	}

	int mid;

	while (low <= high)
	{
		mid = low + (high-low)/2;

		if (nums[mid]==val)
			return 0;
		else if (nums[mid] < val)
			low = mid+1;
		else
			high = mid-1;
	}

	return -1;
}

int threeSumClosest(vector<int>& nums, int target)
{
	int i,j,k,u,v,x,y,z;

	int n = nums.size();

	if (n==3)
		return absval(nums[0]+nums[1]+nums[2]);

	sort(nums.begin(), nums.end());

	cout<<" printing the nus vector after sorting :- "<<endl;
	for (i=0;i<nums.size();i++)
		cout<<nums[i]<<" ";
	cout<<endl;

	int cond = -1;

	for (i=0;i<n;i++)
	{
		for (j=i+1;j<n;j++)
		{
			x = nums[i]+nums[j];
			y = target - x;

			if ((j+1)<n)
			{
				cond = binSearch(nums,y, j+1, n-1);

				if (cond==0)
					return target;
			}
		}
	}

	i = 0;
	j = n-1;

	int mindiff1,mindiff2, sum1, sum2;

	mindiff2 = pow(2,sizeof(int)*8-1)-1;
	sum2 = -1;

	while (i<j && (j-i)>=2)
	{
		// cout<<" hello "<<endl;
		k=i+1;
		mindiff1 = pow(2,sizeof(int)*8-1)-1;
		sum1 = -1;

		while (k<j)
		{
			x = nums[i] + nums[k] + nums[j];
			y = absval(x - target);

			if (mindiff1 > y)
			{
				sum1 = x;
				mindiff1 = y;
			}

			k++;
		}

		if (mindiff2 > mindiff1)
		{
			mindiff2 = mindiff1;
			sum2 = sum1;

			if (mindiff2==0)
				return target;
		}

		// cout<<" i = "<<i<<" , j = "<<j<<" , sum1 = "<<sum1<<" , mindiff1 = "<<mindiff1<<endl;

		if (sum1 < target)
			i++;
		else
			j--;
	}

	// cout<<" sum2 = "<<sum2<<" , mindiff2 = "<<mindiff2<<endl;

	return sum2;
}

int main()
{
	cout<<" 16. 3Sum Closest "<<endl;

	// example 1
	vector<int> nums = {-1,2,1,-4};
	int target = 1;

	// example 2
	// vector<int> nums = {4,0,5,-5,3,3,0,-4,-5};
	// int target = -2;

	cout<<" printing the nums vector :- "<<endl;

	for (int i=0;i<nums.size();i++)
		cout<<nums[i]<<" ";
	cout<<endl;
	cout<<" target = "<<target<<endl;

	int answer = threeSumClosest(nums, target);

	cout<<endl;
	cout<<" answer = "<<answer<<endl;
}