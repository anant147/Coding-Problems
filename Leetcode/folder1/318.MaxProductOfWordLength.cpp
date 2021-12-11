#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
#include<cstring>
using namespace std;

int maxProduct(vector<string>& words)
{
	int i,j,k,u,v,x,y,z;

	vector<vector<int>> alphstor;
	vector<int> wordlen;

	for (i=0;i<words.size();i++)
	{
		x = words[i].size();
		wordlen.push_back(x);

		vector<int> temp;
		temp.resize(26,0);

		for (j=0;j<x;j++)
		{
			u = ((int)words[i][j])-97;
			temp[u]++;
		}

		alphstor.push_back(temp);
		temp.clear();
	}

	int cond=0;
	int val = 0;

	for (i=0;i<alphstor.size();i++)
	{
		for (j=i+1;j<alphstor.size();j++)
		{
			cond = 0;

			for (k=0;k<26;k++)
			{
				if (alphstor[i][k]>0 && alphstor[j][k]>0)
				{
					cond=1;
					break;
				}
			}

			if (cond == 0)
			{
				x = wordlen[i] * wordlen[j];

				if (val < x)
					val = x;
			}
		}
	}

	return val;
}

int main()
{
	cout<<" 318. Maximum Product of Word Lengths "<<endl;

	// example 1
	// vector<string> words = {"abcw","baz","foo","bar","xtfn","abcdef"};

	// example 2
	// vector<string> words = {"a","ab","abc","d","cd","bcd","abcd"};

	// example 3
	vector<string> words = {"a","aa","aaa","aaaa"};

	cout<<" printing the words vector :- "<<endl;
	for (int i=0;i<words.size();i++)
		cout<<words[i]<<"  ";
	cout<<endl;

	int answer = maxProduct(words);

	cout<<" answer =  "<<answer<<endl;
}