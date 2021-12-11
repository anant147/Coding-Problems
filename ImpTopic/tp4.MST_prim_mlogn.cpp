#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
#include<cstring>
using namespace std;

void printMST(int parent[], int key[], int n)
{
	int i,j,k;

	int sum = 0;

	cout<<endl;
	cout<<" printing the edges of the mst with their weights :- "<<endl;
	for (i=1;i<n;i++)
	{
		sum = sum + key[i];
		cout<<parent[i]<<" , "<<i<<" , "<<key[i]<<endl;
	}
	cout<<endl;
	cout<<" sum of weights of edges of mst = "<<sum<<endl;
}

void primMST(int n , vector<vector<int>>& graph)
{
	int i,j,k,u,v,x,y,z;

	vector<int> edges[n];
	vector<int> weight[n];

	for (i=0;i<graph.size();i++)
	{
		u = graph[i][0]; v = graph[i][1]; x = graph[i][2];

		edges[u].push_back(v);
		weight[u].push_back(x);
	}

	cout<<endl;
	cout<<" printing the edges vector :- "<<endl;
	for (i=0;i<n;i++)
	{
		cout<<" for i = "<<i<<endl;
		for (j=0;j<edges[i].size();j++)
			cout<<edges[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;

	cout<<endl;
	cout<<" printing the weight vector :- "<<endl;
	for (i=0;i<n;i++)
	{
		cout<<" for i = "<<i<<endl;
		for (j=0;j<weight[i].size();j++)
			cout<<weight[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;

	int key[n];
	int parent[n];
	bool setMST[n];

	int maxval = pow(2,sizeof(int)*8-1)-1;

	for (i=0;i<n;i++)
	{
		key[i] = maxval;
		setMST[i] = false;
	}

	key[0] = 0; parent[0] = -1;

	priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pair<int,int> ptemp;

	pq.push(make_pair(0,0));

	int count = 0;

	while (count < (n-1) && !pq.empty())
	{
		ptemp = pq.top();
		pq.pop();

		u = ptemp.second;

		setMST[u] = true;
		count++;

		for (i=0;i<edges[u].size();i++)
		{
			v = edges[u][i];  z = weight[u][i];

			if (setMST[v]==false && z<key[v])
			{
				parent[v] = u;
				key[v] = z;
				pq.push(make_pair(z,v));
			}
		}
	}

	printMST(parent, key, n);
}

int main()
{
	cout<<" tp4. Minimum Spanning tree by prim algo - o(n log e) method"<<endl;

	int n = 9;

	vector<vector<int>> graph = {
		                        {0,1,4},
		                        {0,7,8},
		                        {1,2,8},
		                        {1,7,11},
		                        {2,3,7},
		                        {2,8,2},
		                        {2,5,4},
		                        {3,4,9},
		                        {3,5,14},
		                        {4,5,10},
		                        {5,6,2},
		                        {6,7,1},
		                        {6,8,6},
		                        {7,8,7},
		                        };

    cout<<" n = "<<n<<endl;

    cout<<" printing the graph vector :- "<<endl;
    for (int i=0;i<graph.size();i++)
    	cout<<graph[i][0]<<" , "<<graph[i][1]<<" , "<<graph[i][2]<<endl;
    cout<<endl;

    primMST(n, graph);

}