#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<unordered_map>
#include<queue>
#include<stack>
#include<cmath>
#include<cstring>
using namespace std;

int getIndex(vector<int>& a, int u,int v, int target)
{
	int low = u;
	int high = v;

	int mid;

	if (a[high] < target)
		return -1;

	while (low <= high)
	{
		mid = low + (high-low)/2;

		if (a[mid] == target)
			return 0;
		else if (a[mid]<target)
		{
			if ((mid+1)<=v)
			{
				if (a[mid+1]==target)
					return 0;
				else if (a[mid+1]>target)
					return mid;
				else
					low = mid+1;
			}
		}
		else
			high = mid-1;
	}

	return -1;
}

bool searchMatWithCoord(vector<vector<int>>& matrix, int x, int y, int n, int m, int target)
{
	if (matrix[x][y]==target)
		return true;

	int i,j;

	vector<int> v1 = matrix[x];
	vector<int> v2;

	for (i=0;i<n;i++)
		v2.push_back(matrix[i][y]);	vector<vector<int>> matrix = {  
		                         {1,   4,  7, 11, 15},
                                 {2,   5,  8, 12, 19},
                                 {3,   6,  9, 16, 22},
                                 {10, 13, 14, 17, 24},
                                 {18, 21, 23, 26, 30}
                                 };

    // example 1                             
    // int target = 5;

    // example 2
    // int target = 20;

    // example 3
    int target = 17;

	int index1 = -1;
	int index2 = -1;

	if (x==(n-1) && y==(m-1))
		return false;
	else if (x==(n-1))
	{
		index1 = getIndex(v1,y,m-1,target);

		if (index1==0)
			return true;
		else if (index1==-1)
			return false;
		else
			return searchMatWithCoord(matrix,x,index1,n,m,target);
	}
	else if (y==(m-1))
	{
		index2 = getIndex(v2,x,n-1,target);

		if (index2==0)
			return true;
		else if (index2==-1)
			return false;
		else 
			return searchMatWithCoord(matrix,index2,y,n,m,target);
	}
	else
	{
		index1 = getIndex(v1,y,m-1,target);
	    index2 = getIndex(v2,y,n-1,target);

	    if (index1 == 0 || index2==0)
	    	return true;
	    else if (index1 == -1 && index2 == -1)
	    	return false;
	    else if (index1 == -1)
	    	return searchMatWithCoord(matrix,index2,y,n,m,target);
	    else if (index2 == -1)
	    	return searchMatWithCoord(matrix,x,index1,n,m,target);
	    else
	    	return ( searchMatWithCoord(matrix,x,index1,n,m,target) || searchMatWithCoord(matrix,index2,y,n,m,target) );
    }
}

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    int i,j,k,u,v,x,y,z;
        
    if (matrix.size()==0) 
        return false;
    
     if ( matrix[0].size()==0)
         return false;
        
	int n = matrix.size();

	if (n==0)
		return false;

	int m = matrix[0].size();
        
    if (m==0)
        return false;

	bool answer = searchMatWithCoord(matrix,0,0,n,m,target);

	return answer;
}

int main()
{
	cout<<" 240. Search a 2D Matrix II "<<endl;

	vector<vector<int>> matrix = {  
		                         {1,   4,  7, 11, 15},
                                 {2,   5,  8, 12, 19},
                                 {3,   6,  9, 16, 22},
                                 {10, 13, 14, 17, 24},
                                 {18, 21, 23, 26, 30}
                                 };

    // example 1                             
    // int target = 5;

    // example 2
    // int target = 20;

    // example 3
    int target = 17;


    int i,j;

    cout<<" printing the matrix vector :- "<<endl;
    for (i=0;i<matrix.size();i++)
    {
    	for (j=0;j<matrix[i].size();j++)
    		cout<<matrix[i][j]<<" ";
    	cout<<endl;
    }
    cout<<endl;

    cout<<" target = "<<target<<endl;

    bool answer = searchMatrix(matrix, target);

    if (answer)
    	cout<<" target is in the matrix "<<endl;
    else 
    	cout<<" target is not in the matrix "<<endl;

}