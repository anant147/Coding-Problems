#include<iostream>
#include<climits>
using namespace std;

int maxSubarraySum(int a[], int n)
{
	int max_so_far = INT_MIN;
	int max_ending_here = 0;

	for (int i=0;i<n;i++)
	{
		max_ending_here += a[i];

		if (max_so_far < max_ending_here)
			max_so_far = max_ending_here;

		if (max_ending_here < 0)
			max_ending_here = 0;
	}

	return max_so_far;
}

int main()
{
	cout<<" Samsung question 27 :- "<<endl;
	cout<<" kadane algorithm - maximum subarray sum :- "<<endl;
	cout<<endl;

	int a[] = {-2,-3,4,-1,-2,1,5,-3};
	int n = sizeof(a)/sizeof(a[0]);

	cout<<" printing the a array :- "<<endl;
	for (int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	cout<<endl;

	int max_sum = maxSubarraySum (a,n);

	cout<<" maximum subarray sum is = "<<max_sum<<endl;
	cout<<endl;
}