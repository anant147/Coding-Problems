#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// dynamic programming video 12
// cutting rod problem - so to maximize profit
// time complexity - o (n*length)

int max(int a,int b)
{
	if(a<b)
		return b;
	else
		return a;
}

void printSolution(vector<vector<int>> vtemp,int profit[],int length,int n)
{
	int count[n]={0};

	int i,j,k;

	i=n-1;
	j=length;
	int cond=1;

	while(cond==1)
	{
		if(j==0 || i== -1)
			break;
		else if ((i!=0) && (vtemp[i][j]==vtemp[i-1][j]))
			i=i-1;
		else
		{
			k=i;
			j=j-i-1;
			count[i]++;

			if (j==0)
			{
				cond=0;
				break;
			}
		}

	}

	// cout<<"i = "<<i<<endl;
 
 // printing distribution of rod 
 cout<<"printing distribution of rod length and its profit "<<endl;
 for (i=0;i<n;i++)
 {
 	if (count[i]!=0)
 	{
 		// cout<<"hello 5 "<<endl;
 		cout<<"for i = "<<(i+1)<<" , rod pieces count = "<<count[i]<<" , with profit -- "<<profit[i]<<" * "<<count[i]<<" = "<<(profit[i]*count[i])<<endl;
 	}
 }


}

int cuttingRod(int profit[],int n,int length)
{
 int i,j,k;
 int temp[n][length+1];

 for(i=0;i<n;i++)
 	temp[i][0]=0;

 // main code
 for(i=0;i<n;i++)
 {
 	for(j=1;j<=length;j++)
 	{
 		if(i==0)
 		{
         temp[i][j]=temp[i][j-i-1]+profit[i];
 		}
 		else
 		{
         if (j<=i)
         	temp[i][j]=temp[i-1][j];
         else
         	temp[i][j]=max(temp[i-1][j],temp[i][j-i-1]+profit[i]);
 		}
 	}
 }

 // printing the temp matrix
 cout<<"printing the temp matrix --"<<endl;

 for (i=0;i<n;i++)
 {
 	for (j=0;j<=length;j++)
 		cout<<temp[i][j]<<" ";
 	cout<<endl;
 }
 cout<<endl;

 k=temp[n-1][length];

 vector<vector<int>> vtemp;

 for (i=0;i<n;i++)
 {
 	vector<int> v;
 	for(j=0;j<=length;j++)
 		v.push_back(temp[i][j]);

 	vtemp.push_back(v);
 	v.clear();
 }

  for (i=0;i<n;i++)
 {
 	for (j=0;j<=length;j++)
 		cout<<vtemp[i][j]<<" ";
 	cout<<endl;
 }
 cout<<endl;

 
 // int count[n];

 // for(i=0;i<n;i++)
 // 	count[i]=0;

 printSolution(vtemp,profit,length,n);

 return k;
}

int main()
{
	int length=5;
	int profit[]={2,5,7,8};
	int n=4;

	cout<<"length = "<<length<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"for len = "<<(i+1)<<" , profit = "<<profit[i]<<endl;
	}
	cout<<endl;

	int answer = cuttingRod(profit,n,length);
	cout<<"answeer = "<<answer<<endl;
}

