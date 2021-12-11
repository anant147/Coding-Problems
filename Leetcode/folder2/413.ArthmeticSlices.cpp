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

int numberOfArithmeticSlices(vector<int>& nums)
{
	int i,j,k,u,v,x,y,z;

	int n = nums.size();

	if (n<=1)
		return 0;

	int count = 0;

	i=0;
	j=1;
	k=2;

	while (k<n)
	{
		if ((nums[k]-nums[j] == nums[j]-nums[i]))
		{
			int len = 0;

			while (k<n && (nums[k]-nums[j] == nums[j]-nums[i]))
			{
				len++;
				i++;
				j++;
				k++;
			}

			count = count + ((len*(len+1))/2);

			i = k;
			j = i+1;
			k = i+2;
		}
		else
		{
			i++;
			j++;
			k++;
		}
	}

	return count;
}

int main()
{
	cout<<" 413. Arithmetic Slices "<<endl;

	// example 1
	// vector<int> nums = {1, 2, 3, 4};

	// example 2
	vector<int> nums = {1,2,3,8,9,10};

	cout<<" printing the nums vector :- "<<endl;

	for (int i=0;i<nums.size();i++)
		cout<<nums[i]<<" ";
	cout<<endl;
	// cout<<endl;

	int answer = numberOfArithmeticSlices(nums);

	cout<<" answer = "<<answer<<endl;
}