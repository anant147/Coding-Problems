#include<iostream>
#include<vector>
#include<utility>
#include<stack>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;

void heapify(vector<int>& nums,int pt,int n)
{
	int left = 2*pt+1;
	int right = 2*pt+2;

	int u,v,x,y,z;

	if (left>=n && right>=n)
		return;

	int index = pt;

	if (nums[left]>nums[pt])
		index = left;

	if (right<n && nums[right]>nums[index])
		index = right;

	if (index != pt)
	{
		int temp = nums[index];
		nums[index] = nums[pt];
		nums[pt] = temp;
		heapify(nums,index,n);
	}
}

int getLargestElem(vector<int>& nums,int n)
{
	if (n==0)
		return -1;

	if (n==1)
		return nums[0];

	int u = nums[0];
	int v = nums[n-1];

	nums[0] = v;
	nums[n-1] = u;

	heapify(nums,0,n-1);

	return u;
}

int findKthLargest(vector<int>& nums,int k)
{
	int i,j,u,v,x,y;

	int n = nums.size();

	int fl = floor(n/2);

	for (i=fl;i>=0;i--)
		heapify(nums,i,n);

	// cout<<" printing the nums as heap :- "<<endl;
	// for (i=0;i<n;i++)
	// 	cout<<nums[i]<<" ";
	// cout<<endl;

	int count=0;
	int val = -1;

	while(count != k)
	{
		val = getLargestElem(nums,n);
		n--;
		count++;
	}

	return val; 
}

int main()
{
	cout<<" 215. Kth Largest Element in an Array "<<endl;

	// example 1
	// vector<int> nums = {3,2,1,5,6,4};
	// int k = 2;

	// example 2
	vector<int> nums = {3,2,3,1,2,4,5,5,6};
	int k = 4;

	cout<<" printing the nums vector :- "<<endl;
	for (int i=0;i<nums.size();i++)
		cout<<nums[i]<<" ";
	cout<<endl;

	cout<<" k = "<<k<<endl;

	int answer = findKthLargest(nums,k);
	cout<<" answer = "<<answer<<endl;
}