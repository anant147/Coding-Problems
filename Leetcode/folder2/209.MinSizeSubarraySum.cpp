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

int minSubArrayLen(int s, vector<int>& nums)
{
	int i,j,k,u,v,x,y,z;

	int n = nums.size();

	int sum = 0;

	int len = n+1;
	int cond1,cond2;

	i=0;
	j=0;
	while (j<n)
	{
		cond1 = 0;

		while (j<n && cond1 == 0)
		{
			sum = sum+nums[j];

			if (sum>=s)
			{
				cond1 = 1;
				break;
			}
			else
				j++;
		}

		if (cond1 == 1)
		{
			x = j-i+1;

			if (len > x)
				len = x;

			u = i;

			cond2 = 0;

			while (cond2==0 && u<=j)
			{
				sum = sum - nums[u];

				if (sum>=s)
				{
					u++;
					y = j-u+1;

					if (len > y)
						len = y;
				}
				else
				{
					cond2=1;
					sum = sum + nums[u];
					break;
				}
			}

			i=u;
			j++;
		}
	}

	return len;
}

int main()
{
	cout<<" 209. Minimum Size Subarray Sum "<<endl;

	int s = 7;
	vector<int> nums = {2,3,1,2,4,3};

	cout<<" s = "<<s<<endl;
	cout<<" printing the nums vector :- "<<endl;
	for (int i=0;i<nums.size();i++)
		cout<<nums[i]<<" ";
	cout<<endl;
	cout<<endl;

	int answer = minSubArrayLen(s, nums);

	cout<<" answer = "<<answer<<endl;
}