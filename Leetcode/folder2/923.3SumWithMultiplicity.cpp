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

int threeSumMulti(vector<int>& nums, int target)
{
    long long int i,j,k,u,v,x,y,z;

	long long int mod = pow(10,9)+7;

	vector<long long int> ctr;
	ctr.resize(105,0);

	for (i=0;i<nums.size();i++)
	{
		k = nums[i];
		ctr[k]++;
	}

	long long int count = 0;

	if (target%3==0)
	{
		k = target/3;

		if (ctr[k]>=3)
		{
			u = ctr[k];
			v = (u*(u-1)*(u-2))/6;
			count = (count+v)%mod;
		}
	}

	vector<long long int> val;

	for (i=0;i<=100;i++)
	{
		if (ctr[i]>0)
			val.push_back(i);

		j = target - 2*i;

		if (j>=0 && j<=100 && j!=i && ctr[i]>=2 && ctr[j]>=1)
		{
			u = ctr[i];
			v = ctr[j];
			x = (u*(u-1)/2);
			y = (x*v)%mod;
			count = (count + y)%mod;
		}
	}

	long long int n = val.size();

	cout<<" printing the val vector :- "<<endl;
	for (i=0;i<val.size();i++)
		cout<<val[i]<<" ";
	cout<<endl;

	if (n>=3)
	{
		for (i=0;i<n-1;i++)
		{
			for (j=i+1;j<n;j++)
			{
				x = target - val[i] - val[j];

				cout<<" val1 = "<<val[i]<<" , val2 = "<<val[j]<<", x = "<<x<<endl;

				if (x > val[i] && x > val[j])
				{
					if (x<=100 && ctr[x]>0)
					{
						u = (ctr[x] * ctr[val[i]] * ctr[val[j]] )%mod;
						count = (count + u)%mod;
					}
				}
				else
					break;
			}
		}
	}

	return (int)(count);
}

int main()
{
	cout<<" 923. 3Sum With Multiplicity "<<endl;

	// example 1
	// vector<int> nums = {1,1,2,2,3,3,4,4,5,5};
	// int target = 8;

	// example 2
	// vector<int> nums = {1,1,2,2,2,2};
	// int target = 5;

	// example 3
	vector<int> nums = {95,93,46,2,29,41,28,74,9,10};
	int target = 196;

	cout<<" printing the nums vector :- "<<endl;
	for (int i=0;i<nums.size();i++)
		cout<<nums[i]<<" ";
	cout<<endl;

	cout<<" target = "<<target<<endl;

	int answer = threeSumMulti(nums, target);

	cout<<" answer = "<<answer<<endl;
}