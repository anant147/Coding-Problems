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

int maxval(int a, int b)
{
	if (a>b)
		return a;
	else
		return b;
}

vector<int> largestDivisibleSubset(vector<int>& nums)
{
	int i,j,k,u,v,x,y,z;

	int n = nums.size();

	if (n==0 || n==1)
		return nums;

	sort(nums.begin(), nums.end());

	vector<int> count;
	count.resize(n,1);

	for (i=1;i<n;i++)
	{
		for (j=i-1;j>=0;j--)
		{
			if (nums[i]%nums[j] == 0)
				count[i] = maxval(count[i], 1 + count[j]);
		}
	}

	int maxindex = 0;

	for (i=1;i<n;i++)
	{
		if (count[i] > count[maxindex])
			maxindex = i;
	}

	vector<int> result;
	int temp = nums[maxindex];
	int curcnt = count[maxindex];

	for (i = maxindex;i>=0;i--)
	{
		if (temp%nums[i]==0 && curcnt == count[i])
		{
			result.push_back(nums[i]);
			temp = nums[i];
			curcnt--;
		}
	}

	sort(result.begin(), result.end());

	return result;
}

int main()
{
	cout<<" 368. Largest Divisible Subset "<<endl;

	// example 1
	// vector<int> nums = {1,2,3};

	// example 2
	// vector<int> nums = {1,2,4,8};

	// example 3
	vector<int> nums = {1,2,4,8,9,72};

	// example 4
	// vector<int> nums = {3,4,6,8,12,16,32};

	cout<<" printing the nums vector :- "<<endl;

	for (int i=0;i<nums.size();i++)
	{
		cout<<nums[i]<<" ";
	} 
	cout<<endl;

	vector<int> answer = largestDivisibleSubset(nums);

	cout<<" printing the answer vector :- "<<endl;
	for (int i=0;i<answer.size();i++)
		cout<<answer[i]<<" ";
	cout<<endl;


}