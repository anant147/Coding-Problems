#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// dynamic programming video 8
// coin change bottom up approach -  number of ways to form given value


// time complexity - o (n*m)
// space complexity - o (n*m)
int totalWayGetCoinValue1(int coin[],int n,int m)
{
	int i,j,k,u,answer;

	int temp[n][m+1];

	cout<<"function 1 - with space complexity -  o (n*m) "<<endl;

	for (int i = 0; i < n; ++i)
	{
		temp[i][0]=1;
	}

	// main code
	for (i=0;i<n;i++)
	{
		for (j=1;j<=m;j++)
		{
			if (j < coin[i])
			{
				if (i==0)
					temp[i][j]=0;
				else
					temp[i][j]=temp[i-1][j];
			}
			else
			{
				if (i==0)
				{
					temp[i][j]=temp[i][j-coin[i]];
				}
				else
					temp[i][j]=temp[i][j-coin[i]]+temp[i-1][j];
			}
		}
	}

	// print temp matrix
	cout<<"printing temp matrix "<<endl;
	for (i = 0; i < n; ++i)
	{
		for(j=0;j<=m;j++)
			cout<<temp[i][j]<<" ";
		cout<<endl;
	}

	answer = temp[n-1][m];

	return answer;
}


// time complexity - o (n*m)
// space complexity - o (m)
int totalWayGetCoinValue2(int coin[],int n,int m)
{
	int i,j,k,u,answer;

	int temp[m+1];

	cout<<"function 2 - with space complexity -  o (m) "<<endl;

	temp[0]=1;

	// main code
	for (i=0;i<n;i++)
	{
		for (j=1;j<=m;j++)
		{
			if (j < coin[i])
			{
				if (i==0)
					temp[j]=0;
			}
			else
			{
				if (i==0)
				{
					temp[j]=temp[j-coin[i]];
				}
				else
					temp[j]=temp[j-coin[i]]+temp[j];
			}
		}
	}

	// print temp matrix
	cout<<"printing temp array "<<endl;
	for (i = 0; i<=m; ++i)
	{
	cout<<temp[i]<<" ";
	}

	cout<<endl;

	answer = temp[m];

	return answer;
}

int main()
{
	
	int coin[]={1,2,3};
	// int coin[]={4,1,2};
	int n = 3;
	int m = 5;
	cout<<"print the parameters "<<endl;
	cout<<"n = "<<n<<endl;
	cout<<"m = "<<m<<endl;
	cout<<"coin array - "<<endl;
	for (int i=0;i<n;i++)
		cout<<coin[i]<<" ";
	cout<<endl;

	int answer1 = totalWayGetCoinValue1(coin,n,m); // space complexity - o(n*m)
	cout<<"answer1 = "<<answer1<<endl;

	int answer2 = totalWayGetCoinValue2(coin,n,m); // space complexity - o (m)
	cout<<"answer2 = "<<answer2<<endl;
}
