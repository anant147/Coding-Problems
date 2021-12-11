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

string reorganizeString(string s)
{
	int i,j,k,u,v,x,y,z;

	int n = s.size();

	if (n==1)
		return s;

	vector<int> freq;
	freq.resize(26,0);

	for (i=0;i<n;i++)
	{
		k = (int)(s[i])-97;
		freq[k]++;
	}

	priority_queue<pair<int,int>> pq;
	vector<pair<int,int>> vtmp1, vtmp2;

	pair<int,int> ptemp1, ptemp2;

	for (i=0;i<26;i++)
	{
		if (freq[i]!=0)
			pq.push(make_pair( freq[i], i));
	}

	int count = 0;
	string answer = "";
	char ctemp;

	while (count < n || !pq.empty())
	{
		if (!pq.empty())
		{
			ptemp1 = pq.top();
			pq.pop();

			x = ptemp1.first;
			y = ptemp1.second;

			ctemp = (char)(y+97);
			answer.push_back(ctemp);
			count++;

			if (x>1)
				vtmp1.push_back(make_pair( x-1,y));
	    }

		if (vtmp2.size()!=0)
		{
			for (j=0;j<vtmp2.size();j++)
			{
				ptemp1 = vtmp2[j];
				pq.push(ptemp1);
			}
			vtmp2.clear();
	    }

		if (!pq.empty())
		{
			ptemp1 = pq.top();
			pq.pop();

			x = ptemp1.first;
			y = ptemp1.second;

			ctemp = (char)(y+97);
			answer.push_back(ctemp);
			count++;

			if (x>1)
				vtmp2.push_back(make_pair(x-1,y));
		}

		if (vtmp1.size()!=0)
		{
			for (j=0;j<vtmp1.size();j++)
			{
				ptemp1 = vtmp1[j];
				pq.push(ptemp1);
			}
			vtmp1.clear();
	    }
	}

	int cond = 0;

	for (i=0;i<n-1;i++)
	{
		if (answer[i]==answer[i+1])
		{
			cond=1;
			break;
		}
	}

	if (cond==0)
		return answer;
	else
		return "";
}

int main()
{
	cout<<" 767. Reorganize String  "<<endl;

	// example 1
	string s = "aab";

	// example 2
	// string s = "aaab";

	cout<<" s = "<<s<<endl;

	string answer = reorganizeString(s);

	cout<<" answer = "<<answer<<endl;

}