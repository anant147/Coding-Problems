#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<unordered_map>
#include<queue>
#include<stack>
#include<cmath>
#include<cstring>
#include<climits>
using namespace std;

#define V 4
#define INF INT_MAX

void printDistMat(int dist[V][V])
{
	int i,j;

	cout<<endl;
	cout<<" printing the dist matrix :-"<<endl;

	for (i=0;i<V;i++)
	{
		for (j=0;j<V;j++)
		{
			if (dist[i][j]==INF)
				cout<<"INF"<<" ";
			else
				cout<<dist[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

void floydWarshal(int graph[V][V])
{
	int i,j,k,u,v,x,y,z;

	int dist[V][V];

	for (i=0;i<V;i++)
	{
		for (j=0;j<V;j++)
			dist[i][j] = graph[i][j];
	}

	for (k=0;k<V;k++)
	{
		for (i=0;i<V;i++)
		{
			for (j=0;j<V;j++)
			{
				if (dist[i][k]!=INF && dist[k][j]!=INF && ( dist[i][j] > ( dist[i][k] + dist[k][j] ) ) )
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	printDistMat(dist);
}


int main()
{
	cout<<" tp5. Floyd Warshall algorithm - complexity of o(V*V*V)"<<endl;

	int graph[V][V] = {
		              {0,5,INF,10},
		              {INF,0,3,INF},
		              {INF,INF,0,1},
		              {INF,INF,INF,0}
		              };

	cout<<" printing the graph matrix :-"<<endl;

	for (int i=0;i<V;i++)
	{
		for (int j=0;j<V;j++)
		{
			if (graph[i][j]==INF)
				cout<<"INF"<<" ";
			else
				cout<<graph[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;

	floydWarshal(graph);
}