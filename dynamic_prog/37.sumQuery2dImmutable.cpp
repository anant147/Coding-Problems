#include<iostream>
#include<vector>
#include<utility>
#include<cstring>
using namespace std;

// dp video 37
// sum query in 2d array - given 2d matrix , we have to tell the sum in the rectange enclosed by given two points
// time complexity - o(n * m)
// space complexty -  o(n * m)

void sumQuery2dImmutable(int *mat,int n,int m,vector<pair<pair<int,int>,pair<int,int>>> vpoint)
{
 int i,j,k,u,v,x0,x1,y0,y1,val;
 int row1,row2,col1,col2;

 // print the mat in the function
 cout<<" printing the mat in the function - "<<endl;
 for (i=0;i<n;i++)
 {
 	for (j=0;j<m;j++)
 	{
 		val = *((mat+i*m)+j);
 		cout<<val<<" ";
 	}
 	cout<<endl;
 }

 int temp[n+1][m+1];

 for (i=0;i<=n;i++)
 	temp[i][0]=0;

 for (i=1;i<=m;i++)
 	temp[0][i]=0;

 // making the temp array
 for (i=1;i<=n;i++)
 {
 	for (j=1;j<=m;j++)
 	{
 		val = *((mat+(i-1)*m)+j-1);
 		temp[i][j] = temp[i-1][j] + temp[i][j-1] + val - temp[i-1][j-1];
 	}
 }

 cout<<endl;
 // printing the temp matrix
 cout<<" printing the temp matrix "<<endl;
 for (i=0;i<=n;i++)
 {
 	for (j=0;j<=m;j++)
 		cout<<temp[i][j]<<" ";
 	cout<<endl;
 }
 cout<<endl;
 cout<<"solution for the given queries -- "<<endl;
 for (i=0;i<vpoint.size();i++)
 {
 	x0 = vpoint[i].first.first;
 	y0 = vpoint[i].first.second;
 	x1 = vpoint[i].second.first;
 	y1 = vpoint[i].second.second;

 	cout<<"for query no. "<<i<<endl;
 	cout<<" points for the sum query are - ("<<x0<<","<<y0<<") and ("<<x1<<","<<y1<<") "<<endl;

 	if (x0<x1)
 	{
     row2=x1;
     row1=x0;
 	}
 	else
 	{
 	 row2=x0;
 	 row1=x1;
 	}

 	if (y0<y1)
 	{
      col2=y1;
      col1=y0;
 	}
 	else
 	{
 	  col2=y0;
 	  col1=y1;
 	}

 	int answer = temp[row2][col2] - temp[row2][col1-1] - temp[row1-1][col2] + temp[row1-1][col1-1];
 	cout<<"value for this query is "<<answer<<endl;
 	cout<<endl;
 }

}

int main()
{
	int i,j,k;

	int n=4;
	int m=4;

	int mat[n][m] = {{2,0,-3,4},
	                 {6,3,2,-1},
	                 {5,4,7,3},
	                 {2,-6,8,1}};

	cout<<" sum query in 2d array --"<<endl;
	cout<<" row == "<<n<<endl;
	cout<<" col == "<<m<<endl;
	cout<<" print the elements of the array -- "<<endl;
	for (i=0;i<n;i++)
	{
	for (j=0;j<m;j++)
	cout<<mat[i][j]<<" ";
	cout<<endl;
	}

	vector<pair<pair<int,int>,pair<int,int>>> vpoint;

	vpoint.push_back(make_pair(make_pair(1,3),make_pair(3,2)));
	vpoint.push_back(make_pair(make_pair(1,1),make_pair(3,4)));
	vpoint.push_back(make_pair(make_pair(4,4),make_pair(2,3)));
	vpoint.push_back(make_pair(make_pair(1,1),make_pair(1,4)));
	vpoint.push_back(make_pair(make_pair(2,3),make_pair(3,2)));

	sumQuery2dImmutable((int *)mat,n,m,vpoint);

}