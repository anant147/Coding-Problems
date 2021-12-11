#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
using namespace std;

// dp video 33
// regular expression text - pattern matching problem - given string text of length n and string pattern of length m
// time complexity - o(n*m)
// space complexty - o(n*m)

bool regularExpressionTp(string text,string pattern)
{
	int i,j,k,u,v;

	int n = text.length();
	int m = pattern.length();

	bool temp[n+1][m+1];

	temp[0][0] = true;

	for (i=1;i<=m;i++)
		temp[0][i] = false;

	for (i=1;i<=n;i++)
		temp[i][0] = false;

	for (i=1;i<=n;i++)
	{
		for (j=1;j<=m;j++)
		{
			if (text[i-1] == pattern[j-1] || pattern[j-1] == '.')
				temp[i][j] = temp[i-1][j-1];
			else if (pattern[j-1] == '*')
			{
				temp[i][j] = temp[i][j-2];


				if (text[i-1] == pattern[j-2] || pattern[j-2] == '.')
				{
					temp[i][j] =  temp[i][j] | temp[i-1][j] | temp[i][j-1];
				}
				// cout<<"at i = "<<i<<" , j = "<<j<<" , vt - "<<text[i-1]<<" ,vp "<<pattern[j-2]<<" val - "<<temp[i][j]<<endl;
			}
			else
				temp[i][j] = false;
		}
	}

	// printing the temp matrix 
	cout<<" printing the temp matrix -- "<<endl;
	for (i=0;i<=n;i++)
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
	// string text = "xaabyc";
	// string text = "xaaaabkcy";
	// string pattern = "xa*b.c";

	// string text = "xaabyjjjnmo";
	// string text = "xbjjnp";
	// string pattern = "xa*b.j*n.o*";

	string text="aa";
	string pattern="a*";




	cout<<" regular expression text - pattern matching problem -- "<<endl;
	cout<<" text string -- "<<text<<endl;
	cout<<" pattern string -- "<<pattern<<endl;
	bool answer = regularExpressionTp(text,pattern);

	if (answer == true)
	cout<<"given text string - "<<text<<" is matched with pattern string - "<<pattern<<endl;
	else
	cout<<"given text string - "<<text<<" is not matched with pattern string - "<<pattern<<endl;

}