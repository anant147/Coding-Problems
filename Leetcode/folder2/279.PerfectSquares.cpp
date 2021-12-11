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

int binsearch(vector<int>& sqval, int val)
{
	int low = 0;
	int high = sqval.size()-1;

	while (low<=high)
	{
		int mid = low + (high-low)/2;

		if (sqval[mid]==val)
			return mid;
		else if (sqval[mid]<val)
		{
			if (sqval[mid+1]>val)
				return mid;
			else
				low = mid+1;
		}
		else
			high = mid-1;
	}

	return -1;
}

int minval(int a, int b)
{
	if (a<b)
		return a;
	else
		return b;
}

int numSquares(int n)
{
	int i,j,k,u,v,x,y,z;

	if (n<4)
		return n;

	int maxval = pow(2,sizeof(int)*8-1)-1;
	int maxsqrt = sqrt(maxval);

	vector<int> sqval;

	for (i=1;i<=maxsqrt;i++)
		sqval.push_back(i*i);

	int sqlen = sqval.size();

	int pos;

	if (sqval[sqlen-1]<n)
		pos = sqlen;
	else if (sqval[sqlen-1]==n)
		return 1;
	else
	{
		pos = binsearch(sqval,n);

		if (sqval[pos]==n)
			return 1;
		else if (pos==-1)
			return 0;
		else
			pos = pos + 1;
	}

	vector<vector<int>> valstor;

	valstor.resize(pos,vector<int> (n+1,0));

	for (i=0;i<pos;i++)
	{
		for (j=1;j<=n;j++)
		{
			if (i==0)
				valstor[i][j] = j;
			else
			{
				if (j<sqval[i])
					valstor[i][j] = valstor[i-1][j];
				else
					valstor[i][j] = minval( valstor[i-1][j], 1 + valstor[i][j-sqval[i]]);
			}
		}
	}

	return valstor[pos-1][n];

}

int main()
{
	cout<<" 279. Perfect Squares "<<endl;

	// example 1
	// int n = 12;

	// example 2
	int n = 13;

	cout<<" n = "<<n<<endl;

	int answer = numSquares(n);

	cout<<" answer = "<<answer<<endl;
}