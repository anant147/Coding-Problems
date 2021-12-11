#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<map>
#include<unordered_map>
#include<queue>
#include<stack>
#include<cmath>
#include<cstring>
using namespace std;

int maxDifference1(vector<int>& nums)
{
	int n = nums.size();

	if (n<=1)
		return 0;

	int i;

	vector<int> mintor, maxtor;
	mintor.resize(n,0);
	maxtor.resize(n,0);

	for (i=0;i<n;i++)
	{
		if (i==0)
			mintor[i] = nums[i];
		else 
		{
			if (mintor[i-1] < nums[i])
				mintor[i] = mintor[i-1];
			else
				mintor[i] = nums[i];
		}
	}

	for (i=n-1;i>=0;i--)
	{
		if (i== n-1)
			maxtor[i] = nums[i];
		else
		{
			if (maxtor[i+1] > nums[i])
				maxtor[i] = maxtor[i+1];
			else
				maxtor[i] = nums[i];
		}
	}

	int diff = 0;

	for (i=0;i<n;i++)
	{
		if (diff < (maxtor[i] - mintor[i]))
			diff = maxtor[i] - mintor[i];
	}

	return diff;
}

int maxDifference2(vector<int> nums)
{
	int n = nums.size();

	if (n<=1)
		return 0;

	int diff = nums[1] - nums[0];
	int minelem = nums[0];

	for (int i=1;i<n;i++)
	{
		if ( diff < (nums[i] - minelem) )
			diff = nums[i] - minelem;

		if (minelem > nums[i])
			minelem = nums[i];
	}

	return diff;
}

int main()
{
	cout<<" Sap Labs question "<<endl;

	cout<<" Maximum difference Aj - Ai s.t. j > i and A[j]>A[i] "<<endl;

	vector<int> nums = {2,3,10,6,4,8,1};

	cout<<" printing the nums vector :- "<<endl;
	for (int i=0;i<nums.size();i++)
		cout<<nums[i]<<" ";
	cout<<endl;
	cout<<endl;

	int answer1 = maxDifference1(nums);

	cout<<" answer1 = "<<answer1<<endl;

	int answer2 = maxDifference2(nums);
	cout<<endl;

	cout<<" answer2 = "<<answer2<<endl;




}