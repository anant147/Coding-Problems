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

int maxval(int x, int y)
{
	if (x>y)
		return x;
	else
		return y;
}

int findLUSlength(string a, string b)
{
	int i,j,k,u,v,x,y,z;

	int n = a.size();
	int m = b.size();

	vector<vector<int>> stor;
	stor.resize(n+1, vector<int>(m+1,0));

	for (i=1;i<=n;i++)
	{
		for (j=1;j<=m;j++)
		{
			if (a[i-1]==b[j-1])
				stor[i][j] = 1 + stor[i-1][j-1];
			else
				stor[i][j] = maxval(stor[i-1][j], stor[i][j-1]);
		}
	}

	// cout<<" printing the stor vector :-"<<endl;
	// for (i=0;i<=n;i++)
	// {
	// 	for (j=0;j<=m;j++)
	// 		cout<<stor[i][j]<<" ";
	// 	cout<<endl;
	// }
	// cout<<endl;

	if (stor[n][m]==n || stor[n][m]==m)
		return -1;
	else
	{
		k = maxval(n,m);

		return (k-stor[n][m]);
	}


}

int main()
{
	cout<<" 521. Longest Uncommon Subsequence I "<<endl;

	// example 1
	// string a = "aba";
	// string b = "cdc";

	// 	// example 1
	// string a = "aaa";
	// string b = "bbb";

	// 	// example 1
	string a = "aaa";
	string b = "aaa";

	cout<<" a = "<<a<<endl;
	cout<<" b = "<<b<<endl;

	int answer = findLUSlength(a, b);

	cout<<" answer = "<<answer<<endl;
}