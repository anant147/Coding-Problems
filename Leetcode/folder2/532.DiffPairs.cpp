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

int findPairs(vector<int>& nums,int k)
{
	int i,j,u,v,x,y,z;

	int n = nums.size();

	if (n==1)
		return 0;

	sort(nums.begin(),nums.end());

	int count = 0;

	if (k==0)
	{
		i=0;

		while (i<n)
		{
			u = i;
			int ctr = 0;

			while(u<n)
			{
				if (nums[i]==nums[u])
				{
					ctr++; u++;
				}
				else
					break;
			}

			if (ctr > 1)
				count++;

			i = u;
		}
	}
	else
	{
		i=0;
		j=0;
		int val;

		while(j<n)
		{
			u = i;

			while(u<n)
			{
				if (nums[i]==nums[u])
				{
				   u++;
				}
				else
					break;
			}

			i=u-1;
			val = nums[i]+k;
			
			if (i==j)
				j = i+1;

			if (j<n)
			{
				int cond = 0;
				while(j<n)
				{
					if (nums[j]<val)
						j++;
					else if (nums[j]==val)
					{
						cond = 1;
						count++;
						break;
					}
					else 
						break;
				}

				if (cond==1)
				{
					v = j;

					while(v<n)
					{
						if (nums[v]==nums[j])
							v++;
						else
							break;
					}

					j=v;
				}
			}
			else
				break;

			i++;
		}
	}

	return count;
}

int main()
{
	cout<<" 532. K-diff Pairs in an Array "<<endl;

	// example1
	// vector<int> nums = {3,1,4,1,5};
	// int k = 2;

	// example2
	// vector<int> nums = {1,2,3,4,5};
	// int k = 1;

	// example 3
	// vector<int> nums = {1,3,1,5,4};
	// int k = 0;

	// example 4
	vector<int> nums = {1,2,4,4,3,3,0,9,2,3};
	int k = 3;

	cout<<" k = "<<k<<endl;
	cout<<" printing the nums vector :- "<<endl;
	for (int i=0;i<nums.size();i++)
		cout<<nums[i]<<" ";
	cout<<endl;

	int answer = findPairs(nums,k);

	cout<<" answer = "<<answer<<endl;
}