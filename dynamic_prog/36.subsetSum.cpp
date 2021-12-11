#include<iostream>
#include<vector>
using namespace std;

// dp video 36
// subset sum problem - given array of n elements and a value m, we have to tell whether the subset of array constitute to form given value or not 
// time complexity - o(n * m)
// space complexty -  o(n * m)


int subsetSum(int a[],int n,int m)
{
	int i,j,k,x,y,u,v;

	bool temp[n][m+1];

	for (i=0;i<n;i++)
		temp[i][0]=true;

	for (i=0;i<n;i++)
	{
		for (j=1;j<=m;j++)
		{
			if (i==0)
			{
				if (j==a[i])
					temp[i][j]=true;
				else
					temp[i][j]=false;
			}
			else
			{
				if (j<a[i])
					temp[i][j]=temp[i-1][j];
				else
					temp[i][j] = temp[i-1][j] | temp[i-1][j-a[i]];
			}
		}
	}

	// printing the temp matrix
	cout<<" printing the temp matrix "<<endl;
	for (i=0;i<n;i++)
	{
		for (j=0;j<=m;j++)
			cout<<temp[i][j]<<" ";
		cout<<endl;
	}

	if (temp[n-1][m] == true)
	{
      vector<int> vp;
      vector<int> vind;

      x=n-1;
      y=m;

      while(true)
      {
      	if(y==0)
      		break;
      	else
      	{
      		if ((x==0) && (temp[x][y] == true) && (y==a[x]))
      		{
      			y=y-a[x];
      			vp.push_back(a[x]);
      			vind.push_back(x);
      		}
      		else if (temp[x][y] == temp[x-1][y] && temp[x][y] == true)
      		{
              x=x-1;
      		}
      		else if ( (temp[x][y] == temp[x-1][y-a[x]]) && temp[x][y] == true)
      		{
             vp.push_back(a[x]);
             vind.push_back(x);
             y=y-a[x];
             x=x-1;
      		}
      	}
      }

      // printing the elements that form the given value
      cout<<" printing the elements that form given value m -- "<<m<<endl;
      for (i=vp.size()-1;i>=0;i--)
      	cout<<"value at index -- "<<vind[i]<<" is -- "<<vp[i]<<endl;

	}

	return temp[n-1][m];
}

int main()
{
	int i,j;

	// int a[] = {2,3,7,8,10};
	// int m = 11;
	int a[] = {3,5,6,8,9,10};
	int m = 17;
	int n = sizeof(a)/sizeof(a[0]);
	

	cout<<" subset sum problem "<<endl;
	cout<<" elements of the array -- "<<endl;
	for (i=0;i<n;i++)
	cout<<a[i]<<" ";
	cout<<endl;
	cout<<" value to be checked -- "<<m<<endl;
	cout<<endl;

	int answer = subsetSum(a,n,m);
	if (answer == true)
		cout<<"subset of given array sum up to produce given value ."<<endl;
	else
		cout<<"subset of given array do not sum up to produce given value ."<<endl;
}