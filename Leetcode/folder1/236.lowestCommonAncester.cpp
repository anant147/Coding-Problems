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

struct TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
{
  if (root == NULL)
  	return NULL;

  if (root == p || root == q)
  	return root;

   TreeNode *left = lowestCommonAncestor(root->left,p,q);
   TreeNode *right = lowestCommonAncestor(root->right,p,q);

  if (left != NULL && right != NULL)
  	return root;

  if (left == NULL && right == NULL)
  	return NULL;

  if (left != NULL)
  	return left;
  else
  	return right;
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

	root1 = newNode(6);
	root2 = newNode(7);
	root3 = newNode(4);
	root2 = merge(2,root2,root3);
	rootl = merge(5,root1,root2);

	root1 = newNode(0);
	root2 = newNode(8);
	rootr = merge(1,root1,root2);

	root = merge(3,rootl,rootr);

    cout<<"236. Lowest Common Ancestor of a Binary Tree "<<endl;
	cout<<" Preorder of the binary tree --- "<<endl;
	preorder(root);
	cout<<endl;
	cout<<endl;

	// struct TreeNode *reuslt = lowestCommonAncestor(root, TreeNode* p, TreeNode* q);
}