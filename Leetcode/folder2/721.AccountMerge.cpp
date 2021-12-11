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

int findGrp(vector<vector<int>>& astor, int x)
{
	if (astor[x][0] != x)
		astor[x][0] = findGrp(astor, astor[x][0]);

	return astor[x][0];
}

int unionGrp(vector<vector<int>>& astor, int x, int y)
{
	int px = findGrp(astor, x);
	int py = findGrp(astor, y);

	if (astor[px][1] < astor[py][1])
	{
		astor[px][0] = py;
		return py;
	}
	else if (astor[px][1] > astor[py][1])
	{
		astor[py][0] = px;
		return px;
	}
	else
	{
		astor[py][0] = px;
		astor[px][1]++;
		return px;
	}
}


vector<vector<string>> accountsMerge(vector<vector<string>>& accounts)
{
	int i,j,k,u,v,x,y,z;

	int n = accounts.size();

	if (n==1)
		return accounts;

	vector<vector<int>> astor;
	astor.resize(n, vector<int>(2,0));

	for (i=0;i<n;i++)
		astor[i][0] = i;

	vector<string> namstor, etemp;
	vector<vector<string>> mstor;

	string s1,s2;

	for (i=0;i<n;i++)
	{
		s1 = accounts[i][0];
		namstor.push_back(s1);

		for (j=1;j<accounts[i].size();j++)
		{
			s2 = accounts[i][j];
			etemp.push_back(s2);
		}

		mstor.push_back(etemp);
		etemp.clear();
	}

	unordered_map<string,int> mp;

	int cond = 0;
	int val = -1;

	for (i=0;i<n;i++)
	{
		cond = 0;
		val = -1;

		for (j=0;j<mstor[i].size();j++)
		{
			s1 = mstor[i][j];

			if (mp.find(s1)==mp.end())
				mp[s1] = i;
			else
			{
				val = mp[s1];

				if (namstor[val]==namstor[i] && val!=i)
				{
					cond = 1;
					// astor[i][0] = val;
					z = unionGrp(astor, val, i);
					val = z;
					break;
			    }
			}

			if (cond==1)
				break;
		}

		if (cond==1)
		{
			for (j=0;j<mstor[i].size();j++)
			{
				s1 = mstor[i][j];
				mp[s1] = val;
			}
		}
	}

	vector<int> relstor[n];

	for (i=0;i<n;i++)
	{
		x = findGrp(astor,i);
		relstor[x].push_back(i);
	}

	cout<<" printing the relstor vector :- "<<endl;
	for (i=0;i<n;i++)
	{
		cout<<" i = "<<i<<endl;
		for (j=0;j<relstor[i].size();j++)
			cout<<relstor[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;

	vector<vector<string>> result;
	vector<string> vstemp1, vstemp2;
	vector<string>::iterator vtit;

	for (i=0;i<n;i++)
	{
		if (astor[i][0]==i)
		{
			for (j=0;j<relstor[i].size();j++)
			{
				k = relstor[i][j];

				for (u=0;u<mstor[k].size();u++)
					vstemp1.push_back(mstor[k][u]);
			}

			sort(vstemp1.begin(), vstemp1.end());

			vtit = unique(vstemp1.begin(), vstemp1.end());
			vstemp1.resize(distance(vstemp1.begin(),vtit));

			vstemp2.push_back(namstor[i]);

			for (j=0;j<vstemp1.size();j++)
			{
				s1 = vstemp1[j];
				vstemp2.push_back(s1);
			}

			result.push_back(vstemp2);
			vstemp1.clear();
			vstemp2.clear();
		}
	}

	return result;
}

int main()
{
	cout<<" 721. Accounts Merge "<<endl;

	// example 1
	// vector<vector<string>> accounts = {
	// 	                              {"John", "johnsmith@mail.com", "john00@mail.com"}, 
	// 	                              {"John", "johnnybravo@mail.com"}, 
	// 	                              {"John", "johnsmith@mail.com", "john_newyork@mail.com"}, 
	// 	                              {"Mary", "mary@mail.com"}
	// 	                              };

	// example 2
	vector<vector<string>> accounts =  {
		                               {"David","David0@m.co","David4@m.co","David3@m.co"},
	                                   {"David","David5@m.co","David5@m.co","David0@m.co"},
	                                   {"David","David1@m.co","David4@m.co","David0@m.co"},
	                                   {"David","David0@m.co","David1@m.co","David3@m.co"},
	                                   {"David","David4@m.co","David1@m.co","David3@m.co"}
	                                   };

	cout<<" printing the accounts vector :- "<<endl;
	for (int i=0;i<accounts.size();i++)
	{
		for (int j=0;j<accounts[i].size();j++)
			cout<<accounts[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;

	vector<vector<string>> answer = accountsMerge(accounts);

	cout<<" printing the answer vector :- "<<endl;
	for (int i=0;i<answer.size();i++)
	{
		for (int j=0;j<answer[i].size();j++)
			cout<<answer[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
}