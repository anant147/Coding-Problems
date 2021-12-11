#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
#include<cstring>
#include<unordered_map>
using namespace std;

vector<int> findNumOfValidWords1(vector<string>& words, vector<string>& puzzles)
{
	unordered_map<int,int> mp;

	int i,j,k,u,v,x,y,z;

	for (i=0;i<words.size();i++)
	{
		int wordval = 0;

		for (j=0;j<words[i].size();j++)
			wordval = wordval | (1<<(words[i][j]-'a'));

		mp[wordval]+=1;
	}

	vector<int> result;

	for (i=0;i<puzzles.size();i++)
	{
		int len = puzzles[i].size()-1;
		int count = 0;

		for (j=0;j<(1<<len);j++)
		{
			int puzval = (1<<(puzzles[i][0]-'a'));

			for (k=0;k<len;k++)
			{
				if ((j & (1<<k)))
					puzval = puzval | (1<<(puzzles[i][k+1]-'a'));
			}

			if (mp.count(puzval))
				count+=mp[puzval];
		}

		result.push_back(count);
	}

	return result;
}

vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles)
{
	unordered_map<int,int> mp;

	int i,j,k,u,v,x,y,z;

	for (i=0;i<words.size();i++)
	{
		int wordval = 0;

		for (j=0;j<words[i].size();j++)
		{
			wordval = wordval | (1<<(words[i][j]-'a'));
		}

		mp[wordval]+=1;
	}

	vector<int> result;

	for (i=0;i<puzzles.size();i++)
	{
		int puzval = 0;

		for (j=0;j<puzzles[i].size();j++)
			puzval = puzval | (1<<(puzzles[i][j]-'a'));

		int mask = puzval;
		int firstval = (1<<(puzzles[i][0]-'a'));
		int count = 0;

		while(true)
		{
			if ( ((puzval & firstval)==firstval) && mp.find(puzval) != mp.end())
				count += mp[puzval];


			if (puzval==0)
				break;

			puzval = (puzval-1) & mask;
		}

		result.push_back(count);
	}

	return result;
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles)
// {
// 	int i,j,k,u,v,x,y,z;

// 	vector<int> temp;

// 	vector<vector<int>> walpstor;
// 	vector<vector<int>> palpstor;
// 	vector<int> plenstor;

// 	char ctemp;

// 	for (i=0;i<words.size();i++)
// 	{
// 		temp.resize(26,0);

// 		for (j=0;j<words[i].size();j++)
// 		{
// 			ctemp = words[i][j];

// 			u = (int)(ctemp)-97;
// 			temp[u]++; 
// 		}

// 		walpstor.push_back(temp);
// 		temp.clear();
// 	}

// 	for (i=0;i<puzzles.size();i++)
// 	{
// 		temp.resize(26,0);

// 		for (j=0;j<puzzles[i].size();j++)
// 		{
// 			ctemp = puzzles[i][j];

// 			u = (int)(ctemp) - 97;
// 			temp[u]++;
// 		}

// 		palpstor.push_back(temp);
// 		temp.clear();
// 	}

// 	int n = puzzles.size();

// 	vector<int> wcnt;
// 	wcnt.resize(n,0);

// 	int count;
// 	int cond;

// 	for (i=0;i<palpstor.size();i++)
// 	{
// 		count = 0;
// 		for (j=0;j<walpstor.size();j++)
// 		{
// 			ctemp = puzzles[i][0];
// 			u = (int)(ctemp)-97;

// 			if (walpstor[j][u]>0)
// 			{
// 				cond=0;
// 				for (k=0;k<26;k++)
// 				{
// 					if (walpstor[j][k]>0)
// 					{
// 						if (palpstor[i][k]==0)
// 							cond=1;
// 					}

// 					if (cond==1)
// 						break;
// 				}

// 				if (cond==0)
// 					count++;
// 			}
// 		}
// 		wcnt[i] = count;
// 	}

// 	return wcnt;
// }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	cout<<" 1178. Number of Valid Words for Each Puzzle "<<endl;

	vector<string> words = {"aaaa","asas","able","ability","actt","actor","access"};

	vector<string> puzzles = {"aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"};

	int i;

	cout<<" printing the words vector :- "<<endl;
	for (i=0;i<words.size();i++)
		cout<<words[i]<<" ";
	cout<<endl;

	cout<<" printing the puzzles vector :- "<<endl;
	for (i=0;i<puzzles.size();i++)
		cout<<puzzles[i]<<" ";
	cout<<endl;
	cout<<endl;

	vector<int> answer = findNumOfValidWords(words, puzzles);

	cout<<" printing the answer vector :- "<<endl;
	for (i=0;i<answer.size();i++)
		cout<<answer[i]<<" ";
	cout<<endl;
}