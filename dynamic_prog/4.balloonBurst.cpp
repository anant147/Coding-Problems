#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// dynamic programming video 4
// balloon burst

int max(int a,int b)
{
	if (a<b)
		return b;
	else
		return a;
}

int balloonBurst(int a[],int n)
{
  int i,j,k,len,left,right,after,before,answer;
  int mat[n][n];

  memset(mat,0,sizeof mat); // initializing 0 to whole matrix

  for (len = 1;len<=n;len++)
  {
  	for (i=0;i<=(n-len);i++)
  	{
  		j=i+len-1;

  		for (k=i;k<=j;k++)
  		{
  			left = 1;
  			right = 1;

  			if (i!=0)
  			 left=a[i-1];

  			if(j!=(n-1))
  				right=a[j+1];

  			after=0;
  			before=0;

  			if (i!=k)
  				before = mat[i][k-1];

  			if (j!=k)
  				after = mat[k+1][j];

  			mat[i][j]=max(mat[i][j], after + before + (left * right * a[k]));
  		}
  	}
  }

  // print the matrix obtained by bottom up approach
  for (i=0;i<n;i++)
  {
  	for (j=0;j<n;j++)
  		cout<<mat[i][j]<<" ";

  	cout<<endl;
  }

  answer = mat[0][n-1];
 
  cout<<"answer - "<<answer<<endl;


  return answer;
}

int main()
{
 // int a[]={3,1,5,8};

	int a[]={2,4,3,5};

 int answer = balloonBurst(a,4);

 cout<<"answer - "<<answer<<endl;
}
