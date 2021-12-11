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

int uniquePathsWithObstacles(vector<vector<int>>& grid)
{
	int i,j,k,u,v,x,y,z;

	int n = grid.size();

	if (n==0)
		return 0;

	int m = grid[0].size();

	if (m==0)
		return 0;

	vector<vector<int>> sol;
	sol.resize(n, vector<int> (m,-1));

	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
		{
			if (i==0 && j==0)
			{
				if (grid[i][j]==1)
					sol[i][j] = 0;
				else
					sol[i][j] = 1;
			}
			else if (i==0)
			{
				if (grid[i][j]==1)
					sol[i][j] = 0;
				else
					sol[i][j] = sol[i][j-1];
			}
			else if (j==0)
			{
				if (grid[i][j] == 1)
					sol[i][j] = 0;
				else
					sol[i][j] = sol[i-1][j];
			}
			else
			{
				if (grid[i][j] == 1)
					sol[i][j] = 0;
				else
					sol[i][j] = sol[i-1][j] + sol[i][j-1];
			}
		}
	}

	// cout<<" printing the sol vector :- "<<endl;

	// for (i=0;i<n;i++)
	// {
	// 	for (j=0;j<m;j++)
	// 		cout<<sol[i][j]<<" ";
	// 	cout<<endl;
	// }
	// cout<<endl;

	return sol[n-1][m-1];
}

int main()
{
	cout<<" Sap labs iit g question :- "<<endl;
	cout<<" 63. Unique Paths II "<<endl;

	vector<vector<int>> grid = {
		                       {0,0,0},
                               {0,1,0},
                               {0,0,0}
                               };

    cout<<" printing the grid vector :- "<<endl;
    for (int i=0;i<grid.size();i++)
    {
    	for (int j=0;j<grid[i].size();j++)
    		cout<<grid[i][j]<<" ";
    	cout<<endl;
    }
    cout<<endl;

    int answer = uniquePathsWithObstacles(grid);

    cout<<" answer = "<<answer<<endl;
}