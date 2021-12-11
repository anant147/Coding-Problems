#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;

bool SortVector(const vector<int>& v1, const vector<int>& v2)
{
	return (v1[0]>v2[0]);
}

int dfsForNum(vector<vector<int>>& matrix,vector<vector<int>>& pathlen, vector<vector<int>>& dir, vector<vector<int>>& tempvisit, pair<int,int>& point, int len, int n, int m)
{
	int i,j,k,u,v,x,y,z;

	pair<int,int> point1,point2;
	int px,px1,px2;
	int py,py1,py2;

	px = point.first;
	py = point.second;
	tempvisit[px][py]=1;

	int len1 = len+1;

	int maxval = len1;
	int val;

	for (i=0;i<4;i++)
	{
		if (i==0 && (px-1)>=0 && (matrix[px][py]!=matrix[px-1][py]) && tempvisit[px-1][py]==0)
		{
			if (matrix[px][py]<matrix[px-1][py])
			{
				if (pathlen[px-1][py]!=0 )
					val = len1+pathlen[px-1][py];
				else
				{
					point = make_pair(px-1,py);
					val = dfsForNum(matrix,pathlen,dir,tempvisit,point,len1,n,m);
				}

				if (maxval < val)
				{
					maxval = val;
					dir[px][py]=0;
				}
			}
		    else
		    {
		    	if (pathlen[px-1][py]!=0 && dir[px-1][py]==2 && (matrix[px][py]>matrix[px-1][py]) && maxval<(pathlen[px-1][py]-1))
		    	{
		    		maxval = pathlen[px-1][py]-1;
		    	}
		    }
		}

		if (i==1 && (py-1)>=0 && (matrix[px][py]!=matrix[px][py-1]) && tempvisit[px][py-1]==0)
		{
			if (matrix[px][py]<matrix[px][py-1])
			{
				if (pathlen[px][py-1]!=0 )
					val = len1+pathlen[px][py-1];
				else
				{
					point = make_pair(px,py-1);
					val = dfsForNum(matrix,pathlen,dir,tempvisit,point,len1,n,m);
				}

				if (maxval < val)
				{
					maxval = val;
					dir[px][py]=1;
				}
		    }
		    else
		    {
		    	if (pathlen[px][py-1]!=0 && dir[px][py-1]==3 && (matrix[px][py]>matrix[px][py-1]) && maxval<(pathlen[px][py-1]-1))
		    	{
		    		maxval = pathlen[px][py-1]-1;
		    	}		    	
		    }
		}

		if (i==2 && (px+1)<n && (matrix[px][py]!=matrix[px+1][py]) && tempvisit[px+1][py]==0)
		{
			if (matrix[px][py]<matrix[px+1][py])
			{
				if (pathlen[px+1][py]!=0 )
					val = len1+pathlen[px+1][py];
				else
				{
					point = make_pair(px+1,py);
					val = dfsForNum(matrix,pathlen,dir,tempvisit,point,len1,n,m);
				}

				if (maxval < val)
				{
					maxval = val;
					dir[px][py]=2;
				}
		    }
		    else
		    {
		    	if (pathlen[px+1][py]!=0 && dir[px+1][py]==0 &&  (matrix[px][py]>matrix[px+1][py]) && maxval<(pathlen[px+1][py]-1))
		    	{
		    		maxval = pathlen[px+1][py]-1;
		    	}
		    }
		}

		if (i==3 && (py+1)<m && (matrix[px][py]!=matrix[px][py+1]) && tempvisit[px][py+1]==0)
		{
			if (matrix[px][py]<matrix[px][py+1])
			{
				if (pathlen[px][py+1]!=0)
					val = len1+pathlen[px][py+1];
				else
				{
					point = make_pair(px,py+1);
					val = dfsForNum(matrix,pathlen,dir,tempvisit,point,len1,n,m);
				}

				if (maxval < val)
				{
					maxval = val;
					dir[px][py]=3;
				}
		    }
		    else
		    {
		    	if (pathlen[px][py+1]!=0 && dir[px][py+1]==1 && (matrix[px][py]>matrix[px][py+1]) && maxval<(pathlen[px][py+1]-1))
		    	{
		    		maxval = pathlen[px][py+1]-1;
		    	}
		    }
		}
	}

	tempvisit[px][py]=0;

	return maxval;
}

