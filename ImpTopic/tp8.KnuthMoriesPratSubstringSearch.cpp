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

bool knuthMorrisPrattPatternMatch(string text, string pattern)
{
	int i,j,k,u,v,x,y,z;

	int tlen = text.size();
	int plen = pattern.size();

	if (tlen < plen)
		return false;

	vector<int> patsufval;
	patsufval.resize(plen,0);

	j=0;
	i=1;

	while(i<plen)
	{
		if (pattern[i] == pattern[j])
		{
			patsufval[i] = j+1;
			i++;
			j++;
		}
		else
		{
			if (j!=0)
				j = patsufval[j-1];
			else
				i++;
		}
	}

	cout<<" printing the patsufval vector :- "<<endl;
	for (i=0;i<patsufval.size();i++)
		cout<<patsufval[i]<<" ";
	cout<<endl;

	int cond = 0;
	i=0;
	j=0;

	while(j<plen && i<tlen)
	{
		if (pattern[j]==text[i])
		{
			i++;
			j++;
		}
		else
		{
			if (j!=0)
				j = patsufval[j-1];
			else
				i++;
		}

		if (j==plen)
			cond=1;
	}

	if (cond==1)
	{
		cout<<" matched "<<endl;
		return true;
	}
	else
	{
		cout<<" not matched "<<endl;
		return false;
	}
}

int main()
{
	cout<<" tp8. Knuth–Morris–Pratt(KMP) Pattern Matching(Substring search) "<<endl;

	// example 1
	// string text = "abcxabcdabxabcdabcdabcy";
	// string pattern = "abcdabcy";

	// example 2
	// string text = "acacabacacabacacacac";
	// string pattern = "acacabacacabacacac";

	// // example 3
	// string text = "abcabcabcghi";
	// string pattern = "abcda";

	// example 4
	string text = "ajwilldohiswork";
	string pattern = "andyanant";


	cout<<" text = "<<text<<endl;
	cout<<" pattern = "<<pattern<<endl;

	bool answer = knuthMorrisPrattPatternMatch(text, pattern);

	if (answer)
		cout<<" given pattern is found in the given text"<<endl;
	else
		cout<<" given pattern is not found in the given text."<<endl;
}