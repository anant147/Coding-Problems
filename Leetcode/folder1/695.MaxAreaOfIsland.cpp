#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
using namespace std;

int getAreaForPoint(vector<vector<int>>& grid,vector<vector<int>>& vcheck,pair<int,int>& point,int n,int m)
{
	int i,j,k,u,v,x,y,z;

	queue<pair<int,int>> q1;

	pair<int,int> ptemp;
	int px,py;

	int px1 = point.first;
	int py1 = point.second;

	vcheck[px1][py1]=1;

	int count = 0;

	q1.push(point);

	while(!q1.empty())
	{
		ptemp = q1.front();
		q1.pop();

		px = ptemp.first;
		py = ptemp.second;

		if ((px-1)>=0 && grid[px-1][py]==1 && vcheck[px-1][py]==0)
		{
			q1.push(make_pair(px-1,py));
			vcheck[px-1][py]=1;
			count++;
		}

		if ((py-1)>=0 && grid[px][py-1]==1 && vcheck[px][py-1]==0)
		{
			q1.push(make_pair(px,py-1));
			vcheck[px][py-1]=1;
			count++;
		}

		if ((px+1)<n && grid[px+1][py]==1 && vcheck[px+1][py]==0)
		{
			q1.push(make_pair(px+1,py));
			vcheck[px+1][py]=1;
			count++;
		}

		if ((py+1)<m && grid[px][py+1]==1 && vcheck[px][py+1]==0)
		{
			q1.push(make_pair(px,py+1));
			vcheck[px][py+1]=1;
			count++;
		}
	}

	count++;

	return count;
}

int maxAreaOfIsland(vector<vector<int>>& grid)
{
	int i,j,k,u,v,x,y,z;

	int maxval = 0;
	int val;

	pair<int,int> point;
	int px,py;

	int n = grid.size();
	if (n==0)
		return 0;

	int m = grid[0].size();

	if (n==1 && m==1)
	{
		if (grid[i][j]==0)
			return 0;
		else
			return 1;
	}

	vector<vector<int>> vcheck;
	vcheck.resize(n,vector<int> (m,0));

	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
		{
			if (grid[i][j]==1 && vcheck[i][j]==0)
			{
				point = make_pair(i,j);

				val = getAreaForPoint(grid,vcheck,point,n,m);

				if (maxval < val)
					maxval = val;
			}
		}
	}

	return maxval;
}

int main()
{
	cout<<" 695. Max Area of Island "<<endl;

	// example 1
	// vector<vector<int>> grid = {
	// 	                        {1,1,1,1,0},
	// 	                        {1,1,0,1,0},
	// 	                        {1,1,0,0,0},
	// 	                        {0,0,0,0,0}
	// 	                        };

    // example 2
	vector<vector<int>> grid = {
		                        {1,1,0,0,0},
		                        {1,1,0,0,0},
		                        {0,0,1,0,0},
		                        {0,0,0,1,1}
		                        };

	// example 3 
	// vector<vector<int>> grid = {
 //                                {1,1,1,1,1,1,1}
	//                             };

    cout<<" printing the grid vector :- "<<endl;
    int i,j,k,u,v,x,y,z;

    for (i=0;i<grid.size();i++)
    {
    	for (j=0;j<grid[i].size();j++)
    		cout<<grid[i][j]<<" ";
    	cout<<endl;
    }
    cout<<endl;

    int answer = maxAreaOfIsland(grid);

    cout<<" answer = "<<answer<<endl;
}