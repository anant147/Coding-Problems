#include<bits/stdc++.h>
using namespace std;

void addEdge( vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
}

void dfs(int node, vector<int> adj[], vector<int>& dp, vector<bool>& visited, int n)
{
	visited[node] = true;

	for (int i=0;i<adj[node].size();i++)
	{
		if (!visited[adj[node][i]])
			dfs(adj[node][i], adj, dp, visited, n);

		dp[node] = max( dp[node], 1+ dp[adj[node][i]]);
	}
}

int findLongestPath( vector<int> adj[], int n)
{
	vector<int> dp;
	dp.resize(n, 0);

	vector<bool> visited;
	visited.resize(n, false);

	for (int i=1;i<n;i++)
	{
		if (!visited[i])
			dfs(i, adj, dp, visited, n);
	}

	int answer = 0;

	cout<<" printing the max path for each node of graph :- "<<endl;
	for (int i=1;i<n;i++)
	{
		cout<<" for i = "<<i<<" , len = "<<dp[i]<<endl;

		answer = max( answer, dp[i]);
	}
	cout<<endl;

	return answer;
}

int main()
{
	cout<<"  Morgan Stanley 4 question :- "<<endl;
	cout<<" Longest path in a directed Acyclic graph :- "<<endl;
	cout<<endl;

	int n = 5;
	vector<int> adj[n+1];

	addEdge(adj, 1, 2);
	addEdge(adj, 1, 3);
	addEdge(adj, 3, 2);
	addEdge(adj, 2, 4);
	addEdge(adj, 3, 4);

	cout<<" printing the edges of the graph :- "<<endl;
	for (int i=1;i<=n;i++)
	{
		cout<<" for i = "<<i<<endl;
		for (int j=0;j<adj[i].size() ;j++)
			cout<<adj[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;

	int answer = findLongestPath(adj, n);

	cout<<" answer = "<<answer<<endl;
}