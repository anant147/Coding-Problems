#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;

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
		if (i==0 && (px-1)>=0 && (matrix[px][py]<matrix[px-1][py]) && tempvisit[px-1][py]==0)
		{
			
			if (pathlen[px-1][py]!=0 )
				val = len1+pathlen[px-1][py];
			else
			{
				point = make_pair(px-1,py);
				val = dfsForNum(matrix,pathlen,dir,tempvisit,point,len1,n,m);
			}

			if (maxval < val)
				maxval = val;
		}

		if (i==1 && (py-1)>=0 && (matrix[px][py]<matrix[px][py-1]) && tempvisit[px][py-1]==0)
		{
			if (pathlen[px][py-1]!=0 )
				val = len1+pathlen[px][py-1];
			else
			{
				point = make_pair(px,py-1);
				val = dfsForNum(matrix,pathlen,dir,tempvisit,point,len1,n,m);
			}

			if (maxval < val)
				maxval = val;
		}

		if (i==2 && (px+1)<n && (matrix[px][py]<matrix[px+1][py]) && tempvisit[px+1][py]==0)
		{
			if (pathlen[px+1][py]!=0 )
				val = len1+pathlen[px+1][py];
			else
			{
				point = make_pair(px+1,py);
				val = dfsForNum(matrix,pathlen,dir,tempvisit,point,len1,n,m);
			}

			if (maxval < val)
				maxval = val;
		}

		if (i==3 && (py+1)<m && (matrix[px][py]<matrix[px][py+1]) && tempvisit[px][py+1]==0)
		{
			if (pathlen[px][py+1]!=0)
				val = len1+pathlen[px][py+1];
			else
			{
				point = make_pair(px,py+1);
				val = dfsForNum(matrix,pathlen,dir,tempvisit,point,len1,n,m);
			}

			if (maxval < val)
				maxval = val;
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


	int maxval = 0;

	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
		{
			point = make_pair(i,j);

			val = dfsForNum(matrix,pathlen,dir,tempvisit,point,0,n,m);

			pathlen[i][j] = val;

			if (maxval < pathlen[i][j])
				maxval = pathlen[i][j];
		}
	}

	cout<<endl;
	cout<<" printing the pathlen vector :- "<<endl;
	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
			cout<<pathlen[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;

	return maxval;
}

