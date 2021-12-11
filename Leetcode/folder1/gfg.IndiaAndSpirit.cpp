#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
using namespace std;

int bfsForCities(vector<vector<int>>& citymap, vector<vector<int>>& tempvisit,pair<int,int>& point, int n, int m)
{
	int i,j,k,u,v,x,y;

	queue<pair<int,int>> q1;
	// vector<pair<int,int>> tvect;

	int count = 0;

	pair<int,int> point1,point2;
	int px1,px2,px;
	int py1,py2,py;

	px1 = point.first;
	py1 = point.second;

	tempvisit[px1][py1]=1;
	q1.push(point);
	count++;

	while(!q1.empty())
	{
		point1 = q1.front();
		q1.pop();

		px = point1.first;
		py = point1.second;

		if ((px-1)>=0 && (py-1)>=0 && citymap[px-1][py-1]==1 && tempvisit[px-1][py-1]==0)
		{
			q1.push(make_pair(px-1,py-1));
			tempvisit[px-1][py-1]=1;
			count++;
		}

		if ((px-1)>=0 && citymap[px-1][py]==1 && tempvisit[px-1][py]==0)
		{
			q1.push(make_pair(px-1,py));
			tempvisit[px-1][py]=1;
			count++;
		}

		if ((px-1)>=0 && (py+1)<m && citymap[px-1][py+1]==1 && tempvisit[px-1][py+1]==0)
		{
			q1.push(make_pair(px-1,py+1));
			tempvisit[px-1][py+1]=1;
			count++;
		}

		if ((py-1)>=0 && citymap[px][py-1]==1 && tempvisit[px][py-1]==0)
		{
			q1.push(make_pair(px,py-1));
			tempvisit[px][py-1]=1;
			count++;
		}

		if ((py+1)<m  && citymap[px][py+1]==1 && tempvisit[px][py+1]==0)
		{
			q1.push(make_pair(px,py+1));
			tempvisit[px][py+1]=1;
			count++;
		}

		if ((px+1)<n && (py-1)>=0 && citymap[px+1][py-1]==1 && tempvisit[px+1][py-1]==0)
		{
			q1.push(make_pair(px+1,py-1));
			tempvisit[px+1][py-1]=1;
			count++;
		}

		if ((px+1)<n && citymap[px+1][py]==1 && tempvisit[px+1][py]==0)
		{
			q1.push(make_pair(px+1,py));
			tempvisit[px+1][py]=1;
			count++;
		}

		if ( (px+1)<n && (py+1)<m && citymap[px+1][py+1]==1 && tempvisit[px+1][py+1]==0)
		{
			q1.push(make_pair(px+1,py+1));
			tempvisit[px+1][py+1]=1;
			count++;
		}
	}

	return count;

}

int maxCities(vector<vector<char>>& a, int n, int m)
{
	int i,j,k,u,v,x,y,z;

	if (n==1 && m==1)
		return 0;

	vector<vector<int>> tempvisit, citymap;

	tempvisit.resize(n, vector<int> (m,0));
	citymap.resize(n, vector<int> (m,0));

	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
		{
			if (a[i][j]=='*')
			{
				citymap[i][j]=2;

				if ((i-1)>=0 && (j-1)>=0 && a[i-1][j-1]!='*')
					citymap[i-1][j-1]=1;

				if ((i-1)>=0 && a[i-1][j]!='*')
					citymap[i-1][j]=1;

				if ( (i-1)>=0 && (j+1)<m && a[i-1][j+1]!='*')
					citymap[i-1][j+1]=1;

				if ((j-1)>=0 && a[i][j-1]!='*')
					citymap[i][j-1]=1;

				if ((j+1)<m && a[i][j+1]!='*')
					citymap[i][j+1]=1;

				if ((i+1)<n && (j-1)>=0 && a[i+1][j-1]!='*')
					citymap[i+1][j-1]=1;

				if ((i+1)<n && a[i+1][j]!='*')
					citymap[i+1][j]=1;

				if ((i+1)<n && (j+1)<m && a[i+1][j+1]!='*')
					citymap[i+1][j+1]=1;
			}
		}
	}

	cout<<endl;
	cout<<" printing the citymap :- "<<endl;
	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
			cout<<citymap[i][j]<<" ";
		cout<<endl;
	}

	cout<<endl;

	int maxval = 0;

	int val;

	pair<int,int> point;

	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
		{
			if (citymap[i][j]==1 && tempvisit[i][j]==0)
			{
				point = make_pair(i,j);
				val = bfsForCities(citymap,tempvisit,point,n,m);

				if (maxval < val)
					maxval = val;
			}
		}
	}


	return maxval;
}

int main()
{
	cout<<" India and its Spirituality "<<endl;
	int n = 5;
	int m = 5;
	vector<vector<char>> a = {{'.','.','.','.','*'},
	                          {'.','.','.','.','.'},
	                          {'.','.','*','.','.'},
	                          {'.','.','.','.','.'},
	                          {'.','.','.','.','.'}};

	int i,j,k;

	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}

	int answer = maxCities(a,n,m);

	cout<<" answer = "<<answer<<endl;
}