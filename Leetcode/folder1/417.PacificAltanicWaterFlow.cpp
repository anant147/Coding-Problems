#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<queue>
using namespace std;

bool bfsForPacificAtlantic(vector<vector<int>>& matrix, vector<vector<int>>& canvisit, vector<vector<int>>& tempvisit, pair<int,int>& point, int n, int m)
{
	int i,j,k,u,v,x,y,z;

	vector<pair<int,int>> vtemp;
	queue<pair<int,int>> q1;
	pair<int,int> point1,point2;

	int px,px1,px2;
	int py,py1,py2;

	px1 = point.first;
	py1 = point.second;

	tempvisit[px1][py1]=1;
	vtemp.push_back(point);
	q1.push(point);

	int cond1=0;
	int cond2=0;

	while(!q1.empty())
	{
		point1 = q1.front();
		q1.pop();

		px = point1.first;
		py = point1.second;

		if (canvisit[px][py]==1)
		{
			cond1=1;
			cond2=1;
			break;
		}

		if (px==0 || py==0)
			cond1=1;

		if (px==(n-1) || py==(m-1))
			cond2=1;

		if (cond1==1 && cond2==1)
			break;

		if ((px-1)>=0 && tempvisit[px-1][py]==0 && matrix[px][py]>=matrix[px-1][py])
		{
			tempvisit[px-1][py]=1;
			vtemp.push_back(make_pair(px-1,py));
			q1.push(make_pair(px-1,py));
		}

		if ((py-1)>=0 && tempvisit[px][py-1]==0 && matrix[px][py]>=matrix[px][py-1])
		{
			tempvisit[px][py-1]=1;
			vtemp.push_back(make_pair(px,py-1));
			q1.push(make_pair(px,py-1));
		}

		if ((px+1)<n && tempvisit[px+1][py]==0 && matrix[px][py]>=matrix[px+1][py])
		{
			tempvisit[px+1][py]=1;
			vtemp.push_back(make_pair(px+1,py));
			q1.push(make_pair(px+1,py));
		}

		if ((py+1)<m && tempvisit[px][py+1]==0 && matrix[px][py]>=matrix[px][py+1])
		{
			tempvisit[px][py+1]=1;
			vtemp.push_back(make_pair(px,py+1));
			q1.push(make_pair(px,py+1));
		}
	}

	for (i=0;i<vtemp.size();i++)
	{
		point1 = vtemp[i];
		px = point1.first;
		py = point1.second;

		tempvisit[px][py] = 0;
	}

	if (cond1==1 && cond2==1)
		return true;
	else
		return false;
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix)
{
	int i,j,k,u,v,x,y,z;

	int n = matrix.size();
	int m = matrix[0].size();

	vector<vector<int>> canvisit;
	vector<vector<int>> tempvisit;

	canvisit.resize(n, vector<int> (m,0));
	tempvisit.resize(n, vector<int> (m,0));

	canvisit[0][m-1]=1;
	canvisit[n-1][0]=1;

	vector<vector<int>> result;
	vector<int> temp;

	pair<int,int> point,point1,point2;
	int px,px1,px2;
	int py,py1,py2;

	bool val;

	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
		{
			if (canvisit[i][j]==1)
			{
				temp.push_back(i);
				temp.push_back(j);
				result.push_back(temp);
				temp.clear();
			}
			else
			{
				point = make_pair(i,j);
				val = bfsForPacificAtlantic(matrix,canvisit,tempvisit,point,n,m);

				if (val==true)
				{
					canvisit[i][j]=1;
					temp.push_back(i);
					temp.push_back(j);
					result.push_back(temp);
					temp.clear();
				}
			}
		}
	}

	return result;
}

int main()
{
	cout<<" 417. Pacific Atlantic Water Flow "<<endl;

	vector<vector<int>> matrix = {
                                 {1,2,2,3,5},
                                 {3,2,3,4,4},
                                 {2,4,5,3,1},
                                 {6,7,1,4,5},
                                 {5,1,1,2,4}
	                             };

	int i,j,k;

	for (i=0;i<matrix.size();i++)
	{
		for (j=0;j<matrix[i].size();j++)
			cout<<matrix[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;

	vector<vector<int>> answer = pacificAtlantic(matrix);

	cout<<" answer of given question is :- "<<endl;
	for (i=0;i<answer.size();i++)
	{
		for (j=0;j<answer[i].size();j++)
			cout<<answer[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;

}