#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

// dp video 35
// string interleaving problem - given 3 strings , we have to tell whether first two strings are interleaved to form the third string or not 
// time complexity - o(n * m)
// space complexty -  o(n * m)


bool stringInterleaving(string input1,string input2,string medinput)
{
	int i,j,u,v;

	int n=input1.length();
	int m=input2.length();
	int k=medinput.length();

	bool temp[n+1][m+1];

	temp[0][0]=true;

	for (i=1;i<=m;i++)
	{
		if (medinput[i-1]==input2[i-1])
			temp[0][i] = temp[0][i-1];
		else
			temp[0][i] = false;
	}

	for (i=1;i<=n;i++)
	{
		if (medinput[i-1]==input1[i-1])
			temp[i][0]=temp[i-1][0];
		else
			temp[i][0]=false;
	}

	for (i=1;i<=n;i++)
	{
		for (j=1;j<=m;j++)
		{
			if ((medinput[i+j-1] == input1[i-1]) && (medinput[i+j-1] == input2[j-1]))
				temp[i][j] = temp[i-1][j] | temp[i][j-1];
			else if (medinput[i+j-1] == input1[i-1])
				temp[i][j] = temp[i-1][j];
			else if (medinput[i+j-1] == input2[j-1])
				temp[i][j] = temp[i][j-1];
			else
				temp[i][j] = false;
		}
	}

	// print the temp matrix
	cout<<endl;
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

	// string input1 = "axy";
	// string input2 = "aab";
	// // string medinput = "aaxaby";
	// string medinput = "abaaxy";

    string input1 = "abcd";
    string input2 = "bedk";
    // string medinput = "abebcdkd";
    // string medinput = "abebcddk";
    string medinput = "abebckdd";
	int n = input1.length();
	int m = input2.length();
	int k = medinput.length();

	cout<<" string interleaving problem  "<<endl;
	cout<<" input1 string -- "<<input1<<endl;
	cout<<" length of input1 -- "<<n<<endl;
	cout<<" input2 string -- "<<input2<<endl;
	cout<<" length of input2 -- "<<m<<endl;
	cout<<" medinput string -- "<<medinput<<endl;
	cout<<" length of medinput -- "<<k<<endl;

	if ((n+m)!=k)
	{
	cout<<"interleaving of these strings is not possible "<<endl;
	}
	else
	{
	bool answer = stringInterleaving(input1,input2,medinput);

		if (answer == true)
		{
		cout<<"both input strings - "<<input1<<" and "<<input2<<" are interleaved with string - "<<medinput<<endl;
		}
		else
		{
		cout<<"both input strings - "<<input1<<" and "<<input2<<" are not interleaved with string - "<<medinput<<endl;
		}

	}
}