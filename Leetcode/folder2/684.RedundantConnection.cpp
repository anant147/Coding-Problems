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

int findGrp(vector<vector<int>>& vstor, int x)
{
	if (vstor[x][0] != x)
		vstor[x][0] = findGrp(vstor, vstor[x][0]);

	return vstor[x][0];
}

void unionGrp(vector<vector<int>>& vstor, int x, int y)
{
	int px = findGrp(vstor, x);
	int py = findGrp(vstor, y);

	if (vstor[px][1] < vstor[py][1])
		vstor[px][0] = py;
	else if (vstor[px][1] > vstor[py][1])
		vstor[py][0] = px;
	else
	{
		vstor[py][0] = px;
		vstor[px][1]++;
	}
}

vector<int> findRedundantConnection(vector<vector<int>>& edges)
{
	int i,j,k,u,v,x,y,z;

	int n = edges.size();

	vector<vector<int>> vstor;
	vstor.resize(n+1, vector<int>(2,0));

	vstor[0][0] = -1; vstor[0][1] = -1;

	for (i=1;i<=n;i++)
		vstor[i][0] = i;

	vector<int> result;

	for (i=0;i<n;i++)
	{
		u = edges[i][0]; v = edges[i][1];

		x = findGrp(vstor,u);
		y = findGrp(vstor,v);

		if (x != y)
		{
			unionGrp(vstor,u,v);
		}
		else
		{
			result.push_back(u);
			result.push_back(v);

			break;
		}
	}

	return result;
}

int main()
{
	cout<<" 684. Redundant Connection  "<<endl;

	// example 1
	// vector<vector<int>> edges = {
	// 	                        {1,2},
	// 	                        {1,3},
	// 	                        {2,3}
	// 	                        };

	// example 2
    vector<vector<int>> edges = {
    	                        {1,2}, 
    	                        {2,3}, 
    	                        {3,4}, 
    	                        {1,4}, 
    	                        {1,5}
    	                        };

	cout<<" printing the edges vector :- "<<endl;

	for (int i=0;i<edges.size();i++)
		cout<<edges[i][0]<<" , "<<edges[i][1]<<endl;
	cout<<endl;

	vector<int> answer = findRedundantConnection(edges);

	cout<<" printing the answer vector :- "<<endl;

	for (int i=0;i<answer.size();i++)
		cout<<answer[i]<<" ";
	cout<<endl;
}