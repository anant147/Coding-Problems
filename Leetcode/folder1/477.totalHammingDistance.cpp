#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
#include<cstring>
using namespace std;

int totalHammingDistance(vector<int>& nums)
{
	int i,j,k,u,v,x,y,z;

	int n = nums.size();

	// sort(nums.begin(),nums.end());

	vector<vector<int>> bitstor;

	int count;

	for (i=0;i<n;i++)
	{
		k = nums[i];

		vector<int> temp;
		temp.resize(32,0);

		j=0;
		while(j<32 && k!=0)
		{
			temp[j] = k%2;
			k = k/2;
			j++;
		}

		bitstor.push_back(temp);
		temp.clear();
	}

	vector<int> vbitsum;
	vbitsum.resize(32,0);

	for (i=0;i<bitstor.size();i++)
	{
		for (j=0;j<bitstor[i].size();j++)
		{
			vbitsum[j] = vbitsum[j] + bitstor[i][j];
		}
	}

	// cout<<" printing the bitstor vector :- "<<endl;
	// for (i=0;i<bitstor.size();i++)
	// {
	// 	for (j=0;j<bitstor[i].size();j++)
	// 		cout<<bitstor[i][j]<<" ";
	// 	cout<<endl;
	// }
	// cout<<endl;

	// cout<<" printing the bitstor vector :- "<<endl;
	// for (i=0;i<vbitsum.size();i++)
	// 	cout<<vbitsum[i]<<" ";
	// cout<<endl;

	int sum = 0;
	count = 0;

	int m = bitstor.size();

	for (i=0;i<bitstor.size();i++)
	{
		count = 0;

		for (j=0;j<bitstor[i].size();j++)
		{
			if (bitstor[i][j]==0)
				count = count + vbitsum[j];
			else
				count = count + ( m - vbitsum[j] );
		}
		sum = sum + count;
	}

	return (sum/2);
}

int main()
{
	cout<<" 477. Total Hamming Distance "<<endl;

	// example 1
	// vector<int> nums = {2,14,4};

	// example 2
	vector<int> nums = {4,4,14};

	cout<<" printing the nums vector :- "<<endl;
	for (int i=0;i<nums.size();i++)
		cout<<nums[i]<<" ";
	cout<<endl;

	int answer = totalHammingDistance(nums);

	cout<<" answer = "<<answer<<endl;
}