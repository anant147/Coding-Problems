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
	if (root != NULL)
	{
	  cout<<root->val<<" ";
	  preorder(root->left);
	  preorder(root->right);
	}
}

int maxval2(int a,int b)
{
	if (a>b)
		return a;
	else 
		return b;
}

int maxval3(int a,int b,int c)
{
	return maxval2(a,maxval2(b,c));
}

long long int sumOfTree(struct TreeNode* root)
{
	if (root==NULL)
		return (long long int)0;

	if (root->left==NULL && root->right==NULL)
		return (long long int)(root->val);

	long long int lsum = sumOfTree(root->left);
	long long int rsum = sumOfTree(root->right);

	return (long long int)((root->val) + lsum + rsum);
}

int prodSplitted(struct TreeNode* root,long long int msum)
{
	long long int modval = pow(10,9)+7;
	int i,j,k,x,y,z,p;

	long long int u,v;

	if (root==NULL)
		return 0;

	if (root->left==NULL && root->right==NULL)
	{
		u = (long long int)(root->val);
		v = msum - u;
		p = (int)((u*v)%modval);
		return p;
	}

	long long int lsum = sumOfTree(root->left);
	long long int rsum = sumOfTree(root->right);

	long long int tsum = (long long int)((root->val)+lsum + rsum);

	v = msum - tsum;
	p = (int)((tsum*v)%modval);

	int lprod = prodSplitted(root->left,msum);
	int rprod = prodSplitted(root->right,msum);

	return maxval3(p,lprod,rprod);
}

int maxProduct(struct TreeNode* root)
{
	int i,j,k,u,v,x,y,z;

	int modval = pow(10,9)+7;

	long long int maxsum = sumOfTree(root);

	int maxprod = prodSplitted(root,maxsum);

	// cout<<" sum of the tree = "<<maxsum<<endl;

	return maxprod;
}

int main()
{
	cout<<" 1339. Maximum Product of Splitted Binary Tree "<<endl;

	struct TreeNode *root = NULL;
	struct TreeNode *rootl = NULL;
	struct TreeNode *rootr = NULL;
	struct TreeNode *root1 = NULL;
	struct TreeNode *root2 = NULL;
	struct TreeNode *root3 = NULL;
	struct TreeNode *root4 = NULL;

	// tree example 1
	root1 = newNode(4);
	root2 = newNode(5);
	rootl = merge(2,root1,root2);

	root1 = newNode(6);
	rootr = merge(3,root1,NULL);

	root = merge(1,rootl,rootr);

	cout<<" Preorder of the given binary tree -- "<<endl;
	preorder(root);
	cout<<endl;
	cout<<endl;

	int answer = maxProduct(root);

	cout<<" answer = "<<answer<<endl;

}