#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
using namespace std;

void heapify(vector<vector<int>>& adifval,int point, int sz)
{
	int left = 2*point+1;
	int right = 2*point+2;

	if (left>=sz && right>=sz)
		return;

	int index = point;

	if (adifval[point][0]>adifval[left][0])
		index = left;

	if (right<sz && (adifval[index][0] > adifval[right][0]) )
		index = right;

	if (index != point)
	{
		vector<int> temp = adifval[index];
		adifval[index] = adifval[point];
		adifval[point] = temp;

		heapify(adifval, index, sz);
	}
}

vector<int> getMinimum(vector<vector<int>>& adifval)
{
	int sz = adifval.size();
	vector<int> temp1,temp2;

	if (sz==1)
	{
		temp1 = adifval[0]; adifval.pop_back();  return temp1;
	}

	temp1 = adifval[0];
	temp2 = adifval[sz-1];

	adifval[0] = temp2;
	adifval.pop_back();

	sz=sz-1;

	heapify(adifval,0,sz);
	return temp1;
}

void insertElement(vector<vector<int>>& adifval, vector<int>& temp)
{
	vector<int> temp1,temp2;

	int sz = adifval.size();
	if (sz==0)
	{
		adifval.push_back(temp); return;
	}

	adifval.push_back(temp);
	sz =sz+1;

	int rt = sz-1;
	int parent = (rt-1)/2;

	while(parent>=0 && (adifval[parent][0]>adifval[rt][0]))
	{
		temp1 = adifval[parent];
		adifval[parent] = adifval[rt];
		adifval[rt] = temp1;

		rt = parent;
		parent = (rt-1)/2;
	}
}

int smallestDistancePair(vector<int>& nums,int k)
{
	int i,j,u,v,x,y,z;

	int n = nums.size();

	int arr1[1000005];
	int abdif[1000005];

	for (i=0;i<1000005;i++)
	{
		arr1[i] = 0; abdif[i] = 0;
	}

	vector<vector<int>> elmval, adifval;

	sort(nums.begin(), nums.end());

	// cout<<"printing the nums :"<<endl;
	// for (i=0;i<nums.size();i++)
	// 	cout<<nums[i]<<" ";
	// cout<<endl;

	int count,val1,val2;

	for (i=0;i<n;)
	{
		j=i;
		u = nums[i];
		count=0;

		while(j<n && nums[j]==u)
		{
			count++; j++;
		}

		elmval.push_back({u,count});
		i=j;
	}

	// cout<<" elmval vector"<<elmval.size()<<endl;
	for (i=0;i<elmval.size();i++)
	{
		u = elmval[i][0]; v = elmval[i][1];
		// cout<<" u = "<<u<<", v =  "<<v<<endl;

		if (v>1)
		{
			z = (v*(v-1))/2;
			abdif[0]=abdif[0]+z;
		}

		for (j=i+1;j<elmval.size();j++)
		{ 
			x = elmval[j][0]; y = elmval[j][1];
			val1 = x-u;

			if (val1<0)
				val1 = (-1)*val1;

			abdif[val1] = abdif[val1]+(v*y);
		}
	}

	vector<int> temp;

	// cout<<" count of each type of diff val. "<<endl;
	for (i=0;i<1000005;i++)
	{
		if (abdif[i]!=0)
		{
			// cout<<" i = "<<i<<" , count = "<<abdif[i]<<endl;
			temp = {i,abdif[i]};
			insertElement(adifval,temp);
		}
	}

	count = k;


	while(count>0)
	{
		temp = getMinimum(adifval);
		val1 = temp[0];
		u = temp[1];
		// cout<<" val1 = "<<val1<<" , u = "<<u<<endl;
		count=count-u;
	}

	return val1;
}

int main()
{
	cout<<" 719. Find K-th Smallest Pair Distance "<<endl;

	// example1 
	// vector<int> nums = {1,3,1};
	// int k = 1;

	// // example 2
	vector<int> nums ={9,10,7,10,6,1,5,4,9,8};
	int k = 18;

	cout<<" printing the nums vector :- "<<endl;
	for (int i=0;i<nums.size();i++)
		cout<<nums[i]<<" ";
	cout<<endl;

	cout<<" k = "<<k<<endl;

	int answer = smallestDistancePair(nums,k);
	cout<<" answer = "<<answer<<endl;

}