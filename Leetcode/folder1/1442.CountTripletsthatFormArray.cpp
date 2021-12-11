#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
#include<cstring>
using namespace std;

int countTriplets(vector<int>& arr)
{
	int i,j,k,u,v,x,y,z;

	if (arr.size()==0 || arr.size()==1)
		return 0;

	vector<vector<int>> bitstor;
	vector<int> temp;

	int count = 0;

	int n = arr.size();

	for (i=0;i<n;i++)
	{
		x = arr[i];

		for (j=i+1;j<n;j++)
		{
			x = x^arr[j];

			if (x==0)
				count = count + (j-i);
		}
	}

	return count;
}

int main()
{
	cout<<" 1442. Count Triplets That Can Form Two Arrays of Equal XOR "<<endl;

	// example 1
	// vector<int> arr = {2,3,1,6,7};

	// example 2
	// vector<int> arr = {1,1,1,1,1};

	// example 3
	// vector<int> arr = {2,3};

	// example 4
	// vector<int> arr = {1,3,5,7,9};

	// example 5
	vector<int> arr = {7,11,12,9,5,2,7,17,22};

	cout<<" printing the arr vector :- "<<endl;
	for (int i=0;i<arr.size();i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	cout<<endl;

	int answer = countTriplets(arr);
	cout<<" answer = "<<answer<<endl;

}