#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
	struct TrieNode *children[26];
	bool IsEnd;
};

struct TrieNode *getNode()
{
	struct TrieNode *pnode = new TrieNode;

	pnode->IsEnd = false;
    
    for(int i=0;i<26;i++)
    	pnode->children[i]=NULL;

    return pnode;
}


void insert(struct TrieNode *root,string key)
{
	struct TrieNode *pCrawl = root;

	for(int i=0;i<key.length();i++)
	{
		int index = key[i]-'a';

		if(!pCrawl->children[index])
			pCrawl->children[index]=getNode();

		pCrawl=pCrawl->children[index];
	}

	pCrawl->IsEnd=true;
}


bool search(struct TrieNode *root,string key)
{
	struct TrieNode *pCrawl = root;

	for(int i=0;i<key.length();i++)
	{
		int index = key[i]-'a';

		if(!pCrawl->children[index])
			return false;

		pCrawl=pCrawl->children[index];
	}

	return (pCrawl!=NULL && pCrawl->IsEnd);
}

bool isEmpty(struct TrieNode *root)
{
	for(int i=0;i<26;i++)
	{
		if(root->children[i]!=NULL)
			return false;
	}

	return true;
}



TrieNode* remove(struct TrieNode *root,string key, int depth)
{
	if(!root)
		return NULL;

	if(depth==key.size())
	{
		if(root->IsEnd)
			root->IsEnd=false;

		if(isEmpty(root))
		{
			delete(root);
			root=NULL;
		}

		return root;
	}

	int val = key[depth]-'a';

	root->children[val] = remove(root->children[val],key,depth+1);

	if(isEmpty(root) && root->IsEnd ==false)
	{
		delete(root);
		root=NULL;
	}

	return root;


}

void display(struct TrieNode* root,string s,int level)
{
 if(root->IsEnd==true)
 {
 	s=s+'\0';
 	cout<<s<<endl;
 }



 int i;
 for(i=0;i<26;i++)
 {
  if(root->children[i])
  {
  	char k=i+'a';
  	s=s+k;

  	// cout<<"hello"<<endl;

  	display(root->children[i],s,level+1);
  }
 }

}

int main()
{
	int i;

 	string keys[] = {"the","game","gamer","is","isended","there"};

 	int n = sizeof(keys)/sizeof(keys[0]);

 	struct TrieNode *root = getNode();

 	for(i=0;i<n;i++)
 		insert(root,keys[i]);

 	string keysto[] = {"them","is","you"};

 	for(i=0;i<3;i++)
 	{
 		bool val = search(root,keysto[i]);

 		if(val==true)
 		{
 			cout<<"Yes"<<endl;

 			remove(root,keysto[i],0);
 		}
 		else
 			cout<<"No"<<endl;
 	}

   string s="";
 	display(root,s,0);


}