#include<bits/stdc++.h>
using namespace std;

int maxLen( int arr[], int n)
{
	unordered_map<int,int> hm;

	int sum = 0;
	int max_len = 0;
	int ending_idx = -1;

	for (int i=0;i<n;i++)
	{
		if (arr[i] == 0)
			arr[i] = -1;
	}

	for (int i=0;i<n;i++)
	{
		sum += arr[i];

		if (sum == 0)
		{
			max_len = i+1;
			ending_idx = i;
		}

		if (hm.find(sum+n) != hm.end())
		{
			int u = i - hm[sum+n];

			if (max_len < u)
			{
				max_len = u;
				ending_idx = i;
			}
		}
		else
		{
			hm[sum+n] = i;
		}
	}

	for (int i=0;i<n;i++)
	{
		if (arr[i] == -1)
			arr[i] = 0;
	}

	cout<<" starting point = "<<ending_idx - max_len + 1<<" , ending point = "<<ending_idx<<endl;

	return max_len;
}

int main()
{
	cout<<" Morgan Stanley 2 "<<endl;
	cout<<" Largest subarray with equal number of 0s and 1s "<<endl;
	cout<<endl;

	// ex1
	// int arr[] = {1,0,0,1,0,1,1};

	// ex2
	// int arr[] = {1, 0, 1, 1, 1, 0, 0};

	// ex3
	// int arr[] = {1, 1, 1, 1};

	// ex4
	int arr[] = {0, 0, 1, 1, 0};

	int n = sizeof(arr)/ sizeof(arr[0]);

	cout<<" n = "<<n<<endl;
	for (int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;

	int answer = maxLen(arr,n);
	cout<<" answer = "<<answer<<endl;
}