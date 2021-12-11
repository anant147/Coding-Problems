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

int sumNumbers(TreeNode *root)
{
	struct TreeNode *curr = root;
	stack <pair <struct TreeNode*,pair <int,int> > > stk;

	pair<struct TreeNode*,pair<int,int>> pr1,pr2,pr3;

	pair<int,int> prp1,prp2,prp3;

	struct TreeNode *lnode = NULL;
	struct TreeNode *rnode = NULL;

	stk.push(make_pair(root,make_pair(0,root->val)));

	if (root->left == NULL && root->right == NULL)
		return root->val;

	int size,val1,val2,cond;
	int sum = 0;

	int u,v,x,y,z;


	while(!stk.empty())
	{
	  pr1 = stk.top();
	  curr = pr1.first;
	  cond = pr1.second.first;
	  val1 = pr1.second.second;
	  
	  if (cond == 0)
	  {
	  	lnode = curr->left;

	  	if (lnode != NULL)
	  	{
	  		val2 = (10*val1) + (lnode->val);

	  		stk.pop();
	  		stk.push(make_pair(curr,make_pair(1,val1)));
	  		stk.push(make_pair(lnode,make_pair(0,val2)));

	  		if (lnode->left == NULL && lnode->right == NULL)
	  			sum = sum + val2;
	  	}
	  	else
	  	{
	  		stk.pop();
	  		stk.push(make_pair(curr,make_pair(1,val1)));
	  	}
	  }
	  else if (cond == 1)
	  {
	  	rnode = curr->right;

	  	if (rnode != NULL)
	  	{
	  		val2 = (10*val1) + (rnode->val);

	  		stk.pop();
	  		stk.push(make_pair(curr,make_pair(2,val1)));
	  		stk.push(make_pair(rnode,make_pair(0,val2)));

	  		if (rnode->left == NULL && rnode->right == NULL)
	  			sum = sum + val2;
	  	}
	  	else
	  	{
	  		stk.pop();
	  		stk.push(make_pair(curr,make_pair(2,val1)));
	  	}
	  }
	  else if (cond == 2)
	  {
	  	stk.pop();
	  }
	}

	return sum;
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

	// Tree example 1
	// root1 = newNode(2);
	// root2 = newNode(3);
	// root = merge(1,root1,root2);

	// tree example 2
	root1 = newNode(5);
	root2 = newNode(1);
	rootl = merge(9,root1,root2);

	rootr = newNode(0);

	root = merge(4,rootl,rootr);

	cout<<" 129. Sum Root to Leaf Numbers "<<endl;
	cout<<" Preorder of the binary tree --- "<<endl;
	preorder(root);
	cout<<endl;

	int result = sumNumbers(root);
	cout<<" result = "<<result<<endl;

}