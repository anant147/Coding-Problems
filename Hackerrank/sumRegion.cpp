#include <iostream>
#include <vector>

using namespace std;

vector<int> sumRegion(vector<vector<int>>& matrix,vector<int> rw1,vector<int> cl1,vector<int> rw2,vector<int> cl2)
{
    int i,j,k,val,u,v,x,y;

    vector<vector<int>> sumtrix;

    int row = matrix.size();
    int col = matrix[0].size();

    for(i=0;i<row;i++)
    {
    	vector<int> vk;

    	for(j=0;j<col;j++)
    	{
    		if(i==0)
    		{
              if(j==0)
              {
                val = matrix[i][j];
              }
              else
              {
                val = matrix[i][j]+vk[vk.size()-1];
              }

              vk.push_back(val);

    		}
    		else
    		{
              
              if(j==0)
              {
                 val = matrix[i][j]+sumtrix[i-1][j];
              }
              else
              {
                val = matrix[i][j] + sumtrix[i-1][j] + vk[vk.size()-1] - sumtrix[i-1][j-1];
              }

              vk.push_back(val);

    		}

    	}

    	sumtrix.push_back(vk);
    }

    cout<<"Sum matrix "<<endl;

    for(i=0;i<row;i++)
    {
    	for(j=0;j<col;j++)
    		cout<<sumtrix[i][j]<<" ";

    	cout<<endl;
    }

    cout<<endl;

    vector<int> result;

    for(i=0;i<rw1.size();i++)
    {
    	int row1 = rw1[i];
    	int col1 = cl1[i];
    	int row2 = rw2[i];
    	int col2 = cl2[i];


        int reqval;

    	if(row1==0 && col1==0)
    	{
          reqval=sumtrix[row2][col2];
    	}
    	else if(row1==0)
    	{
    		reqval=sumtrix[row2][col2]-sumtrix[row2][col1-1];
    	}
    	else if(col1==0)
    	{
    		reqval = sumtrix[row2][col2]-sumtrix[row1-1][col2];
    	}
    	else
    	{
    		reqval = sumtrix[row2][col2] - sumtrix[row2][col1-1] - sumtrix[row1-1][col2] + sumtrix[row1-1][col1-1];
    	}

    	result.push_back(reqval);
    }


    vector<int> result1 = {0};
	return result;
}

int main()
{
	vector<vector<int>> matrix = {
  {3, 0, 1, 4, 2},
  {5, 6, 3, 2, 1},
  {1, 2, 0, 1, 5},
  {4, 1, 0, 1, 7},
  {1, 0, 3, 0, 5}
};

vector<int> rw1 = {2,1,1};
vector<int> cl1 = {1,1,2};
vector<int> rw2 = {4,2,2};
vector<int> cl2 = {3,2,4};

vector<int> result = sumRegion(matrix,rw1,cl1,rw2,cl2);

for(int i=0;i<result.size();i++)
{
	cout<<"for i = "<<(i+1)<<" val  = "<<result[i]<<endl;
}

}