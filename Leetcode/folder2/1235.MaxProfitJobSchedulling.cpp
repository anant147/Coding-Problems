#include <bits/stdc++.h> 
using namespace std;

static bool compare(const vector<int>& v1, const vector<int>& v2)
{
	if (v1[1] < v2[1])
		return true;
	else if (v1[1] == v2[1])
	{
		if (v1[2] > v2[1])
			return true;
		else
			return false;
	}
	else
		return false;
}

int maxval(int a, int b)
{
	if (a>b)
		return a;
	else
		return b;
}

int lastNonConflict(vector<vector<int>>& job, int n)
{
	int i;

	for (i=n-1;i>=0;i--)
	{
		if (job[i][1] <= job[n][0])
			return i;
	}

	return -1;
}

int jobScheduling( vector<int>& startTime, vector<int>& endTime, vector<int>& profit)
{
	int i,j,k,u,v,x,y,z;

	int n = startTime.size();

	vector<int> temp;
	vector<vector<int>> job;

	for (i=0;i<n;i++)
	{
		k = startTime[i]; u = endTime[i]; v = profit[i];
		temp.push_back(k);
		temp.push_back(u);
		temp.push_back(v);

		job.push_back(temp);

		temp.clear();
	}

	// cout<<" hello1 "<<endl;

	sort(job.begin(), job.end(), compare);

	// cout<<" hello2"<<endl;

	vector<int> table;
	table.resize(n,0);

	table[0] = job[0][2];

	for (i=1;i<n;i++)
	{
		int inclProf = job[i][2];
		int l = lastNonConflict(job,i);

		if (l != -1)
			inclProf += table[l];

		table[i] = maxval(inclProf, table[i-1]);
	}

	return table[n-1];
}

int main()
{
	cout<<" JPMC question "<<endl;
	cout<<" 1235. Maximum Profit in Job Scheduling "<<endl;

	// example 1
	// vector<int> startTime = {1,2,3,3};
	// vector<int> endTime = {3,4,5,6};
	// vector<int> profit = {50,10,40,70};

	// example2
	// vector<int> startTime = {1,2,3,4,6};
	// vector<int> endTime = {3,5,10,6,9};
	// vector<int> profit = {20,20,100,70,60};

	// example3
	vector<int> startTime = {1,1,1};
	vector<int> endTime = {2,3,4};
	vector<int> profit = {5,6,4};

	cout<<" printing the startTime vector :- "<<endl;
	for (int i=0;i<startTime.size();i++)
		cout<<startTime[i]<<" ";
	cout<<endl;
	cout<<endl;

	cout<<" printing the endTime vector :- "<<endl;
	for (int i=0;i<endTime.size();i++)
		cout<<endTime[i]<<" ";
	cout<<endl;
	cout<<endl;

	cout<<" printing the profit vector :- "<<endl;
	for (int i=0;i<profit.size();i++)
		cout<<profit[i]<<" ";
	cout<<endl;
	cout<<endl;

	int answer = jobScheduling(startTime, endTime, profit);

	cout<<" answer = "<<answer<<endl;
}