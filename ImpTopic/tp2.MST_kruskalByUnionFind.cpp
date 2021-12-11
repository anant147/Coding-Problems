#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
#include<cstring>
using namespace std;

int findGrp(vector<vector<int>>& subset, int x)
{
	if (subset[x][0] != x)
		subset[x][0] = findGrp(subset, subset[x][0]);

	return subset[x][0];
}

void unionGrp(vector<vector<int>>& subset, int x, int y)
{
	int px = findGrp(subset, x);
	int py = findGrp(subset, y);

	if (subset[px][1] < subset[py][1])
	{
		subset[px][0] = py;
	}
	else if (subset[px][1] > subset[py][1])
	{
		subset[py][0] = px;
	}
	else
	{
		subset[py][0] = px;
		subset[px][1]++;
	}
}

void mstKruskal(int n, vector<vector<int>>& edges)
{
	int i,j,k,u,v,x,y,z;

	priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

	pair<int, pair<int,int>> ptemp;

	for (i=0;i<edges.size();i++)
	{
		x = edges[i][0] ; y = edges[i][1] ;  z = edges[i][2];
		pq.push(make_pair(z, make_pair(x,y)));
	}

	vector<vector<int>> subset;
	subset.resize(n, vector<int> (2,0));

	for (i=0;i<n;i++)
		subset[i][0] = i;

	vector<vector<int>> result;
	vector<int> vtemp;

	int rsum = 0;
	int count = 0;

	int px,py;

	while (count<(n-1) && !pq.empty())
	{
		ptemp = pq.top();
		pq.pop();

		u = ptemp.first;
		x = ptemp.second.first;
		y = ptemp.second.second;

		px = findGrp(subset,x);
		py = findGrp(subset,y);

		if (px != py)
		{
			count++;

			vtemp.push_back(x);  vtemp.push_back(y); vtemp.push_back(u);
			result.push_back(vtemp);
			vtemp.clear();

			rsum = rsum + u;
			unionGrp(subset, x, y);
		}
	}

	cout<<" printing the edges of the Minimum spanning tree :-"<<endl;
	for (i=0;i<result.size();i++)
		cout<<result[i][0]<<" , "<<result[i][1]<<" , "<<result[i][2]<<endl;
	cout<<endl;

	cout<<" cost of mst = "<<rsum<<endl;
}

int main()
{
	cout<<" tp2. Minimum spanning tree by Kruskal algorithm using using union find method :- "<<endl;

	// example 1
	// int n = 4;
	// int e = 5;

	// vector<vector<int>> edges = {
	// 	                        {0,1,10},
	// 	                        {0,2,6},
	// 	                        {1,3,15},
	// 	                        {2,3,4},
	// 	                        {0,3,5}
	// 	                        };

	// example 2
	int n = 9;
	int e = 14;

	vector<vector<int>> edges = {
		                        {7,6,1},
		                        {8,2,2},
		                        {6,5,2},
		                        {0,1,4},
		                        {2,5,4},
		                        {8,6,6},
		                        {2,3,7},
		                        {7,8,7},
		                        {0,7,8},
		                        {1,2,8},
		                        {3,4,9},
		                        {5,4,10},
		                        {1,7,11},
		                        {3,5,14}
		                        };

	cout<<" n = "<<n<<endl;
	cout<<" e = "<<e<<endl;

	for (int i=0;i<edges.size();i++)
		cout<<edges[i][0]<<" , "<<edges[i][1]<<" , "<<edges[i][2]<<endl;
	cout<<endl;

	mstKruskal(n,edges);
}