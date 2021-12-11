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

bool wildcardMatch(string st, string pattern)
{
	int i,j,k,u,v,x,y,z;

	int n = st.size();
	int m = pattern.size();

	vector<vector<bool>> valstor;
	valstor.resize(n+1,vector<bool> (m+1,false));

	valstor[0][0] = true;

	for (j=1;j<=m;j++)
	{
		if (pattern[j]=='*')
			valstor[0][j] = valstor[0][j-1];
	}

	for (i=1;i<=n;i++)
	{
		for (j=1;j<=m;j++)
		{
			if (st[i-1]==pattern[j-1])
				valstor[i][j] = valstor[i-1][j-1];
			else if (pattern[j-1]=='?')
				valstor[i][j] = valstor[i-1][j-1];
			else if (pattern[j-1]=='*')
				valstor[i][j] = valstor[i-1][j] || valstor[i][j-1];
			else
				valstor[i][j] = false;
		}
	}

	cout<<" printing the valstor vector :- "<<endl;
	for (i=0;i<=n;i++)
	{
		for (j=0;j<=m;j++)
			cout<<valstor[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;

	return valstor[n][m];
}


int main()
{
	cout<<" tp6. Wildcard Matching problem  "<<endl;

	string st = "xaylmz";
	string pattern = "x?y*z";

	cout<<" st = "<<st<<endl;
	cout<<" pattern = "<<pattern<<endl;

	bool answer = wildcardMatch(st, pattern);

	if (answer)
		cout<<" Given string st is matched with pattern "<<endl;
	else
		cout<<" Given string st is not matched with pattern "<<endl;

}