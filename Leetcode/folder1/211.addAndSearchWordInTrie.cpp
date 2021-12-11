#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<cstring>
#include<cmath>
using namespace std;

struct TrieNode
{
	struct TrieNode *children[26];
	bool isEndOfWord;
};

struct TrieNode* getNode()
{
	struct TrieNode *root = (struct TrieNode*)malloc(sizeof(struct TrieNode));

	for (int i=0;i<26;i++)
		root->children[i]=NULL;

	root->isEndOfWord = false;

	return root;
}

void insert(struct TrieNode* root,string key)
{
	struct TrieNode* tnode = root;

	int i,index;

	for (i=0;i<key.size();i++)
	{
		index =key[i]-'a';

		if (!tnode->children[index])
			tnode->children[index] = getNode();

		tnode = tnode->children[index];
	}

	tnode->isEndOfWord = true;
}

bool search(struct TrieNode* root,string key)
{
	// cout<<"key in function -- "<<key<<endl;
	struct TrieNode* tnode = root;
	struct TrieNode* pnode;

	int i,j,index,remlen;

	int len = key.size();

	bool cond1,cond2;

	string tempkey;

	for (i=0;i<key.size();i++)
	{
		if (key[i] =='.')
		{
			if (i==len-1)
			{
				cond1=false;

				for (j=0;j<26;j++)
				{
					if ((tnode->children[j])!=NULL)
					{
						pnode = tnode->children[j];
						if (pnode->isEndOfWord)
							cond1=true;
					}

					if (cond1==true)
						return true;
				}
				return false;
			}
			else
			{
				remlen = len-i-1;
				tempkey = key.substr(i+1,remlen);

				cond1 = false;
				cond2 = false;

				for (j=0;j<26;j++)
				{
					if ((tnode->children[j])!=NULL)
					{
						// cout<<"tempkey -- "<<tempkey<<endl;
						// cout<<"J = "<<j<<endl;
						pnode = tnode->children[j];
						cond2 = search(pnode,tempkey);
					}

					if (cond2==true)
						return true;
				}
				return false;
			}
		}
		else
		{
			index = key[i]-'a';
			// cout<<"index = "<<index<<endl;

			if (!(tnode->children[index]))
				return false;

			tnode = tnode->children[index];
		}
	}

	return ((tnode !=NULL) && (tnode->isEndOfWord==true));
}

int main()
{
	cout<<" 211. Add and Search Word - Data structure design "<<endl;

	struct TrieNode *root = getNode();

	vector<string> wordsToInsert = {"mad","bad","dad"};
	int i,j,k,u,v,x,y,z;

	cout<<" words to be inserted in trie --> "<<endl;
	for(i=0;i<wordsToInsert.size();i++)
	{
		cout<<i<<" "<<wordsToInsert[i]<<endl;
		insert(root,wordsToInsert[i]);
	}
	cout<<endl;

	vector<string> wordToSearch = {"pad","bad",".ad","b..","mad."};

	cout<<" words to be searched in trie --> "<<endl;
	bool cond;
	for (i=0;i<wordToSearch.size();i++)
	{
		cout<<i<<" "<<wordToSearch[i]<<endl;
		cond = search(root,wordToSearch[i]);
		if (cond)
			cout<<"found"<<endl;
		else
			cout<<"not found "<<endl;
	}


}