#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<queue>
#include<stack>
using namespace std;

bool checkComponent(vector<vector<int>>& graph,vector<int>& color, vector<int>& visited, int point, int n)
{
	int i,j,k,u,v,x,y,z;

	queue<int> q1;
	q1.push(point);

	visited[point]=1;
	color[point]=1;

	int cond = 0;

	while(!q1.empty())
	{
		k = q1.front();
		q1.pop();

		for (i=0;i<graph[k].size();i++)
		{
			u = graph[k][i];

			if (color[u]==-1 && visited[u]==0)
			{
				visited[u]=1;
				q1.push(u);

				if (color[k]==1)
					color[u]=2;
				else if (color[k]==2)
					color[u]=1;
			}
			else
			{
				if (color[k]==color[u])
				{
					cond=1;
					return false;
				}
			}
		}
	}

	return true;
}

bool isBipartite(vector<vector<int>>& graph)
{
	int i,j,k,u,v,x,y,z;

	int n = graph.size();

	if ((n==0) || (n==1))
		return true;

	vector<int> color,visited;
	color.resize(n,-1);
	visited.resize(n,0);

	for (i=0;i<n;i++)
	{
		if (color[i]==-1)
		{
			if (checkComponent(graph,color,visited,i,n)==false)
				return false;
		}
	}
	return true;
}

int main()
{
	cout<<" 785. Is Graph Bipartite? "<<endl;
	// vector<vector<int>> graph = {
	// 	                        {1,3},
	// 	                        {0,2},
	// 	                        {1,3},
	// 	                        {0,2}
	// 	                        };

	vector<vector<int>> graph = {
		                        {1,2,3},
		                        {0,2},
		                        {0,1,3},
		                        {0,2}
	                            };

    int n = graph.size();
    int i,j,k,u,v;

    cout<<" n = "<<n<<endl;
    cout<<" printing graph vector :- "<<endl;
    for (i=0;i<n;i++)
    {
    	for (j=0;j<graph[i].size();j++)
    		cout<<graph[i][j]<<" ";
    	cout<<endl;
    }  
    cout<<endl;

    bool answer = isBipartite(graph);

    if (answer)
    	cout<<" Graph is Bipartite "<<endl;
    else
    	cout<<" Graph is not Bipartite "<<endl;
}