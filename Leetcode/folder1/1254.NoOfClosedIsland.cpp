#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

bool isMove(vector<vector<int>>& grid,vector<vector<int>>& visited,int row,int col)
{
	int n = grid.size();
	int m = grid[0].size();

	// cout<<" hello in  isMove function"<<endl;

	return ((row>=0) && (col>=0) && (row<n) && (col<m) && (!grid[row][col]) && (!visited[row][col]));
}

void DFS(vector<vector<int>>& grid,vector<vector<int>>& visited,int row,int col,vector<pair<int,int>>& vland)
{
	int n = grid.size();
	int m = grid[0].size();

	// cout<<" hello in dfs function"<<endl;

	int x1[4] = {0 ,-1, 0, 1};
	int y1[4] = {-1, 0, 1, 0};

	visited[row][col] = 1;
	vland.push_back(make_pair(row,col));

	int i,j,k,u,v;

	for (i=0;i<4;i++)
	{
		if (isMove(grid,visited,row+x1[i],col+y1[i]))
			DFS(grid,visited,row+x1[i],col+y1[i],vland);
	}
}

bool checkIland(vector<pair<int,int>>& vland,int n,int m)
{
	int i,j,k,u,v,x,y;
	pair<int,int> p1,p2,p3;

	bool val = true;

	for (i=0;i<vland.size();i++)
	{
		p1 = vland[i];
		x = p1.first;
		y = p1.second;

		if (x==0 || x==(n-1) || y==0 || y==(m-1))
			return false;
	}

	return true;
}

int closedIsland(vector<vector<int>>& grid)
{
  if (grid.size()==0)
  	return 0;

  int i,j,k,u,v,x,y,z;

  int n = grid.size();
  int m = grid[0].size();

  // cout<<" hello1"<<endl;

  vector<vector<int>> visited;
  vector<int> temp;

  for (i=0;i<n;i++)
  {
  	for (j=0;j<m;j++)
  		temp.push_back(0);

  	visited.push_back(temp);
  	temp.clear();
  }

  // cout<<" hello2"<<endl;

  vector<pair<int,int>> vland;

  pair<int,int> p1,p2;

  int count = 0;

  bool ilval;

  for (i=0;i<n;i++)
  {
  	for (j=0;j<m;j++)
  	{
  		if (grid[i][j]==0 && visited[i][j]==0)
  		{
  			DFS(grid,visited,i,j,vland);

  			// cout<<" Elements of island starting with i = "<<i<<" and j = "<<j<<endl;

  			// for (k=0;k<vland.size();k++)
  			// {
  			// 	p1 = vland[k];
  			// 	x = p1.first;
  			// 	y = p1.second;
  			// 	if (k==vland.size()-1)
  			// 		cout<<"  ("<<x<<" , "<<y<<") ";
  			// 	else
  			// 		cout<<"  ("<<x<<" , "<<y<<") , ";
  			// }
  			// cout<<endl;
  			// cout<<endl;

  			ilval = checkIland(vland,n,m);

  			if (ilval)
  				count++;

  			vland.clear();
  		}
  	}
  }

  return count;
}

int main()
{
	cout<<" 1254. Number of Closed Islands "<<endl;

	// vector<vector<int>> grid = {{1,1,1,1,1,1,1,0},
	//                             {1,0,0,0,0,1,1,0},
	//                             {1,0,1,0,1,1,1,0},
	//                             {1,0,0,0,0,1,0,1},
	//                             {1,1,1,1,1,1,1,0}};

	// vector<vector<int>> grid = {{0,0,1,0,0},
 //                                {0,1,0,1,0},
 //                                {0,1,1,1,0}};

	vector<vector<int>> grid = {{1,1,1,1,1,1,1},
                                {1,0,0,0,0,0,1},
                                {1,0,1,1,1,0,1},
                                {1,0,1,0,1,0,1},
                                {1,0,1,1,1,0,1},
                                {1,0,0,0,0,0,1},
                                {1,1,1,1,1,1,1}};

	int i,j,k,u,v,x,y;

	cout<<" Elements of the grid --- "<<endl;
	for (i=0;i<grid.size();i++)
	{
		for (j=0;j<grid[i].size();j++)
			cout<<grid[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;

	int answer = closedIsland(grid);
	cout<<endl;
	cout<<" answer = "<<answer<<endl;
}