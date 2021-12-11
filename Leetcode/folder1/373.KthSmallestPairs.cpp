#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<stack>
#include<queue>
#include<cmath>
using namespace std;

void heapify(vector<vector<int>>& hvect, int point, int n)
{
	int left = 2*point+1;
	int right = 2*point+2;

	if (left>=n && right>=n)
		return;

	int index = point;

	if (hvect[left][2] < hvect[point][2])
		index = left;

	if (right<n && (hvect[right][2] < hvect[index][2]))
		index = right;

	if (index != point)
	{
		vector<int> temp = hvect[point];
		hvect[point] = hvect[index];
		hvect[index] = temp;

		heapify(hvect, index, n);
	}
}

vector<int> minPair(vector<vector<int>>& hvect, int n)
{
	if (n==0)
		return {0,0};
	else if (n==1)
		return {hvect[0][0],hvect[0][1]};

	vector<int> temp1 = hvect[0];
	vector<int> temp2 = hvect[n-1];

	hvect[0] = temp2;
	hvect[n-1] = temp1;

	heapify(hvect,0,n-1);

	return {temp1[0],temp1[1]};
}

vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k)
{
	int i,j,u,v,x,y,z;

	u = nums1.size();
	v = nums2.size();

	vector<vector<int>> hvect;

	for (i=0;i<u;i++)
	{
		for (j=0;j<v;j++)
			hvect.push_back({nums1[i], nums2[j], nums1[i] + nums2[j]});
	}

	int n = u*v;

	int fl = floor(n/2);

	for (i=fl;i>=0;i--)
		heapify(hvect, i, n);

	vector<vector<int>> spair;
	vector<int> temp;
	int count=0;



	while(count!=k && n!=0)
	{
		temp = minPair(hvect,n);
		spair.push_back(temp);
		temp.clear();
		n--;
		count++;
	}

	return spair;
}

int main()
{
	cout<<" 373. Find K Pairs with Smallest Sums "<<endl;

	// example 1
	// vector<int> nums1 = {1,7,11};
	// vector<int> nums2 = {2,4,6};
	// int k = 3;

	// example 2
	// vector<int> nums1 = {1,1,2};
	// vector<int> nums2 = {1,2,3};
	// int k = 2;

	// example 2
	vector<int> nums1 = {1,2};
	vector<int> nums2 = {3};
	int k = 3;
	int i;

	cout<<" printing nums1 vector :- "<<endl;
	for (i=0;i<nums1.size();i++)
	  cout<<nums1[i]<<" ";
	cout<<endl;

	cout<<" printing nums2 vector :- "<<endl;
	for (i=0;i<nums2.size();i++)
	  cout<<nums2[i]<<" ";
	cout<<endl;

	cout<<" k = "<<k<<endl;

	vector<vector<int>> answer = kSmallestPairs(nums1, nums2, k);

	for (int i=0;i<answer.size();i++)
	  cout<<answer[i][0]<<" , "<<answer[i][1]<<endl;


}