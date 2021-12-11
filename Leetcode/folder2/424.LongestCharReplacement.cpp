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

int characterReplacement(string s, int k)
{
	int i,j,u,v,x,y,z;

	int n = s.size();

	if (n<=k)
		return n;

	if (k==0)
	{
		int sum = 0;
		i=0;

		while (i<n)
		{
			int count = 0;
			j = i;
			u = (int)(s[i])-65;

			while (j<n)
			{
				v = (int)(s[j])-65;

				if (u==v)
				{
					count++;
					j++;
				}
				else
					break;
			}

			if (sum < count)
				sum = count;

			i=j;
		}

		return sum;
	}

	vector<int> indPres[26];

	for (i=0;i<n;i++)
	{
		u = (int)(s[i])-65;
		indPres[u].push_back(i);
	}

	vector<int> indNotPres[26];

	for (i=0;i<26;i++)
	{
		if (indPres[i].size() != 0)
		{
			int ilen = indPres[i].size();

			for (j=0;j<ilen;j++)
			{
				u = indPres[i][j];

				if (j==0)
				{
					if (u!=0)
					{
						for (x=0;x<u;x++)
							indNotPres[i].push_back(x);
					}

					if (ilen==1)
					{
						if (u!=(n-1))
						{
							for (x=u+1;x<n;x++)
								indNotPres[i].push_back(x);
						}
					}
				}
				else if (j==(ilen-1))
				{
					v = indPres[i][j-1];

					for (x=v+1;x<u;x++)
						indNotPres[i].push_back(x);

					if (u!=(n-1))
					{
						for (x=u+1;x<n;x++)
							indNotPres[i].push_back(x);
					}
				}
				else
				{
					v = indPres[i][j-1];

					for (x=v+1;x<u;x++)
					    indNotPres[i].push_back(x); 
				}
			}
		}
	}

	// cout<<" printing the indPres and indNotPres  vector :- "<<endl;
	// for (i=0;i<26;i++)
	// {
	// 	if (indPres[i].size()!=0)
	// 	{
	// 		cout<<" for i = "<<i<<endl;
	// 		for (j=0;j<indPres[i].size();j++)
	// 			cout<<indPres[i][j]<<" ";
	// 		cout<<endl;

	// 		for (j=0;j<indNotPres[i].size();j++)
	// 			cout<<indNotPres[i][j]<<" ";
	// 		cout<<endl;
	// 		cout<<endl;
	// 	}
	// }

	int cnt1, cnt2 , cnt3;
	int answer = k;
	int val;

	// cout<<" k = "<<k<<endl;

	for (i=0;i<26;i++)
	{
		if (indPres[i].size()!=0)
		{
			u = indPres[i].size()+k;

			if (u>=n)
			{
				answer = n;
			}
			else
			{
				int ilen = indNotPres[i].size();

				// cout<<" ilen = "<<ilen<<endl;

				for (j=0;j<ilen-k+1;j++)
				{
					v = j+k-1;

					cnt2 = indNotPres[i][v] - indNotPres[i][j]+1;

					if (j==0)
						cnt1 = indNotPres[i][j];
					else
						cnt1 = indNotPres[i][j]-indNotPres[i][j-1]-1;

					if (v==(ilen-1))
						cnt3 = (n-1) - indNotPres[i][v];
					else
						cnt3 = indNotPres[i][v+1]-indNotPres[i][v]-1;

					// cout<<"for i = "<<i<<" , j = "<<j<<" ,v = "<<v<<" ,cnt1 = "<<cnt1<<" , cnt2 = "<<cnt2<<" , cnt3 = "<<cnt3<<endl;

					if (answer < (cnt1 + cnt2 + cnt3))
						answer = (cnt1+cnt2+cnt3);
				}
			}
		}

		if (answer==n)
			break;
	}

	return answer;
}

int main()
{
	cout<<" 424. Longest Repeating Character Replacement "<<endl;

	// example 1
	// string s = "ABAB";
	// int k = 2;

	// example 2
	// string s = "AABABBA";
	// int k = 1;

	// example 3
	string s = "AAAB";
	int k = 0;

	cout<<" s = "<<s<<endl;
	cout<<" k = "<<k<<endl;

	int answer = characterReplacement(s, k);

	cout<<" answer = "<<answer<<endl;
}