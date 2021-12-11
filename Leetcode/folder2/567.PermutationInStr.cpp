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

bool checkInclusion(string s1, string s2)
{
	int i,j,k,u,v,x,y,z;

	int n = s1.size();
	int m = s2.size();

	if (n>m)
		return false;

	vector<int> chstor;
	chstor.resize(26,0);

	for (i=0;i<n;i++)
	{
		k = (int)(s1[i])-97;
		chstor[k]++;
	}

	vector<int> temp;
	vector<vector<int>> alphstor;

	for (i=0;i<m;i++)
	{
		temp.resize(26,0);

		k = (int)(s2[i])-97;
		temp[k]=1;

		if (i==0)
		{
			alphstor.push_back(temp);
		}
		else
		{
			for (j=0;j<26;j++)
				temp[j] = temp[j] + alphstor[i-1][j];

			alphstor.push_back(temp);
		}

		temp.clear();
	}

	int cond1 = 0;

	for (i=0;i<m-n+1;i++)
	{
		int cond2 = 0;

		if (i==0)
		{
			for (j=0;j<26;j++)
			{
				if (alphstor[n-1][j] != chstor[j])
				{
					cond2=1;
					break;
				}
			}

			if (cond2==0)
				cond1=1;
		}
		else
		{
			for (j=0;j<26;j++)
			{
				if ( (alphstor[i+n-1][j] - alphstor[i-1][j]) != chstor[j])
				{
					cond2=1;
					break;
				}
			}

			if (cond2==0)
				cond1=1;
		}

		if (cond1==1)
			break;
	}

	if (cond1==1)
		return true;
	else
		return false;
}

int main()
{
	cout<<" 567. Permutation in String "<<endl;

	// example 1
	// string s1 = "ab";
	// string s2 = "eidbaooo";

	// example 2
	string s1 = "ab";
	string s2 = "eidboaoo";

	cout<<" s1 = "<<s1<<endl;
	cout<<" s2 = "<<s2<<endl;

	bool answer = checkInclusion(s1,s2);

	if (answer)
		cout<<" Permutation of s1 is in s2  "<<endl;
	else
		cout<<" Permutation of s1 is not in s2 "<<endl;


}