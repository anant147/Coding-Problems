#include<iostream>
#include<stack>
#include<vector>
#include<utility>
#include<algorithm>
#include<cmath>
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

/////////////////////////////////////////////////////////////////////////////////////////

string serialize(struct TreeNode* root)
{
	
}

int main()
{
	struct TreeNode *root = NULL;
	struct TreeNode *rootl = NULL;
	struct TreeNode *rootr = NULL;
	struct TreeNode *root1 = NULL;
	struct TreeNode *root2 = NULL;
	struct TreeNode *root3 = NULL;
	struct TreeNode *root4 = NULL;

	rootl = newNode(2);
	root1 = newNode(4);
	root2 = newNode(5);
	rootr = merge(3,root1,root2);

	root = merge(1,rootl,rootr);

	cout<<" 297. Serialize and Deserialize Binary Tree "<<endl;
	cout<<" preorder of the binary tree --- "<<endl;
	preorder(root);
	cout<<endl;

	string answer = serialize(root);

	cout<<" answer = "<<answer<<endl;



}