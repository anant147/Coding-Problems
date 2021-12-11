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

int numberOfSubarrays(vector<int>& nums, int k)
{
	int i,j;

	int alen = nums.size();

	vector<int> index;

	for (i=0;i<nums.size();i++)
	{
		if (nums[i]%2 == 1)
			index.push_back(i);
	}

	int n = index.size();

	int sum = 0;

	if (n<k)
		return sum;
	else
	{
		int cnt1,cnt2;

		for (i=0;i<n-k+1;i++)
		{
			j = i+k-1;

			if (i==0)
			{
				cnt1 = index[0]+1;

				if (j==n-1)
					cnt2 = alen - index[j];
				else
					cnt2 = index[j+1] - index[j];
			}
			else
			{
				cnt1 = index[i] - index[i-1];

				if (j==n-1)
					cnt2 = alen - index[j];
				else
					cnt2 = index[j+1] - index[j];
			}

			sum = sum + (cnt1 * cnt2);
		}

		return sum;
	}
}

int main()
{
	cout<<" 1248. Count Number of Nice Subarrays "<<endl;

	// example 1
	// vector<int> nums = {1,1,2,1,1};
	// int k = 3;

	// example 2
	// vector<int> nums = {2,4,6};
	// int k = 1;

	// example 3
	vector<int> nums = {2,2,2,1,2,2,1,2,2,2};
	int k = 2;

	cout<<" printing the nums vector :- "<<endl;
	for (int i=0;i<nums.size();i++)
		cout<<nums[i]<<" ";
	cout<<endl;
	cout<<" k = "<<k<<endl;

	int answer = numberOfSubarrays(nums, k);

	cout<<" answer = "<<answer<<endl;
}