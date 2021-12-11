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

int maxval(int a, int b)
{
	if (a<b)
		return b;
	else
		return a;
}

int binSearch(vector<int>& difficulty, int val)
{
	int n = difficulty.size();

	int low = 0;
	int high = n-1;

	if (val < difficulty[low])
		return -1;

	if (difficulty[high] < val)
		return high;

	while (low <= high)
	{
		int mid = low + (high-low)/2;

		if (difficulty[mid] == val)
		{
			while (mid<n && difficulty[mid]==val)
				mid++;

			return (mid-1);
		}
		else if (difficulty[mid] < val)
		{
			if ((mid+1)<n && (difficulty[mid+1] > val) )
				return mid;
			else
				low = mid+1;
		}
		else if (difficulty[mid] > val)
		{
			high = mid-1;
		}
	}

	return -1;
}

int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker)
{
	int i,j,k,u,v,x,y,z;

	int n = difficulty.size();

	vector<pair<int,int>> vtemp;

	for (i=0;i<difficulty.size();i++)
	{
		vtemp.push_back(make_pair( difficulty[i], profit[i]));
	}

	sort(vtemp.begin(), vtemp.end());

	for (i=0;i<difficulty.size();i++)
	{
		u = vtemp[i].first;
		v = vtemp[i].second;

		difficulty[i] = u;
		profit[i] = v;
	}

	vector<int> maxpt;
	maxpt.resize(n,0);

	maxpt[0] = profit[0];

	for (i=1;i<n;i++)
	{
		maxpt[i] = maxval(maxpt[i-1], profit[i]);
	}

	int sum = 0;

	for (i=0;i<worker.size();i++)
	{
		int index = binSearch(difficulty, worker[i]);

		if (index != -1)
			sum = sum + maxpt[index];
	}

	return sum;
}

int main()
{
	cout<<" 826. Most Profit Assigning Work "<<endl;

	vector<int> difficulty = {2,4,6,8,10};
	vector<int> profit = {10,20,30,40,50};
	vector<int> worker = {4,5,6,7};

	int i;
	cout<<" printing the difficulty vector :- "<<endl;
	for (i=0;i<difficulty.size();i++)
		cout<<difficulty[i]<<" ";
	cout<<endl;

	cout<<" printing the profit vector :- "<<endl;
	for (i=0;i<profit.size();i++)
		cout<<profit[i]<<" ";
	cout<<endl;

	cout<<" printing the worker vector :- "<<endl;
	for (i=0;i<worker.size();i++)
		cout<<worker[i]<<" ";
	cout<<endl;

	int answer = maxProfitAssignment(difficulty, profit, worker);

	cout<<" answer = "<<answer<<endl;
}