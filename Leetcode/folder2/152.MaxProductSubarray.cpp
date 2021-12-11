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

int minval(int a, int b)
{
	if (a<b)
		return a;
	else
		return b;
}

int maxval(int a, int b)
{
	if (a<b)
		return b;
	else
		return a;
}

int maxProduct(vector<int>& nums)
{
	int i,j,k,u,v,x,y,z;

	int n = nums.size();

	int max_end = 1;
	int min_end = 1;

	int maxim = 1;
	int flag = 0;

	for (i=0;i<n;i++)
	{
		if (nums[i]>0)
		{
			max_end = max_end * nums[i];
			min_end = minval(min_end * nums[i], 1);
			flag = 1;
		}
		else if (nums[i]==0)
		{
			max_end = 1;
			min_end = 1;
		}
		else
		{
			int temp = max_end;
			max_end = maxval(min_end * nums[i], 1);
			min_end = temp * nums[i];
		}

		if (maxim < max_end)
			maxim = max_end;
	}

	if (flag==0 && maxim==1)
		return 0;
	else
		return maxim;

}

int main()
{
	cout<<"  152. Maximum Product Subarray "<<endl;

	// example 1
	// vector<int> nums = {2,3,-2,4};

	// example 2
	vector<int> nums = {-2, 0, -1};

	cout<<" printing the nums vector :- "<<endl;

	for (int i=0;i<nums.size();i++)
		cout<<nums[i]<<" ";
	cout<<endl;

	int answer = maxProduct(nums);

	cout<<" answer = "<<answer<<endl;
}