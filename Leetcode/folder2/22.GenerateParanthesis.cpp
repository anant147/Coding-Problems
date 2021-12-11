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

vector<string> generateParenthesis(int n)
{
	int i,j,k,u,v,x,y,z;
	int slen;

	if (n==1)
		return {"()"};

	vector<string> vcur,vprev;
	vector<string>:: iterator vstrit;

	string stemp, nstemp;

	vprev.push_back("()");

	for (i=2;i<=n;i++)
	{
		for (j=0;j<vprev.size();j++)
		{
			slen = vprev[j].size();
			stemp = vprev[j];

			for (k=0;k<=slen;k++)
			{
				if (k==0)
				{
					nstemp = "()"+stemp;
					vcur.push_back(nstemp);
				}
				else if (k==slen)
				{
					nstemp = stemp + "()";
					vcur.push_back(nstemp);
				}
				else
				{
					nstemp = stemp.substr(0,k) + "()" + stemp.substr(k,slen-k);
					vcur.push_back(nstemp);
				}
			}
		}

		sort(vcur.begin(), vcur.end());
		vstrit = unique(vcur.begin(), vcur.end());
		vcur.resize(distance(vcur.begin(),vstrit));

		vprev.clear();
		vprev = vcur;
		vcur.clear();
	}

	return vprev;
}

int main()
{
	cout<<" 22. Generate Parentheses "<<endl;

	// example 1
	// int n = 1;

	// example 2
	// int n = 3;

	// example 3
	int n = 8;

	vector<string> answer = generateParenthesis(n);

	cout<<" printing the answer vector :- "<<endl;
	for (int i=0;i<answer.size();i++)
		cout<<answer[i]<<" ";
	cout<<endl;
	cout<<endl;




}