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

string customSortString(string s, string t)
{
	int i,j,k,u,v,x,y,z;

	int n = s.size();

	priority_queue<pair<int,int>> pq;
	pair<int,int> ptemp;

	for (i=0;i<n;i++)
	{
		k = (int)(s[i])-97;
		pq.push(make_pair(n-i,k));
	}

	n = t.size();

	vector<int> freq;
	freq.resize(26,0);

	for (i=0;i<n;i++)
	{
		k = (int)(t[i])-97;
		freq[k]++;
	}

	string answer = "";
	char ctemp;

	while (!pq.empty())
	{
		ptemp = pq.top();
		pq.pop();

		y = ptemp.second;

		if (freq[y]>0)
		{
			ctemp = (char)(y+97);

			while(freq[y]!=0)
			{
				answer.push_back(ctemp);
				freq[y]--;
			}
		}
	}

	for (i=0;i<26;i++)
	{
		if (freq[i]!=0)
		{
			ctemp = (char)(i+97);

			while( freq[i]!=0)
			{
				answer.push_back(ctemp);
				freq[i]--;
			}
		}
	}

	return answer;
}

int main()
{
	cout<<" 791. Custom Sort String "<<endl;

	string s = "cba";
	string t = "abcd";

	cout<<" s = "<<s<<endl;
	cout<<" t = "<<t<<endl;

	string answer = customSortString(s,t);

	cout<<" answer = "<<answer<<endl;
}