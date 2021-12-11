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

int longestMountain(vector<int>& nums)
{
	int i,j,k,u,v,x,y,z;

	int n = nums.size();

	if (n<=2)
		return 0;

	int length = 0;

	for (i=1;i<=n-2; )
	{
		if (nums[i-1] < nums[i] && nums[i] > nums[i+1])
		{
			int count = 1;
			y = i;
			x = i-1;

			while (x>=0)
			{
				if (nums[x] < nums[y])
				{
					count++;
					x--;
					y--;
				}
				else
					break;
			}

			x = i;
			y = i+1;

			while (y<n)
			{
				if (nums[x] > nums[y])
				{
					count++;
					x++;
					y++;
				}
				else
					break;
			}

			if (length < count)
				length = count;

			i = y;
		}
		else
		{
			i++;
		}
	}

	return length;
}

int main()
{
	cout<<" 845. Longest Mountain in Array "<<endl;

	// example 1
	vector<int> nums = {2,1,4,7,3,2,5};

	// example 2
	// vector<int> nums = {2,2,2};

	cout<<" printing the nums vector :- "<<endl;
	for (int i=0;i<nums.size();i++)
		cout<<nums[i]<<" ";
	cout<<endl;
	cout<<endl;

	int answer = longestMountain(nums);

	cout<<" answer = "<<answer<<endl;
}