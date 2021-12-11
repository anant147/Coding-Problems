#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<cmath>
#include<unordered_map>
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

struct TreeNode* buildTreeFromInAndPost(vector<int>& inorder,vector<int>& postorder,int st,int ed,int *index,unordered_map<int,int>& mpinord)
{
	if (st>ed)
		return NULL;

	int val = postorder[*index];
	struct TreeNode* node = newNode(val);
	(*index)--;

	if (st==ed)
		return node;

	int mid = mpinord[val];

	node->right = buildTreeFromInAndPost(inorder,postorder,mid+1,ed,index,mpinord);
	node->left = buildTreeFromInAndPost(inorder,postorder,st,mid-1,index,mpinord);

	return node;
}


struct TreeNode* buildTree(vector<int>& inorder,vector<int>& postorder)
{
	if (inorder.size()!=postorder.size())
		return NULL;

	int index = inorder.size()-1;
	unordered_map<int,int> mpinord;

	int i;

	for (i=0;i<inorder.size();i++)
		mpinord[inorder[i]]=i;

	return buildTreeFromInAndPost(inorder,postorder,0,index,&index,mpinord);
}

int main()
{
	cout<<" 106. Construct Binary Tree from Inorder and Postorder Traversal "<<endl;

	struct TreeNode* root = NULL;
	struct TreeNode* root1 = NULL;
	struct TreeNode* root2 = NULL;
	struct TreeNode* root3 = NULL;
	struct TreeNode* root4 = NULL;
	struct TreeNode* rootl = NULL;
	struct TreeNode* rootr = NULL;

	// vector<int> inorder = {9,3,15,20,7};
	// vector<int> postorder = {9,15,7,20,3};

	vector<int> inorder = {4,2,5,1,6,3,7};
	vector<int> postorder = {4,5,2,6,7,3,1};

	int i,j;

	cout<<" inorder of the binary tree --"<<endl;
	for (i=0;i<inorder.size();i++)
		cout<<inorder[i]<<" ";
	cout<<endl;
	cout<<endl;
	cout<<" postorder of the binary tree -- "<<endl;
	for (i=0;i<postorder.size();i++)
		cout<<postorder[i]<<" ";
	cout<<endl;
	cout<<endl;

	root = buildTree(inorder,postorder);
	cout<<" preorder of the binary tree -- "<<endl;
	preorder(root);
	cout<<endl;
}