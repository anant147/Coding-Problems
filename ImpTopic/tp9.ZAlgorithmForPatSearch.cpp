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

int ZAlgorithm(string text, string pattern)
{
	int i,j,k,u,v,x,y,z;

	int tlen = text.size();
	int plen = pattern.size();

	if (tlen < plen)
		return 0;

	string comb = pattern + '$' + text;

	cout<<" comb = "<<comb<<endl;

	int clen = comb.size();

	vector<int> zval;
	zval.resize(clen, 0);

	int left = 0;
	int right = 0;

	for (i=1;i<clen;i++)
	{
		if (i>right)
		{
			left = i;
			right = i;

			while (right<clen && comb[right] == comb[right-left])
				right++;

			zval[i] = right-left;
			right--;
		}
		else
		{
			k = i-left;

			if (zval[k] < right-i+1)
				zval[i] = zval[k];
			else
			{
				left = i;

				while(right < clen && comb[right] == comb[right-left])
					right++;

				zval[i] = right - left;
				right--;
			}
		}
	}

	cout<<" printing the zval vector :- "<<endl;
	for (i=0;i<zval.size();i++)
		cout<<zval[i]<<" ";
	cout<<endl;
	cout<<endl;

	int index = -1;
	int count = 0;
	for (i=0;i<zval.size();i++)
	{
		if (zval[i]==plen)
		{
			count++;
			index = i-plen-1;
			cout<<" "<<count<<" . pattern start at index val of "<<index<<endl;
		}
	}

	return count;
}

int main()
{
	cout<<" tp9. Z Algorithm for pattern search and its counting in given text "<<endl;

	// example 1
	// string text = "baabaa";
	// string pattern = "aab";

	// example 2
	string text = "aabxaabxcaabxaabxay";
	string pattern = "aab";

	cout<<" text = "<<text<<endl;
	cout<<" pattern = "<<pattern<<endl;

	int answer = ZAlgorithm(text, pattern);

	cout<<endl;
	cout<<" given pattern is match with given text "<<answer<<" times"<<endl;


}