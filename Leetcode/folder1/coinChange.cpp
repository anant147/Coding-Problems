#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int coinsChange(vector<int>& coins, int amount) 
{
	int i,j,k,u,v,x,y,answer;

	int n=coins.size();
	int m=amount;

	int temp[n][m+1];
	bool check[n][m+1];

	for (i=0;i<n;i++)
	{
		for (j=0;j<=m;j++)
		{
			if (j==0)
				check[i][j]=true;
			else
				check[i][j]=false;

			temp[i][j]=0;
		}
	}

	sort(coins.begin(),coins.end());

	for (i=0;i<n;i++)
	{
		for (j=1;j<=m;j++)
		{
			if (i==0)
			{      
              if (j>=coins[i])
              {
              	if (check[i][j-coins[i]])
              	{
              		check[i][j]=true;
              		temp[i][j]=1+temp[i][j-coins[i]];
              	}
              }
			}
			else
			{
				if (j<coins[i])
				{
					check[i][j]=check[i-1][j];
					temp[i][j]=temp[i-1][j];
				}
				else
				{
                   if (check[i-1][j] && check[i][j-coins[i]])
                   {
                       if (temp[i-1][j] < (1+temp[i][j-coins[i]]))
                       {
                       	  check[i][j]=true;
                       	  temp[i][j]=temp[i-1][j];
                       }
                       else
                       {
                       	check[i][j]=true;
                       	temp[i][j]=1+temp[i][j-coins[i]];
                       }
                   }
                   else if (check[i][j-coins[i]])
                   {
                   	   check[i][j]=true;
                   	   temp[i][j]=1+temp[i][j-coins[i]];
                   }
                   else if (check[i-1][j])
                   {
                   	   check[i][j]=true;
                   	   temp[i][j]=temp[i-1][j];
                   }
				}
			}
		}
	}

	// cout<<" printing temp matrix -- "<<endl;
	// for (i=0;i<n;i++)
	// {
	// 	for (j=0;j<=m;j++)
	// 		cout<<temp[i][j]<<" ";
	// 	cout<<endl;
	// }
	// cout<<endl;

	// cout<<" printing check matrix -- "<<endl;
	// for (i=0;i<n;i++)
	// {
	// 	for (j=0;j<=m;j++)
	// 		cout<<check[i][j]<<" ";
	// 	cout<<endl;
	// }
	// cout<<endl;

	if (check[n-1][m])
		answer=temp[n-1][m];
	else
		answer=-1;

	return answer;    
}

int main()
{
	int i,j,k;
	// vector<int> coins = {1,2,5};
	// int amount = 11;

	vector<int> coins = {2};
	int amount = 3;

	cout<<" 322. coins change problem -- "<<endl;
	cout<<" value of the coins -- "<<endl;
	for (i=0;i<coins.size();i++)
	cout<<coins[i]<<" ";
	cout<<endl;
	cout<<" amount = "<<amount<<endl;

	int answer = coinsChange(coins,amount);

	cout<<" answer = "<<answer<<endl;

}