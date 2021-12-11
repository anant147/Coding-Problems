#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int uniquePaths(int m,int n)
{
	int i,j,k,u,v,x,y,answer;

	int temp[n][m];

	for (i=0;i<n;i++)
		temp[i][0]=1;

	for (i=0;i<m;i++)
		temp[0][i]=1;

	for (i=1;i<n;i++)
	{
		for (j=1;j<m;j++)
		{
			temp[i][j]= temp[i][j-1] + temp[i-1][j];
		}
	}

	cout<<" print temp matrix -- "<<endl;
	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
			cout<<temp[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;

	return temp[n-1][m-1];
}

int main()
{
	int i,j,k;
	// int m=3;
	// int n=2;

	int m=7;
	int n=3;

	

	cout<<" unique path problem -- "<<endl;
	cout<<" m = "<<m<<endl;
	cout<<" n = "<<n<<endl;

	cout<<endl;
	int answer = uniquePaths(m,n);
	cout<<" answer = "<<answer<<endl;
}