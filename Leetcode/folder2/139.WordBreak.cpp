#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<stack>
#include<cmath>
#include<cstring>
using namespace std;

bool wordBreak(string s, vector<string>& wordDict)
{
	int i,j,k,u,v,x,y,z;

	int n = s.size();

	int m = wordDict.size();

	if (n==0 && m==0)
		return false;

	if (n==0)
	{
		for (i=0;i<wordDict.size();i++)
		{
			if (wordDict[i].size() == 0)
				return true;
		}
		return false;
	}

	sort(wordDict.begin(), wordDict.end());

	unordered_set<string> st;

	for (i=0;i<m;i++)
		st.insert(wordDict[i]);

	vector<vector<bool>> sol;
	sol.resize(n, vector<bool> (n,false));

	for (i=0;i<n;i++)
	{
		string temp = s.substr(i,1);

		if (st.find(temp) != st.end())
			sol[i][i] = true;
	}

	for (int len=2;len<=n;len++)
	{
		for (i=0;i<n-len+1;i++)
		{
			j = i+len-1;
			string temp = s.substr(i,len);

			if (st.find(temp) != st.end())
			{
				sol[i][j] = true;
			}
			else
			{
				for (k=i;k<j;k++)
				{
					if (sol[i][k] && sol[k+1][j])
					{
						sol[i][j] = true;
						break;
					}
				}
			}
		}
	}

	// cout<<" printing the sol vector :- "<<endl;
	// for (i=0;i<n;i++)
	// {
	// 	for (j=0;j<n;j++)
	// 		cout<<sol[i][j]<<" ";
	// 	cout<<endl;
	// }
	// cout<<endl;

	return sol[0][n-1];
}

int main()
{
	cout<<" 139. Word Break "<<endl;

	// example 1
	// string s = "leetcode";
	// vector<string> wordDict = {"leet", "code"};

	// example 2
	// string s = "applepenapple";
	// vector<string> wordDict = {"apple", "pen"};

	// example 3
	string s = "catsandog";
	vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};

	cout<<"s = "<<s<<endl;
	cout<<" printing the wordDict vector :- "<<endl;
	for (int i=0;i<wordDict.size();i++)
		cout<<wordDict[i]<<" ";
	cout<<endl;
	cout<<endl;

	bool answer = wordBreak(s, wordDict);

	if (answer)
		cout<<" condition is satisfied"<<endl;
	else
		cout<<" condition is not satisfied "<<endl;
}