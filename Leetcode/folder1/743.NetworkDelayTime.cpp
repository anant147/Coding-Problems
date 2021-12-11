#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<queue>
#include<cmath>
using namespace std;

void bfsForNetwork(vector<int> varr[],vector<int> vcost[],vector<int>& cost,int point,int n)
{
	queue<int> q1;

	q1.push(point);

	int i,j,k,u,v,x,y,z;

	while(!q1.empty())
	{
		x = q1.front();
		q1.pop();

		for (i=0;i<varr[x].size();i++)
		{
			y = varr[x][i];
			z = vcost[x][i];

			if (cost[y] > (cost[x] + z))
			{
				q1.push(y);
				cost[y] = cost[x] + z;
			}
		}
	}
}

int networkDelayTime(vector<vector<int>>& times, int n,int k)
{
	int i,j,u,v,x,y,z;

	vector<int> varr[n+1];
	vector<int> vcost[n+1];

	int maxval = pow(2,sizeof(int)*8-1)-1;

	vector<int> cost;
	cost.resize(n+1,maxval);

	cost[0]=-1;
	cost[k]=0;

	for (i=0;i<times.size();i++)
	{
		x = times[i][0];
		y = times[i][1];
		z = times[i][2];

		varr[x].push_back(y);
		vcost[x].push_back(z);

	}

	// cout<<" printing the varr vector :- "<<endl;
	// for (i=0;i<(n+1);i++)
	// {
	// 	cout<<" for i = "<<i<<endl;
	// 	for (j=0;j<varr[i].size();j++)
	// 		cout<<varr[i][j]<<" ";
	// 	cout<<endl;
	// }
	// cout<<endl;

	// cout<<" printing the vcost vector :- "<<endl;
	// for (i=0;i<(n+1);i++)
	// {
	// 	cout<<" for i = "<<i<<endl;
	// 	for (j=0;j<vcost[i].size();j++)
	// 		cout<<vcost[i][j]<<" ";
	// 	cout<<endl;
	// }
	// cout<<endl;

	bfsForNetwork(varr,vcost,cost,k,n);

	int cond = 0;

	int maxval1 = pow(2,sizeof(int)*8-1)-1;
	maxval = 0;

	for (i=0;i<(n+1);i++)
	{
		if (cost[i]==maxval1)
		{
			cond=1;
			break;
		}

		if (maxval < cost[i])
			maxval = cost[i];
	}

	if (cond==1)
		return -1;
	else
		return maxval;
}

int main()
{
	cout<<" 743. Network Delay Time "<<endl;

	vector<vector<int>> times = {
	                            {2,1,1},
	                            {2,3,1},
	                            {3,4,1}
	                            };
	int n = 4;
	int k = 2;

	int i,j,u,v;

	cout<<" printing the times vector :- "<<endl;
	for (i=0;i<times.size();i++)
	{
		for (j=0;j<times[i].size();j++)
			cout<<times[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;

	cout<<" no. of nodes - "<<n<<endl;
	cout<<" source node :- "<<k<<endl;

	int answer = networkDelayTime(times,n,k);

	cout<<" answer = "<<answer<<endl;
}