#include<bits/stdc++.h>
using namespace std;

int getSmallestPosNo(int arr[], int n)
{
	int i,j,k,u,v;

	vector<int> stor;
	stor.resize(101, 0);

	for (i=0;i<n;i++)
	{
		if (arr[i] > 0)
			stor[ arr[i]]++;
	}

	for (i=1;i<=100;i++)
	{
		if (stor[i] == 0)
			return i;
	}

	return -1;
}

int main()
{
	cout<<" Samsung 1  "<<endl;
	cout<<" print the smallest positive number missing "<<endl;

	// example 1
	// int n = 5;
	// int arr[] = {1,2,3,4,5};

	// example 2
	int n = 5;
	int arr[] = {0,-10,1,3,-20};

	cout<<" n = "<<n<<endl;
	cout<<" printing the arr array :- "<<endl;
	for (int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;

	int answer = getSmallestPosNo(arr, n);

	cout<<" answer = "<<answer<<endl;
}