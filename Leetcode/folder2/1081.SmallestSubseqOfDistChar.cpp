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

string smallestSubsequence(string s)
{
	int i,j,k;

	int n = s.size();

	if (n==0 || n==1)
		return s;

	vector<int> freq, checker;
	freq.resize(26,0);
	checker.resize(26,0);

	for (i=0;i<n;i++)
	{
		k = (int)(s[i])-97;
		freq[k]++;
	}

	stack<char> st;
	char ctemp;

	for (i=0;i<n;i++)
	{
		ctemp = s[i];
		k = (int)(ctemp)-97;
		freq[k]--;

		if (checker[k]==1)
			continue;

		while (!st.empty() && st.top() > ctemp && freq[(int)(st.top())-97]>0)
		{
			checker[(int)(st.top())-97] = 0;
			st.pop();
		}

		checker[k] = 1;
		st.push(ctemp);
	}

	string answer = "";

	while( !st.empty() )
	{
		answer = st.top() + answer;
		st.pop();
	}

	return answer;
}

int main()
{
	cout<<" 1081. Smallest Subsequence of Distinct Characters "<<endl;

	//example 1
	// string s = "bcabc";

	// example 2
	string s = "cbacdcbc";

	cout<<" s = "<<s<<endl;

	string answer = smallestSubsequence(s);

	cout<<" answer = "<<answer<<endl;


}