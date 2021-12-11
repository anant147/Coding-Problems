#include<iostream>
#include<vector>
#include<cmath>
#include<utility>
using namespace std;

long long countArray(int n,int k,int x)
{
	long long i,j,u,v;
	long long answer;

	if (n==0)
		return 0;
	else if (n==1 || n==2)
		return 1;

	long long arr1[n];
	long long arr2[n];
	long long marr[n];

	long long mod = pow(10,9)+7;

	arr1[0]=1;
	arr2[0]=0;
	marr[0]=1;

	for (i=1;i<n;i++)
	{
		if (i==1)
		{
			arr1[1]=0;
			arr2[1]=1;
			marr[1]=k-1;
		}
		else
		{
			marr[i] = (marr[i-1]*(k-1))%mod;
			arr1[i] = (arr2[i-1]*(k-1))%mod;

			if (i%2==1)
				arr2[i] = (arr1[i] + 1) % mod;
			else
				arr2[i] = (arr1[i] - 1) % mod;
		}
	}

	// print arr1 , arr2 and marr array
	cout<<" printing arr1 array -- "<<endl;
	for (i=0;i<n;i++)
		cout<<arr1[i]<<" ";
	cout<<endl;

	cout<<" printing arr2 array -- "<<endl;
	for (i=0;i<n;i++)
		cout<<arr2[i]<<" ";
	cout<<endl;

	cout<<" printing marr array -- "<<endl;
	for (i=0;i<n;i++)
		cout<<marr[i]<<" ";
	cout<<endl;

	cout<<endl;

	if (x==1)
		answer = (marr[n-2]-arr1[n-2])%mod;
	else
		answer = (marr[n-2]-arr2[n-2])%mod;

	return answer;
}

int main()
{
	// int n=4;
	// int k=3;
	// int x=1;

	int n=4;
	int k=6;
	int x=1;



	cout<<" count array --- "<<endl;
	cout<<" n = "<<n<<endl;
	cout<<" k = "<<k<<endl;
	cout<<" x = "<<x<<endl;

	cout<<endl;

	long long answer = countArray(n,k,x);

	cout<<" answer = "<<answer<<endl;
}