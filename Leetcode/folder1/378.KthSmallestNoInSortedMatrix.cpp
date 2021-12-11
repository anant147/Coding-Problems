#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<stack>
#include<queue>
#include<cmath>
using namespace std;

void heapify(vector<int>& nums,int point, int n)
{
	int left = 2*point+1;
	int right = 2*point+2;

	if (left>=n && right>=n)
		return;

	int index = point;

	if (nums[left] < nums[point])
		index = left;

	if (right<n && nums[right] < nums[index])
		index = right;

	if (index != point)
	{
		int temp = nums[point];
		nums[point] = nums[index];
		nums[index] = temp;

		heapify(nums,index, n);
	}
}

int getMinimumElement(vector<int>& nums,int n)
{
	if (n==0)
		return -1;
	else if (n==1)
		return nums[0];
	
	int u = nums[0];
	int v = nums[n-1];

	nums[0] = v;
	nums[n-1] = u;

	heapify(nums,0,n-1);

	return u;
}

int kthSmallest(vector<vector<int>>& matrix, int k)
{
	int i,j,u,v,x,y,z;

	u = matrix.size();
	v = matrix[0].size();

	vector<int> nums;

	for (i=0;i<u;i++)
	{
		for (j=0;j<v;j++)
			nums.push_back(matrix[i][j]);
	}

	int n = nums.size();

	int fl = floor(n/2);

	for (i=fl;i>=0;i--)
		heapify(nums,i,n);

	// cout<<" printing the nums vector :- "<<endl;
	// for (i=0;i<nums.size();i++)
	// 	cout<<nums[i]<<" ";
	// cout<<endl;

	int count = 0;
	int val = 0;

	while(count != k)
	{
		val = getMinimumElement(nums,n);
		n--;
		count++;
	}

	return val;
}

int main()
{
	cout<<" 378. Kth Smallest Element in a Sorted Matrix "<<endl;

	vector<vector<int>> matrix = {
	                             {1,5,9},
	                             {10,11,13},
	                             {12,13,15}
	                             };

	int k = 8;

	cout<<" printing the matrix :- "<<endl;
	for (int i=0;i<matrix.size();i++)
	{
	   for (int j=0;j<matrix[i].size();j++)
	     cout<<matrix[i][j]<<" ";
	   cout<<endl;
	}
	cout<<endl;

	cout<<" k = "<<k<<endl;

	int answer = kthSmallest(matrix, k);

	cout<<" answer = "<<answer<<endl;


}