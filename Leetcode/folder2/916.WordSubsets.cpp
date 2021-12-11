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

vector<string> wordSubsets(vector<string>& A, vector<string>& B)
{
	int i,j,k,u,v,x,y,z;

	vector<int> bstor,temp;
	bstor.resize(26,0);

	string stemp;

	for (i=0;i<B.size();i++)
	{
		stemp = B[i];
		temp.resize(26,0);

		for (j=0;j<stemp.size();j++)
		{
			k = (int)(stemp[j])-97;
			temp[k]++;
		}

		for (j=0;j<26;j++)
		{
			if (bstor[j] < temp[j])
				bstor[j] = temp[j];
		}

		temp.clear();
	}

	vector<string> result;
	int cond;

	for (i=0;i<A.size();i++)
	{
		stemp = A[i];
		temp.resize(26,0);

		for (j=0;j<stemp.size();j++)
		{
			k = (int)(stemp[j])-97;
			temp[k]++;
		}

		cond = 0;
		for (j=0;j<26;j++)
		{
			if (bstor[j]!=0 && bstor[j] > temp[j])
			{
				cond = 1;
				break;
			}
		}

		if (cond==0)
			result.push_back(stemp);

		temp.clear();
	}

	return result;
}

int main()
{
	cout<<" 916. Word Subsets "<<endl;

	// example 1
	// vector<string> A = {"amazon","apple","facebook","google","leetcode"};
	// vector<string> B = {"e","o"};

	// example 2
	// vector<string> A = {"amazon","apple","facebook","google","leetcode"};
	// vector<string> B = {"l","e"};

	// example 3
	// vector<string> A = {"amazon","apple","facebook","google","leetcode"};
	// vector<string> B = {"e","oo"};

	// example 4
	// vector<string> A = {"amazon","apple","facebook","google","leetcode"};
	// vector<string> B = {"lo","eo"};

	// example 5
	vector<string> A = {"amazon","apple","facebook","google","leetcode"};
	vector<string> B = {"ec","oc","ceo"};

	cout<<" printing the A vector :- "<<endl;
	for (int i=0;i<A.size();i++)
		cout<<A[i]<<" ";
	cout<<endl;

	cout<<" printing the B vector :- "<<endl;
	for (int i=0;i<B.size();i++)
		cout<<B[i]<<" ";
	cout<<endl;

	cout<<endl;

	vector<string> answer = wordSubsets(A,B);
	cout<<" printing the answer vector :- "<<endl;
	for (int i=0;i<answer.size();i++)
		cout<<answer[i]<<" ";
	cout<<endl;


}