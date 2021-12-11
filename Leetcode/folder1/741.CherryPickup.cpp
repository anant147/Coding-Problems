#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<stack>
#include<queue>
#include<cmath>
using namespace std;

int maxval(int a, int b)
{
	if (a>b)
		return a;
	else
		return b;
}

int getVal(vector<vector<int>>& grid, vector<vector<vector<int>>>& dp, int x, int y, int z)
{
	int w = x + y - z;

	if (x==-1 || y==-1 || z==-1 || w==-1)
		return -2;

	if (dp[x][y][z]!=-1)
		return dp[x][y][z];

	if (grid[x][y] == -1 || grid[z][w]==-1)
	{
		dp[x][y][z] = -2;
		return -2;
	}

	int val = -2;

	val = maxval(val, getVal(grid, dp, x-1, y, z-1));
	val = maxval(val, getVal(grid, dp, x-1, y, z));
	val = maxval(val, getVal(grid, dp, x, y-1,z));
	val = maxval(val, getVal(grid, dp, x, y-1,z-1));

	if (val !=-2)
	{
		val = val+grid[x][y];

		if (x!=z || y!=w)
			val = val + grid[z][w];
	}

	dp[x][y][z] = val;

	return val;
}

int cherryPickup( vector<vector<int>>& grid)
{
	int i,j,k,u,v,x,y,z;

	int n = grid.size();

	vector<vector<vector<int>>> dp;
	dp.resize(n, vector<vector<int>>(n, vector<int>(n,-1)));

	dp[0][0][0] = grid[0][0];

	int val = getVal(grid, dp, n-1, n-1, n-1);

	if (val==-2)
		return 0;
	else
		return dp[n-1][n-1][n-1];
}

int main()
{
	cout<<" 741. Cherry Pickup "<<endl;

	// example 1
	// vector<vector<int>> grid = {
	// 	                       {0,1,-1},
	// 	                       {1,0,-1},
	// 	                       {1,1,1}
	// 	                       };

	// example 2
	// vector<vector<int>> grid = {
	// 	                       {1,1,-1},
	// 	                       {1,-1,-1},
	// 	                       {-1,1,1}
	// 	                       };

	// example 3
	vector<vector<int>> grid = {
		                       {1,1,1,1,0,0,0},
		                       {0,0,0,1,0,0,0},
		                       {0,0,0,1,0,0,1},
		                       {1,0,0,1,0,0,0},
		                       {0,0,0,1,0,0,0},
		                       {0,0,0,1,0,0,0},
		                       {0,0,0,1,1,1,1}
		                       };

	int i,j;

	cout<<" printing the grid vector :- "<<endl;

	for (i=0;i<grid.size();i++)
	{
		for (j=0;j<grid[i].size();j++)
		{
			cout<<grid[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;	

	int answer = cherryPickup(grid);

	cout<<" answer = "<<answer<<endl;
}