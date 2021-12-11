#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<queue>
using namespace std;

vector<pair<int,int>> bfsForBoard(vector<vector<char>>& board,vector<vector<int>>& vcheck,pair<int,int>& point,int n,int m)
{
	queue<pair<int,int>> q1;

	int i,j,k,u,v,x,y,z;

	vector<pair<int,int>> vtemp;

	int cond = 0;

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

		if ((px-1)>=0 && board[px-1][py]=='O' && vcheck[px-1][py]==0)
		{
			vcheck[px-1][py]=1;
			vtemp.push_back(make_pair(px-1,py));
			q1.push(make_pair(px-1,py));
		}

		if ((py-1)>=0 && board[px][py-1]=='O' && vcheck[px][py-1]==0)
		{
			vcheck[px][py-1]=1;
			vtemp.push_back(make_pair(px,py-1));
			q1.push(make_pair(px,py-1));			
		}

		if ((px+1)<n && board[px+1][py]=='O' && vcheck[px+1][py]==0)
		{
			vcheck[px+1][py]=1;
			vtemp.push_back(make_pair(px+1,py));
			q1.push(make_pair(px+1,py));
		}

		if ((py+1)<m && board[px][py+1]=='O' && vcheck[px][py+1]==0)
		{
			vcheck[px][py+1]=1;
			vtemp.push_back(make_pair(px,py+1));
			q1.push(make_pair(px,py+1));			
		}
	}

	for (i=0;i<vtemp.size();i++)
	{
		ptemp = vtemp[i];
		px = ptemp.first;
		py = ptemp.second;

		if (px==0 || py==0 || px==(n-1) || py==(m-1))
		{
			cond=1;
			break;
		}
	}


	if (px1==0 || py1==0 || px1==(n-1) || py1==(m-1))
	{
		cond=1;
	}

	if (cond==1)
	{
		cout<<endl;
		cout<<" for point , x1 = "<<px1<<" , y1 = "<<py1<<" , not a part of Surrounded  Regions "<<endl;
		cout<<endl;
		vtemp.clear();
	}
	else
	{
		cout<<endl;
		cout<<" for point , x1 = "<<px1<<" , y1 = "<<py1<<" ,  a part of Surrounded  Regions "<<endl;
		cout<<endl;
		vtemp.push_back(make_pair(px1,py1));
	}

	return vtemp;
}

void solve(vector<vector<char>>& board)
{
	int i,j,k,u,v,x,y,z;

	int n = board.size();

	if (n<=2)
		return;

	int m = board[0].size();

	if (m<=2)
		return;

	vector<vector<int>> vcheck;
	vcheck.resize(n,vector<int> (m,0));

	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
			cout<<vcheck[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;

	vector<pair<int,int>> vtemp;

	pair<int,int> point;
	pair<int,int> ptemp;
	int px,py;

	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
		{
			if (board[i][j]=='O' && vcheck[i][j]==0)
			{
				point = make_pair(i,j);
				vtemp = bfsForBoard(board,vcheck,point,n,m);

				if (vtemp.size()!=0)
				{
					for (k=0;k<vtemp.size();k++)
					{
						ptemp = vtemp[k];
						px = ptemp.first;
						py = ptemp.second;

						board[px][py]='X';
					}
					vtemp.clear();
				}
			}
		}
	}


}

int main()
{
	cout<<" 130. Surrounded Regions "<<endl;

	vector<vector<char>> board =  {
		                          {'X','X','X','X'},
	                              {'X','O','O','X'},
	                              {'X','X','O','X'},
	                              {'X','O','X','X'}
	                              };

	cout<<" content in the board :- "<<endl;
	int i,j,k,u,v,x,y,z;

	for (i=0;i<board.size();i++)
	{
		for (j=0;j<board[i].size();j++)
			cout<<board[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;

	solve(board);
}