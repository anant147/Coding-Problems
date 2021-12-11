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

int longestOnes(vector<int>& nums, int k)
{
	int i,j;

	int n = nums.size();

	if (n<=k)
		return n;

	if (k==0)
	{
		int sum = 0;
		i=0;

		while (i<n)
		{
			int count = 0;
			j=i;

			while (j<n)
			{
				if (nums[i]==nums[j])
				{
					count++;
					j++;
				}
				else
					break;
			}

			if (sum < count)
				sum = count;

			i = j;
		}

		return sum;
	}

	vector<int> index;

	int count = 0;

	for (i=0;i<n;i++)
	{
		if (nums[i]==0)
			index.push_back(i);
		else
			count++;
	}

	if ((count+k)>=n)
		return n;
	else
	{
		int answer = k;

		int cnt1, cnt2, cnt3;

		int ilen = index.size();

		for (i=0;i<ilen-k+1;i++)
		{
			j = i+k-1;

			cnt2 = index[j] - index[i] + 1;

			if (i==0)
				cnt1 = index[i];
			else
				cnt1 = index[i] - index[i-1] - 1;

			if (j == (ilen-1))
				cnt3 = (n-1) - index[j];
			else
				cnt3 = index[j+1] - index[j] - 1;

			if (answer < (cnt1 + cnt2 + cnt3))
				answer = (cnt1 + cnt2 + cnt3);

			if (answer==n)
				break;
		}

		return answer;
	}
}

int main()
{
	cout<<" 1004. Max Consecutive Ones III "<<endl;

	// example 1
	// vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
	// int k = 2;

	// example 2
	vector<int> nums = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
	int k = 3;

	// example 3
	// vector<int> nums = {};
	// int k = 0;

	cout<<" printing the nums vector :- "<<endl;
	for (int i=0;i<nums.size();i++)
		cout<<nums[i]<<" ";
	cout<<endl;

	cout<<" k = "<<k<<endl;

	int answer = longestOnes(nums, k);

	cout<<" answer = "<<answer<<endl;
}