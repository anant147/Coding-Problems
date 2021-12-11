#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// dynamic programming video 8
// coin change bottom up approach - minimum number of coin to form particular value
// time complexity - o (n*m)
// space complexity - o (n*m)

int minval(int a,int b)
{
	if (a<b)
		return a;
	else
		return b;
}

void printSolution(vector<vector<int>> vtemp,int coin[],int n,int m)
{
	int count[n]={0};

	int i,j;

	i=n-1;
	j=m;

	while(true)
	{
		if(j==0 || i== -1)
			break;
		else if ((i!=0) && vtemp[i][j]==vtemp[i-1][j])
			i=i-1;
		else
		{
			j=j-coin[i];
			count[i]++;
		}

	}
    
    // print the contribution of coin
    cout<<"coin distribution for given m"<<endl;
	for (i=0;i<n;i++)
	{
		if (count[i]!=0)
			cout<<"for i = "<<i<<" , coin val = "<<coin[i]<<" , count - "<<count[i]<<endl;
	}
}

int coinChangeBottomUp2(int coin[],int n,int m)
{
	int i,j,k,answer,u,v,l;

	int temp[n][m+1];

	for (i=0;i<n;i++)
		temp[i][0]=0;

	int maxval = m*1000;
    
    cout<<"maxval - "<<maxval<<" , represent infinity"<<endl;
    // main code
	for(i=0;i<n;i++)
	{
		for (j=1;j<=m;j++)
		{
			if (i==0)
			{
				if (j<coin[i])
					temp[i][j]=maxval;
				else if (j==coin[i])
				{
					temp[i][j]=1;
				}
				else
				  {
				  	if (temp[i][j-coin[i]]!=0)
				  		temp[i][j]=1+temp[i][j-coin[i]];
				  	else
				  		temp[i][j]=maxval;

				  }
			}
			else
			{
              if (j<coin[i])
              	temp[i][j]=temp[i-1][j];
              else
              	temp[i][j]=min(temp[i-1][j],1+temp[i][j-coin[i]]);
			}
		}
	}

	// print the temp matrix
	cout<<"print the temp matrix "<<endl;

	for(i=0;i<n;i++)
	{
		for(j=0;j<=m;j++)
			cout<<temp[i][j]<<" ";
		cout<<endl;
	}

	 answer = temp[n-1][m];

	 vector<vector<int>> vtemp;

	 for (i=0;i<n;i++)
	 {
	 	vector<int> v;

	 	for (j=0;j<=m;j++)
	 	{
	 		v.push_back(temp[i][j]);
	 	}
	 	vtemp.push_back(v);
	 	v.clear();
	 }

	printSolution(vtemp,coin,n,m);
	return answer;
}


int main()
{
	// int coin[]={1,5,6,8};
	int coin[]={2,5,6,8};
	int n = 4;
	int m = 11;
	cout<<"print the parameters "<<endl;
	cout<<"n = "<<n<<endl;
	cout<<"m = "<<m<<endl;
	cout<<"coin array - "<<endl;
	for (int i=0;i<n;i++)
		cout<<coin[i]<<" ";
	cout<<endl;

	int answer = coinChangeBottomUp2(coin,n,m);
	cout<<"answer = "<<answer<<endl;
}