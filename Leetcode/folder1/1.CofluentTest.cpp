#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<queue>
#include<cmath>
#include<stack>
using namespace std;

bool reachTheEnd(int rows, vector<string>& grid, int maxTime)
{
	int i,j,k,u,v,x,y,z;

	int n = grid.size();
	int m = grid[0].size();

	vector<vector<int>> mat;
	mat.resize(n, vector<int>(n,-1));

	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
		{
			if (grid[i][j]=='#')
				mat[i][j]=-2;
		}
	}

	mat[0][0]=0;
	priority_queue< pair< int, pair< int, int > > > pq;
	pq.push(make_pair(0,make_pair(0,0)));

	pair<int, pair<int,int>> ptemp1,ptemp2;

	int count = 0;

	while (!pq.empty())
	{
		ptemp1 = pq.top();
		pq.pop();

		u = ptemp1.first;
		x = ptemp1.second.first;
		y = ptemp1.second.second;

		v = u+1;

		if (v<=maxTime)
		{
			if ((x-1)>=0 && mat[x-1][y]==-1)
			{
				mat[x-1][y] = v;
				pq.push(make_pair( v, make_pair( x-1, y)));
			}

			if ((y-1)>=0 && mat[x][y-1]==-1)
			{
				mat[x][y-1] = v;
				pq.push(make_pair( v, make_pair( x, y-1)));

			}

			if ((x+1)<=(n-1) && mat[x+1][y]==-1)
			{
				mat[x+1][y] = v;
				pq.push(make_pair( v, make_pair( x+1, y)));
			}

			if ((y+1)<=(m-1) && mat[x][y+1]==-1)
			{
				mat[x][y+1] = v;
				pq.push(make_pair( v, make_pair( x, y+1)));
			}
	    }
	}

	if (mat[n-1][m-1]!=-1 && mat[n-1][m-1]<=maxTime)
		return true;
	else
		return false;
}

int main()
{
	cout<<" Reach the end :- "<<endl;

	int rows = 3;
	vector<string> grid= {"..##","#.##","#..."};

	int maxTime = 5;

	bool answer = reachTheEnd(rows, grid, maxTime );

	if (answer)
		cout<<" required results are achived "<<endl;
	else
		cout<<" result are not achieved "<<endl;
}