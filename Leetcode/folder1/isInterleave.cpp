#include<iostream>
#include<vector>
#include<cstring>
#include<utility>
using namespace std;

bool isInterleave(string s1,string s2,string s3)
{
	int i,j,k,u,v,x,y;

	int n=s1.length();
	int m=s2.length();
	k = s3.length();

	if ((n+m)!=k)
		return false;

	if (n==0 && m==0 && k==0)
		return true;

	if (n==0 && m==0 && k!=0)
		return false;

	if ((n!=0 || m!=0) && k==0)
		return false;

	bool temp[n+1][m+1];

	temp[0][0]=true;

	for (i=1;i<=n;i++)
	{
		if (s1[i-1]==s3[i-1])
			temp[i][0]=temp[i-1][0];
		else
			temp[i][0]=false;
	}

	for (i=1;i<=m;i++)
	{
		if (s2[i-1]==s3[i-1])
			temp[0][i]=temp[0][i-1];
		else
			temp[0][i]=false;
	}

	for (i=1;i<=n;i++)
	{
		for (j=1;j<=m;j++)
		{
			if (s3[i+j-1]==s1[i-1] && s3[i+j-1]==s2[j-1])
				temp[i][j] = temp[i-1][j] | temp[i][j-1];
			else if (s3[i+j-1]==s1[i-1])
				temp[i][j] = temp[i-1][j];
			else if (s3[i+j-1]==s2[j-1])
				temp[i][j] = temp[i][j-1];
			else
				temp[i][j] = false;
		}
	}

	// print the temp matrix
	// cout<<" printing the temp matrix "<<endl;
	// for (i=0;i<=n;i++)
	// {
	// 	for (j=0;j<=m;j++)
	// 		cout<<temp[i][j]<<" ";
	// 	cout<<endl;
	// }
	// cout<<endl;


 return temp[n][m];
}

int main()
{
	int i,j,k,u,y;

	// string s1 = "aa";
	// string s2 = "bb";
	// string s3 = "abab";

	// string s1 = "aabcc";
	// string s2 = "dbbca";
	// string s3 = "aadbbcbcac";

	string s1 = "aabcc";
	string s2 = "dbbca";
	string s3 = "aadbbbaccc";

	cout<<" string interleaving problem "<<endl;
	cout<<" s1 = "<<s1<<endl;
	cout<<" s2 = "<<s2<<endl;
	cout<<" s3 = "<<s3<<endl;

	cout<<endl;
	bool answer = isInterleave(s1,s2,s3);

	if (answer)
	cout<<" two strings are interleaved with third string"<<endl;
	else
	cout<<" two strings are not interleaved with third string"<<endl;

}