#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

// dynamic programming video 19
//  matrix chain multiplication problem - find minimum cost of matrix chain mulltiplication of n matrices 
// time complexity - o (n*n*n)
// space complexity - o (n*n)

void printparanthesis(int i,int j,int n,int *bracket,char &name)
{
 if (i==j)
 {
 	cout<<name++;
 	return;
 }

 cout<<"( ";

 printparanthesis(i,*((bracket+i*n)+j),n,bracket,name);

 printparanthesis(*((bracket+i*n)+j)+1,j,n,bracket,name);

 cout<<" )";
}

// //////////////////////////////////////////////////////////////////////////////////

int matrixChainMultiplication1(vector<pair<int,int>> vmat)
{
	int i,j,k,u,v,val,len,cut;

	int n=vmat.size();

	int temp[n][n]={0};
	int bracket[n][n];

	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
			bracket[i][j]=-1;
	}

	for (len=2;len<=n;len++)
	{
		for (i=0;i<(n-len+1);i++)
		{
			j=i+len-1;
            u = pow(2,sizeof(int)*4-1)-1;

			for(k=i;k<j;k++)
			{
				val = temp[i][k]+temp[k+1][j]+(vmat[i].first * vmat[k].second * vmat[j].second);

				if (val<u)
				{
					u=val;
					v=k;
				}
			}
			temp[i][j]=u;
			bracket[i][j]=v;
		}
	}

	// print the temp matrix

	cout<<"printing the temp matrix "<<endl;

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			cout<<temp[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;

	// print the temp matrix

	cout<<"printing the bracket matrix "<<endl;

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			cout<<bracket[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;

	int answer=temp[0][n-1];

	char name='A';

	cout<<"optimaal paranthesis for method 1 "<<endl;

	printparanthesis(0,n-1,n,(int *)bracket,name);
	cout<<endl;

	return answer;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void printparanthesis2(int i,int j,int n,int *bracket,char &name)
{
 if (i==j)
 {
 	cout<<name++;
 	return;
 }

 cout<<"( ";

 printparanthesis2(i,*((bracket+i*n)+j),n,bracket,name);

 printparanthesis2(*((bracket+i*n)+j)+1,j,n,bracket,name);

 cout<<" )";
}

int matrixChainMultiplication2(vector<int> vd)
{
	int i,j,k,len,val,u,v;
	int n = vd.size();

	int temp[n][n]={0};
	int bracket[n][n]={0};

    int cnt = 0;

	for (len=2;len<n;len++)
	{
		for (i=1;i<(n-len+1);i++)
		{
			j=i+len-1;
			u = pow(2,sizeof(int)*4-1)-1;

			for (k=i;k<j;k++)
			{
				val = temp[i][k]+temp[k+1][j]+(vd[i-1]*vd[k]*vd[j]);

				if(val<u)
				{
					u=val;
					v=k;
				}
			}
			temp[i][j]=u;
			bracket[i][j]=v;
			cnt++;
			cout<<"for i ="<<i<<" , j = "<<j<<" , cnt = "<<cnt<<endl;
		}
	}

		// print the temp matrix

	cout<<"printing the temp matrix "<<endl;

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			cout<<temp[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;

		// print the temp matrix

	cout<<"printing the bracket matrix "<<endl;

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			cout<<bracket[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;

	int answer = temp[1][n-1];

	char name='A';

	cout<<"optimaal paranthesis for method 2 "<<endl;

	printparanthesis(1,n-1,n,(int *)bracket,name);
	cout<<endl;

	return answer;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

int matrixChainMultiplication3(vector<int> vd)
{
  int i,j,k,len,val,u,v;

  int n = vd.size();

  int temp[n-1][n-1]={0};
  int bracket[n-1][n-1];

  for (i=0;i<(n-1);i++)
  {
  	for(j=0;j<(n-1);j++)
  		bracket[i][j]=-1;
  }

  int cnt=0;

  for (len=2;len<n;len++)
  {
  	for (i=0;i<n-len;i++)
  	{
  		j=i+len-1;
  		u=pow(2,sizeof(int)*8-1)-1;

  		for (k=i+1;k<=j;k++)
  		{
  			val = temp[i][k-1]+temp[k][j]+(vd[i]*vd[k]*vd[j+1]);

  			if (val<u)
  			{
  				u=val;
  				v=k;
  			}
  		}

  		temp[i][j]=u;
  		bracket[i][j]=v-1;
  		cnt++;
  		cout<<" for i = "<<i<<" , j = "<<j<<" , cnt = "<<cnt<<endl;
  	}
  }
  cout<<endl;

  // printing the temp matrix
  cout<<" printing the temp matrix "<<endl;

	for(i=0;(i+1)<n;i++)
	{
		for(j=0;(j+1)<n;j++)
			cout<<temp[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;


  // printing the temp matrix
  cout<<" printing the bracket matrix "<<endl;

  for(i=0;(i+1)<n;i++)
	{
		for(j=0;(j+1)<n;j++)
			cout<<bracket[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;


  int answer = temp[0][n-2];

  char name = 'A';

  cout<<"optimaal paranthesis for method 3 "<<endl;

  printparanthesis(0,n-2,n-1,(int *)bracket,name);
  cout<<endl;

  return answer;
}

int main()
{
	
	vector<pair<int,int>> vmat;
    
 //    int n=4;
	// int a1[]={2,3,6,4};
	// int a2[]={3,6,4,5};

	int n=6;
	int a1[]={2,5,6,7,3,2};
	int a2[]={5,6,7,3,2,3};

	for (int i=0;i<n;i++)
		vmat.push_back(make_pair(a1[i],a2[i]));

	cout<<"Matrix chain mulltiplication problem by  use of vector of pair "<<endl;

	cout<<"number of matrices = "<<n<<endl;

	int cond=1;

	for(int i=0;i<n-1;i++)
	{
		if(vmat[i].second != vmat[i+1].first)
		{
			cond=0;
			break;
		}
	}

	  cout<<"dimension of matrices "<<endl;

	  for(int i=0;i<n;i++)
	  	cout<<"for matrix  "<<i<<" , order = ( "<<vmat[i].first<<" , "<<vmat[i].second<<" )"<<endl;
	  cout<<endl;

	if (cond==1)
	{

      int answer1 = matrixChainMultiplication1(vmat);  // by use of vector of pair containing dimension of the matrix
      cout<<"answer1 = "<<answer1<<endl;

      cout<<endl;

      vector<int> vd;

      for(int i=0;i<n;i++)
      	vd.push_back(a1[i]);

      vd.push_back(a2[n-1]);

      cout<<" matrix chain multiplication by vector or array method , ordering start with i = 0 "<<endl;
      cout<<" size of array or vector containing dimension of matrices "<<vd.size()<<endl;

      cout<<" elements of the array "<<endl;

      for (int i=0;i<vd.size();i++)
      	cout<<vd[i]<<" ";

      cout<<endl;


      // cout<<endl;
      // cout<<" matrix chain multiplication by vector or array method "<<endl;

      int answer2 = matrixChainMultiplication2(vd); // by use  of vector which contain 
      // the dimension of matrix in serial order.here, order start with i = 1
      cout<<" answer2 = "<<answer2<<endl;
      
      cout<<endl;
      cout<<" matrix chain multiplication by vector or array method , ordering start with i = 1 "<<endl;
      int answer3 = matrixChainMultiplication3(vd); // by use  of vector which contain 
      // the dimension of matrix in serial order.here, order start with i = 1
      cout<<" answer3 = "<<answer3<<endl;
	}
	else
	{
	  cout<<"matrices cannot be multiplied "<<endl;	
	}
}