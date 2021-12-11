#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

// dynamic programming video 18
// longest  palindromic subsequence problem - find longest  longest palindromic subsequence for given strings of length n 
// time complexity - o (n*n)
// space complexity - o (n*n)

int maxval(int a,int b)
{
	if(a<b)
		return b;
	else
		return a;
}


string getPalSubsequence(vector<vector<int>> vtemp,string input)
{
	int i,j,k,n;

	n = input.length();

	vector<char> vf;
	vector<char> vb;
    
    i=0;
    j=n-1;

   // getting palindromic subsequence
	while(true)
	{
		if (vtemp[i][j]!=0)
		{
			if((vtemp[i][j]==(2+vtemp[i+1][j-1])) && (input[i]==input[j]))
			{
		     vf.push_back(input[i]);
		     vb.push_back(input[j]);
		     cout<<"cond1"<<endl;
		     i=i+1;
		     j=j-1; 
			}
			else if((i-j)==0 && (vtemp[i][j]==1))
			{
             vf.push_back(input[i]);
             cout<<"cond2"<<endl;
             i=i+1;
             j=j-1;
			}
			else if (vtemp[i][j]==vtemp[i+1][j])
			{
				cout<<"cond3"<<endl;
				i=i+1;
			}
			else if (vtemp[i][j]==vtemp[i][j-1])
			{
				cout<<"cond4"<<endl;
				j=j-1;
			}
	    }
	    else
	    	break;
	}

	string answer="";
    
    // storing vf to answer
	for(i=0;i<vf.size();i++)
		answer=answer+vf[i];

    // storing vb to answer
	for(i=vb.size()-1;i>=0;i--)
		answer=answer+vb[i];

	return answer;
}


int longestPalindromicSubsequence(string input)
{
	int i,j,k,len,n;

	n = input.length();
   
	int temp[n][n];

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)
				temp[i][j]=1;
			else 
				temp[i][j]=0;
		}
	}

	// print the temp matrix
	cout<<" print the temp matrix before main code "<<endl;

	for (i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			cout<<temp[i][j]<<" ";
		cout<<endl;
	}

	// main code 
	for (len=2;len<=n;len++)
	{
		for(i=0;i<(n-len+1);i++)
		{
			j=i+len-1;

			if (input[i]==input[j])
				temp[i][j]=2+temp[i+1][j-1];
			else
				temp[i][j] = maxval(temp[i][j-1],temp[i+1][j]);
		}
	}

		

	// print the temp matrix
	cout<<" print the temp matrix after main code "<<endl;

	for (i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			cout<<temp[i][j]<<" ";
		cout<<endl;
	}

	vector<vector<int>> vtemp;

    for(i=0;i<=n;i++)
    {
    	vector<int> v;
    	for(j=0;j<=n;j++)
    		v.push_back(temp[i][j]);

    	vtemp.push_back(v);
    	v.clear();
    }

	int answer = temp[0][n-1];

	string palsubsequence = getPalSubsequence(vtemp,input);

	cout<<"longest palindromic subsequence  is --  "<<palsubsequence<<" of length "<<answer<<endl;

	return answer; 
}


int main()
{
	// string input ="agbdba";
    // string input ="agbdksdkba";
    string input ="agbdksddkba";
	cout<<"longest palindromic subsequence problem "<<endl;

	cout<<" input = "<<input<<endl;

	int answer = longestPalindromicSubsequence(input);

	cout<<" answer = "<<answer<<endl;

}
