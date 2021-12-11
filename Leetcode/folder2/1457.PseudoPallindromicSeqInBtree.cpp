#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<unordered_map>
#include<queue>
#include<stack>
#include<cmath>
#include<cstring>
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

int pseudoPalindromicPaths(struct TreeNode *root)
{
	int i,j,k,u,v,x,y,z;

	struct TreeNode *node = root;

	if (root==NULL)
		return 0;

	if (root->left==NULL && root->right==NULL)
		return 1;

	stack<pair<struct TreeNode*,vector<int>>> st;

	pair<struct TreeNode*,vector<int>> ptemp,ptemp1,ptemp2;

	vector<int> temp1, temp2, temp3;

	int val = node->val;

	int nodeval;

	temp1 = {0,val,val};

	int cond,cond1,cond2;

	st.push(make_pair(node,temp1));
	temp1.clear();

	vector<int> nstor;
	nstor.resize(10,0);
	nstor[val]++;

	int count = 0;

	while (!st.empty())
	{
		ptemp = st.top();
		st.pop();
		node = ptemp.first;
		temp1 = ptemp.second;
		nodeval = temp1[0];
		u = temp1[1];
		v = temp1[2];

		if (nodeval==0)
		{
			if (node->left != NULL)
			{
				temp1[0]++;
				st.push(make_pair(node,temp1));
				temp1.clear();

				x = node->left->val;  nstor[x]++;
				y = v^x;
				temp1 = {0,x,y};
				st.push(make_pair(node->left,temp1));
				temp1.clear();
			}
			else 
			{
				if (node->right != NULL)
				{
					temp1[0] = 2;
					st.push(make_pair(node,temp1));
					temp1.clear();

					x = node->right->val;  nstor[x]++;
					y = v^x;
					temp1 = {0,x,y};
					st.push(make_pair(node->right, temp1));
					temp1.clear();
				}
				else
				{
					if (v==0)
					{
						// cout<<" v = "<<v<<endl;
						cond = 0;

						for (i=1;i<10;i++)
						{
							// cout<<" val for i = "<<i<<" is "<<nstor[i]<<endl;
							if (nstor[i]%2==1)
							{
								cond=1;
								break;
							}
						}

						if (cond==0)
							count++;
					}
					else if (v!=0 && nstor[v]%2==1)
					{
						// cout<<" v = "<<v<<endl;
						cond = 0;

						for (i=1;i<10;i++)
						{
							if (i!=v && nstor[i]%2==1)
							{
								cond=1; break;
							}
						}

						if (cond==0)
							count++;
					}

					nstor[u]--;
				}
			}
		}
		else if (nodeval==1)
		{
			if (node->right != NULL)
			{
				temp1[0] = 2;
				st.push(make_pair(node, temp1));
				temp1.clear();

				x = node->right->val; nstor[x]++;
				y = v^x;
				temp1 = {0,x,y};
				st.push(make_pair(node->right, temp1));
				temp1.clear();
			}
			else
			{
				nstor[u]--;
			}
		}
		else if (nodeval==2)
		{
			nstor[u]--;
		}
	}

	return count;
}

int main()
{
	cout<<" 1457. Pseudo-Palindromic Paths in a Binary Tree "<<endl;

	struct TreeNode* root = NULL;
	struct TreeNode* root1 = NULL;
	struct TreeNode* root2 = NULL;
	struct TreeNode* root3 = NULL;
	struct TreeNode* root4 = NULL;
	struct TreeNode* rootl = NULL;
	struct TreeNode* rootr = NULL;

	// example 1
	// root1 = newNode(3);
	// root2 = newNode(1);
	// rootl = merge(3, root1,root2);

	// root3 = newNode(1);
	// rootr = merge(1, NULL, root3);
	// root = merge(2, rootl, rootr);

	// example 2
	// root = newNode(9);

	// example 3
	root1 = newNode(1);
	root2 = newNode(1);
	root3 = merge(3, NULL, root2);
	rootl = merge(1, root1, root3);

	rootr = newNode(1);

	root = merge(2, rootl, rootr);

	cout<<" preorder of the binary tree :-  "<<endl;
	preorder(root);
	cout<<endl;
	cout<<endl;

	int answer = pseudoPalindromicPaths(root);

	cout<<" answer = "<<answer<<endl;
	cout<<endl;

}