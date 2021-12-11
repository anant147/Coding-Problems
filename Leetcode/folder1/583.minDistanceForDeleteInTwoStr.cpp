#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int minval(int a,int b)
{
	if (a<b)
		return a;
	else
		return b;
}

int minval3(int a,int b,int c)
{
	return minval(a,minval(b,c));
}

int minDistance(string word1,string word2)
{
	int i,j,k,u,v,x,y,answer;

	int n = word1.length();
	int m = word2.length();

	if (n==0 && m==0)
		return 0;
	else if (n==0)
		return m;
	else if (m==0)
		return n;

	int temp[n+1][m+1];

	for (i=0;i<=n;i++)
		temp[i][0]=i;

	for (i=1;i<=m;i++)
		temp[0][i]=i;

	for (i=1;i<=n;i++)
	{
		for (j=1;j<=m;j++)
		{
			if (word1[i-1]==word2[j-1])
				temp[i][j]=temp[i-1][j-1];
			else 
				temp[i][j]=minval3(1+temp[i][j-1],2+temp[i-1][j-1],1+temp[i-1][j]);
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
	string word1 = "sea";
	string word2 = "eat";
	cout<<" 583. delete operations for two strings "<<endl;
	cout<<" word1 = "<<word1<<endl;
	cout<<" word2 = "<<word2<<endl;
	int answer = minDistance(word1,word2);
	cout<<" answer = "<<answer<<endl;
}