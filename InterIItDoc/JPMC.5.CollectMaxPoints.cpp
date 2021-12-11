#include <bits/stdc++.h> 
using namespace std;


bool isValid(int r, int c, int x1 , int y1, int y2)
{
	return ((0<=x1) && (x1<r) && (0<=y1) && (y1<c) && (0<=y2) && (y2<c));
}


int getMaxValue(vector<vector<int>>& grid, vector<vector<vector<int>>>& dp, int r, int c, int x1, int y1, int y2)
{
	if (!isValid(r,c,x1,y1,y2))
		return INT_MIN;

	if (x1 == r-1 && y1==0 && y2==c-1)
	{
		if (y1==y2)
			return grid[x1][y1];
		else
			return (grid[x1][y1] + grid[x1][y2]);
	}

	if (x1 == r-1)
		return INT_MIN;

	if (dp[x1][y1][y2] != -1)
		return dp[x1][y1][y2];

	int answer = INT_MIN;

	int temp = (y1==y2) ? grid[x1][y1] : (grid[x1][y1] + grid[x1][y2]);

	answer = max(answer, temp + getMaxValue(grid, dp, r, c, x1+1, y1, y2));
	answer = max(answer, temp + getMaxValue(grid, dp, r, c, x1+1, y1, y2-1));
	answer = max(answer, temp + getMaxValue(grid, dp, r, c, x1+1, y1, y2+1));

	answer = max(answer, temp + getMaxValue(grid, dp, r, c, x1+1, y1-1, y2-1));
	answer = max(answer, temp + getMaxValue(grid, dp, r, c, x1+1, y1-1, y2));
	answer = max(answer, temp + getMaxValue(grid, dp, r, c, x1+1, y1-1, y2+1));

	answer = max(answer, temp + getMaxValue(grid, dp, r, c, x1+1, y1+1, y2+1));
	answer = max(answer, temp + getMaxValue(grid, dp, r, c, x1+1, y1+1, y2));
	answer = max(answer, temp + getMaxValue(grid, dp, r, c, x1+1, y1+1, y2-1));

	return (dp[x1][y1][y2] = answer);
}

int geMaxCollection(vector<vector<int>>& grid, int r, int c)
{
	if (r==0 || c==0)
		return 0;

	vector<vector<vector<int>>> dp;
	dp.resize(r, vector<vector<int>>(c, vector<int> (c,-1)));

	return getMaxValue(grid, dp, r, c, 0 , 0, c-1);
}

int main()
{
	cout<<" JPMC question "<<endl;
	cout<<" Collect maximum points in a grid using two traversals (Variant of Cherry pickup) "<<endl;

	vector<vector<int>> grid = {
		                       {3, 6, 8, 2}, 
                               {5, 2, 4, 3}, 
                               {1, 1, 20, 10}, 
                               {1, 1, 20, 10}, 
                               {1, 1, 20, 10}, 
                               };

    int r = grid.size();
    int c = grid[0].size();

    cout<<" r = "<<r<<endl;
    cout<<" c = "<<c<<endl;

    cout<<" printing the grid vector :- "<<endl;
    for (int i=0;i<grid.size();i++)
    {
    	for (int j=0;j<grid[i].size();j++)
    		cout<<grid[i][j]<<" ";
    	cout<<endl;
    }
    cout<<endl;

    int answer = geMaxCollection(grid, r, c);

    cout<<" answer = "<<answer<<endl;
}