#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
#include<cstring>
using namespace std;

int minkey(int key[], bool mstSet[], int n)
{
	int i,j;

	int min = pow(2,sizeof(int)*8-1)-1;

	int index = -1;

	for (i=0;i<n;i++)
	{
		if (mstSet[i]==false && min>key[i])
		{
			index = i;
			min = key[i];
		}
	}

	return index;
}

void printMST(int parent[], int n, int *graph)
{
	int i,j,k,u,v,x,y,z;

	for (i=1;i<n;i++)
	{
		u = parent[i];
		k = *((graph+i*n)+u);

		cout<<u<<" , "<<i<<" , "<<k<<endl;
	}
	cout<<endl;
}

void primMST(int n, int *graph)
{
	int i,j,k,u,v,x,y,z;

	int parent[n];
	int key[n];
	bool mstSet[n];

	int maxval = pow(2,sizeof(int)*8-1)-1;

	for (i=0;i<n;i++)
	{
		key[i] = maxval; mstSet[i] = false;
	}

	key[0] = 0;
	parent[0] = -1;

	for (i=0;i<(n-1);i++)
	{
		u = minkey(key,mstSet,n);
		cout<<u<<endl;

		mstSet[u] = true;

		for (j=0;j<n;j++)
		{
			k = *((graph+u*n)+j);

			if (k!=0 && mstSet[j]==false && key[j]>k)
			{
				key[j] = k;
				parent[j] = u;
			}
		}
	}



	printMST(parent, n,graph);
}

int main()
{
	cout<<" tp3 Minimum Spanning tree by prim algo - o(n*n) method "<<endl;

	int n = 5;

	int graph[n][n] =   {
	                    { 0, 2, 0, 6, 0 }, 
                        { 2, 0, 3, 8, 5 }, 
                        { 0, 3, 0, 0, 7 }, 
                        { 6, 8, 0, 0, 9 }, 
                        { 0, 5, 7, 9, 0 }
                        };

    primMST(n,(int *)graph); 
}