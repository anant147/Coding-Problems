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

int minval (int a, int b)
{
	if (a<b)
		return a;
	else
		return b;
}

int maxval (int a, int b)
{
	if (a<b)
		return b;
	else
		return a;
}

double getMedTwo(int a, int b)
{
	return ((a+b)/2.0);
}

double getMedThree(int a,int b, int c)
{
	int max = maxval(a,maxval(b,c));
	int min = minval(a,minval(b,c));

	return double( (a+b+c) - (max+min) );
}

double getMedFour(int a, int b, int c, int d)
{
	int min = minval(a,minval(b,minval(c,d)));
	int max = maxval(a,maxval(b,maxval(c,d)));
	int sum = a + b + c + d;

	return ((sum - (min+max))/2.0);
}

double getMedOfVect(vector<int>& nums1, int n)
{
	if (n==0)
		return (double)(0);
	else if (n%2==0)
		return ((nums1[n/2-1] + nums1[n/2])/2.0);
	else
		return double(nums1[n/2]);
}

double getMedian(vector<int>& nums1, vector<int>& nums2, int n, int m)
{
	if (n==0)
		return getMedOfVect(nums2,m);
	else if (n==1)
	{
		if (m==1)
			return getMedTwo(nums1[0], nums2[0]);

		if (m%2==1)
			return getMedTwo(nums2[m/2], getMedThree( nums1[0], nums2[m/2-1], nums2[m/2+1]));
		else
			return getMedThree(nums1[0], nums2[m/2-1], nums2[m/2]);
	}
	else if (n==2)
	{
		if (m==2)
			return getMedFour(nums1[0], nums1[1], nums2[0], nums2[1]);

		if (m%2==1)
			return getMedThree(nums2[m/2], maxval(nums1[0], nums2[m/2-1]), minval(nums1[1], nums2[m/2+1]));
		else
			return getMedFour(nums2[m/2], nums2[m/2-1], maxval(nums1[0], nums2[m/2-2]), minval(nums1[1], nums2[m/2+1]));
	}
	else
	{
		int idx1 = (n-1)/2;
		int idx2 = (m-1)/2;

		vector<int>::iterator it;
		vector<int> temp;

		if (nums1[idx1] <= nums2[idx2])
		{
			it = nums1.begin()+idx1;
			nums1.assign(it,nums1.end());

			return getMedian(nums1,nums2, n/2+1, m - idx1);
		}
		else
		{
			it = nums2.begin() + idx1;
			nums2.assign(it,nums2.end());

			return getMedian(nums1, nums2, n/2+1, m - idx1);
		}
	}
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	int n = nums1.size();
	int m = nums2.size();

	if (n==0 && m==0)
		return 0.0;

	if (n<m)
		return getMedian(nums1, nums2, n, m);
	else
		return getMedian(nums2, nums1, m, n);
}

int main()
{
	cout<<" 4. Median of Two Sorted Arrays "<<endl;

	// example1 
	// vector<int> nums1 = {1,3};
	// vector<int> nums2 = {2};

	// example2
	// vector<int> nums1 = {1,2};
	// vector<int> nums2 = {3,4};

	// // example3
	// vector<int> nums1 = {0,0};
	// vector<int> nums2 = {0,0};

	// // example4
	vector<int> nums1 = {1};
	vector<int> nums2 = {};

	// // example5
	// vector<int> nums1 = {};
	// vector<int> nums2 = {2};

	cout<<" printing the nums1 vector :- "<<endl;
	int i,j,k;
	for (i=0;i<nums1.size();i++)
		cout<<nums1[i]<<" ";
	cout<<endl;

	cout<<" printing the nums2 vector :- "<<endl;
	for (i=0;i<nums2.size();i++)
		cout<<nums2[i]<<" ";
	cout<<endl;

	double answer = findMedianSortedArrays(nums1, nums2);

	cout<<" answer = "<<answer<<endl;


}