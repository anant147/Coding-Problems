#include <bits/stdc++.h> 
using namespace std;

int maxval(int a, int b)
{
	if (a>b)
		return a;
	else
		return b;
}

bool isValid(int r, int c, int x1, int y1, int y2)
{
	return ( (0<=x1) && (x1<r) && (0<=y1) && (y1<c) && (0<=y2) && (y2<c) );
}

int getMaxValue(vector<vector<int>>& grid, vector<vector<vector<int>>>& dp, int r, int c, int x1, int y1, int y2)
{
	int minimum = (-1)*pow(2,sizeof(int)*8-1);

	if (!isValid(r,c,x1,y1,y2))
		return minimum;

	if (x1== r-1)
	{
		if (y1==y2)
			return grid[x1][y1];
		else
			return ( grid[x1][y1] + grid[x1][y2]);
	}

	if (dp[x1][y1][y2] != -1)
		return dp[x1][y1][y2];

	int temp = (y1==y2) ? grid[x1][y1] : (grid[x1][y1] + grid[x1][y2]);

	int answer = minimum;

	answer = maxval(answer, temp + getMaxValue( grid, dp, r, c, x1+1, y1, y2-1));
	answer = maxval(answer, temp + getMaxValue( grid, dp, r, c, x1+1, y1, y2));
	answer = maxval(answer, temp + getMaxValue( grid, dp, r, c, x1+1, y1, y2+1));

	answer = maxval(answer, temp + getMaxValue( grid, dp, r, c, x1+1, y1-1, y2-1));
	answer = maxval(answer, temp + getMaxValue( grid, dp, r, c, x1+1, y1-1, y2));
	answer = maxval(answer, temp + getMaxValue( grid, dp, r, c, x1+1, y1-1, y2+1));

	answer = maxval(answer, temp + getMaxValue( grid, dp, r, c, x1+1, y1+1, y2-1));
	answer = maxval(answer, temp + getMaxValue( grid, dp, r, c, x1+1, y1+1, y2));
	answer = maxval(answer, temp + getMaxValue( grid, dp, r, c, x1+1, y1+1, y2+1));

	return (dp[x1][y1][y2] = answer);
}

int cherryPickup(vector<vector<int>>& grid)
{
	int r = grid.size();
	int c = grid[0].size();

	vector<vector<vector<int>>> dp;
	dp.resize(r, vector<vector<int>>(c, vector<int>(c,-1)));

	return getMaxValue(grid, dp, r, c, 0, 0, c-1);
}

int main()
{
	cout<<" 1463. Cherry Pickup II "<<endl;

	// example 1
	// vector<vector<int>> grid =  {
	// 	                        {3,1,1},
	// 	                        {2,5,1},
	// 	                        {1,5,5},
	// 	                        {2,1,1}
	// 	                        };

    // example 2
    // vector<vector<int>> grid = {
    // 	                       {1,0,0,0,0,0,1},
    // 	                       {2,0,0,0,0,3,0},
    // 	                       {2,0,9,0,0,0,0},
    // 	                       {0,3,0,5,4,0,0},
    // 	                       {1,0,2,3,0,0,6}
    // 	                       };

    // example 3
    // vector<vector<int>> grid = {
    // 	                       {1,0,0,3},
    // 	                       {0,0,0,3},
    // 	                       {0,0,3,3},
    // 	                       {9,0,3,3}
    // 	                       };

    // exam4
    vector<vector<int>> grid = {
    	                       {1,1},
    	                       {1,1}
    	                       };

    cout<<" printing the grid vector :- "<<endl;
    for (int i=0;i<grid.size();i++)
    {
    	for (int j=0;j<grid[i].size();j++)
    		cout<<grid[i][j]<<" ";
    	cout<<endl;
    }
    cout<<endl;

    int answer = cherryPickup(grid);

    cout<<" answer = "<<answer<<endl;
}