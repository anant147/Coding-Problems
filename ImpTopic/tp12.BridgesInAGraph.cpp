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

int minval(int a, int b)
{
	if (a<b)
		return a;
	else
		return b;
}

void getBridge(vector<int> graph[], int u, int n, vector<pair<int,int>>& bridges, vector<bool>& visited, vector<int>& parent, vector<int>& disc, vector<int>& low)
{
	static int time = 0;

	visited[u] = true;

	disc[u] = time;
	low[u] = time;
	time++;

	int i,j,k,v,x,y,z;

	for (i=0;i<graph[u].size();i++)
	{
		v = graph[u][i];

		if (visited[v] == false)
		{
			parent[v] = u;
			getBridge(graph, v, n, bridges, visited, parent, disc, low);

			low[u] = minval(low[u], low[v]);

			if (low[v] > disc[u])
			{
				bridges.push_back(make_pair(u,v));
			}
		}
		else if (parent[u] !=  v)
		{
			low[u] = minval(low[u], disc[v]);
		}
	}
}

void printBridges(int n, vector<vector<int>>& edges)
{
	int i,j,k,u,v,x,y,z;

	vector<int> graph[n];

	for (i=0;i<edges.size();i++)
	{
		u = edges[i][0]; v = edges[i][1];

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	vector<int> parent, disc, low;
	parent.resize(n, -1);
	disc.resize(n, -1);
	low.resize(n, -1);

	vector<bool> visited;
	visited.resize(n, false);

	vector<pair<int,int>> bridges;

	for (i=0;i<n;i++)
	{
		if (visited[i] == false)
			getBridge(graph, i, n, bridges, visited, parent, disc, low);
	}

	cout<<" printing the bridges in the graph :- "<<endl;

	if (bridges.size()==0)
		cout<<" NO bridges are present in this graph "<<endl;
	else
	{
		for (i=0;i<bridges.size();i++)
			cout<<bridges[i].first<<" , "<<bridges[i].second<<endl;
		cout<<endl;
    }
}

int main()
{
	cout<<" tp 12. Bridges in a Graph ."<<endl;

	// example 1
	int n = 5;
	vector<vector<int>> edges = {
		                        {1,0},
		                        {0,2},
		                        {2,1},
		                        {0,3},
		                        {3,4}
		                        };

	// example 2
    // int n = 4;
    // vector<vector<int>> edges = {
    // 	                        {0,1},
    // 	                        {1,2},
    // 	                        {2,3}
    // 	                        };

    // example 3
    // int n = 7;
    // vector<vector<int>> edges = {
    // 	                        {0,1},
    // 	                        {1,2},
    // 	                        {2,0},
    // 	                        {1,3},
    // 	                        {1,4},
    // 	                        {1,6},
    // 	                        {3,5},
    // 	                        {4,5}
    // 	                        };

    // example 4
    // int n = 4;
    // vector<vector<int>> edges = {
    // 	                        {0,1},
    // 	                        {1,2},
    // 	                        {2,3},
    // 	                        {0,3}
    // 	                        };

    cout<<" n (vertices) = "<<n<<endl;
    cout<<" printing the edges vector :- "<<endl;
    for (int i=0;i<edges.size();i++)
    {
    	cout<<edges[i][0]<<" "<<edges[i][1]<<endl;
    }
    cout<<endl;

    printBridges(n, edges);
}