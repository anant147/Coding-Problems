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

int closestToTarget(vector<int>& arr, int target)
{
	int i,j,k,u,v,x,y,z;

	int n = arr.size();

	int minval = pow(2,sizeof(int)*8-1)-1;

	for (i=0;i<n;i++)
	{
		k = arr[i]-target;

		if (k<0)
			k = k*-1;

		if (minval>k)
			minval = k;
	}

	for (i=0;i<n;i++)
	{
		if (i==0)
			u = arr[i];
		else
			u = u & arr[i];

		k = u - target;

		if (k<0)
			k = k*(-1);

		if (minval>k)
			minval = k;
	}

	for (i=n-1;i>=0;i--)
	{
		if (i==(n-1))
			u = arr[i];
		else
			u = u & arr[i];

		k = u - target;

		if (k<0)
			k = k*(-1);

		if (minval>k)
			minval = k;
	}

	return minval;
}

int main()
{
	cout<<" 1521. Find a Value of a Mysterious Function Closest to Target "<<endl;

	// example 1
	// vector<int> arr = {9,12,3,7,15};
	// int target = 5;

	// example 2
	// vector<int> arr = {1000000,1000000,1000000};
	// int target = 1;

	// example 3
	vector<int> arr = {1,2,4,8,16};
	int target = 0;

	cout<<" printing the arr vector :- "<<endl;
	for (int i=0;i<arr.size();i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	cout<<endl;
	cout<<" target = "<<target<<endl;
	cout<<endl;

	int answer = closestToTarget(arr, target);
	cout<<" answer = "<<answer<<endl;
}