#include <iostream>
#include <vector>
using namespace std;

// dynamic programming video 26
//  minimum cost path problem  - find the minimum cost path problem from top-left point to the bottom-right point of given matrix with condition that only rightward and downward movements are possible
// time complexity - o ( row * col )
// space complexity - o ( row * col )

int minval(int a,int b)
{
	if (a<b)
		return a;
	else
		return b;
}

int minimumCostPath(int *val,int row,int col)
{
	int i,j,k,u,v,x,y;
	int temp[row][col];

	vector<int> vcost;
	vector<pair<int,int>> vpoint;

	// print the val matrix in the function
	cout<<" printing the val matrix in the function -- "<<endl;
	for (i=0;i<row;i++)
	{
		for (j=0;j<col;j++)
		{
			x = *((val+i*col)+j);
			cout<<x<<" ";
		}
		cout<<endl;
	}
	cout<<endl;

	for (i=0;i<row;i++)
	{
		if (i==0)
			temp[0][0] = *(val+i*col);
		else
			temp[i][0] = temp[i-1][0] + *(val+i*col);
	}

	for (i=1;i<col;i++)
		temp[0][i] = temp[0][i-1] + *(val+i);

	for (i=1;i<row;i++)
	{
		for (j=1;j<col;j++)
		{
          temp[i][j] = *((val+i*col)+j) + minval(temp[i-1][j],temp[i][j-1]);
		}
	}

	int answer = temp[row-1][col-1];

	// printing the temp matrix
	cout<<" printing the temp matrix --"<<endl;
	for (i=0;i<row;i++)
	{
		for (j=0;j<col;j++)
			cout<<temp[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;

	x=row-1;
	y=col-1;

	while (true)
	{
		k = *((val+x*col)+y);
		vcost.push_back(k);
		vpoint.push_back(make_pair(x,y));

		if (x==0 && y==0)
			break;
		else
		{
			if (x == 0)
				y=y-1;
			else if (y == 0)
				x=x-1;
			else if (temp[x][y-1]<temp[x-1][y])
				y=y-1;
			else
				x=x-1;
		}
	}

	// printing the path of points 
	cout<<" printing the points in the shortest path -- "<<endl;
	for (i=vpoint.size()-1;i>=0;i--)
	{
		if (i==0)
			cout<<" ( "<<vpoint[i].first<<" , "<<vpoint[i].second<<" ) "<<endl;
		else
			cout<<" ( "<<vpoint[i].first<<" , "<<vpoint[i].second<<" )  --> ";
	}
	cout<<endl;

	// printing the cost associated with each point in the shortest path
	cout<<" printing the cost associated with each point in the shortest path --- "<<endl;
	for (i=vcost.size()-1;i>=0;i--)
	{
		if (i==0)
			cout<<vcost[i]<<" "<<endl;
		else
			cout<<vcost[i]<<"  -->  ";
	}
	cout<<endl;
	
	return answer;
}

int main()
{
	// int row = 3;
	// int col = 4;
	// int val[row][col] = {{1,3,5,8},
	//                      {4,2,1,7},
	//                      {4,3,2,3}};

	// int row = 3;
	// int col = 3;
	// int val[row][col] = {{1,2,3},
	//                      {4,8,2},
	//                      {1,5,3}};

	int row = 4;
	int col = 5;
	int val[row][col] = {{1,4,6,7,3},
	                     {3,2,4,3,7},
	                     {6,1,5,6,5},
	                     {3,2,1,6,8}};
	cout<<" minimum cost path problem "<<endl;
	cout<<" row of the val matrix = "<<row<<endl;
	cout<<" col of the val matrix = "<<col<<endl;
	cout<<" elements of the val matrix -- "<<endl;
	for (int i=0;i<row;i++)
	{
	for (int j=0;j<col;j++)
	  cout<<val[i][j]<<" ";
	cout<<endl;  
	}
	cout<<endl;

	int answer = minimumCostPath((int *)val,row,col);

	cout<<" final answer = "<<answer<<endl;                     
}