#include<iostream>
#include<vector>
#include<utility>
#include<queue>
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
	if (root!=NULL)
	{
	  cout<<root->val<<" ";
	  preorder(root->left);
	  preorder(root->right);
	}
}

int findBottomLeftValue(struct TreeNode* root)
{
	int i,j,k,u,v,x,y,z;

	struct TreeNode *node = root;

	int cond;
	int val;

	queue<struct TreeNode*> q1,q2;

	q1.push(node);

	while (!q1.empty() || !q2.empty())
	{
		cond=0;
		if (!q1.empty())
		{
			while(!q1.empty())
			{
				node = q1.front();
				q1.pop();

				if (cond==0)
				{
					val = node->val;
					cond=1;
				}

				if (node->left != NULL)
					q2.push(node->left);

				if (node->right != NULL)
					q2.push(node->right);
			}
		}

		cond=0;
		if (!q2.empty())
		{
			while(!q2.empty())
			{
				node = q2.front();
				q2.pop();

				if (cond==0)
				{
					val = node->val;
					cond=1;
				}

				if (node->left != NULL)
					q1.push(node->left);

				if (node->right != NULL)
					q1.push(node->right);
			}
		}
	}

	return val;
}

int main()
{
	cout<<" 513. Find Bottom Left Tree Value "<<endl;

	struct TreeNode *root = NULL;
	struct TreeNode *rootl = NULL;
	struct TreeNode *rootr = NULL;
	struct TreeNode *root1 = NULL;
	struct TreeNode *root2 = NULL;
	struct TreeNode *root3 = NULL;
	struct TreeNode *root4 = NULL;

	// example 1
	// rootl = newNode(1);
	// rootr = newNode(3);
	// root = merge(2,rootl,rootr);

	// example 2
	root1 = newNode(4);
	rootl = merge(2,root1,NULL);

	root1 = newNode(7);
	root2 = merge(5,root1,NULL);
	root3 = newNode(6);
	rootr = merge(3,root2,root3);

	root = merge(1,rootl,rootr);

	cout<<" preorder of given binary tree :- "<<endl;
	preorder(root);
	cout<<endl;
	cout<<endl;

	int answer = findBottomLeftValue(root);

	cout<<" the bottom left value of given tree is - "<<answer<<endl;

}