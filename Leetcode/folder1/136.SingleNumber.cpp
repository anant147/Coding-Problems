#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<stack>
#include<queue>
#include<cmath>
using namespace std;

int singleNumber(vector<int>& nums)
{
	int i,j,k,u,v,x,y,z;

	int val = 0;

	vector<vector<int>> nbitstor;

	vector<int> vtemp;
	vtemp.resize(32,0);

	int cond = 0;

	for (i=0;i<nums.size();i++)
	{
		vector<int> temp;
		temp.resize(32,0);

		j=0;
		k = nums[i];

		if (k<0)
			k = k*(-1);

		while(j<32 && k!=0)
		{
			temp[j] = k%2;
			j++;
			k = k/2;
		}

		if (nums[i]<0)
		{
			cond = 0;
			j=0;

			while(j<32)
			{
				if (cond==0)
				{
					if (temp[j]==1)
						cond=1;
				}
				else
				{
					if (temp[j]==0)
						temp[j]=1;
					else
						temp[j]=0;
				}
				j++;
			}

		}

		nbitstor.push_back(temp);
		temp.clear();
	}

	// cout<<" printing the nbitstor vector :- "<<endl;
	for (i=0;i<nbitstor.size();i++)
	{
		for (j=0;j<nbitstor[i].size();j++)
		{
			// cout<<nbitstor[i][j]<<" ";
			if (nbitstor[i][j]==vtemp[j])
				vtemp[j]=0;
			else
				vtemp[j]=1;
		}
		// cout<<endl;
	}
	// cout<<endl;

	// cout<<"printing the vtemp vector :-"<<endl;
	for (j=0;j<31;j++)
	{
		// cout<<vtemp[j]<<" ";
		if (vtemp[j]==0)
			u=0;
		else
			u = pow(2,j);

		val = val + u;
	}
	// cout<<endl;

	if (vtemp[31]==0)
		return val;
	else
	{
		v = ((-1)*pow(2,31))+val;
		return v;
	}
}

int main()
{
	cout<<" 136. Single Number "<<endl;

	// example 1
	// vector<int> nums = {2,2,1};

	// example 2
	// vector<int> nums = {4,1,2,1,2};

	// example 3
	vector<int> nums = {-1,-1,-2};

	cout<<" printing the nums vector :- "<<endl;
	for (int i=0;i<nums.size();i++)
		cout<<nums[i]<<" ";
	cout<<endl;

	int answer = singleNumber(nums);

	cout<<" answer = "<<answer<<endl;
}