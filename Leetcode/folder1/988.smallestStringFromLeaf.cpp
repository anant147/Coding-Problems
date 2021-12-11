#include<iostream>
#include<stack>
#include<vector>
#include<cstring>
#include<utility>
#include<algorithm>
using namespace std;

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode* newNode(int val)
{
	struct TreeNode *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	root->val = val;
	root->left = NULL;
	root->right = NULL;

	return root;
}

struct TreeNode* merge(int val, struct TreeNode *left, struct TreeNode *right)
{
	struct TreeNode *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));

	root->val = val;
	root->left = left;
	root->right = right;

	return root;
}

void preorder(struct TreeNode *root)
{
	if (root != NULL)
	{
	  cout<<root->val<<" ";
	  preorder(root->left);
	  preorder(root->right);
	}
}

string smallestFromLeaf(struct TreeNode *root)
{
	struct TreeNode* curr = root;
	struct TreeNode* lnode = NULL;
	struct TreeNode* rnode = NULL;

	stack<pair<struct TreeNode*,pair<string,int>>> stk;

	pair<struct TreeNode*,pair<string,int>> pr1,pr2;

	int i,j,k,u,v,x,y,z;

	int cond;

	if (root == NULL)
		return "";

	string sval1 = "";
	string sval2 = "";
	sval1 = sval1 + (char)((root->val)+97);

	if (root->left == NULL && root->right == NULL)
		return sval1;

	stk.push(make_pair(curr,make_pair(sval1,0)));

	vector<string> stresult;

	while( !stk.empty())
	{
		pr1 = stk.top();

		curr = pr1.first;
		sval1 = pr1.second.first;
		cond = pr1.second.second;

		if (cond == 0)
		{
			lnode = curr->left;

			if (lnode != NULL)
			{
				sval2 = sval1 + (char)((lnode->val)+97);

				stk.pop();
				stk.push(make_pair(curr,make_pair(sval1,1)));
				stk.push(make_pair(lnode,make_pair(sval2,0)));

				if (lnode->left == NULL && lnode->right == NULL)
					stresult.push_back(sval2);
			}
			else
			{
				stk.pop();
				stk.push(make_pair(curr,make_pair(sval1,1)));
			}
		}
		else if (cond ==1)
		{
			rnode = curr->right;

			if (rnode != NULL)
			{
				sval2 = sval1 + (char)((rnode->val)+97);

				stk.pop();
				stk.push(make_pair(curr,make_pair(sval1,2)));
				stk.push(make_pair(rnode,make_pair(sval2,0)));

				if (rnode->left == NULL && rnode->right == NULL)
					stresult.push_back(sval2);
			}
			else
			{
				stk.pop();
				stk.push(make_pair(curr,make_pair(sval1,2)));
			}
		}
		else if (cond == 2)
		{
			stk.pop();
		}
	}

	vector<string> result;
    // cout<<" obtained strings -- "<<endl;
	for (i=0;i<stresult.size();i++)
	{
		sval1 = stresult[i];
		reverse(sval1.begin(),sval1.end());
		result.push_back(sval1);
		// cout<<sval1<<endl;
	}
	// cout<<endl;

	sort(result.begin(),result.end());

	return result[0];
}

int main()
{
	struct TreeNode* root = NULL;
	struct TreeNode* rootl = NULL;
	struct TreeNode* rootr = NULL;
	struct TreeNode* root1 = NULL;
	struct TreeNode* root2 = NULL;
	struct TreeNode* root3 = NULL;
	struct TreeNode* root4 = NULL;

	// tree example 1
	// root1 = newNode(3);
	// root2 = newNode(4);
	// rootl = merge(1,root1,root2);

	// root1 = newNode(3);
	// root2 = newNode(4);
	// rootr = merge(2,root1,root2);

	// root = merge(0,rootl,rootr);

	// tree example 2
	// root1 = newNode(0);
	// root1 = merge(1,root1,NULL);
	// rootl = merge(2,NULL,root1);

	// root1 = newNode(0);
	// rootr = merge(1,root1,NULL);

	// root = merge(2,rootl,rootr);

	// tree example 3
	root1 = newNode(1);
	root2 = newNode(3);
	rootl = merge(1,root1,root2);

	root1 = newNode(0);
	root2 = newNode(2);
	rootr = merge(3,root1,root2);

	root = merge(25,rootl,rootr);

	cout<<" 988. Smallest String Starting From Leaf "<<endl;
	cout<<" Preorder of the given binary tree --- "<<endl;
	preorder(root);
	cout<<endl;

	cout<<endl;

	string result = smallestFromLeaf(root);
	cout<<" resultant string -- "<<result<<endl;


}