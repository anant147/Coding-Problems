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

bool rabinKarpSubstringSearch(string text, string pattern)
{
	int i,j,k,u,v,x,y,z;

	int tlen = text.size();
	int plen = pattern.size();

	if (tlen < plen)
		return false;

	int hpval,htval;

	hpval = 0;
	htval = 0;

	int prval = 3;

	for (i=0;i<plen;i++)
	{
		u = (int)(pattern[i])-96;
		hpval = hpval + u*(pow(prval,i));
	}

	cout<<" hpval = "<<hpval<<endl;

	int cond=0;
	int trcond = 0;

	int val = 0;

	for (i=0;i<tlen-plen+1;i++)
	{
		if (cond==0)
		{
			cond = 1;

			htval = 0;

			for (j=0;j<plen;j++)
			{
				u = (int)(text[j])-96;
				htval = htval + u*(pow(prval,j));
			}

			if (htval == hpval)
			{
				val = 0;

				for (j=0;j<plen;j++)
				{
					if (pattern[j] != text[j])
					{
						val = 1; break;
					}
				}

				if (val==0)
					trcond=1;
			}
		}
		else
		{
			u = (int)(text[i-1])-96;
			htval = htval-u;
			htval = htval/prval;
			v = (int)(text[i+plen-1])-96;
			htval = htval + v*(pow(prval,plen-1));

			if (htval == hpval)
			{
				val = 0;

				for (j=0;j<plen;j++)
				{
					if (pattern[j] != text[i+j])
					{
						val=1;
						break;
					}
				}

				if (val==0)
					trcond = 1;
			}
		}

		if (trcond==1)
			break;
	}

	if (trcond==0)
		return false;
	else
		return true;
}

int main()
{
	cout<<" tp7 Rabin Karp Substring Search Pattern Matching problem "<<endl;

	// example 1
	// string text = "abdabc";
	// string pattern = "abc";

	// example 2
	// string text = "abedabc";
	// string pattern = "abc";

	// example 3
	// string text = "abcgabcflmxyz";
	// string pattern = "abc";

	// example 4
	// string text = "abcgabcflmxyz";
	// string pattern = "xyz";

	// // example 5
	string text = "abcgabcflmxyz";
	string pattern = "gab";

	cout<<" text = "<<text<<endl;
	cout<<" pattern = "<<pattern<<endl;

	bool answer = rabinKarpSubstringSearch(text, pattern);

	if (answer)
		cout<<" given pattern is found in the given text"<<endl;
	else
		cout<<" given pattern is not found in the given text."<<endl;
}