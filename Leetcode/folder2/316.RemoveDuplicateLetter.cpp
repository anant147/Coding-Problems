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

string removeDuplicateLetters(string s)
{
	int i,j,k,u,v,x,y,z;

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

	stack<char> stk1;

	char ctemp;

	for (i=0;i<n;i++)
	{
		ctemp = s[i];
		k = (int)(ctemp)-97;
		freq[k]--;

		if (checker[k]==1)
			continue;

		while (!stk1.empty() && stk1.top()>ctemp && freq[(int)(stk1.top())-97]>0)
		{
			checker[(int)(stk1.top())-97] = 0;
			stk1.pop();
		}

		checker[k] = 1;
		stk1.push(ctemp);

	}

	string answer = "";

	while(!stk1.empty())
	{
		answer = stk1.top() + answer;
		stk1.pop();
	}

	return answer;
}

int main()
{
	cout<<" 316. Remove Duplicate Letters "<<endl;

	// example 1
	string s = "cdadabcc";

		// example 2
	// string s = "abcd";

	// example 3
	// string s = "ecbacba";

		// example 4
	// string s = "leetcode";

	// example 5
	// string s = "abacb";

	// example 6
	// string s = "bcabc";

	cout<<" s = "<<s<<endl;

	string answer = removeDuplicateLetters(s);

	cout<<" answer = "<<answer<<endl;

}