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

int findGrp(vector<vector<int>>& pstor, int x)
{
	if (pstor[x][0] != x)
		pstor[x][0] = findGrp(pstor, pstor[x][0]);

	return pstor[x][0];
}

void unionGrp(vector<vector<int>>& pstor, int x, int y)
{
	int px = findGrp(pstor, x);
	int py = findGrp(pstor, y);

	if (pstor[px][1] < pstor[py][1])
		pstor[px][0] = py;
	else if (pstor[px][1] > pstor[py][1])
		pstor[py][0] = px;
	else
	{
		pstor[py][0] = px;
		pstor[px][1]++;
	}
}

int minCostConnectPoints(vector<vector<int>>& points)
{
	int i,j,k,u,v,x,y,z;

	int n = points.size();

	if (n==1)
		return 0;

	vector<vector<int>> pstor;
	pstor.resize(n,vector<int>(2,0));

	for (i=0;i<n;i++)
		pstor[i][0] = i;

	vector<pair<int,pair<int,int>>> vptemp;
	pair<int,pair<int,int>> ptemp;

	for (i=0;i<n;i++)
	{
		for (j=i+1;j<n;j++)
		{
			u = points[i][0] - points[j][0];
			v = points[i][1] - points[j][1];

			if (u<0)
				u = (-1)*u;

			if (v<0)
				v = (-1)*v;

			x = u+v;

			vptemp.push_back(make_pair(x, make_pair(i,j)));
		}
	}

	sort(vptemp.begin(), vptemp.end());

	int count = 0;
	int sum = 0;

	int px,py;

	i=0;

	while (count < (n-1) && i<vptemp.size())
	{
		ptemp = vptemp[i];
		u = ptemp.first;
		x = ptemp.second.first;
		y = ptemp.second.second;

		px = findGrp(pstor, x);
		py = findGrp(pstor, y);

		if (px != py)
		{
			count++;
			sum = sum + u;
			unionGrp(pstor, x, y);
		}

		i++;
	}

	return sum;
}

int main()
{
	cout<<" 1584. Min Cost to Connect All Points "<<endl;

	// example 1
	// vector<vector<int>> points = {{0,0},{2,2},{3,10},{5,2},{7,0}};

	// example 2
	// vector<vector<int>> points = {{3,12},{-2,5},{-4,1}};

	// example 3
	// vector<vector<int>> points = {{0,0},{1,1},{1,0},{-1,1}};

	// example 4
	// vector<vector<int>> points = {{-1000000,-1000000},{1000000,1000000}};	

	// example 4
	vector<vector<int>> points = {{0,0}};

	cout<<" printing the points vector :- "<<endl;

	for (int i=0;i<points.size();i++)
		cout<<points[i][0]<<" , "<<points[i][1]<<endl;
	cout<<endl;

	int answer = minCostConnectPoints(points);

	cout<<" answer = "<<answer<<endl;





}