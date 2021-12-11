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

int findGrp(vector<vector<int>>& cstor, int x)
{
	if (cstor[x][0] != x)
		cstor[x][0] = findGrp(cstor, cstor[x][0]);

	return cstor[x][0];
}

void unionGrp(vector<vector<int>>& cstor, int x, int y)
{
	int px = findGrp(cstor, x);
	int py = findGrp(cstor, y);

	if (cstor[px][1] < cstor[py][1])
		cstor[px][0] = py;
	else if (cstor[px][1] > cstor[py][1])
		cstor[py][0] = px;
	else
	{
		cstor[py][0] = px;
		cstor[px][1]++;
	}
}

string smallestStringWithSwaps(string s, vector<vector<int>>& pairs)
{
	int i,j,k,u,v,x,y,z;

	int n = s.size();

	if (n==1)
		return s;

	string stemp = s;
	sort(stemp.begin(), stemp.end());

	if (stemp == s)
		return s;

	vector<int> chgrp[n];
	vector<vector<int>> cstor;
	cstor.resize(n, vector<int>(2,0));

	for (i=0;i<n;i++)
		cstor[i][0] = i;

	for (i=0;i<pairs.size();i++)
	{
		u = pairs[i][0]; v = pairs[i][1];

		x = findGrp(cstor, u);  
		y = findGrp(cstor, v);

		if (x != y)
		{
			unionGrp(cstor,u,v);
		}
	}

	for (i=0;i<n;i++)
	{
		x = findGrp(cstor, i);
		chgrp[x].push_back(i);
	}

	vector<int> index;
	vector<char> ctemp;

	string result = s;

	for (i=0;i<n;i++)
	{
		if (chgrp[i].size()>0)
		{
			for (j=0;j<chgrp[i].size();j++)
			{
				k = chgrp[i][j];
				index.push_back(k);
				ctemp.push_back(s[k]);
			}

			sort(index.begin(),index.end());
			sort(ctemp.begin(), ctemp.end());

			for (j=0;j<index.size();j++)
			{
				k = index[j];
				result[k] = ctemp[j];
			}

			index.clear();
			ctemp.clear();
		}
	}

	return result;
}

int main()
{
	cout<<" 1202. Smallest String With Swaps "<<endl;

	// example 1
	// string s = "dcab";
	// vector<vector<int>> pairs = {{0,3},{1,2}};

	// example 2
	// string s = "dcab";
	// vector<vector<int>> pairs = {{0,3},{1,2},{0,2}};

	// example 3
	string s = "cba";
	vector<vector<int>> pairs = {{0,1},{1,2}};

	cout<<" s = "<<s<<endl;
	cout<<" printing the pairs vector :- "<<endl;
	for (int i=0;i<pairs.size();i++)
		cout<<pairs[i][0]<<" , "<<pairs[i][1]<<endl;
	cout<<endl;

	string answer = smallestStringWithSwaps(s, pairs);

	cout<<" answer = "<<answer<<endl;



}

