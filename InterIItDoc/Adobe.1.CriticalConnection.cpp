#include<bits/stdc++.h>
using namespace std;

void getCritcialConn(vector<int> edge[], int n , int node, vector<bool>& visited, vector<int>& disc, vector<int>& low, vector<int>& parent, vector<vector<int>>& answer)
{
	static int time = 0;

	visited[node] = true;

	disc[node] = low[node] = ++time;

	for (int i=0;i<edge[node].size();i++)
	{
		int v = edge[node][i];

		if (!visited[v])
		{
			parent[v] = node;
			getCritcialConn(edge , n, v, visited, disc, low, parent, answer);

			low[node] = min(low[node], low[v]);

			if (low[v] > disc[node])
			{
				vector<int> temp = {node, v};
				answer.push_back(temp);
				temp.clear();
			}
		}
		else if (v != parent[node])
		{
			low[ node] = min( low[node], disc[v]);
		}
	}
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections)
{

    vector<int> edge[n];

    for (int i=0;i<connections.size();i++)
    {
    	int u = connections[i][0];
    	int v = connections[i][1];

    	edge[u].push_back(v);
    	edge[v].push_back(u);
    }

	vector<bool> visited;
	visited.resize(n,false);

	vector<int> disc;
	disc.resize(n,0);

	vector<int> low;
	low.resize(n,0);

	vector<int> parent;
	parent.resize(n,-1);

	vector<vector<int>> answer;

	for (int i=0;i<n;i++)
	{
		if ( !visited[i])
			getCritcialConn( edge, n , i, visited, disc, low, parent, answer);
	}

	return answer;
}

int main()
{
	cout<<" Adobe question 1 "<<endl;
	cout<<" leetcode question 1192. Critical Connections in a Network "<<endl;
	cout<<endl;

	// There are n servers numbered from 0 to n-1 connected by undirected server-to-server connections forming a network where connections[i]
	 // = [a, b] represents a connection between servers a and b. Any server can reach any other server directly or indirectly through the network.
	// A critical connection is a connection that, if removed, will make some server unable to reach some other server.
	// Return all critical connections in the network in any order.

	int n = 4;
	vector<vector<int>> connections = {
		                              {0,1},
		                              {1,2},
		                              {2,0},
		                              {1,3}
		                              };

    cout<<" n = "<<n<<endl;
    cout<<" printing the connections vector :- "<<endl;
    for (int i=0;i<connections.size();i++)
    	cout<< connections[i][0]<<" , "<<connections[i][1]<<endl;
    cout<<endl;

    vector<vector<int>> answer = criticalConnections(n, connections);

    if ( answer.size() == 0)
    	cout<<" there is no critical connection in given graph"<<endl;
    else
    {
    	cout<<" printing the answer vector :- "<<endl;
    	for (int i=0;i<answer.size();i++)
    		cout<< answer[i][0]<<" , "<< answer[i][1]<<endl;
    	cout<<endl;
    }

}