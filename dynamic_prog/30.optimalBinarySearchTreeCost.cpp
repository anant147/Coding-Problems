#include<iostream>
#include <vector>
#include <cmath>
using namespace std;

// dynamic programming video 30
//  minimum cost of searching  keys in optimal binary search tree for given aray of keys and frequency of n elements
// time complexity - o ( n*n*n )
//  space complexity - o ( n*n )

int optimalBinarySearchTreeCost(int keys[],int freq[],int n)
{
	int i,j,k,u,v,x,y,val,len;

	int sum[n][n] = {0};
	int cost[n][n] = {0};
	int tracer[n][n];

	int maxvl = pow(2,sizeof(int)*8-1)-1;

	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
			tracer[i][j]=-1;
	}

	for (i=0;i<n;i++)
	{
		val=0;
		for (j=i;j<n;j++)
		{
			val=val+freq[j];
			sum[i][j]=val;
		}
	}

	for(i=0;i<n;i++)
		cost[i][i]=freq[i];

	// main code 
	for (len=2;len<=n;len++)
	{
		for (i=0;i<(n-len+1);i++)
		{
			j=i+len-1;
            cost[i][j]=maxvl;

			for (k=i;k<=j;k++)
			{
				if (k==i)
					x=0;
				else
					x=cost[i][k-1];

				if (k==j)
					y=0;
				else
					y=cost[k+1][j];

				val = x+y+sum[i][j];
				// cout<<"for i ="<<i<<" , j = "<<j<<" , k = "<<k<<" , val = "<<val<<endl;

				if (val < cost[i][j])
				{
					cost[i][j]=val;
					tracer[i][j]=k;
				}
			}

		}
	}

	int answer = cost[0][n-1];

    // printing the sum matrix 
    cout<<" printing the sum matrix --- "<<endl;
    for (i=0;i<n;i++)
    {
    	for (j=0;j<n;j++)
    		cout<<sum[i][j]<<" ";
    	cout<<endl;
    }

    cout<<endl;

    // printing the cost matrix 
    cout<<" printing the cost matrix -- "<<endl;
    for (i=0;i<n;i++)
    {
    	for (j=0;j<n;j++)
    		cout<<cost[i][j]<<"  ";
    	cout<<endl;
    }
    cout<<endl;

    // printing the tracer matrix 
    cout<<" printing the tracer matrix -- "<<endl;
    for (i=0;i<n;i++)
    {
    	for (j=0;j<n;j++)
    		cout<<tracer[i][j]<<" ";
    	cout<<endl;
    } 
    cout<<endl;
	return answer;
}

int main()
{
	int i,j,k;

	// int keys[] = {10,12,16,21};
	// int freq[] = {4,2,6,3};

	int keys[] = {8,10,12,15,18,21};
	int freq[] = {5,4,3,1,4,1};

	int n = sizeof(freq)/sizeof(freq[0]);
	cout<<" minimum cost of searching  keys in optimal binary search tree "<<endl;
	cout<<" number of keys -- "<<n<<endl;
	cout<<" keys array -- "<<endl;
	for (i=0;i<n;i++)
		cout<<keys[i]<<" ";
	cout<<endl;
	cout<<" freq array --- "<<endl;
	for (i=0;i<n;i++)
		cout<<freq[i]<<" ";
	cout<<endl;
	cout<<endl;

	int answer = optimalBinarySearchTreeCost(keys,freq,n);

	cout<<" final answer = "<<answer<<endl;


}