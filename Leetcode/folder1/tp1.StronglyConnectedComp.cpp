#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
#include<cstring>
using namespace std;

void dfs(vector<int> graph[], vector<int>& visited, stack<int>& st, int point, int n)
{
	visited[point]=1;
	int i,u;

	for (i=0;i<graph[point].size();i++)
	{
		u = graph[point][i];

		if (visited[u]==0)
			dfs(graph, visited, st, u, n);
	}

	st.push(point);
}

void dfsRevg(vector<int> revg[], vector<int>& visited, int point, int n)
{
	visited[point]=1;
	cout<<point<<" ";

	int i,v;

	for (i=0;i<revg[point].size();i++)
	{
		v = revg[point][i];

		if (visited[v]==0)
			dfsRevg(revg, visited, v, n);
	}
}

void getStronglyConnectedComp(int n, vector<vector<int>>& edges)
{
	int i,j,k,u,v,x,y,z;

	vector<int> visited;
	visited.resize(n,0);

	stack<int> st;

	vector<int> graph[n];
	vector<int> revg[n];

	for (i=0;i<edges.size();i++)
	{
		u = edges[i][0]; v = edges[i][1];

		graph[u].push_back(v);
		revg[v].push_back(u);
	}

	cout<<" printing the graph vector :- "<<endl;
	for (i=0;i<n;i++)
	{
		cout<<" i = "<<i<<endl;
		for (j=0;j<graph[i].size();j++)
			cout<<graph[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;

	cout<<" printing the revg vector :- "<<endl;
	for (i=0;i<n;i++)
	{
		cout<<" i = "<<i<<endl;
		for (j=0;j<revg[i].size();j++)
			cout<<revg[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;

	for (i=0;i<n;i++)
	{
		if (visited[i]==0)
			dfs(graph, visited, st, i, n);
	}

	for (i=0;i<n;i++)
		visited[i]=0;

	int count = 0;

	while (!st.empty())
	{
		u = st.top();
		st.pop();

		if (visited[u]==0)
		{
			cout<<" printing element of comp no. = "<<count<<endl;

			dfsRevg(revg, visited, u, n);
			cout<<endl;
			count++;
		}
	}

	cout<<endl;
	cout<<" total no. of strongly connected comp = "<<count<<endl;
	cout<<endl;
}

int main()
{
	cout<<" Strongly connected components "<<endl;

	// int n = 5;
	// vector<vector<int>> edges = {
	// 	                        {1,0},
	// 	                        {0,2},
	// 	                        {2,1},
	// 	                        {0,3},
	// 	                        {3,4}
	// 	                        };

	// int n = 6;
	// vector<vector<int>> edges = {
	// 	                        {0,1},
	// 	                        {1,2},
	// 	                        {2,0},
	// 	                        {2,3},
	// 	                        {3,4},
	// 	                        {4,5},
	// 	                        {5,3}
	// 	                        };

	int n = 6;
	vector<vector<int>> edges = {
		                        {0,1},
		                        {1,2},
		                        {2,0},
		                        {2,3},
		                        {3,4},
		                        {4,5},
		                        {5,3},
		                        {1,5},
		                        {5,1}
		                        };

	cout<<" vectices n = "<<n<<endl;
	cout<<" printing the edges vector :- "<<endl;
	for (int i=0;i<edges.size();i++)
		cout<<edges[i][0]<<" , "<<edges[i][1]<<endl;
	cout<<endl;

	getStronglyConnectedComp(n,edges);
}