#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<queue>
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

vector<int> rightSideView(struct TreeNode* root)
{
	int i,j,k,u,v,x,y,z;

	if (root==NULL)
		return {};

	queue<struct TreeNode*> q1,q2;

	struct TreeNode* node = root;

	q1.push(node);

	vector<int> vtemp;

	while (!q1.empty() || !q2.empty())
	{
		if (!q1.empty())
		{
			while(!q1.empty())
			{
				node = q1.front();

				if (q1.size()==1)
					vtemp.push_back(node->val);

				q1.pop();

				if (node->left!=NULL)
					q2.push(node->left);

				if (node->right !=NULL)
					q2.push(node->right);
			}
		}

		if (!q2.empty())
		{
			while(!q2.empty())
			{
				node = q2.front();

				if (q2.size()==1)
					vtemp.push_back(node->val);

				q2.pop();

				if (node->left != NULL)
					q1.push(node->left);

				if (node->right != NULL)
					q1.push(node->right);
			}
		}
	}

	return vtemp;
}


int main()
{
	cout<<" 199. Binary Tree Right Side View "<<endl;

	struct TreeNode *root = NULL;
	struct TreeNode *rootl = NULL;
	struct TreeNode *rootr = NULL;
	struct TreeNode *root1 = NULL;
	struct TreeNode *root2 = NULL;
	struct TreeNode *root3 = NULL;
	struct TreeNode *root4 = NULL;

	// example 1
	root1 = newNode(5);
	rootl = merge(2,NULL,root1);
	root2 = newNode(4);
	rootr = merge(3,NULL,root2);
	root = merge(1,rootl,rootr);

	cout<<" printing given tree - "<<endl;
	preorder(root);
	cout<<endl;
	cout<<endl;

	int i,j,k;
	vector<int> temp = rightSideView(root);

	cout<<" printing temp vector :-"<<endl;
	for (i=0;i<temp.size();i++)
		cout<<temp[i]<<" ";
	cout<<endl;
}