#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;

// dp video 39
// total path from top-left corner to bottom right corner of the matrix 
// time complexity - o(row * col)
// space complexty -  o(row * col)

int getTotalPathInMatrixFromTlToBr(int *mat,int row,int col)
{
	int i,j,k,u,v,x,y,val,len;

	int temp[row][col];

	// printing the mat in function
	cout<<endl;
	cout<<" printing the mat in the function -- "<<endl;
	for (i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			val = *((mat + i*col)+j);
			cout<<val<<" ";
		}
		cout<<endl;
	}

	cout<<endl;

	for (i=0;i<row;i++)
		temp[i][0]=1;

	for (i=0;i<col;i++)
		temp[0][i]=1;

	for (i=1;i<row;i++)
	{
		for (j=1;j<col;j++)
			temp[i][j]= temp[i-1][j] + temp[i][j-1];
	}

	// printing the temp matrix
	cout<<" printing the temp matrix -- "<<endl;
	for (i=0;i<row;i++)
	{
		for (j=0;j<col;j++)
			cout<<temp[i][j]<<" ";
		cout<<endl;
	}

	return temp[row-1][col-1];
}

int main()
{
	int i,j,k;
	// int row = 4;
	// int col = 4;
	// int mat[row][col] = {{1,2,3,4},
	//                      {5,6,7,8},
	//                      {9,10,11,12},
	//                      {13,14,15,16}};

	int row = 5;
	int col = 6;
	int mat[row][col] = {{1,2,3,4,5,2},
	                     {6,7,8,9,10,2},
	                     {11,12,13,14,15,2},
	                     {16,17,18,19,20,2},
	                     {21,22,23,25,26,2}};

    cout<<" total path from top-left corner to bottom right corner of the matrix -- "<<endl;
    cout<<" row in the matrix -- "<<row<<endl;
    cout<<" col in the matrix -- "<<col<<endl;
    cout<<"elements of the matrix -- "<<endl;
    for (i=0;i<row;i++)
    {
    for (j=0;j<col;j++)
       cout<<mat[i][j]<<" ";
    cout<<endl;
    }

    cout<<endl;
    int answer = getTotalPathInMatrixFromTlToBr((int *)mat,row,col);

    cout<<" total paths from the top-left corner to the bottom-right corner in the matrix -- "<<answer<<endl;	                     
}