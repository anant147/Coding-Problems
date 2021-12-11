#include<iostream>
#include<vector>
using namespace std;

// dp video 34
// staircase fibannoci series problem - given number of stairs , we have to tell the number of ways in which we can reach given stair if 
// at particular time , we can jump 1 stair or 2 stairs.
// time complexity - o(n)
// space complexty - o(1) { or o(n) if we make use of array }

int staircaseFibannoci1(int n)
{
	int i;

	if (n<=0)
	return 0;
	else if(n==1)
	return 1;
	else if(n==2)
	return 2;
	else
	{
     int f1=1;
     int f2=2;
     int f;

     for (i=3;i<=n;i++)
     {
     f=f1+f2;
     f1=f2;
     f2=f;
     }

     return f;
	}
}

int staircaseFibannoci2(int n)
{
	int i;

	if (n<=0)
	return 0;
	else if(n==1)
	return 1;
	else if(n==2)
	return 2;
	else
	{
     int a[n+1];

     a[0]=0;
     a[1]=1;
     a[2]=2;


     for (i=3;i<=n;i++)
     {
     a[i]=a[i-1]+a[i-2];
     }

     cout<<" printing a array -- "<<endl;

     for (i=0;i<=n;i++)
     	cout<<a[i]<<" ";
     cout<<endl;

     return a[n];
	}
}


int main()
{
	int i,j;

	// int n = 4;
	int n = 8;

	cout<<" staircase fibannoci series problem "<<endl;
	int answer1 = staircaseFibannoci1(n);
	cout<<endl;
	cout<<" answer1 = "<<answer1<<endl;
	cout<<endl;
	int answer2 = staircaseFibannoci2(n);
	cout<<endl;
	cout<<" answer2 = "<<answer2<<endl;

}