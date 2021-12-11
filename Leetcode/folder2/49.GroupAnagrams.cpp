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

int findGrp(vector<vector<int>>& stor, int x)
{
	if (stor[x][0] != x)
		stor[x][0] = findGrp(stor, stor[x][0]);

	return stor[x][0];
}

void unionGrp(vector<vector<int>>& stor, int x, int y)
{
	int px = findGrp(stor, x);
	int py = findGrp(stor, y);

	if (stor[px][1] < stor[py][1])
		stor[px][0] = py;
	else if (stor[px][1] > stor[py][1])
		stor[py][0] = px;
	else
	{
		stor[py][0] = px;
		stor[px][1]++;
	}
}

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
	int i,j,k,u,v,x,y,z;

	int n = strs.size();

	vector<vector<int>> stor;
	stor.resize(n, vector<int>(2,0));

	for (i=0;i<n;i++)
		stor[i][0] = i;

	vector<string> ordstr;
	string stemp;

	for (i=0;i<strs.size();i++)
	{
		stemp = strs[i];
		sort(stemp.begin(), stemp.end());
		ordstr.push_back(stemp);
	}

	unordered_map<string,int> mp;

	for (i=0;i<ordstr.size();i++)
	{
		stemp = ordstr[i];

		if (mp.find(stemp) == mp.end())
		{
			mp[stemp] = i;
		}
		else
		{
			k = mp[stemp];

			x = findGrp(stor,k);
			y = findGrp(stor, i);

			if (x != y)
			{
				unionGrp(stor,i,k);
			}
		}
	}

	vector<int> idstor[n];

	for (i=0;i<n;i++)
	{
		x = findGrp(stor, i);
		idstor[x].push_back(i);
	}

	vector<vector<string>> result;
	vector<string> tempstor;

	for (i=0;i<n;i++)
	{
		if (stor[i][0]==i && (idstor[i].size()>0) )
		{
			for (j=0;j<idstor[i].size();j++)
			{
				k = idstor[i][j];
				tempstor.push_back(strs[k]);
			}

			result.push_back(tempstor);
			tempstor.clear();
		}
	}

	return result;
}

int main()
{
	cout<<" 49. Group Anagrams "<<endl;

	// example 1
	// vector<string> strs = {"eat","tea","tan","ate","nat","bat"};

	// example 2
	// vector<string> strs = {""};

	// example 3
	vector<string> strs = {"a"};

	cout<<" printing the strs vector :- "<<endl;
	int i,j,k,u,v;

	for (i=0;i<strs.size();i++)
		cout<<strs[i]<<" ";
	cout<<endl;
	cout<<endl;

	vector<vector<string>> answer = groupAnagrams(strs);

	cout<<" printing the answer vector :- "<<endl;
	for (i=0;i<answer.size();i++)
	{
		for (j=0;j<answer[i].size();j++)
			cout<<answer[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
}