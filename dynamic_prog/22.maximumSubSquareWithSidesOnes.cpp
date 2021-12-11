#include <iostream>
#include <vector>
using namespace std;

// dynamic programming video 22
//  maximum sub square with sides of 1s  problem - find the side of maximum sub square with sides of 1s in given matrix  of 0s and 1s with all 1s
// time complexity - o ( row * col)
// space complexity - o (row * col)

int minval(int a,int b)
{
	if (a<b)
		return a;
	else
		return b;
}

int maxval(int a,int b)
{
	if (a<b)
		return b;
	else
		return a;
}

int maximumSubSquareWithSidesOnes(int *mat,int row,int col)
{

 int i,j,k,u,v,x,y,val,answer,cond,maxSide,localSide;

 int temp[row][col][2];

 // printing the mat matrix

 for (i=0;i<row;i++)
 {
 	for (j=0;j<col;j++)
 	 {
 	 	val = *((mat+i*col)+j);

 	 	cout<<val<<" ";
 	 }
 	 cout<<endl;
 }
 

 cond=0;

 for (i=0;i<row;i++)
 {
 	for (j=0;j<col;j++)
 	{
 		val = *((mat+i*col)+j);

 		if (i == 0)
 		{
          if (cond == 0 && i==0 && j==0)
          {
          	if (val == 0)
          	{
               temp[i][j][0]=0;
               temp[i][j][1]=0;
          	}
          	else
          	{
              temp[i][j][0]=1;
              temp[i][j][1]=1;
          	}
          }
          else
          {
          	if (val == 0)
          	{
               temp[i][j][0]=0;
               temp[i][j][1]=0;
          	}
          	else
          	{
               temp[i][j][0]=1;
               temp[i][j][1]=1+temp[i][j-1][1];
          	}
          }

 		}
 		else if (j == 0)
 		{
            if (val==0)
            {
            	temp[i][j][0]=0;
            	temp[i][j][1]=0;
            }
            else
            {
            	temp[i][j][0]=1+temp[i-1][j][0];
            	temp[i][j][1]=1;
            }
 		}
 		else
 		{
            if (val==0)
            {
            	temp[i][j][0]=0;
            	temp[i][j][1]=0;
            }
            else
            {
            	temp[i][j][0]=1+temp[i-1][j][0];
            	temp[i][j][1]=1+temp[i][j-1][1];
            }
 		}
 	}
 }

 cout<<endl;
 // print the temp matrix
 cout<<" printing the temp matrix -- "<<endl;

 for (i=0;i<row;i++)
 {
 	for (j=0;j<col;j++)
 		cout<<" ( "<<temp[i][j][0]<<" , "<<temp[i][j][1]<<" ) "<<" ";
 	cout<<endl;
 }
 cout<<endl;

 // getting the max side for the sub square of the rectangle

 maxSide = 0;
 int x_vert,y_vert;
 int x_hort,y_hort;

 int xh_val,yh_val;
 int xv_val,yv_val;

 int cnt =0;

 for (i=row-1;i>=0;i--)
 {
 	for (j=col-1;j>=0;j--)
 	{
      localSide = minval(temp[i][j][0],temp[i][j][1]);
      cnt++;
      // cout<<"for cnt -- "<<cnt<<" with i - "<<i<<" , j = "<<j<<" , localSide = "<<localSide<<endl;


	      if (maxSide < localSide)
	      {
		        for (k=localSide;k>maxSide;k--)
		        {
		          x_hort = i;   // horizontal neighbour of point (i,j) with distance of localSide
		          y_hort = j-k+1;

		          x_vert = i-k+1;  // vertical neighbour of point (i,j) with distance of localSide
		          y_vert = j;

		          xh_val = temp[x_hort][y_hort][0];
		          yh_val = temp[x_hort][y_hort][1];

		          xv_val = temp[x_vert][y_vert][0];
		          yv_val = temp[x_vert][y_vert][1];

			          if ((xh_val >= k) && (yv_val >=k))
			          {
			          	maxSide = k;
			          	x=i;
			          	y=j;
			          	// cout<<"condition sucess "<<endl;
			          	// cout<<" for k = "<<k<<endl;
			          	// cout<<" for xh_val = "<<xh_val<<endl;
			          	// cout<<" for yv_val = "<<yv_val<<endl;
			          	// cout<<endl;
			          }
			          else
			          {
              //           cout<<"condition failed "<<endl;
			          	// cout<<" for k = "<<k<<endl;
			          	// cout<<" for xh_val = "<<xh_val<<endl;
			          	// cout<<" for yv_val = "<<yv_val<<endl;
			          	// cout<<endl;
			          }
		        }

	      }
	    // cout<<"maxSide = "<<maxSide<<endl;  
	    // cout<<endl;  
 	}
 }

 answer = maxSide;

  // printing the coordinates of the square
  cout<<" printing the coordinates of the sub square of the matrix with the side of "<<answer<<endl;
  cout<<"first coordinate (x0,y0)  -- ( "<<(x-answer+1)<<" , "<<(y-answer+1)<<" ) "<<endl;
  cout<<"second coordinate (x1,y1)  -- ( "<<(x-answer+1)<<" , "<<(y)<<" ) "<<endl;
  cout<<"third coordinate (x2,y2)  -- ( "<<(x)<<" , "<<(y-answer+1)<<" ) "<<endl;
  cout<<"fourth coordinate (x3,y3)  -- ( "<<(x)<<" , "<<(y)<<" ) "<<endl;
  cout<<endl;

  return answer;
}

int main()
{
	// int row=5;
	// int col=5;

	// int mat[row][col]={{0,0,0,0,1},
 //                       {1,0,1,1,1},
 //                       {1,0,1,0,1},
 //                       {1,1,1,1,1},
 //                       {0,0,1,1,1}};

 //    int row=4;
	// int col=5;
	// int mat[row][col]={{0,0,1,1,1},
 //                       {1,0,1,1,1},
 //                       {0,1,1,1,1},
 //                       {1,0,1,1,1}};

    //  int row = 4;
    // int col = 6;

    // int mat[row][col]= {{1,0,0,1,1,1},
    //                     {1,0,1,1,0,1},
    //                     {0,1,1,1,1,1},
    //                     {0,0,1,1,1,1}};

    int row = 7;
    int col = 6;

    int mat[row][col] = {{1,1,1,0,0,1},
                         {1,1,1,1,1,0},
                         {0,1,1,1,1,1},
                         {0,1,1,0,1,1},
                         {0,1,0,1,1,1},
                         {0,1,1,1,1,1},
                         {1,0,0,0,1,1}};                         
                                     

    cout<<" maximum sub square with sides problem "<<endl;
    cout<<" row = "<<row<<endl;
    cout<<" col = "<<col<<endl;
    cout<<" elements of the matrix -- "<<endl;

    for (int i=0;i<row;i++)
    {
      for (int j=0;j<col;j++)
      	cout<<mat[i][j]<<" ";
      cout<<endl;
    }
    cout<<endl;

    int answer = maximumSubSquareWithSidesOnes((int *)mat,row,col);
    cout<<" answer = "<<answer<<endl;                   
}