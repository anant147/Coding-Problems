#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<map>
#include<unordered_map>
#include<queue>
#include<stack>
#include<cmath>
#include<cstring>
#define a 0
#define e 1
#define i 2
#define o 3
#define u 4
using namespace std;


int maxval (int x,int y)
{
	if (x>y)
		return x;
	else
		return y;
}

int longestSubsequence(string s)
{
	int j;
	int n = s.size();

	int isa = 0;
	int ise = 0;
	int isi = 0;
	int iso = 0;
	int isu = 0;

	vector<int> dp;
	dp.resize(5,0);

	for (j=0;j<n;j++)
	{
		if (s[j]=='a')
		{
			dp[a]++;
			isa = 1;
		}
		else if (s[j]=='e' && isa==1)
		{
			dp[e] = maxval(1+dp[a], 1+dp[e]);
			ise = 1;
		}
		else if (s[j]=='i' && ise==1)
		{
			dp[i] = maxval(1+dp[e], 1+dp[i]);
			isi = 1;
		}
		else if (s[j]=='o' && isi==1)
		{
			dp[o] = maxval(1+dp[i],1+dp[o]);
			iso = 1;
		}
		else if (s[j]=='u' && iso==1)
		{
			dp[u] = maxval(1+dp[o], 1+dp[u]);
			isu = 1;
		}
	}

	if (isa==1 && ise==1 && isi==1 && iso==1 && isu==1)
		return dp[u];
	else
		return 0;
}

int main()
{
	cout<<" Sap Labs question "<<endl;
	cout<<" Magical Vowels "<<endl;

	// example 1
	// string s = "aeiou";

	// example 2
	// string s = "aeaiou";

	// ex3
	// string s = "aeeiou";

	string s = "aeaeiou";

	cout<<" s = "<<s<<endl;

	int answer = longestSubsequence(s);

	cout<<" answer = "<<answer<<endl;
}