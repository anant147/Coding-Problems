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

int findGrp(vector<vector<int>>& mstor, int val)
{
	if (mstor[val][0] != val)
		mstor[val][0] = findGrp(mstor, mstor[val][0]);

	return mstor[val][0];
}

void unionGrp(vector<vector<int>>& mstor,int x , int y)
{
	int px = findGrp(mstor,x);
	int py = findGrp(mstor,y);

	if (mstor[px][1] < mstor[py][1])
	{
		mstor[px][0] = py;
	}
	else if (mstor[px][1] > mstor[py][1])
	{
		mstor[py][0] = px;
	}
	else
	{
		mstor[py][0] = px;
		mstor[px][1]++;
	}
}

int findCircleNum(vector<vector<int>>& M)
{
	int i,j,k,u,v,x,y,z;

	int n = M.size();

	if (n==1)
		return 1;

	// vector<int> result;
	// result.resize(n,-1);

	vector<vector<int>> mstor;
	mstor.resize(n,vector<int> (2,0));

	for (i=0;i<n;i++)
		mstor[i][0]=i;

	for (i=0;i<n;i++)
	{
		for (j=i+1;j<n;j++)
		{
			if (M[i][j]==1)
			{
				x = findGrp(mstor,i);
				y = findGrp(mstor,j);

				if (x != y)
				{
					unionGrp(mstor,i,j);
				}
			}
		}
	}

	int count = 0;

	for (i=0;i<n;i++)
	{
		if (mstor[i][0]==i)
			count++;
	}
	
	return count;
}

int main()
{
	cout<<" 547. Friend Circles "<<endl;

	// example 1
	// vector<vector<int>> M = {
	// 	                    {1,1,0},
	// 	                    {1,1,0},
	// 	                    {0,0,1}
	// 	                    };

	// example 2
	vector<vector<int>> M = {
		                    {1,1,0},
		                    {1,1,1},
		                    {0,0,1}
		                    };

    int answer = findCircleNum(M);

    cout<<" answer = "<<answer<<endl;


}