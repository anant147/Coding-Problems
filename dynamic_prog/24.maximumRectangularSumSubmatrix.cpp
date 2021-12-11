#include <iostream>
#include <vector>
using namespace std;

// dynamic programming video 24
//  maximum rectangular sum sub matrix  problem - find the maximum rectangular sum sub matrix for given matrix of the integer elements
// time complexity - o (col * col * row)
// space complexity - o ( row )


vector<int> kandaneMaxSubarraySum(int temp[],int n)
{
 vector<int> answer;

 int i,j,k,maxsum,cursum,left1,left2,right,cond;

 maxsum=0;
 cursum=0;
 left1=-1;
 left2=-1;
 right=-1;
 cond=0;

 for (i=0;i<n;i++)
 {
 	if ((cursum+temp[i])<0)
 	{
 		cond=0;
 		cursum=0;
 	}
 	else
 	{
 		if (cond==0)
 		{
 			cond=1;
 			cursum=cursum+temp[i];
 			left1=i;
 		}
 		else
 		{
            cursum=cursum+temp[i];
 		}

 		if (maxsum < cursum)
 		{
 			maxsum = cursum;
 			left2=left1;
 			right=i;
 		}
 	}
 }

 // cout<<" maxsum = "<<maxsum<<endl;
 // cout<<" starting point = "<<left2<<endl;
 // cout<<" ending point = "<<right<<endl;

 answer.push_back(maxsum);
 answer.push_back(left2);
 answer.push_back(right);

 return answer;
}

int maximumRectangularSubarraySum(int *mat,int row,int col)
{
	int i,j,k,answer,val,u,v,x,y;
	int maxsum,maxleft,maxright,maxup,maxdown;
    
    // printing the mat matrix in the function
    cout<<" printing the mat matrix in the function "<<endl;
	for (i=0;i<row;i++)
	{
		for (j=0;j<col;j++)
		{
			val = *((mat+i*col)+j);
			cout<<val<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
    
    // initializing the parameters
	int temp[row]={0};
	maxsum=0;
	maxleft=-1; maxright=-1; maxup = -1;maxdown=-1;

	vector<int> kanswer;

	int cnt = 0;
     
    // main code 
	for (i=0;i<col;i++)
	{
		for (j=i;j<col;j++)
		{
			if (i==j)
			{
              for (k=0;k<row;k++)
              {
              	temp[k]=*((mat+k*col)+j);
              }
			}
			else
			{
               for (k=0;k<row;k++)
               	temp[k]=temp[k]+*((mat+k*col)+j);
			}
			cnt++;
			kanswer = kandaneMaxSubarraySum(temp,row);

			if (maxsum < kanswer[0])
			{
				maxsum=kanswer[0];
				maxleft=i;
				maxright=j;
				maxup=kanswer[1];
				maxdown=kanswer[2];
			}

			cout<<"at iteration = "<<cnt<<" maxvalue - "<<maxsum<<endl;
			cout<<" for i = "<<i<<" , j = "<<j<<endl;
			cout<<"elements in the temp array -- "<<endl;
			for (k=0;k<row;k++)
				cout<<temp[k]<<" ";
			cout<<endl;
			cout<<" left = "<<maxleft<<" , right = "<<maxright<<" , up = "<<maxup<<" , maxdown = "<<maxdown<<endl;
			cout<<endl;
		}
	}

	cout<<endl;
	cout<<" coordinates of the maximum rectangular sum sub matrix "<<endl;
	cout<<" (x0,y0) == ( "<<maxup<<" , "<<maxleft<<" ) "<<endl;
	cout<<" (x1,y1 ) == ( "<<maxup<<" , "<<maxright<<" ) "<<endl;
	cout<<" (x2,y2 ) == ( "<<maxdown<<" , "<<maxleft<<" ) "<<endl;
	cout<<" (x3,y3 ) == ( "<<maxdown<<" , "<<maxright<<" ) "<<endl;
	cout<<endl;

	cout<<" answer = "<<maxsum<<endl;

	return maxsum;
}

int main()
{
	int i,j,k,u,v;

	// int temp[]={-2, -3, 4, -1, -2, 1, 5, -3};
	// int temp[] = { 4, 5, -7 , 2, 4, -7, 6};
	int temp[] = { 3, 5, -2, -4, 3, 8, -10, 2, 3};
	int n = sizeof(temp)/sizeof(temp[0]);
	cout<<" Kandane algorithm to find the sum of maximum sum of the sub array in given array"<<endl;
	cout<<" size of temp array = "<<n<<endl;
	cout<<" elements of the array "<<endl;
	for (i=0;i<n;i++)
		cout<<temp[i]<<" ";
	cout<<endl;

	vector<int> kanswer = kandaneMaxSubarraySum(temp,n);

	cout<<endl;
	cout<<" maximum subarray sum = "<<kanswer[0]<<endl;
	cout<<" starting point of the maximum subarray  = "<<kanswer[1]<<endl;
	cout<<" ending point of the maximum subarray = "<<kanswer[2]<<endl;

	cout<<endl;

	// int row=4;
	// int col=5;
	// int mat[row][col]={{ 2, 1, -3,-4, 5},
 //                       { 0, 6,  3, 4, 1},
 //                       { 2,-2, -1, 4,-5},
 //                       {-3, 3,  1, 0, 3}};

	// int row = 5;
	// int col = 5;
	// int mat[row][col]={{-1, -2, 5, -1, 4},
 //                       {-3, 3,  3,  5,-1},
 //                       {-4, 5, -1, 3,  4},
 //                       { 0, 3,  2, 5, -1},
 //                       { 3, 2, -5, 0, -2}};

    int row = 5;
	int col = 5;
	int mat[row][col]={{-1, -2, 0, -1,-4},
                       {-3, 3,  3,  5,-1},
                       {-4, 5, -1, 3, -4},
                       { 0, 3,  2, 5, -1},
                       { 3, 2, -5, 0, -2}};                   

    cout<<endl;
    cout<<" maximum rectangular sum sub matrix problem "<<endl;
    cout<<" rows in the matrix = "<<row<<endl;
    cout<<" cols in the matrix = "<<col<<endl;
    cout<<" elenents of the matrix == "<<endl;
    for (i=0;i<row;i++)
    {
    	for (j=0;j<col;j++)
    		cout<<mat[i][j]<<" ";
    	cout<<endl;
    }

    cout<<endl;

    int answer = maximumRectangularSubarraySum((int *)mat,row,col);

    cout<<" final answer = "<<answer<<endl;                    

}