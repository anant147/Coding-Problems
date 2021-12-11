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

vector<int> partitionLabels(string s)
{
	int i,j,k,u,v,x,y,z;

	int n = s.size();

	vector<int> alpstor[26];

	for (i=0;i<n;i++)
	{
		k = (int)(s[i])-97;
		alpstor[k].push_back(i);
	}

	int len,len1;

	vector<int> length;

	for (i=0;i<n;)
	{
		k = (int)(s[i])-97;
		len1 = alpstor[k].size();
		u = alpstor[k][0];
		v = alpstor[k][len1-1];

		if (u != v)
		{
			for (j=i+1;j<=v;j++)
			{
				k = (int)(s[j])-97;
				len1 = alpstor[k].size();

				x = alpstor[k][len1-1];

				if (v < x)
					v = x;
			}
		}

		len = v-u+1;
		length.push_back(len);
		i = v+1;
	}

	return length;
}

int main()
{
	cout<<" 763. Partition Labels "<<endl;

	// example 1
	string s = "ababcbacadefegdehijhklij";

	cout<<" s = "<<s<<endl;

	vector<int> answer = partitionLabels(s);

	cout<<" printing the answer vector :- "<<endl;
	for (int i=0;i<answer.size();i++)
		cout<<answer[i]<<" ";
	cout<<endl;

}