#include<iostream>
#include<stack>
#include<vector>
#include<utility>
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
	if (root != NULL)
	{
	  cout<<root->val<<" ";
	  preorder(root->left);
	  preorder(root->right);
	}
}

///////////////////////////////////////////////////////////////////////////////////////////

bool sameBinaryTree(struct TreeNode* root1,struct TreeNode *root2)
{
	if (root1 == NULL && root2 == NULL)
		return true;
	else if (root1 != NULL && root2 == NULL)
		return false;
	else if (root1 == NULL && root2 != NULL)
		return false;
	else
		return (root1->val == root2->val) && sameBinaryTree(root1->left,root2->left) && sameBinaryTree(root1->right,root2->right);
}

int sizeOfBinaryTree(struct TreeNode* root)
{
	if (root == NULL)
		return 0;

	if (root->left == NULL && root->right == NULL)
		return 1;

	int lsize = sizeOfBinaryTree(root->left);
	int rsize = sizeOfBinaryTree(root->right);

	return (1 + lsize + rsize);
}

bool sortBySize(pair<struct TreeNode*,int> pr1, pair<struct TreeNode*,int> pr2)
{
	return (pr1.second <= pr2.second);
}

vector<TreeNode*> findDuplicateSubtrees(TreeNode* root)
{
	vector<struct TreeNode*> result;
	vector<struct TreeNode*> nodeStore;

	stack<pair<struct TreeNode*,int>> stk;

	pair<struct TreeNode*,int> pr1,pr2,pr3;

	struct TreeNode* curr = root;
	struct TreeNode* lnode = NULL;
	struct TreeNode* rnode = NULL;

	if (root == NULL)
		return {};
	else if (root->left == NULL && root->right == NULL)
		return {};

	int i,j,k,m,u,v,x,y,z,t;

	stk.push(make_pair(curr,0));
	nodeStore.push_back(curr);

	int cond;

	while(!stk.empty())
	{
		pr1 = stk.top();
		curr = pr1.first;
		cond = pr1.second;

		if (cond == 0)
		{
			lnode = curr->left;

			if (lnode != NULL)
			{
				nodeStore.push_back(lnode);

				stk.pop();
				stk.push(make_pair(curr,1));
				stk.push(make_pair(lnode,0));
			}
			else
			{
				stk.pop();
				stk.push(make_pair(curr,1));
			}
		}
		else if (cond == 1)
		{
			rnode = curr->right;

			if (rnode != NULL)
			{
				nodeStore.push_back(rnode);

				stk.pop();
				stk.push(make_pair(curr,2));
				stk.push(make_pair(rnode,0));
			}
			else
			{
				stk.pop();
				stk.push(make_pair(curr,2));
			}
		}
		else if (cond == 2)
		{
			stk.pop();
		}
	}

	int n = nodeStore.size();

	if (n==0)
		return {};

	int sizeArr[n];

	for (i=0;i<n;i++)
	{
		k = sizeOfBinaryTree(nodeStore[i]);
		sizeArr[i] = k;
	}

	vector<pair<struct TreeNode*,int>> nodeAndSize;

	for (i=0;i<n;i++)
	{
		curr = nodeStore[i];
		k = sizeArr[i];
		nodeAndSize.push_back(make_pair(curr,k));
	}

	// cout<<" nodeAndSize 1"<<endl;
	// for (i=0;i<nodeAndSize.size();i++)
	// 	cout<<nodeAndSize[i].second<<" ";
	// cout<<endl;

	sort(nodeAndSize.begin(),nodeAndSize.end(),sortBySize);

	// cout<<" nodeAndSize 2 "<<endl;
	// for (i=0;i<nodeAndSize.size();i++)
	// 	cout<<nodeAndSize[i].second<<" ";
	// cout<<endl;

	vector<struct TreeNode*> sameSizeNode;

	for (i=0;i<(n-1);)
	{
		if (nodeAndSize[i].second == nodeAndSize[i+1].second)
		{
			// cout<<" hello 1 "<<endl;
			
			j = i;
			int nodeSize = nodeAndSize[i].second;

			while(true)
			{
				if (nodeAndSize[j].second == nodeSize)
				{
					sameSizeNode.push_back(nodeAndSize[j].first);
					j++;
				}
				else
				{
					break;
				}
			}

			t = sameSizeNode.size();

			int arr[t];

			for (k=0;k<t;k++)
				arr[k] = 0;

			for (k = 0;k<t;k++)
			{
				for (m = k+1;m<t;m++)
				{
					if (arr[k] != 1 && arr[m] == 0)
					{
						bool ans = sameBinaryTree(sameSizeNode[k],sameSizeNode[m]);

						if (ans == true)
						{
							arr[k] = 2;
							arr[m] = 1;
						}
					}
				}
			}

			for (k=0;k<t;k++)
			{
				if (arr[k] == 2)
				{
					result.push_back(sameSizeNode[k]);
				}
			}

			sameSizeNode.clear();
			i = j;
		}
		else
		{
			// cout<<" hello 2 "<<endl;
			i = i+1;
		}
	}

	// cout<<" sizre of b tree "<<endl;
	// for (i=0;i<n;i++)
	// 	cout<<sizeArr[i]<<" ";
	// cout<<endl;

 //    cout<<" size of bianry tree "<<endl;
	// for (u=0;u<nodeAndSize.size();u++)
	// 	cout<<nodeAndSize[u].second<<" ";
	// cout<<endl;

	return result;
}

///////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	struct TreeNode* root = NULL;
	struct TreeNode* rootl = NULL;
	struct TreeNode* rootr = NULL;
	struct TreeNode* root1 = NULL;
	struct TreeNode* root2 = NULL;
	struct TreeNode* root3 = NULL;
	struct TreeNode* root4 = NULL;

	int i,j,k,u;

	root1 = newNode(4);
	rootl = merge(2,root1,NULL);

	root1 = newNode(4);
	root1 = merge(2,root1,NULL);
	root2 = newNode(4);
	rootr = merge(3,root1,root2);

	root = merge(1,rootl,rootr);

	cout<<" Preorder of the given binary tree --- "<<endl;
	preorder(root);
	cout<<endl;
	cout<<endl;

	vector<struct TreeNode*> result = findDuplicateSubtrees(root);

	if (result.size() == 0)
		cout<<" there is no duplicate subtree in this given binary tree."<<endl;
	else
	{
		cout<<" no. of  duplicate trees --- "<<result.size()<<endl;
		cout<<endl;

		for (i=0;i<result.size();i++)
		{
			cout<<"preorder of the "<<(i+1)<<" th subtree -- "<<endl;
			preorder(result[i]);
			cout<<endl;
			cout<<endl;
		}
	}
}