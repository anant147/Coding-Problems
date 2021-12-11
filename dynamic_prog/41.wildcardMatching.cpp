#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

// dp video 41
// Wildcard matching problem - given text string and pattern string ,we have to find that pattern matches with text or not.
// time complexity - o(n*m)
// space complexty -  o(n*m)

bool wildcardMatching(string text,string pattern)
{
	int i,j,k,u,v,x,y,answer;

	int n=text.length();
	int m=pattern.length();

	bool temp[n+1][m+1];

	temp[0][0]=true;

	for(i=1;i<=n;i++)
		temp[i][0]=false;

	for(i=1;i<=m;i++)
		temp[0][i]=false;

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if ((text[i-1]==pattern[j-1]) || pattern[j-1]=='?')
				temp[i][j]=temp[i-1][j-1];
			else if (pattern[j-1]=='*')
				temp[i][j]=temp[i-1][j]|temp[i][j-1];
			else
				temp[i][j]=false;
		}
	}

	// printing the temp matrix
	cout<<" printing the temp matrix -- "<<endl;
	for(i=0;i<=n;i++)
	{
		for (j=0;j<=m;j++)
			cout<<temp[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;

	return temp[n][m];
}

int main()
{
	int i,j;
	// string text = "xaylmz";
	// string pattern = "x?y*z";

	// string text = "xpppktmu";
	// string pattern = "xp?p*m?";

	string text = "xuuutyaaab";
	string pattern = "xu*t?ab";


	cout<<" Wildcard matching problem "<<endl;
	cout<<" text string -- "<<text<<" , with length of "<<text.length()<<endl;
	cout<<" pattern string -- "<<pattern<<" , with length of "<<pattern.length()<<endl;
	cout<<endl;

	bool answer = wildcardMatching(text,pattern);

	if (answer == true)
	cout<<" text string match with the given pattern"<<endl;
	else
	cout<<" text string do not match with the given pattern"<<endl;

}