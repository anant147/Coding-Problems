#include <iostream>
#include <vector>
using namespace std;

// dynamic programming video 29
//  find the numbers without consecutive ones in binary representation from 0 to 2^n-1 , for given n
// time complexity - o ( n )
// case 1 --- space complexity - o ( 1 )
// case 2 --- space complexity - o ( n )

int numberWoutCiveOnesInBinRep1(int n)
{
	int i,j,k;

	if (n<=0)
	return 1;

	if (n==1)
	return 2;

	int f0=1;
	int f1=2;
	int f;

	for (i=2;i<=n;i++)
	{
	  f=f1+f0;
	  f0=f1; f1=f;
	}

	cout<<"final answer = "<<f<<endl;
	return f;
}

int numberWoutCiveOnesInBinRep2(int n)
{
	int i,j,k;

	if (n<=0)
		return 1;

	if (n==1)
		return 2;

	int temp[n+1];

	temp[0]=1;
	temp[1]=2;

	for (i=2;i<=n;i++)
	{
		temp[i]=temp[i-1]+temp[i-2];
	}

	// printing the temp matrix 
	for (i=0;i<=n;i++)
		cout<<temp[i]<<" ";
	cout<<endl;

	return temp[n];
}

int main()
{
	// int n=4;
	// int n=10;
	int n = 20;
	cout<<" find the numbers without consecutive ones in binary representation from 0 to 2^n-1 , for given n "<<endl;
	cout<<" value of n = "<<endl;
	int answer1 = numberWoutCiveOnesInBinRep1(n);
	cout<<" answer1 = "<<answer1<<endl;
    cout<<endl;
	int answer2 = numberWoutCiveOnesInBinRep2(n);
	cout<<" answer2 = "<<answer2<<endl;
}