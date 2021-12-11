#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
using namespace std;

void heapify(vector<vector<int>>& vheap, int point, int sz)
{
	int left = 2*point+1;
	int right = 2*point+2;

	if (left>=sz && right>=sz)
		return;

	int index = point;

	if (vheap[left][1] < vheap[point][1])
		index = left;

	if (right<sz && (vheap[right][1] < vheap[index][1]) )
		index = right;

	if (point != index)
	{
		vector<int> temp = vheap[point];
		vheap[point] = vheap[index];
		vheap[index] = temp;

		heapify(vheap, index, sz);
	}
}

vector<int> getMinimum(vector<vector<int>>& vheap)
{
	int sz = vheap.size();

	if (sz==1)
	{
		vector<int> temp = vheap[0];  vheap.pop_back(); return temp;
	}

	vector<int> temp1,temp2;

	temp1 = vheap[0]; 
	temp2 = vheap[sz-1];

	vheap[0] = temp2;
	vheap.pop_back(); 

	heapify(vheap,0,sz-1);

	return temp1;
}

void insertElement(vector<vector<int>>& vheap, vector<int> temp)
{
	int sz = vheap.size();

	if (sz==0)
	{
		vheap.push_back(temp);  return;
	}

	vector<int> temp1,temp2;

	vheap.push_back(temp);
	sz = sz+1;

	int rt = sz-1;
	int parent = (rt-1)/2;

	while((parent>=0) && (vheap[rt][1] < vheap[parent][1]))
	{
		temp1 = vheap[rt];
		vheap[rt] = vheap[parent];
		vheap[parent] = temp1;

		rt = parent;
		parent = (rt-1)/2;
	}
}

int findCheapestPrice1(int n, vector<vector<int>>& flights, int src, int dst, int k)
{
	int i,j,u,v,x,y,z,s,r;

	int maxval = pow(2,sizeof(int)*8-1)-1;

	vector<int> graph[n];
	vector<int> ecost[n];

	vector<int> cost, stops;
	cost.resize(n, maxval);
	stops.resize(n, -1);

	for (i=0;i<flights.size();i++)
	{
		u = flights[i][0];  v = flights[i][1];  x = flights[i][2];
		graph[u].push_back(v);      ecost[u].push_back(x);
	}

	// cout<<" printing the graph vector :- "<<endl;
	// for (i=0;i<n;i++)
	// {
	// 	cout<<" for point "<<i<<endl;
	// 	for (j=0;j<graph[i].size();j++)
	// 		cout<<graph[i][j]<<" ";
	// 	cout<<endl;
	// }
	// cout<<endl;

	// cout<<" printing the ecost vector :- "<<endl;
	// for (i=0;i<n;i++)
	// {
	// 	cout<<" for point "<<i<<endl;
	// 	for (j=0;j<ecost[i].size();j++)
	// 		cout<<ecost[i][j]<<" ";
	// 	cout<<endl;
	// }
	// cout<<endl;

	cost[src]=0;
	vector<vector<int>> vheap;
	insertElement(vheap,{src,cost[src],-1});

	vector<int> temp,temp1,temp2;
	int sz = vheap.size();

	while(sz!=0)
	{
		temp = getMinimum(vheap);
		u = temp[0];  v = temp[1];  s= temp[2];

		for (i=0;i<graph[u].size();i++)
		{
			x = graph[u][i];  y = ecost[u][i];

			if ((s<k))
			{
				if (cost[x] > (v+ y))
				{
				cost[x] = v+y;
				stops[x] = s + 1;
				temp1 = {x,cost[x],stops[x]};
				insertElement(vheap,temp1);
				temp1.clear();
			    }
			    else
			    {
			    	if (cost[x]!=maxval)
			    	{
			    		z = v+y;
			    		temp1 = {x,z,s+1};
			    		insertElement(vheap,temp1);
			    		temp1.clear();
			    	}
			    }
			}
		}
		temp.clear();
		sz = vheap.size();
	}

	// cout<<endl;
	// cout<<" printing the cost vector :- "<<endl;
	// for (i=0;i<n;i++)
	// 	cout<<cost[i]<<" ";
	// cout<<endl;
	// cout<<endl;
	// cout<<" printing the stops vector :- "<<endl;
	// for (i=0;i<n;i++)
	// 	cout<<stops[i]<<" ";
	// cout<<endl;

	if (cost[dst]==maxval || stops[dst]==-1 || stops[dst]>k)
		return -1;
	else
		return cost[dst];


}

