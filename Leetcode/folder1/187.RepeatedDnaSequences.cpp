#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
#include<cstring>
using namespace std;

vector<string> findRepeatedDnaSequences(string s)
{
	int i,j,k,u,v,x,y,z;

	int n = s.size();

	int tcnt = pow(4,10) + 10;

	vector<int> cntstor;
	cntstor.resize(tcnt,0);

	int cond = 0;
	int curval,preval;
	int sum = 0;

	preval = -1;

	vector<string> result;

	string temp = "";

	for (i=0;i<n-9;i++)
	{
		if (cond==0)
		{
			cond = 1;
			sum = 0;

			j=0;
			for (j=0;j<10;j++)
			{
				if (s[j]=='A')
					u = 0;
				else if (s[j]=='C')
					u = 1;
				else if (s[j]=='G')
					u = 2;
				else
					u = 3;

				sum = sum + u*pow(4,j);
			}

			curval = sum;
			cntstor[curval]++;
		}
		else
		{
			sum = preval/4;

			if (s[i+9]=='A')
				u = 0;
			else if (s[i+9]=='C')
				u = 1;
			else if (s[i+9]=='G')
				u = 2;
			else 
				u = 3;

			sum = sum + u*pow(4,9);

			curval = sum;
			cntstor[curval]++;
		}

		if (cntstor[curval]==2)
		{
			temp = s.substr(i,10);
			result.push_back(temp);
			temp = "";
		}

		preval = curval;
	}
	
	return result;
}

int main()
{
	cout<<" 187. Repeated DNA Sequences "<<endl;

	// example 1
	string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";

	cout<<" s = "<<s<<endl;

	vector<string> answer = findRepeatedDnaSequences(s);

	if (answer.size()==0)
		cout<<" no such strings are found "<<endl;
	else
	{
		cout<<" following are required strings :- "<<endl;
		for (int i=0;i<answer.size();i++)
			cout<<answer[i]<<endl;
	}
}

