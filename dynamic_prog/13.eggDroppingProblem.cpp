#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// dynamic programming video 13
// egg dropping problem - so to minimize number of attempts to find from which floor , on dropping eggs will break
// time complexity - o (n*k*k)
// space complexity - o (n*k*k)

int maxval(int a,int b)
{
	if(a<b)
		return b;
	else
		return a;
}

int minval(int a,int b)
{
	if(a<b)
		return a;
	else
		return b;
}

int eggDroppingProblem(int n,int k)
{
	int i,j,m,x,u,answer,res;

	int temp[n+1][k+1];

	for(i=0;i<=k;i++)
		temp[0][i]=0;

	for(i=1;i<=n;i++)
	{
		temp[i][0]=0;
		temp[i][1]=1;
	}

	for(i=1;i<=k;i++)
		temp[1][i]=i;


    // main code
	for(i=2;i<=n;i++) // outer loop
	{
		for(j=2;j<=k;j++) // inner loop
		{
          if(i>j)
          temp[i][j]=temp[i-1][j];
          else
          {
          	res=2*k;

          	for (x=1;x<=j;x++) // third loop
          	{
             u=1+maxval(temp[i-1][x-1],temp[i][j-x]);
             res=minval(res,u);
             // cout<<"for i -"<<i<<" ,j = "<<j<<" , x = "<<res<<endl;
          	}

          	temp[i][j]=res;
          	// cout<<endl;
          } 
		}
	}

	// printing the temp matrix
	cout<<"print the temp matrix"<<endl;

	for(i=0;i<=n;i++)
	{
		for (j=0;j<=k;j++)
			cout<<temp[i][j]<<" ";
		cout<<endl;
	}

	answer = temp[n][k];
	return answer;
}

int main()
{
	// int n=2; // eggs
	// int k=6; // floors
	// int n = 2;
	// int k = 10;

	int n=4;
	int k=7;

    cout<<"egg dropping problem "<<endl;
	cout<<"eggs = "<<n<<endl;
	cout<<"floors = "<<k<<endl;

	int answer = eggDroppingProblem(n,k);

	cout<<"answer = "<<answer<<endl;
}