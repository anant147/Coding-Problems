#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
using namespace std;

int singleNumber(vector<int>& nums)
{
	int i,j,k,u,v,x,y,z;

	vector<vector<int>> mbitstor;

	vector<int> vtemp;
	vtemp.resize(32,0);

	int minval = pow(2,sizeof(int)*8-1)*(-1);

	int cond = 0;

	for (i=0;i<nums.size();i++)
	{
		k = nums[i];
		vector<int> temp;
		temp.resize(32,0);

		if (k==minval)
			temp[31]=1;
		else
		{
			if (k<0)
				k = k*(-1);

			j=0;

			while(j<32 && k!=0)
			{
				temp[j] = k%2;
				j++;
				k=k/2;
			}

			if (nums[i]<0)
			{
				cond = 0;
				j = 0;

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
	    }

		for (j=0;j<temp.size();j++)
			vtemp[j] = vtemp[j] + temp[j];

		mbitstor.push_back(temp);

		temp.clear();
	}

	cout<<" printing the mbitstor vector :- "<<endl;
	for (i=0;i<mbitstor.size();i++)
	{
		cout<<" no. = "<<nums[i]<<endl;
		for (j=0;j<mbitstor[i].size();j++)
			cout<<mbitstor[i][j]<<" ";
		cout<<endl;
		cout<<endl;
	}
	cout<<endl;

	for (j=0;j<vtemp.size();j++)
		vtemp[j] = (vtemp[j]%3);

	int val = 0;

	for (i=0;i<31;i++)
	{
		if (vtemp[i]==1)
		{
			val = val + pow(2,i);
		}
	}

	if (vtemp[31]==0)
		return val;
	else
	{
		v = (-1)*pow(2,31)+val;
		return v;
	}

}

int main()
{
	cout<<" 137. Single Number II "<<endl;

	// example 1
	// vector<int> nums = {2,2,3,2};

	// example 2
	// vector<int> nums = {0,1,0,1,0,1,99};

	// example 3
	vector<int> nums = {-2,-2,1,1,-3,1,-3,-3,-4,-2};

	cout<<" printing the nums vector :- "<<endl;

	for (int i=0;i<nums.size();i++)
	   cout<<nums[i]<<" ";
	cout<<endl;

	int answer = singleNumber(nums);

	cout<<" answer = "<<answer<<endl;
}