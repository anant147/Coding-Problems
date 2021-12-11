#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#include<utility>
using namespace std;

vector<pair<int,int>> getWaterPointOfGrid(vector<vector<int>>& grid,vector<vector<int>>& watcheck,pair<int,int>& point,int n,int m)
{
    int i,j,k,u,v,x,y,z;

    queue<pair<int,int>> q1;
    vector<pair<int,int>> vtemp;

    pair<int,int> ptemp;
    int px,py;

    int px1 = point.first;
    int py1 = point.second;

    watcheck[px1][py1]=1;

    q1.push(point);
    vtemp.push_back(point);

    while(!q1.empty())
    {
        ptemp = q1.front();
        q1.pop();

        px = ptemp.first;
        py = ptemp.second;

        if ((px-1)>=0 && grid[px-1][py]==0 && watcheck[px-1][py]==0)
        {
            watcheck[px-1][py]=1;
            q1.push(make_pair(px-1,py));
            vtemp.push_back(make_pair(px-1,py));
        }

        if ((py-1)>=0 && grid[px][py-1]==0 && watcheck[px][py-1]==0)
        {
            watcheck[px][py-1]=1;
            q1.push(make_pair(px,py-1));
            vtemp.push_back(make_pair(px,py-1));
        }

        if ((px+1)<n && grid[px+1][py]==0 && watcheck[px+1][py]==0)
        {
            watcheck[px+1][py]=1;
            q1.push(make_pair(px+1,py));
            vtemp.push_back(make_pair(px+1,py));
        }

        if ((py+1)<m && grid[px][py+1]==0 && watcheck[px][py+1]==0)
        {
            watcheck[px][py+1]=1;
            q1.push(make_pair(px,py+1));
            vtemp.push_back(make_pair(px,py+1));
        }
    }

    return vtemp;
}

int absolute(int a)
{
    if (a<0)
        return (-1)*a;
    return a;
}

vector<pair<int,int>> getLandPointOfGrid(vector<vector<int>>& grid,vector<vector<int>>& landcheck,vector<pair<int,int>>& watpoint,int n,int m)
{
    vector<pair<int,int>> landpoint;
    pair<int,int> ptemp;

    int i,j,k,u,v,x,y,z;

    int px,py;

    for (i=0;i<watpoint.size();i++)
    {
        ptemp = watpoint[i];
        px = ptemp.first;
        py = ptemp.second;

        if ((px-1)>=0 && grid[px-1][py]==1 && landcheck[px-1][py]==0)
        {
            landpoint.push_back(make_pair(px-1,py));
            landcheck[px-1][py]=1;
        }

        if ((py-1)>=0 && grid[px][py-1]==1 && landcheck[px][py-1]==0)
        {
            landpoint.push_back(make_pair(px,py-1));
            landcheck[px][py-1]=1;
        }

        if ((px+1)<n && grid[px+1][py]==1 && landcheck[px+1][py]==0)
        {
            landpoint.push_back(make_pair(px+1,py));
            landcheck[px+1][py]=1;
        }

        if ((py+1)<m && grid[px][py+1]==1 && landcheck[px][py+1]==0)
        {
            landpoint.push_back(make_pair(px,py+1));
            landcheck[px][py+1]=1;
        }
    }

    return landpoint;
}


int maxDistance(vector<vector<int>>& grid)
{
    int i,j,k,u,v,x,y,z;

    int n = grid.size();
    int m = grid[0].size();

    int cond1 = 0;
    int cond2 = 0;
    int cond3 = 0;

    for (i=0;i<n;i++) // checking for all zeros
    {
        for (j=0;j<m;j++) 
        {
            if (grid[i][j]==1)
            {
                cond1=1;
                break;
            }
        }

        if (cond1==1)
            break;
    }

    if (cond1==0)
        return -1;

    for (i=0;i<n;i++)  // checking for all ones
    {
        for (j=0;j<m;j++)
        {
            if (grid[i][j]==0)
            {
                cond2=1;
                break;
            }
        }

        if (cond2==1)
            break;
    }

    if (cond2==0)
        return -1;


    pair<int,int> point,point1,point2;
    int px,px1,px2;
    int py,py1,py2;

    vector<vector<int>> watcheck,landcheck;

    watcheck.resize(n, vector<int> (m,0));
    landcheck.resize(n, vector<int> (m,0));

    vector<pair<int,int>> watpoint,landpoint;

    int maxval = 0;
    int minval;
    int val;

    for (i=0;i<n;i++)
    {
        for (j=0;j<m;j++)
        {
            if (grid[i][j]==0 && watcheck[i][j]==0)
            {
                point = make_pair(i,j);

                watpoint = getWaterPointOfGrid(grid,watcheck,point,n,m);

                landpoint = getLandPointOfGrid(grid,landcheck,watpoint,n,m);


                for (u=0;u<landpoint.size();u++)
                {
                    point1 = landpoint[u];
                    px1 = point1.first;
                    py1 = point1.second;

                    landcheck[px1][py1]=0;
                }

                // main computation
                for (u=0;u<watpoint.size();u++)
                {
                    point1 = watpoint[u];
                    px1 = point1.first;
                    py1 = point1.second;

                    minval = pow(2,sizeof(int)*8-1)-1;

                    for (v=0;v<landpoint.size();v++)
                    {
                        point2 = landpoint[v];
                        px2 = point2.first;
                        py2 = point2.second;

                        val = absolute(px1-px2) + absolute(py1-py2);

                        if (minval > val)
                            minval = val;

                        if (minval==1)
                            break;
                    }

                    if (maxval < minval)
                        maxval = minval;
                }

                landpoint.clear();
                watpoint.clear();
            }
        }
    }

    return maxval;
}

int main()
{
	cout<<" 1162. As Far from Land as Possible "<<endl;

    // example 1
    // vector<vector<int>> grid = {{1,0,1},{0,0,0},{1,0,1}};

    // example 2
    vector<vector<int>> grid = {{1,0,0},{0,0,0},{0,0,0}};

    cout<<" printing the grid vector :- "<<endl;
    int i,j,k,u,v,x,y,z;

    for (i=0;i<grid.size();i++)
    {
        for (j=0;j<grid[i].size();j++)
            cout<<grid[i][j]<<" ";
        cout<<endl;
    }

    int answer = maxDistance(grid);

    cout<<" answer = "<<answer<<endl;
}