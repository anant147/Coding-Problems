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

int findTheLongestSubstring(string s)
{
	int i,j,k,u,v,x,y,z;

	int n = s.size();

	if (n==1)
	{
		if (s[0]=='a' || s[0]=='e' || s[0]=='i' || s[0]=='o' || s[0]=='u')
			return 0;
		else
			return 1;
	}

	vector<vector<int>> vwlstor;
	vector<int> temp;

	for (i=0;i<n;i++)
	{
		k = (int)(s[i])-97;

		if (k==0)
			vwlstor.push_back({1,0,0,0,0});
		else if (k==4)
			vwlstor.push_back({0,1,0,0,0});
		else if (k==8)
			vwlstor.push_back({0,0,1,0,0});
		else if (k==14)
			vwlstor.push_back({0,0,0,1,0});
		else if (k==20)
			vwlstor.push_back({0,0,0,0,1});
		else
			vwlstor.push_back({0,0,0,0,0});

	}

	vector<int> valstor;
	int sum = 0;

	// cout<<" printing the vwlstor vector :- "<<endl;
	for (i=0;i<vwlstor.size();i++)
	{
		sum = 0;
		// cout<<"char = "<<s[i]<<endl;
		for (j=0;j<vwlstor[i].size();j++)
		{

			k = vwlstor[i][j];
			// cout<<k<<" ";
			if (k==1)
			{
				sum = sum + pow(2,j);
			}
		}
		// cout<<endl;

		valstor.push_back(sum);
	}

	// cout<<" printing the valstor "<<endl;
	// for (i=0;i<valstor.size();i++)
	// 	cout<<valstor[i]<<" ";
	// cout<<endl;

	vector<int> numval;
	numval.resize(32,-1);

	int len = 0;
	int val = 0;

	for (i=0;i<n;i++)
	{
		val = val^valstor[i];

		if (val==0)
		{
			x = i+1;

			if (len<x)
				len = x;
		}
		else
		{
			if (numval[val]==-1)
				numval[val]=i;
			else
			{
				x = i - numval[val];

				if (len<x)
					len = x;
			}
		}
	}

	return len;
}

int main()
{
	cout<<" 1371. Find the Longest Substring Containing Vowels in Even Counts "<<endl;

	// example 1
	// string s = "eleetminicoworoep";

	// example 2
	// string s = "leetcodeisgreat";

	// example 3
	string s = "bcbcbc";

	cout<<" s = "<<s<<endl;

	int answer = findTheLongestSubstring(s);

	cout<<" answer = "<<answer<<endl;	
}