////////////////////////////////// trial2  ////////////////////////////////////////////////////////////////////////////////////////////////////////////

int getmin(int a,int b)
{
	if (a<b)
		return a;
	else
		return b;
}

int dfsForSrDst(vector<vector<int>>& graph, vector<int>& visited, int n, int stopcnt, int maxstop, int source, int dest)
{
	int maxval = pow(2,sizeof(int)*8-1)-1;
	// cout<<" source = "<<source<<" , dest = "<<dest<<" , stopcnt =  "<<stopcnt<<endl;

	int i,j,k,u,v,x,y,z;

	if (source==dest)
	{
		// cout<<" cond2 "<<endl;
		return 0;
	}

	if (stopcnt>=maxstop)
	{
		// cout<<" cond1 "<<endl;
		return maxval;
	}

	int answer = maxval;

	visited[source]=1;

	for (i=0;i<graph[source].size();i++)
	{
		if (graph[source][i]!=maxval && visited[i]!=1)
		{
			// cout<<" i "<<i<<endl;
			// cout<<" val = "<<graph[source][i]<<endl;
			int curr = dfsForSrDst(graph, visited, n, stopcnt+1, maxstop, i, dest);
			// cout<<" source = "<<source<<" , dest = "<<dest<<" , stopcnt =  "<<stopcnt<<" , curr = "<<curr<<endl;

			if (curr < maxval)
			{
				// cout<<" cond3 "<<endl;
				answer = getmin(answer, curr + graph[source][i]);
				// cout<<" answer = "<<answer<<endl;
			}
		}
	}

	visited[source] = 0;
	return answer;
}


int findCheapestPrice2(int n, vector<vector<int>>& flights, int src, int dst, int k)
{
	int i,j,u,v,x,y,z;

	int maxval = pow(2,sizeof(int)*8-1)-1;

	vector<vector<int>> graph, stops;

	graph.resize(n,vector<int> (n,maxval));

	for (i=0;i<flights.size();i++)
	{
		u = flights[i][0];  v = flights[i][1] ; x = flights[i][2];
		graph[u][v] = x;
	}

	// cout<<endl;
	// cout<<" printing the graph vector :- "<<endl;
	// for (i=0;i<n;i++)
	// {
	// 	for (j=0;j<n;j++)
	// 		cout<<graph[i][j]<<" ";
	// 	cout<<endl;
	// }
	// cout<<endl;

	if (src==dst)
		return 0;
	else
	{
		vector<int> visited;
		visited.resize(n,0);

		int answer = dfsForSrDst(graph,visited,n,-1,k,src,dst);

		if (answer == maxval)
			return -1;
		else
			return answer;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////  trial3 /////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int main()
{
	cout<<" 787. Cheapest Flights Within K Stops "<<endl;

	// example 1
	int n = 3;
	vector<vector<int>> flights = {
		                          {0,1,100},
		                          {1,2,100},
		                          {0,2,500}
		                          };
	int src = 0;
	int dst = 2;
	// int k = 0;// part a
	int k = 1 ;// part b

	// example 2
	// int n = 4;
	// vector<vector<int>> flights = {
	// 	                          {0,1,1},
	// 	                          {0,2,5},
	// 	                          {1,2,1},
	// 	                          {2,3,1}
	// 	                          };

 //    int src = 0;
 //    int dst = 3;
 //    int k = 1;

	cout<<" n = "<<n<<endl;
	cout<<" edges of given graph with their cost :- "<<endl;
	for (int i=0;i<flights.size();i++)
		cout<<flights[i][0]<<" , "<<flights[i][1]<<" , "<<flights[i][2]<<endl;
	cout<<endl;

	cout<<" src = "<<src<<endl;
	cout<<" dst = "<<dst<<endl;
	cout<<" k = "<<k<<endl;

	cout<<endl;
	int answer = findCheapestPrice2(n, flights, src, dst, k);
	cout<<" answer = "<<answer<<endl;

}