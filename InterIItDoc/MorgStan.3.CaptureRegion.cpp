#include<bits/stdc++.h>
using namespace std;

void regionCapture(vector<vector<int>>& matrix, vector<vector<int>>& visited, int x, int y)
{
	visited[x][y] = 1;

	int n = matrix.size();
	int m = matrix[0].size();

	int xshift[4] = {-1, 0, 1, 0};
	int yshift[4] = { 0,-1, 0, 1};

	queue< pair<int,int>> q;
	q.push(make_pair(x,y));

	vector< pair<int,int> > vtemp;
	vtemp.push_back(make_pair(x,y));

	pair<int,int> ptemp;

	int cond = 0;

	while (!q.empty())
	{
		ptemp = q.front();
		q.pop();

		int a = ptemp.first;
		int b = ptemp.second;

		for (int i=0;i<4;i++)
		{
			int c = a+xshift[0];
			int d = b+yshift[0];

			if ( (0<=c && c<n) && (0<=d && d<m) && !visited[c][d] && !matrix[c][d])
			{
				visited[c][d] = 1;
				q.push(make_pair(c,d));
				vtemp.push_back( make_pair(c,d));

				if (c==0 || c==n-1 || d==0 || d==m-1)
				{
					cond=1;
				} 
			}
		}

		if (cond == 1)
			break;
	}

	if (cond == 1)
		vtemp.clear();
	else
	{
		for (int i=0;i<vtemp.size();i++)
		{
			int a = vtemp[i].first;
			int b = vtemp[i].second;

			matrix[a][b] = 1;
		}

		vtemp.clear();
	}
}

void capture(vector<vector<int>>& matrix)
{
	int n = matrix.size();
	int m = matrix[0].size();

	vector<vector<int>> visited;
	visited.resize(n, vector<int> (m,0));

	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
		{
			if (matrix[i][j] == 1)
				visited[i][j] = 1;
			else
			{
				if (i==0 || i==n-1 || j==0 || j==m-1)
					visited[i][j] = 1;
				else
				{
					regionCapture(matrix, visited, i, j);
				}
			}
		}
	}
}

int main()
{
	cout<<" Morgan Stanley 3"<<endl;
	cout<<" Capture Regions on Board "<<endl;
	cout<<endl;

	vector<vector<int>> matrix = {
		                         {1,1,1,1},
		                         {1,0,0,1},
		                         {1,1,0,1},
		                         {1,0,1,1}
		                         };

    cout<<" printing the matrix before function :- "<<endl;
    for (int i=0;i<matrix.size();i++)
    {
    	for (int j=0;j<matrix[i].size();j++)
    		cout<<matrix[i][j]<<" ";
    	cout<<endl;
    }
    cout<<endl;

    capture(matrix);

    cout<<endl;
    cout<<" printing the matrix after function :- "<<endl;
    for (int i=0;i<matrix.size();i++)
    {
    	for (int j=0;j<matrix[i].size();j++)
    		cout<<matrix[i][j]<<" ";
    	cout<<endl;
    }
    cout<<endl;


}