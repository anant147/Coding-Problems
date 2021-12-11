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

int findGrp(vector<vector<int>>& cstor, int x)
{
	if (cstor[x][0] != x)
		cstor[x][0] = findGrp(cstor, cstor[x][0]);

	return cstor[x][0];
}

void unionGrp(vector<vector<int>>& cstor, int x, int y)
{
	int px = findGrp(cstor, x);
	int py = findGrp(cstor, y);

	if (cstor[px][1] < cstor[py][1])
		cstor[px][0] = py;
	else if (cstor[px][1] > cstor[py][1])
		cstor[py][0] = px;
	else
	{
		cstor[py][0] = px;
		cstor[px][1]++;
	}
}

int makeConnected(int n, vector<vector<int>>& connections)
{
	int i,j,k,u,v,x,y,z;

	if (n==1)
		return 0;

	vector<vector<int>> cstor;
	cstor.resize(n,vector<int>(2,0));

	for (i=0;i<n;i++)
		cstor[i][0] = i;

	int count1 = 0;
	int count2 = 0;

	for (i=0;i<connections.size();i++)
	{
		u = connections[i][0];  v = connections[i][1];

		x = findGrp(cstor, u);
		y = findGrp(cstor, v);

		if (x != y)
		{
			unionGrp(cstor,u,v);
		}
		else
			count1++;
	}

	for (i=0;i<n;i++)
	{
		if (cstor[i][0] == i)
			count2++;
	}

	if (count1 >= (count2-1))
		return (count2-1);
	else
		return -1;
}

int main()
{
	cout<<" 1319. Number of Operations to Make Network Connected "<<endl;

	// example 1
	// int n = 4;
	// vector<vector<int>> connections = {{0,1},{0,2},{1,2}};

	// example 2
	// int n = 6;
	// vector<vector<int>> connections = {{0,1},{0,2},{0,3},{1,2},{1,3}};

	// example 3
	// int n = 6;
	// vector<vector<int>> connections = {{0,1},{0,2},{0,3},{1,2}};

	// example 4
	int n = 5;
	vector<vector<int>> connections = {{0,1},{0,2},{3,4},{2,3}};


	cout<<" n = "<<n<<endl;

	cout<<" printing the connections vector :- "<<endl;
	for (int i=0;i<connections.size();i++)
		cout<<connections[i][0]<<" , "<<connections[i][1]<<endl;
	cout<<endl;

	int answer = makeConnected(n, connections);

	cout<<" answer = "<<answer<<endl;
}