#include<bits/stdc++.h>
using namespace std;
#define V 4

int travllingSalesmanProblem(int graph[][V], int s)
{
	vector<int> vertex;

	for (int i=0;i<V;i++)
	{
		if (i != s)
			vertex.push_back(i);
	}

	int min_path = INT_MAX;

	// cout<<" temp min_path = "<<min_path<<endl;

	do{
		int current_pathweight = 0;

		int k = s;
		for (int i=0;i<vertex.size();i++)
		{
			current_pathweight += graph[k][vertex[i]];
			k = vertex[i];
		}

		current_pathweight += graph[k][s];

		min_path = min(min_path, current_pathweight);

		// cout<<" intermediate min_path = "<<min_path<<endl;

	}while( next_permutation(vertex.begin(), vertex.end()));

	return min_path;
}

int main()
{
	cout<<" tp.13. Travelling Salesmen Problem : "<<endl;

	int graph[V][V] = { { 0, 10, 15, 20 },
                       { 10, 0, 35, 25 },
                       { 15, 35, 0, 30 },
                       { 20, 25, 30, 0 } };

    cout<<" printing the graph matrix : "<<endl;
    for (int i=0;i<V;i++)
    {
    	for (int j=0;j<V;j++)
    		cout<<graph[i][j]<<" ";
    	cout<<endl;
    }              
    cout<<endl;

    int s = 0;

    int answer = travllingSalesmanProblem(graph, s);

    cout<<" answer = "<<answer<<endl;




}