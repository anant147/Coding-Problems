#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
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



struct TreeNode* buildTreeFromInAndPre(vector<int>& inorder,vector<int>& preorder,int st,int ed,int *preindex,unordered_map<int,int>& mpinord)
{
	if (st > ed)
		return NULL;

	int val = preorder[*preindex];
	struct TreeNode* node = newNode(val);
	(*preindex)++;

	if (st==ed)
		return node;

	int mid = mpinord[val];

	node->left = buildTreeFromInAndPre(inorder,preorder,st,mid-1,preindex,mpinord);
	node->right = buildTreeFromInAndPre(inorder,preorder,mid+1,ed,preindex,mpinord);

	return node;
}


struct TreeNode* buildTree(vector<int>& inorder,vector<int>& preorder)
{
	if (inorder.size()!=preorder.size())
		return NULL;

	int len = inorder.size();

	int preindex = 0;

	unordered_map<int,int> mpinord;

	for (int i=0;i<inorder.size();i++)
		mpinord[inorder[i]]=i;

	return buildTreeFromInAndPre(inorder,preorder,0,len-1,&preindex,mpinord);
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

void inorder(struct TreeNode *root)
{
	if (root!=NULL)
	{
		inorder(root->left);
		cout<<root->val<<" ";
		inorder(root->right);
	}
}

int main()
{
	cout<<" 105. Construct Binary Tree from Inorder and Preorder Traversal "<<endl;

	struct TreeNode* root = NULL;
	struct TreeNode* root1 = NULL;
	struct TreeNode* root2 = NULL;
	struct TreeNode* root3 = NULL;
	struct TreeNode* root4 = NULL;
	struct TreeNode* rootl = NULL;
	struct TreeNode* rootr = NULL;

	// vector<int> inorder = {9,3,15,20,7};
	// vector<int> postorder = {9,15,7,20,3};

	vector<int> inorder = {9,3,15,20,7};
	vector<int> preorder = {3,9,20,15,7};

	int i,j;

	cout<<" inorder of the binary tree --"<<endl;
	for (i=0;i<inorder.size();i++)
		cout<<inorder[i]<<" ";
	cout<<endl;
	cout<<endl;
	cout<<" preorder of the binary tree -- "<<endl;
	for (i=0;i<preorder.size();i++)
		cout<<preorder[i]<<" ";
	cout<<endl;
	cout<<endl;

	root = buildTree(inorder,preorder);
	if (root != NULL)
		cout<<" yes "<<endl;
	else
		cout<<" no "<<endl;
	cout<<" inorder of the binary tree -- "<<endl;
	inorder(root);
	cout<<endl;
}