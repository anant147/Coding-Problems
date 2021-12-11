#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<queue>
using namespace std;

void bfsForGrid(vector<vector<char>>& grid,vector<vector<int>>& vcheck,pair<int,int>& point,int n,int m)
{
	int i,j,k,u,v,x,y,z;

	queue<pair<int,int>> q1;
	pair<int,int> ptemp;
	int px,py;

	q1.push(point);
	int px1 = point.first;
	int py1 = point.second;

	vcheck[px1][py1]=1;

	while(!q1.empty())
	{
		ptemp = q1.front();
		q1.pop();

		px = ptemp.first;
		py = ptemp.second;

		if ((px-1)>=0 && grid[px-1][py]=='1' && vcheck[px-1][py]==0)
		{
			q1.push(make_pair(px-1,py));
			vcheck[px-1][py]=1;
		}

	    if ((py-1)>=0 && grid[px][py-1]=='1' && vcheck[px][py-1]==0)
		{
			q1.push(make_pair(px,py-1));
			vcheck[px][py-1]=1;
		}

		if ((px+1)<n && grid[px+1][py]=='1' && vcheck[px+1][py]==0)
		{
			q1.push(make_pair(px+1,py));
			vcheck[px+1][py]=1;
		}

	    if ((py+1)<m && grid[px][py+1]=='1' && vcheck[px][py+1]==0)
		{
			q1.push(make_pair(px,py+1));
			vcheck[px][py+1]=1;
		}
	}
}

int numIslands(vector<vector<char>>& grid)
{
	int i,j,k,u,v,x,y,z;

	int n = grid.size();

	if (n==0)
		return 0;

	int m = grid[0].size();

	if (n==1 && m==1)
	{
		if (grid[0][0]=='0')
			return 0;
		else
			return 1;
	}

	vector<vector<int>> vcheck;
	vcheck.resize(n,vector<int> (m,0));

	int count=0;
	pair<int,int> point;
	int px,py;

	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
		{
			if (grid[i][j]=='1' && vcheck[i][j]==0)
			{
				cout<<" i = "<<i<<" , j = "<<j<<endl;
				point = make_pair(i,j);
				bfsForGrid(grid,vcheck,point,n,m);
				count++;
			}
		}
	}

	return count;
}

int main()
{
	cout<<" 200. Number of Islands :- "<<endl;

	// example 1
	// vector<vector<char>> grid = {
	// 	                        {'1','1','1','1','0'},
	// 	                        {'1','1','0','1','0'},
	// 	                        {'1','1','0','0','0'},
	// 	                        {'0','0','0','0','0'}
	// 	                        };

    // example 2
	// vector<vector<char>> grid = {
	// 	                        {'1','1','0','0','0'},
	// 	                        {'1','1','0','0','0'},
	// 	                        {'0','0','1','0','0'},
	// 	                        {'0','0','0','1','1'}
	// 	                        };

	// example 3 
	vector<vector<char>> grid = {
                                {'1','1','1','1','1','1','1'}
	                            };

    cout<<" print the grid vector :- "<<endl;
    int i,j,k,u,v,x,y;

    for (i=0;i<grid.size();i++)
    {
    	for (j=0;j<grid[i].size();j++)
    		cout<<grid[i][j]<<" ";
    	cout<<endl;
    }
    cout<<endl;

    int answer = numIslands(grid);
    cout<<" answer = "<<answer<<endl;
}