#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
#include<cmath>
#include<stack>
using namespace std;

typedef pair<double,pair<int,int>> reqpr;

vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
{
	int i,j,u,v,x,y,z;

	if (points.size()==0 || k==0)
		return {};

	if (points.size()==k)
		return points;

	double val1,val2;

	priority_queue<reqpr, vector<reqpr>, greater<reqpr> > pq;

	for (i=0;i<points.size();i++)
	{
		u = points[i][0]; v = points[i][1];
		val1 = sqrt((u*u) + (v*v));
		pq.push(make_pair(val1, make_pair(u,v)));
	}

	int count = 0;
	vector<vector<int>> result;

	reqpr rtemp;
	vector<int> temp;

	while (!pq.empty() && count!=k)
	{
		rtemp = pq.top();
		u = rtemp.second.first;  v = rtemp.second.second;
		pq.pop();

		temp = {u,v};
		result.push_back(temp);
		temp.clear();
		count++;
	}

	return result;
}

int main()
{
	cout<<" 973. K Closest Points to Origin "<<endl;

	// example 1
	// vector<vector<int>> points = {{1,3},{2,-2}};
	// int k = 1;

	// example 2
	vector<vector<int>> points = {{5,-1},{3,3},{-2,4}};
	int k = 2;

	cout<<" printing the points vector :- "<<endl;

	for (int i=0;i<points.size();i++)
		cout<<points[i][0]<<" , "<<points[i][1]<<endl;
	cout<<endl;

	cout<<" k = "<<k<<endl;

	vector<vector<int>> answer = kClosest(points, k);

	for (int i=0;i<answer.size();i++)
		cout<<answer[i][0]<<" , "<<answer[i][1]<<endl;
	cout<<endl;

}