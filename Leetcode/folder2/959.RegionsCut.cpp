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

int getline(vector<vector<int>>& vtemp, vector<vector<int>>& visited, int x, int y, int n)
{
	// cout<<" helo1"<<endl;

	int px = x;
	int py = y;

	int i,j,k,u,v,z;

	visited[x][y]=1;

	int cond = 0;

	if (vtemp[x][y]==1)
		cond = 1;
	else
		cond = 2;

	vector<vector<int>> cval1 = {
		                        {0,-1},
	                            {1,0},
	                            {-1,0}
	                            };

	// cout<<" cval1 size( = "<<cval1.size()<<endl;

	vector<vector<int>> cval2 = {{0,1},{1,0}};

	int count = 0;

	if (cond==1)
	{
		if (x==0 || y==(n-1))
			count++;

		// cout<<" helo1"<<endl;

		for (i=0;i<cval1.size();i++)
		{
			// cout<<"ak"<<endl;

			u = x + cval1[i][0];  v = y + cval1[i][1];

			if ( (u>=0 && u<=(n-1) && v>=0 && v<=(n-1)) && visited[u][v]==1 && vtemp[u][v]==2 )
			{
				count++;
			} 
		}

		if (x==(n-1))
			count++;

		// cout<<" helo1"<<endl;

		x = x+1; 
		y = y-1;
	}
	else if (cond == 2)
	{
		if (x==0 || y==0)
			count++;

		for (i=0;i<cval2.size();i++)
		{
			u = x + cval2[i][0];  v = y + cval2[i][1];

			if ( (u>=0 && u<=(n-1)) && (v>=0 && v<=(n-1)) && visited[u][v]==1 && vtemp[u][v]==1 )
			{
				count++;
			} 
		}

		if (x==(n-1))
			count++;

		x = x+1;
		y = y+1;
	}

	if (count>=2)
		return 1;

	while (true)
	{
		if (cond==1)
		{
			// cout<<" helo1"<<endl;

			if ((x>=0 && x<=(n-1)) && (y>=0 && y<=(n-1)) && vtemp[x][y]==1 && visited[x][y]==0)
			{
				visited[x][y] = 1;

				if (x==(n-1) || y==0)
					count++;

				if (count>=2)
				{
					cond=3; break;
				}

				for (i=0;i<cval1.size();i++)
				{
					u = x + cval1[i][0];  v = y + cval1[i][1];

					if ( (u>=0 && u<=(n-1)) && (v>=0 && v<=(n-1)) && visited[u][v]==1 && vtemp[u][v]==2 )
					{
						count++;
					} 
				}

				if (count>=2)
				{
					cond = 3; break;
				}

				x++;
				y--;

			}
			else
				cond = 3;
		}
		else if (cond==2)
		{
			if ((x>=0 && x<=(n-1)) && (y>=0 && y<=(n-1)) && vtemp[x][y]==2 && visited[x][y]==0)
			{
				visited[x][y] = 1;

				if (x==(n-1) || y==(n-1))
					count++;

				if (count>=2)
				{
					cond = 3; break;
				}

				for (i=0;i<cval2.size();i++)
				{
					u = x + cval2[i][0];  v = y + cval2[i][1];

					if ( (u>=0 && u<=(n-1)) && (v>=0 && v<=(n-1)) && visited[u][v]==1 && vtemp[u][v]==1 )
					{
						count++;
					} 
				}

				if (count>=2)
				{
					cond = 3; break;
				}

				x++;
				y--;
			}
			else
				cond = 3;
		}
		else
			break;
	}

	if (count>=2)
		return 1;
	else
		return 0;
}

int regionsBySlashes(vector<string>& grid)
{
	int i,j,k,u,v,x,y,z;

	int n = grid.size();

	vector<vector<int>> vtemp;
	vector<int> temp;

	for (i=0;i<grid.size();i++)
	{
		for (j=0;j<grid[i].size();j++)
		{
			if (grid[i][j]==' ')
				temp.push_back(0);
			else if (grid[i][j]=='/')
				temp.push_back(1);
			else if (grid[i][j]=='\\')
				temp.push_back(2);
		}
		vtemp.push_back(temp);
		temp.clear();
	}

	vector<vector<int>> visited;
	visited.resize(n, vector<int>(n,0));

	int count = 1;

	int val;

	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			if (vtemp[i][j] != 0 && visited[i][j]==0)
			{
				if (vtemp[i][j]==1)
				{
					// cout<<"i = "<<i<<" , j = "<<j<<endl;
					if (i==0 && j==0)
					{
						visited[i][j] = 1;
						count++;
					}
					else if (i==(n-1) && j==(n-1))
					{
						visited[i][j] = 1;
						count++;
					}
					else
					{
						val = getline(vtemp, visited, i,j,n);

						count = count + val;
					}
					// cout<<" count = "<<count<<endl;
				}
				else if (vtemp[i][j]==2)
				{
					// cout<<"i = "<<i<<" , j = "<<j<<endl;

					if (i==0 && j==(n-1))
					{
						visited[i][j] = 1;
						count++;
					}
					else if (i==(n-1) && j==0)
					{
						visited[i][j] = 1;
						count++;
					}
					else
					{
						val = getline(vtemp, visited, i,j, n);

						count = count + val;
					}
					// cout<<" count = "<<count<<endl;
				}

			}

		}
	}

	return count;
}

int main()
{
	cout<<" 959. Regions Cut By Slashes ";

	// example 1
	// vector<string> grid= { " /","/ "};

	// example 2
	// vector<string> grid= {  " /","  "};

	// example 3
	// vector<string> grid= {"\\/","/\\"};

	// example 4
	// vector<string> grid= {  "/\\","\\/"};

	// example 5
	// vector<string> grid = {  "//","/ "};

	// example 6
	vector<string> grid = {"\\/\\ "," /\\/"," \\/ ","/ / "};

	int i,j,k;

	cout<<" printing the grid vector :- "<<endl;

	for ( i=0;i<grid.size();i++)
		cout<<grid[i]<<endl;
	cout<<endl;
	// cout<<endl;

	// cout<<" printing the vtemp vector :- "<<endl;

	// for (i=0;i<vtemp.size();i++)
	// {
	// 	for (j=0;j<vtemp[i].size();j++)
	// 		cout<<vtemp[i][j]<<" ";
	// 	cout<<endl;
	// }
	// cout<<endl;

	int answer = regionsBySlashes(grid);

	cout<<" answer = "<<answer<<endl;


}