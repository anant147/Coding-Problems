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

vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries)
{
	int i,j,k,u,v,x,y,z;

	int n = s.size();
	int m = queries.size();

	vector<vector<int>> chstor;

	for (i=0;i<n;i++)
	{
		k = (int)(s[i])-97;

		vector<int> temp;
		temp.resize(26,0);
		temp[k]++;

		if (i==0)
			chstor.push_back(temp);
		else
		{
			for (j=0;j<26;j++)
				temp[j] = temp[j] + chstor[i-1][j];

			chstor.push_back(temp);
		}

		temp.clear();
	}

	vector<bool> answer;

	for (i=0;i<queries.size();i++)
	{
		x = queries[i][0]; y = queries[i][1]; k = queries[i][2];

		int sum = 0;

		if (x==0)
		{
			for (j=0;j<26;j++)
			{
				if ( chstor[y][j]%2 == 1)
					sum++;
			}
		}
		else
		{
			for (j=0;j<26;j++)
			{
				if ( (chstor[y][j] - chstor[x-1][j])%2 == 1)
					sum++;
			}
		}

		int len = y-x+1;

		if (len%2 == 0)
		{

			sum = sum/2;

			if (sum <= k)
				answer.push_back(true);
			else
				answer.push_back(false);
		}
		else
		{
			sum = sum-1;
			sum = sum/2;

			if (sum <= k)
				answer.push_back(true);
			else
				answer.push_back(false);
		}
	}

	return answer;
}

int main()
{
	cout<<" Sap labs iit g question :- "<<endl;
	cout<<" 1177. Can Make Palindrome from Substring "<<endl;

	// example 1
	string s = "abcda";
	vector<vector<int>> queries =  {
		                           {3,3,0},
		                           {1,2,0},
		                           {0,3,1},
		                           {0,3,2},
		                           {0,4,1}
		                           };

	cout<<" s = "<<s<<endl;

	cout<<" printing the queries vector :- "<<endl;

	vector<bool> answer = canMakePaliQueries(s, queries);

	cout<<" printing the answer vector :- "<<endl;

	for (int i=0;i<answer.size();i++)
		cout<<answer[i]<<" ";
	cout<<endl;
}