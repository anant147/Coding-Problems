#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int numDistinct(string s,string t)
{
	int i,j,k,u,v,x,y,answer;

	int n = s.length();
	int m = t.length();

	if (n==0 || m==0)
		return 0;

	int temp[n+1][m+1];

	for (i=0;i<=n;i++)
		temp[i][0]=1;

	for (i=1;i<=m;i++)
		temp[0][i]=0;

	for (i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if (s[i-1]==t[j-1])
				temp[i][j]=temp[i-1][j-1] + temp[i-1][j];
			else
				temp[i][j]=temp[i-1][j];
		}
	}

	// cout<<" printing the temp matrix -- "<<endl;
	// for (i=0;i<=n;i++)
	// {
	// 	for (j=0;j<=m;j++)
	// 		cout<<temp[i][j]<<" ";
	// 	cout<<endl;
	// }

	answer = temp[n][m];

	return answer;
}

int main()
{
	int i,j,k;
	// string s = "rabbbit";
	// string t = "rabbit";

	string s = "babgbag";
	string t = "bag";
	cout<<" 115 . Distinct Sequences -- "<<endl;
	cout<<" string s = "<<s<<endl;
	cout<<" string t = "<<t<<endl;
	int answer = numDistinct(s,t);
	cout<<" answer = "<<answer<<endl;
}