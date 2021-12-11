#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int longestPalindromeSubseq(string s)
{
	int i,j,k,u,v,x,y,answer,len;

	int n = s.length();

	if (n==0)
		return 0;

	int temp[n][n];

	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			if (i==j)
				temp[i][j]=1;
			else
				temp[i][j]=0;
		}
	}

	for (len=2;len<=n;len++)
	{
		for (i=0;i<(n-len+1);i++)
		{
			j=i+len-1;

			if (len==2)
			{
               if(s[i]==s[j])
               	temp[i][j]=2;
               else
               	temp[i][j]=1;
			}
			else
			{
				if (s[i]==s[j])
					temp[i][j]=2+temp[i+1][j-1];
				else
				{
					if (temp[i+1][j] > temp[i][j-1])
						temp[i][j]=temp[i+1][j];
					else
						temp[i][j]=temp[i][j-1];
				}
			}
		}
	}

	// cout<<" printing the temp matrix -- "<<endl;
	// for (i=0;i<n;i++)
	// {
	// 	for (j=0;j<n;j++)
	// 		cout<<temp[i][j]<<" ";
	// 	cout<<endl;
	// }
	// cout<<endl;

	answer = temp[0][n-1];

	return answer;
}

int main()
{
	// string s = "bbbab";
	string s = "cbbd";

	cout<<" 516. longest pallindromic substring -- "<<endl;
	cout<<" string s = "<<s<<endl;

	int answer = longestPalindromeSubseq(s);
	cout<<" answer = "<<answer<<endl;
}