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

void getArtPoint(vector<int> graph[], int u, int n, vector<bool>& visited, vector<int>& parent, vector<int>& disc, vector<int>& low, vector<bool>& artpoint)
{
	static int time = 0;

	int children = 0;

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
			children++;
			parent[v] = u;
			getArtPoint(graph, v, n, visited, parent, disc, low, artpoint);

			low[u] = minval(low[u], low[v]);

			if (parent[u] == -1 && children > 1)
				artpoint[u] = true;

			if (parent[u] != -1 && low[v] >= disc[u])
				artpoint[u] = true;

		}
		else if (v != parent[u])
		{
			low[u] = minval(low[u], disc[v]);
		}
	} 
}

void printArtPoint(int n, vector<vector<int>>& edges)
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
	parent.resize(n,-1);
	disc.resize(n,-1);
	low.resize(n,-1);

	vector<bool> visited, artpoint;
	visited.resize(n, false);
	artpoint.resize(n, false);

	for (i=0;i<n;i++)
	{
		if (visited[i] == false)
			getArtPoint(graph, i, n, visited, parent, disc, low, artpoint);
	}

	cout<<" print the Articulation points of the given graph :- "<<endl;
	for (i=0;i<n;i++)
	{
		if (artpoint[i] == true)
			cout<<i<<" ";
	}
	cout<<endl;
}

int main()
{
	cout<<" tp 11. Articulation Points "<<endl;

	// example 1
	// int n = 5;
	// vector<vector<int>> edges = {
	// 	                        {1,0},
	// 	                        {0,2},
	// 	                        {2,1},
	// 	                        {0,3},
	// 	                        {3,4}
	// 	                        };

	// example 2
    // int n = 4;
    // vector<vector<int>> edges = {
    // 	                        {0,1},
    // 	                        {1,2},
    // 	                        {2,3}
    // 	                        };

    // example 3
    int n = 7;
    vector<vector<int>> edges = {
    	                        {0,1},
    	                        {1,2},
    	                        {2,0},
    	                        {1,3},
    	                        {1,4},
    	                        {1,6},
    	                        {3,5},
    	                        {4,5}
    	                        };

    cout<<" n (vertices) = "<<n<<endl;
    cout<<" printing the edges vector :- "<<endl;
    for (int i=0;i<edges.size();i++)
    {
    	cout<<edges[i][0]<<" "<<edges[i][1]<<endl;
    }
    cout<<endl;

    printArtPoint(n, edges);

}