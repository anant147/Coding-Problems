#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

// dynamic programming video 16
// longest  common substring problem - find longest  common substring for given element of two strings of length n and m respectively
// time complexity - o (n*m)
// space complexity - o (n*m)

string getlongestCommonSubstring(vector<vector<int>> vtemp,string input1,string input2,int u,int v)
{
	int i,j,k;
	vector<int> index1;

	int n=input1.length();
	int m=input2.length();

	i=u;
	j=v;
     
    // getting common substring
    cout<<"tracking the pattern "<<endl; 
	while(true)
	{

	if((i>=1 && j>=1) && (input1[i-1]==input2[j-1]))
	{
		index1.push_back(i-1);
		i=i-1;
		j=j-1;
		cout<<"1.i = "<<i<<endl;
		cout<<"1.j = "<<j<<endl;
	}
	else
		break;
	}

	string answer="";

	for(i=index1.size()-1;i>=0;i--)
		answer=answer+input1[index1[i]];


	return answer;
}

int longestCommonSubstring(string input1,string input2)
{
	int i,j,k,u,v,answer;

	int n=input1.length();
	int m=input2.length();

	int temp[n+1][m+1];

	for(i=0;i<=n;i++)
		temp[i][0]=0;

	for(i=0;i<=m;i++)
		temp[0][i]=0;

    // main code 
    for(i=1;i<=n;i++)
    {
    	for(j=1;j<=m;j++)
    	{
    		if (input1[i-1]==input2[j-1])
    			temp[i][j]=1+temp[i-1][j-1];
    		else
    			temp[i][j]=0;
    	}
    }

    // printing the temp matrix
    cout<<"printing the temp matrix "<<endl;

    answer =0;
    u=-1;
    v=-1;

    for(i=0;i<=n;i++)
    {
    	for(j=0;j<=m;j++)
    	{
    		cout<<temp[i][j]<<" ";
    		if (answer < temp[i][j])
    		{
    			answer=temp[i][j];
    			u=i;
    			v=j;
    		}
    	}
    	cout<<endl;
    }

    cout<<"max value in temp matrix = "<<answer<<" at position ( "<<u<<" , "<<v<<" )"<<endl;


    vector<vector<int>> vtemp;

    for(i=0;i<=n;i++)
    {
    	vector<int> v;
    	for(j=0;j<=m;j++)
    		v.push_back(temp[i][j]);

    	vtemp.push_back(v);
    	v.clear();
    }

    string subseq=getlongestCommonSubstring(vtemp,input1,input2,u,v);
    cout<<"longest subsequence = "<<subseq<<" of length = "<<answer<<endl;

	return answer;
}

int main()
{
 // string input1="abcdaf";
 // string input2="zbcdf";

 string input1="eeeabcdaf";
 string input2="bsreeeavbcdaf";

 int len1=input1.length();
 int len2=input2.length();
 cout<<" longest subsequence problem "<<endl;
 cout<<"input string1 = "<<input1<<" of length =  "<<len1<<endl;
 cout<<"input string2 = "<<input2<<" of length =  "<<len2<<endl;

 int answer = longestCommonSubstring(input1,input2);
 cout<<"answer = "<<answer<<endl;

}