#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// dynamic programming video 7
// coin change bottom up - minimum number of coin to form particular value
// space complexity - o(n)
// time complexity - o(n*n)

int minval(int a,int b)
{
	if(a<b)
	 return a;
	else
	 return b;	
}

void printSolution(int result[],int coin[],int m,int n)
{
	int i,j,k;
	int count[n]={0};

	int start=m;

	while(start!=0)
	{
		if(start==0)
			break;

		k=result[start];

		count[k]++;

		start=start-coin[k];
	}

    // printing the coin and their count
    cout<<"get coin and their count contributing to given value m"<<endl;
	for (i=0;i<n;i++)
	{
		if (count[i] != 0)
		{
			cout<<"for coin of val - "<<coin[i]<<" , count = "<<count[i]<<endl;
		}
	}
}

int coinChangeBottomUp(int coin[],int n,int m)
{
 int i,j,k,u,v,x;

 int total[m+1];
 int result[m+1];

 int maxv = 100*m;

 for(i=0;i<=m;i++)
 {
   if(i==0)
   {
    total[i]=0;
    result[i]=-1;
   }
   else
   {
    total[i]=maxv;
    result[i]=-1;
   }
 }

 // printing initial value of total and result array
 cout<<"initially print total array "<<endl;

 for(i=0;i<=m;i++)
 	cout<<total[i]<<" ";

 cout<<endl;

 cout<<"initially print result array "<<endl;

 for(i=0;i<=m;i++)
 	cout<<result[i]<<" ";

 cout<<endl;

 // main code
 for (i=0;i<n;i++)
 {
 	for (j=1;j<=m;j++)
 	{
 		if(j>=coin[i])
 		{
 			if(total[j]>(1+total[j-coin[i]]) && total[j-coin[i]]!=maxv)
 			{
 				total[j]=1+total[j-coin[i]];
 				result[j]=i;
 			}
 		}
 	}
 }

  // printing final value of total and result array
 cout<<"finally print total array "<<endl;

 for(i=0;i<=m;i++)
 	cout<<total[i]<<" ";

 cout<<endl;

 cout<<"finally print result array "<<endl;

 for(i=0;i<=m;i++)
 	cout<<result[i]<<" ";

 cout<<endl;

 int answer = total[m];

 printSolution(result,coin,m,n);

 return answer;

}

int main()
{
	int m=13;
	int coin[]= {7,2,3,6};
	int n = 4;
	int answer = coinChangeBottomUp(coin,n,m);
	cout<<"answer = "<<answer<<endl;
}