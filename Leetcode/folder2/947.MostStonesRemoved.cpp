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

int findGrp(vector<vector<int>>& stor, int x)
{
	if (stor[x][0] != x)
		stor[x][0] = findGrp(stor, stor[x][0]);

	return stor[x][0];
}

void unionGrp( vector<vector<int>>& stones, vector<vector<int>>& stor, int x, int y)
{
	int px = findGrp(stor, x);
	int py = findGrp(stor, y);

	int cond = 0;

	if (stones[x][0]==stones[y][0] || stones[x][1]==stones[y][1])
		cond = 1;

	if (stones[px][0]==stones[y][0] || stones[px][1]==stones[y][1])
		cond = 1;

	if (stones[x][0]==stones[py][0] || stones[x][1]==stones[py][1])
		cond = 1;

	if (cond == 1)
	{
		stor[py][0] = px;
	}
}

int removeStones(vector<vector<int>>& stones)
{
	int i,j,k,u,v,x,y,z;

	int n = stones.size();

	if (n==1)
		return 0;

	vector<vector<int>> stor;
	stor.resize(n,vector<int>(2,0));

	for (i=0;i<n;i++)
		stor[i][0] = i;

	for (i=0;i<stones.size();i++)
	{
		for (j=i+1; j<stones.size();j++)
		{
			x = findGrp(stor, i);
			y = findGrp(stor, j);

			if (x != y)
			{
				unionGrp(stones, stor, i, j);
			}
		}
	}

	int count = 0;

	for (i=0;i<n;i++)
	{
		if (stor[i][0]==i)
			count++;
	}

	return (n-count);
}

int main()
{
	cout<<" 947. Most Stones Removed with Same Row or Column "<<endl;

	// example1
	// vector<vector<int>> stones = {
	// 	                         {0,0},
	// 	                         {0,1},
	// 	                         {1,0},
	// 	                         {1,2},
	// 	                         {2,1},
	// 	                         {2,2}
	// 	                         };

    // example 2
	// vector<vector<int>> stones = {
	// 	                         {0,0},
	// 	                         {0,2},
	// 	                         {1,1},
	// 	                         {2,0},
	// 	                         {2,2}
	// 	                         };

	// example 3	                         
	vector<vector<int>> stones = {{0,0}};

    cout<<" printing the stones vector :- "<<endl;

    for (int i=0;i<stones.size();i++)
    	cout<<stones[i][0]<<" , "<<stones[i][1]<<endl;
    cout<<endl;

    int answer = removeStones(stones);

    cout<<" answer = "<<answer<<endl;
}