#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
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
	if (root!=NULL)
	{
	  cout<<root->val<<" ";
	  preorder(root->left);
	  preorder(root->right);
	}
}

bool isValidBSTInRange(struct TreeNode *root,int minval,int maxval)
{
	if (root==NULL)
		return true;

	int k = root->val;

	if (!((minval<k) && (k<maxval)))
		return false;
	else
	{
		return isValidBSTInRange(root->left,minval,k) && isValidBSTInRange(root->right,k,maxval);
	}
}

bool isValidBST(struct TreeNode *root)
{
	if (root==NULL)
		return true;

	if (root->left==NULL && root->right==NULL)
		return true;

	int maxval = pow(2,sizeof(int)*8-1)-1;
	int minval = (-1)*pow(2,sizeof(int)*8-1);

	return isValidBSTInRange(root,minval,maxval);
}

int main()
{
	cout<<" 98. Validate Binary Search Tree "<<endl;

	struct TreeNode *root = NULL;
	struct TreeNode *rootl = NULL;
	struct TreeNode *rootr = NULL;
	struct TreeNode *root1 = NULL;
	struct TreeNode *root2 = NULL;
	struct TreeNode *root3 = NULL;
	struct TreeNode *root4 = NULL;

	// tree example 1
	// root1 = newNode(1);
	// root2 = newNode(3);
	// root = merge(2,root1,root2);

	// tree example 2
	rootl = newNode(1);

	root1 = newNode(3);
	root2 = newNode(6);
	rootr = merge(4,root1,root2);

	root = merge(5,rootl,rootr);

	cout<<" Preorder of the binary tree --> "<<endl;
	preorder(root);
	cout<<endl;

	bool answer = isValidBST(root);
	cout<<" answer = "<<answer<<endl; 
}