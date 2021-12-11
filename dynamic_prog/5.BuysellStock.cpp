#include <iostream>
#include <vector>
using namespace std;

// dynamic programming video 5
// buysell stock

int maxval(int a,int b)
{
	if(a<b)
		return b;
	else
		return a;
}

void printActualVaue(int n,int trans,int price[],vector<vector<int>> matv)
{
	int i,j,k,maxdiff;

	i=trans;
	j=n-1;

	vector<int> trtrace;

	while(true)
	{
      if(i==0 || j==0)
      {
      	cout<<"cond 3"<<endl;
      	break;
      }
      else if (matv[i][j]==matv[i][j-1])
      {
      	cout<<"cond 2"<<endl;
      	j=j-1;
      }
      else
      {
      	trtrace.push_back(j);
      	maxdiff = matv[i][j]-price[j];
      	cout<<"cond 1"<<endl;

      	for (k=j-1;k>=0;k--)
      	{
      		if ((matv[i-1][k]-price[k])==maxdiff)
      		{
      			i=i-1;
      			j=k;
      			cout<<"cond 0"<<endl;
      			cout<<"i = "<<i<<" , j = "<<j<<endl;
      			trtrace.push_back(k);
      			break;
      		}
      	}

      }

      cout<<" vsize - "<<trtrace.size()<<endl;
	}

	int profit=0;

	for (i=trtrace.size()-1;i>=0;i--)
	{
		if (i%2==1)
		{
          cout<<"for day - "<<trtrace[i]<<" , stock is bought at "<<price[trtrace[i]]<<endl;
          profit=profit-price[trtrace[i]];
		}
		else
		{
          cout<<"for day - "<<trtrace[i]<<" , stock is sold at "<<price[trtrace[i]]<<endl;
          profit=profit+price[trtrace[i]];
		}
	}

	cout<<"final profit -- "<<profit<<endl;

	cout<<endl;
}

int buysellFast(int price[],int n,int trans)
{
	cout<<"by fast method "<<endl;  // o(n*n) complexity
	int i,j,k,maxdiff,answer;
	int mat[trans+1][n];

	for(i=0;i<n;i++)
		mat[0][i]=0;

	for (i=0;i<=trans;i++)
		mat[i][0]=0;
    
    // making temperory matrix
	for(i=1;i<=trans;i++)
	{
		maxdiff = -price[0];

		for(j=1;j<n;j++)
		{
			maxdiff = maxval(mat[i-1][j-1]-price[j-1],maxdiff);
			mat[i][j] = maxval(mat[i][j-1],price[j]+maxdiff);
		}
	}
 
	// print price array
    cout<<"printing the price array "<<endl;
	for(i=0;i<n;i++)
		cout<<price[i]<<" ";
	cout<<endl;

	// print temporary matrix
    cout<<"printing the formed profit matrix"<<endl;
	for (i=0;i<=trans;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}

	answer = mat[trans][n-1];

	vector<vector<int>> matv;

	for (i=0;i<=trans;i++)
	{
		vector<int> vk;

		for(j=0;j<n;j++)
		{
			vk.push_back(mat[i][j]);
		}
		matv.push_back(vk);
		vk.clear();
	}

	printActualVaue(n,trans,price,matv);


	return answer;
}

// slow method
int buysellSlow(int price[],int n,int trans)
{
	cout<<"by Slow method "<<endl;  // o(n*n *n) complexity
	int i,j,k,maxdiff,answer,maxvl;
	int mat[trans+1][n];

	for(i=0;i<n;i++)
		mat[0][i]=0;

	for (i=0;i<=trans;i++)
		mat[i][0]=0;
    
    // making temperory matrix
	for(i=1;i<=trans;i++)
	{
		maxdiff = -price[0];

		for(j=1;j<n;j++)
		{
		    for (k=0;k<j;k++)
		    {
		    	if((mat[i-1][k]-price[k])>maxdiff)
		    		maxdiff = mat[i-1][k]-price[k];
		    }
			mat[i][j] = maxval(mat[i][j-1],price[j]+maxdiff);
		}
	}
 
	// print price array
    cout<<"printing the price array "<<endl;
	for(i=0;i<n;i++)
		cout<<price[i]<<" ";
	cout<<endl;

	// print temporary matrix
    cout<<"printing the formed profit matrix"<<endl;
	for (i=0;i<=trans;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}

	answer = mat[trans][n-1];

	vector<vector<int>> matv;

	for (i=0;i<=trans;i++)
	{
		vector<int> vk;

		for(j=0;j<n;j++)
		{
			vk.push_back(mat[i][j]);
		}
		matv.push_back(vk);
		vk.clear();
	}

	printActualVaue(n,trans,price,matv);


	return answer;
}

int main()
{
	int price[8] = {2,5,7,1,4,3,1,3};
	int n =8;
	int trans=3;
	int answer1=buysellFast(price,n,trans);
	cout<<"answer1 - "<<answer1<<endl;

	int answer2=buysellSlow(price,n,trans);
	cout<<"answer2 - "<<answer2<<endl;

}