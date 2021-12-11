#include <bits/stdc++.h> 
using namespace std;

int maxval(int a, int b)
{
	if (a>b)
		return a;
	else
		return b;
}

bool isFeasible(vector<int>& arr, int n, int k, int mid)
{
	int pos = arr[0];
	int elements = 1;

	for (int i=1;i<n;i++)
	{
		if (arr[i]-pos >= mid)
		{
			pos = arr[i];
			elements++;

			if (elements==k)
				return true;
		}
	}

	return false;
}

int largestMinDist(vector<int>& arr, int k)
{
	int n = arr.size();

	sort(arr.begin(),arr.end());

	int left = 1;
	int right = arr[n-1];

	int res = -1;

	while (left < right)
	{
		int mid = left + (right - left)/2;

		if (isFeasible(arr, n, k, mid))
		{
			res = maxval(res, mid);
			left = mid + 1;
		}
		else
		{
			right = mid;
		}
	}

	return res;
}

int main()
{
	cout<<" JPMC question 11"<<endl;
	cout<<" Place k elements such that minimum distance is maximized "<<endl;

	// example 1
	// vector<int> arr = {1, 2, 8, 4, 9};
	// int k = 3;

	// example 2
	vector<int> arr = {1, 2, 7, 5, 11, 12};
	int k = 3;

	cout<<" printing the arr vector :- "<<endl;
	for (int i=0;i<arr.size();i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	cout<<endl;

	cout<<" k = "<<k<<endl;

	int answer = largestMinDist(arr,k);

	cout<<" answer = "<<answer<<endl;
}