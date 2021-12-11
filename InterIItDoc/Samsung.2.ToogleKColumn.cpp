#include<bits/stdc++.h>
using namespace std;

int powval(int a, int b)
{
	int val = 1;

	for (int i=1;i<=b;i++)
		val = val*b;

	return val;
}

int main()
{
	cout<<" Samsung 2"<<endl;
	cout<<" A binary matrix of nxm was given, you have to toggle any column k number of times so that you can get the maximum number of rows having all 1’s  "<<endl;
	cout<<endl;

	// example 1
	int n = 3;
	int m = 3;
	int k = 2;

	vector<vector<int>> mat = {
		                      {1,0,0},
		                      {1,0,1},
		                      {1,0,0}
		                      };

    // example 2
    // int n = 3;
	// int m = 3;
	// int k = 3;

	// vector<vector<int>> mat = {
	// 	                      {1,0,0},
	// 	                      {1,0,1},
	// 	                      {1,0,0}
	// 	                      };


    cout<<" n = "<<n<<endl;
    cout<<" m = "<<m<<endl;
    cout<<" k = "<<k<<endl;
    
	cout<<" printing the mat vector :- "<<endl;
	for (int i=0;i<mat.size();i++)
	{
		for (int j=0;j<mat[i].size();j++)
			cout<<mat[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	cout<<endl;

	int size = 1;
	for (int i=1;i<=20;i++)
		size *= 2;

	int *hash = (int*)calloc(size,sizeof(int));

	for (int i=0;i<n;i++)
	{
		int keyVal = 0;
		int numZeros = 0;

		for (int j=0;j<m;j++)
		{
			keyVal += mat[i][j]*powval(2,j);
			if (mat[i][j] == 0)
				numZeros++;
		}

		if ( (k-numZeros)%2 == 0 && (k-numZeros)>=0 )
			hash[keyVal]++;
	}

	int keyWithMaxVal = 0; 
	int maxVal = 0;

	for (int i=1;i<=size;i++)
	{
		if (hash[i] > maxVal)
		{
			maxVal = hash[i];
			keyWithMaxVal = i;
		}
	}

	cout<<" maxVal = "<<maxVal<<endl;
	cout<<" keyWithMaxVal = "<<keyWithMaxVal<<endl;
}

