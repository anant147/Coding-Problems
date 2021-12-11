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

int numSplits(string s)
{
	int i,j,k,u,v,x,y,z;

	int n = s.size();

	if (n==1)
		return 0;

	vector<int> faphstor, baphstor, fowpass, backpass;
	faphstor.resize(26,0);
	baphstor.resize(26,0);

	fowpass.resize(n,0);
	backpass.resize(n,0);

	char ctemp;

	for (i=0;i<n;i++)
	{
		ctemp = s[i];
		u = (int)(ctemp)-97;

		if (i==0)
		{
			faphstor[u]++;
			fowpass[0]++;
		}
		else
		{
			if (faphstor[u]==1)
			{
				fowpass[i] = fowpass[i-1];
			}
			else
			{
				faphstor[u]=1;
				fowpass[i] = fowpass[i-1]+1;
			}
		}
	}

	for (i=n-1;i>=0;i--)
	{
		ctemp = s[i];
		u = (int)(ctemp)-97;

		if (i==(n-1))
		{
			baphstor[u]++;
			backpass[n-1]++;
		}
		else
		{
			if (baphstor[u]==1)
				backpass[i] = backpass[i+1];
			else
			{
				baphstor[u] = 1;
				backpass[i] = backpass[i+1]+1;
			}
		}
	}

	// cout<<" printing the fowpass vector :- "<<endl;
	// for (i=0;i<fowpass.size();i++)
	// 	cout<<fowpass[i]<<" ";
	// cout<<endl;
	// cout<<endl;

	// cout<<" printing the backpass vector :- "<<endl;
	// for (i=0;i<backpass.size();i++)
	// 	cout<<backpass[i]<<" ";
	// cout<<endl;
	// cout<<endl;

	int count = 0;

	for (i=0;i<(n-1);i++)
	{
		if (fowpass[i]==backpass[i+1])
			count++;
	}

	return count;
}

int main()
{
	cout<<" 1525. Number of Good Ways to Split a String "<<endl;

	// example 1
	// string s = "aacaba";

	// example 2
	// string s = "abcd";

	// example 3
	// string s = "aaaaa";

	// example 4
	string s = "acbadbaada";

	cout<<" s = "<<s<<endl;

	int answer = numSplits(s);

	cout<<" answer = "<<answer<<endl;

}