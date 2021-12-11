#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
using namespace std;

bool sortVector(const vector<int>& v1, const vector<int>& v2)
{
	if (v1[0]<v2[0])
		return true;
	else if (v1[0]==v2[0])
	{
		if (v1[1]<=v2[1])
			return true;
		else
			return false;
	}
	else
		return false;
}

vector<int> makeSegtree(vector<vector<int>>& rangeStor, vector<int>& segtree, vector<int>& nums, int st, int ed, int lower, int upper, int pos)
{
	if (st==ed)
	{
		segtree[pos]=nums[st];

		int k = segtree[pos];
		rangeStor.push_back({st,ed,k});

		if (lower<=k && k<=upper)
			return {k,1};
		else
			return {k,0};
	}

	int mid = st + ((ed-st)/2);

	vector<int> temp1 = makeSegtree(rangeStor, segtree, nums,  st, mid, lower, upper, 2*pos+1);
	vector<int> temp2 = makeSegtree(rangeStor, segtree, nums,  mid+1, ed, lower, upper, 2*pos+2);

	int u = temp1[0] + temp2[0];
	int v = temp1[1] + temp2[1];

	segtree[pos] = u;
	rangeStor.push_back({st,ed,u});

	if (lower<=u && u<=upper)
		return {u,1+v};
	else
		return {u,v};
}

int countRangeSum(vector<int>& nums,int lower,int upper)
{
	int i,j,k,u,v,x,y,z;

	vector<int> segtree;

	int n = nums.size();
	int nceil = ceil(log2(n));
	int ssz = 2*(int)(pow(2,nceil))-1;

	int minval = (-1)*pow(2,sizeof(int)*8-1);

	segtree.resize(ssz,minval);

	vector<vector<int>> rangeStor;

	vector<int> val = makeSegtree(rangeStor, segtree, nums, 0, n-1, lower, upper, 0);

	// cout<<" value of val vector :-"<<endl;
	// cout<<val[0]<<" "<<val[1]<<endl;

	sort(rangeStor.begin(),rangeStor.end(),sortVector);

	vector<vector<int>> matStor,validator;
	matStor.resize(n, vector<int> (n,0));
	validator.resize(n, vector<int> (n,0));

	// cout<<endl;
	// cout<<" printing the value of rangeStor vector :- "<<endl;
	for (i=0;i<rangeStor.size();i++)
	{
		u = rangeStor[i][0];
		v = rangeStor[i][1];
		x = rangeStor[i][2];
		// cout<<u<<" , "<<v<<" , "<<x<<endl;

		matStor[u][v]=x;
		validator[u][v]=1;
	}
	// cout<<endl;

	// cout<<" printing the matStor vector :- "<<endl;
	// for (i=0;i<n;i++)
	// {
	// 	for (j=0;j<n;j++)
	// 		cout<<matStor[i][j]<<" ";
	// 	cout<<endl;
	// }
	// cout<<endl;

	// cout<<" printing the validator vector :- "<<endl;
	// for (i=0;i<n;i++)
	// {
	// 	for (j=0;j<n;j++)
	// 		cout<<validator[i][j]<<" ";
	// 	cout<<endl;
	// }
	// cout<<endl;

	int count = 0;
	int len;

	for (len=1;len<=n;len++)
	{
		if (len==1)
		{
			for (i=0;i<n;i++)
			{
				k = matStor[i][i];
				if (lower<=k && k<=upper)
					count++;
			}
		}
		else if (len==n)
		{
			k = matStor[0][n-1];

			if (lower<=k && k<=upper)
				count++;
		}
		else
		{
			for (i=0;i<(n-len+1);i++)
			{
				j=i+len-1;

				if (validator[i][j]==0)
				{
					u = matStor[i][j-1] + matStor[i+1][j] - matStor[i+1][j-1];
					matStor[i][j]=u;
					validator[i][j]=1;
				}

				k = matStor[i][j];

				if (lower<=k && k<=upper)
					count++;
			}
		}
	}

	// cout<<" printing the matStor vector :- "<<endl;
	// for (i=0;i<n;i++)
	// {
	// 	for (j=0;j<n;j++)
	// 		cout<<matStor[i][j]<<" ";
	// 	cout<<endl;
	// }
	// cout<<endl;

	// cout<<" printing the validator vector :- "<<endl;
	// for (i=0;i<n;i++)
	// {
	// 	for (j=0;j<n;j++)
	// 		cout<<validator[i][j]<<" ";
	// 	cout<<endl;
	// }
	// cout<<endl;

	return count;
}

int main()
{
	cout<<" 327. Count of Range Sum "<<endl;

	int i,j,k;
	vector<int> nums = {-2,5,-1};
	int lower = -2;
	int upper = 2;

	cout<<" printing the nums vector :- "<<endl;
	for (i=0;i<nums.size();i++)
		cout<<nums[i]<<" ";
	cout<<endl;

	cout<<" lower = "<<lower<<endl;
	cout<<" upper = "<<upper<<endl;

	int answer = countRangeSum(nums,lower,upper);
	cout<<" answer = "<<answer<<endl;
}