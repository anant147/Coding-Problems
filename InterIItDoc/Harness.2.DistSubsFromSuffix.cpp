#include <bits/stdc++.h> 
using namespace std;

struct suffix
{
	int index;
	int rank[2];
};

int cmp(struct suffix a, struct suffix b)
{
	return (a.rank[0] == b.rank[0]) ? (a.rank[1] < b.rank[1] ? 1 : 0) : (a.rank[0] < b.rank[0] ? 1 : 0);
}

vector<int> buildSuffixArray(string txt)
{
	int n = txt.size();

	struct suffix suffixes[n];

	int i,j,k;

	for (i=0;i<n;i++)
	{
		suffixes[i].index = i;
		suffixes[i].rank[0] = txt[i]-'a';
		suffixes[i].rank[1] = ((i+1)<n) ? (txt[i+1]-'a') : -1;
	}

	sort(suffixes, suffixes+n, cmp);

	int ind[n];

	for (k=4;k<(2*n);k=k*2)
	{
		int rank = 0;
		int prev_rank = suffixes[0].rank[0];
		suffixes[0].rank[0] = rank;
		ind[suffixes[0].index] = 0;

		for (i=1;i<n;i++)
		{
			if (suffixes[i].rank[0] == prev_rank && suffixes[i].rank[1] == suffixes[i-1].rank[1])
			{
				prev_rank = suffixes[i].rank[0];
				suffixes[i].rank[0] = rank;
			}
			else
			{
				prev_rank = suffixes[i].rank[0];
				suffixes[i].rank[0] = ++rank;
			}

			ind[suffixes[i].index] = i;
		}

		for (i=0;i<n;i++)
		{
			int next_index = suffixes[i].index + (k/2);
			suffixes[i].rank[1] = (next_index < n) ? suffixes[ind[next_index]].rank[0] : -1;
		}

		sort(suffixes, suffixes+n, cmp);
	}

	vector<int> suffixArr;

	for (i=0;i<n;i++)
		suffixArr.push_back(suffixes[i].index);

	return suffixArr;
}

vector<int> kasai(string txt, vector<int> suffixArr)
{
	int n = suffixArr.size();

	vector<int> lcp;
	lcp.resize(n, 0);

	vector<int> invSuff;
	invSuff.resize(n, 0);

	for (int i=0;i<n;i++)
		invSuff[suffixArr[i]] = i;

	int k = 0;

	for (int i=0;i<n;i++)
	{
		if (invSuff[i] == n-1)
		{
			k = 0;
			continue;
		}

		int j = suffixArr[ invSuff[i]+1];

		while ((i+k)<n && (j+k)<n && txt[i+k]==txt[j+k])
			k++;

		lcp[invSuff[i]] = k;

		if (k>0)
			k--;
	}

	return lcp;
}

int countDistinctSubstring(string txt)
{
	int n = txt.size();

	vector<int> suffixArr = buildSuffixArray(txt);
	vector<int> lcp = kasai(txt, suffixArr);

	int result = n - suffixArr[0];

	for (int i=1;i<n;i++)
		result += (n - suffixArr[i]) - lcp[i-1];

	result++;

	return result;
}


int main()
{
	cout<<" 2. Harness question :- "<<endl;
	cout<<" Count of distinct substrings of a string using Suffix Array "<<endl;
	cout<<endl;

	// string txt = "ababa";
	// string txt = "abcd";
	string txt = "anant";
	cout<<" txt = "<<txt<<endl;

	int answer = countDistinctSubstring(txt);

	cout<<" answer = "<<answer<<endl;
}