int longestIncreasingPath(vector<vector<int>>& matrix)
{
	int i,j,k,u,v,x,y,z;

	int n = matrix.size();

	if (n==0)
		return 0;

	int m = matrix[0].size();

	if (n==1 && m==1)
		return 1;

	vector<vector<int>> tempvisit;
	vector<vector<int>> pathlen;
	vector<vector<int>> dir;

	tempvisit.resize(n, vector<int> (m,0));
	pathlen.resize(n, vector<int> (m,0));
	dir.resize(n, vector<int> (m,-1));

	pair<int,int> point;

	int val;

	vector<vector<int>> matstor;

	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
		{
			k = matrix[i][j];
			matstor.push_back({k,i,j});
		}
	}

	sort(matstor.begin(),matstor.end(),SortVector);

	// cout<<endl;
	// for (i=0;i<matstor.size();i++)
	// {
	// 	cout<<matstor[i][0]<<" , "<<matstor[i][1]<<" , "<<matstor[i][2]<<endl;
	// }
	// cout<<endl;

	int maxval = 0;

	for (i=0;i<matstor.size();i++)
	{
		u = matstor[i][1];
		v = matstor[i][2];

		point = make_pair(u,v);

		val = dfsForNum(matrix, pathlen, dir, tempvisit, point, 0, n, m);

		pathlen[u][v] = val;

		// cout<<"for u = "<<u<<" , v = "<<v<<" , len = "<<pathlen[u][v]<<endl;

		if (maxval < pathlen[u][v])
			maxval = pathlen[u][v];
	}

	// for (i=0;i<n;i++)
	// {
	// 	for (j=0;j<m;j++)
	// 	{
	// 		point = make_pair(i,j);

	// 		val = dfsForNum(matrix,pathlen,dir,tempvisit,point,0,n,m);

	// 		pathlen[i][j] = val;

	// 		if (maxval < pathlen[i][j])
	// 			maxval = pathlen[i][j];
	// 	}
	// }

	// cout<<endl;
	// cout<<" printing the pathlen vector :- "<<endl;
	// for (i=0;i<n;i++)
	// {
	// 	for (j=0;j<m;j++)
	// 		cout<<pathlen[i][j]<<" ";
	// 	cout<<endl;
	// }
	// cout<<endl;
	// cout<<endl;
	// cout<<" printing the dir vector :- "<<endl;
	// for (i=0;i<n;i++)
	// {
	// 	for (j=0;j<m;j++)
	// 		cout<<dir[i][j]<<" ";
	// 	cout<<endl;
	// }
	// cout<<endl;

	return maxval;
}

int main()
{
	cout<<" 329. Longest Increasing Path in a Matrix "<<endl;
	cout<<" tle de rha h"<<endl;

	// example 1
	vector<vector<int>> matrix = {
	                          {9,9,4},
	                          {6,6,8},
	                          {2,1,1}
	                          };

	// example 2
	// vector<vector<int>> matrix = {
	//                           {3,4,5},
	//                           {3,2,6},
	//                           {2,2,1}
	//                           };

	// example 3
	// vector<vector<int>> matrix = {
	// 	                         {7,8,9},
	// 	                         {9,7,6},
	// 	                         {7,2,3}
	// 	                         };

	// example 4
	// vector<vector<int>> matrix = {{0,1,2,3,4,5,6,7,8,9},
	//                               {19,18,17,16,15,14,13,12,11,10},
	//                               {20,21,22,23,24,25,26,27,28,29},
	//                               {39,38,37,36,35,34,33,32,31,30},
	//                               {40,41,42,43,44,45,46,47,48,49},
	//                               {59,58,57,56,55,54,53,52,51,50},
	//                               {60,61,62,63,64,65,66,67,68,69},
	//                               {79,78,77,76,75,74,73,72,71,70},
	//                               {80,81,82,83,84,85,86,87,88,89},
	//                               {99,98,97,96,95,94,93,92,91,90},
	//                               {100,101,102,103,104,105,106,107,108,109},
	//                               {119,118,117,116,115,114,113,112,111,110},
	//                               {120,121,122,123,124,125,126,127,128,129},
	//                               {139,138,137,136,135,134,133,132,131,130},
	//                               {0,0,0,0,0,0,0,0,0,0}};                          

	cout<<" printing the matrix matrix :- "<<endl;
	int i,j,k;
	for (i=0;i<matrix.size();i++)
	{
		for (j=0;j<matrix[i].size();j++)
			cout<<matrix[i][j]<<" ";
		cout<<endl;
	}

	int answer = longestIncreasingPath(matrix);

	cout<<" answer = "<<answer<<endl;
}