int main()
{
	cout<<" 329. Longest Increasing Path in a Matrix "<<endl;

	// example 1
	// vector<vector<int>> matrix = {
	//                           {9,9,4},
	//                           {6,6,8},
	//                           {2,1,1}
	//                           };

	// example 2
	// vector<vector<int>> matrix = {
	//                           {3,4,5},
	//                           {3,2,6},
	//                           {2,2,1}
	//                           };

	// example 3
	// vector<vector<int>> matrix = {{7,8,9},{9,7,6},{7,2,3}};

	// example 4
	vector<vector<int>> matrix = {{0,1,2,3,4,5,6,7,8,9},
	                              {19,18,17,16,15,14,13,12,11,10},
	                              {20,21,22,23,24,25,26,27,28,29},
	                              {39,38,37,36,35,34,33,32,31,30},
	                              {40,41,42,43,44,45,46,47,48,49},
	                              {59,58,57,56,55,54,53,52,51,50},
	                              {60,61,62,63,64,65,66,67,68,69},
	                              {79,78,77,76,75,74,73,72,71,70},
	                              {80,81,82,83,84,85,86,87,88,89},
	                              {99,98,97,96,95,94,93,92,91,90},
	                              {100,101,102,103,104,105,106,107,108,109},
	                              {119,118,117,116,115,114,113,112,111,110},
	                              {120,121,122,123,124,125,126,127,128,129},
	                              {139,138,137,136,135,134,133,132,131,130},
	                              {0,0,0,0,0,0,0,0,0,0}};                          

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


##############################################################################################################333

#include<iostream>
#include<vector>
#include<utility>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

bool sortVect(const vector<int>& v1,const vector<int>& v2)
{
	return (v1[1]>v2[1]);
}

bool topoSort(vector<int> rel[], vector<int>& group, vector<int>& visited, vector<int>& tempvisit, stack<int>& st, int point, int n)
{
	int i,j,k,u,v,x,y,z;

	visited[point] = 1;
	tempvisit[point] = 1;

	int gval1 = group[point];
	int gval2;

	bool cond=true;
	bool temp;

	for (i=0;i<rel[point].size();i++)
	{
		k = rel[point][i];
		gval2 = group[k];

		if (gval1==gval2)
		{
			if (visited[k]==0)
			{
				temp = topoSort(rel,group,visited,tempvisit,st,k,n);

				if (temp == false)
					cond= false;
			}
			else
			{
				if (tempvisit[k]==1)
				{
					temp = false;
					cond = false;
				}
			}
		}

		if (cond==false)
			return false;
	}

	tempvisit[point] = 0;

	st.push(point);

	return true;
}

vector<int> sortItems(int n,int m, vector<int>& group, vector<vector<int>>& beforeItems)
{
	int i,j,k,u,v,x,y,z;

	vector<int> rel[n];

	for (i=0;i<beforeItems.size();i++)
	{
		for (j=0;j<beforeItems[i].size();j++)
		{
			k = beforeItems[i][j];

			rel[k].push_back(i);
		}
	}

	// cout<<" printing the rel vector :-"<<endl;

	// for (i=0;i<n;i++)
	// {
	// 	cout<<" for i = "<<i<<endl;
	// 	for (j=0;j<rel[i].size();j++)
	// 		cout<<rel[i][j]<<" ";
	// 	cout<<endl;
	// }
	// cout<<endl;

	vector<int> grel[m+1];

	for (i=0;i<n;i++)
	{
		k = group[i];

		grel[k+1].push_back(i);
	}

	// cout<<" printing the grel vector :- "<<endl;
	// for (i=0;i<=m;i++)
	// {
	// 	cout<<" for i = "<<(i-1)<<endl;
	// 	for (j=0;j<grel[i].size();j++)
	// 	{
	// 		cout<<grel[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	// cout<<endl;

	vector<int> temp;
	vector<vector<int>> vtemp;

	for (i=0;i<=m;i++)
	{
		temp = grel[i];
		for (j=0;j<temp.size();j++)
		{
			u = grel[i][j];
			v = rel[u].size();
			vtemp.push_back({u,v});
		}

		sort(vtemp.begin(),vtemp.end(),sortVect);

		grel[i].clear();
		temp.clear();

		for (j=0;j<vtemp.size();j++)
			grel[i].push_back(vtemp[j][0]);

		vtemp.clear();
	}

	// cout<<" printing the grel vector :- "<<endl;
	// for (i=0;i<=m;i++)
	// {
	// 	cout<<" for i = "<<(i-1)<<endl;
	// 	for (j=0;j<grel[i].size();j++)
	// 	{
	// 		cout<<grel[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	// cout<<endl;

	stack<int> st;
	vector<int> visited,tempvisit;
	visited.resize(n,0);
	tempvisit.resize(n,0);

	bool cond;

	for (i=0;i<=m;i++)
	{
		for (j=0;j<grel[i].size();j++)
		{
			k = grel[i][j];

			if (visited[k]==0)
			{
				cond = topoSort(rel, group, visited, tempvisit, st,k,n);

				if (cond==false)
					return {};
			}
		}
	}

	if (st.size()!=n)
		return {};
	else
	{
		vector<int> answer;

		while(!st.empty())
		{
			k = st.top();
			answer.push_back(k);
			st.pop();
		}

		return answer;
	}
}

int main()
{
	cout<<" 1203. Sort Items by Groups Respecting Dependencies "<<endl;

	// example 1
	// int i,j,k,u,v;
	// int n = 8;
	// int m = 2;
	// vector<int> group = {-1,-1,1,0,0,1,0,-1};
	// vector<vector<int>> beforeItems = {
	// 	                              {},
	// 	                              {6},
	// 	                              {5},
	// 	                              {6},
	// 	                              {3,6},
	// 	                              {},
	// 	                              {},
	// 	                              {}
	// 	                              };

	// example 2
	// int i,j,k,u,v;
	// int n = 8;
	// int m = 2;
	// vector<int> group = {-1,-1,1,0,0,1,0,-1};
	// vector<vector<int>> beforeItems = {
	// 	                              {},
	// 	                              {6},
	// 	                              {5},
	// 	                              {6},
	// 	                              {3},
	// 	                              {},
	// 	                              {4},
	// 	                              {}
	// 	                              };

	// example 3
    // int n = 4;
    // int m = 1;
    // vector<int> group = {-1,0,0,-1};
    // vector<vector<int>> beforeItems = {
    // 	                              {},
    // 	                              {0},
    // 	                              {1,3},
    // 	                              {2}
    // 	                               };                       

    cout<<" n = "<<n<<endl;
    cout<<" m = "<<m<<endl;
    cout<<" printing the group val :-"<<endl;
    for (i=0;i<n;i++)
    	cout<<group[i]<<" ";
    cout<<endl;
    cout<<" printing the beforeItems vector :- "<<endl;
    for (i=0;i<n;i++)
    {
    	cout<<" for i :-"<<i<<endl;
    	for (j=0;j<beforeItems[i].size();j++)
    		cout<<beforeItems[i][j]<<" ";
    	cout<<endl;
    }
    cout<<endl;

    vector<int> answer = sortItems(n,m,group,beforeItems);

    if (answer.size()==0)
    	cout<<" size of answer vector is zero"<<endl;
    else
    {
	    cout<<" printing the answer vector :-"<<endl;
	    for (i=0;i<answer.size();i++)
	    	cout<<answer[i]<<" ";
	    cout<<endl;
    }

}