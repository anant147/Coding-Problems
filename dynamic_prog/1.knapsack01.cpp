#include <iostream>
#include <vector>
using namespace std;

// dynamic programming video 1
// 0/1 knapsack problem bottom up approach

int max(int a,int b)
{
	if (a < b)
		return b;
	else
		return a;
}

int knapsack01(int wt[],int val[],int size,int totalwt)
{
	int i,j,k;

	int temp[size][totalwt+1];

	for (i=0;i<size;i++)
		temp[i][0]=0;

    // filling the temp matrix

	for (i=0;i<size;i++)
	{
		for (j=1;j<=totalwt;j++)
		{
			if (i==0)
			{
				if((j-wt[i])>=0)
					temp[i][j]=val[i];
				else
					temp[i][j]=0;
			}
			else
			{
				if ((j-wt[i])>=0)
					temp[i][j]=max(temp[i-1][j],temp[i-1][j-wt[i]]+val[i]);
				else
					temp[i][j]=temp[i-1][j];
			}
		}
	}

	// printing the element of the matrix

    for (i = 0;i<size;i++)
    {
    	for (j=0;j<=totalwt;j++)
    	{
    		cout<<temp[i][j]<<" ";
    	}
    	cout<<endl;
    }

    cout<<endl;

    int ans = temp[size-1][totalwt];

    // getting items which producing maximum value

    vector <int> v;
    int cond = 1;

    int col = totalwt;
    int row = size-1;

    int mval = temp[row][col];

    cout<<"items - "<<endl;

    while (cond == 1)
    {
    	if (mval == 0)
    	{
    		cond =0;
    		break;
    	}
    	else
    	{
    		if (row !=0)
    		{
    			if (temp[row][col]==temp[row-1][col])
    			{
                   row=row-1;
    			}
    			else
    			{
                  v.push_back(row);
                  cout<<"item inserted - "<<row<<endl;
                  col = col - wt[row];
                  row = row-1;
                  mval = temp[row][col];
    			}
    		}
    		else
    		{
                 v.push_back(row);
                 cout<<"item inserted - "<<row<<endl;
                 mval = 0;
                 break;
    		}
    	}
    }

    cout<<endl;

    // producing the list of items

    cout<<" weight and cost of items inserted "<<endl;

    for (i=0;i<v.size();i++)
    {
    	k = v[i];
    	cout<<"for item - "<<k<<" , weight - "<<wt[k]<<" and val - "<<val[k]<<endl;
    }

    cout<<endl;

    return ans;
}

int main()
{
	// int wt[4] = {1,3,4,5};
	// int val[4] = {1,4,5,7};

	int wt[4] = {3,1,4,5};
	int val[4] = {4,1,5,7};

	int totalwt = 7;

	int size = 4;

	int ans = knapsack01(wt,val,size,totalwt);

	cout<<"answer - "<<ans<<endl;
}