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

////////////////////////// main code for recovering ////////////////////////////////////////

struct TreeNode* getSecondNode(struct TreeNode *root, int valObt,int valToFind)
{
	stack<pair<struct TreeNode*,int>> stk;
	pair<struct TreeNode*,int> pr1,pr2,pr3;
	struct TreeNode *curr = root;
	struct TreeNode *node1 = NULL;
	struct TreeNode *node2 = NULL;
	int chk;
	struct TreeNode *parent = NULL;

	struct TreeNode *nodex = NULL;
	struct TreeNode *nodey = NULL;

	int x = valObt;
	int y = valToFind;

	int condx = 0;
	int condy = 0;

	if (curr->val == y)
	{
		nodey = root;
		condy = 1;
	}

	stk.push(make_pair(root,0));

	while(condx == 0 || condy == 0)
	{
		pr1 = stk.top();
		node1 = pr1.first;
		chk = pr1.second;

		if (chk == 0)
		{
			stk.pop();
			node2 = node1->left;

			if (node2 != NULL)
			{
				stk.push(make_pair(node1,1));

				if (node2->val ==y)
				{
					if (condx == 0)
					{
						condy = 1;
						nodey = node2;
					}
				}
				else if (node2->val == x)
				{
					if (condy==1)
					{
						condx=1;
						nodex = node2;
					}
				}

				stk.push(make_pair(node2,0));
			}
			else
			{
				stk.push(make_pair(node1,1));
			}
		}
		else if (chk==1)
		{
			stk.pop();
			node2 = node1->right;

			if (node2 != NULL)
			{
				stk.push(make_pair(node1,2));

				if (node2->val == y)
				{
					if (condx == 0)
					{
						condy = 1;
						nodey = node2;
					}
				}
				else if (node2->val == x)
				{
					if (condy == 1)
					{
						condx = 1;
						nodex = node2;
					}
				}

				stk.push(make_pair(node2,0));
			}
			else
			{
				stk.push(make_pair(node1,2));
			}
		}
		else if (chk==2)
		{
			if (node1->val == y)
			{
				condy = 0;
				nodey = NULL;

				if (condx == 1)
				{
					condx = 0;
					nodex = NULL;
				}
			}
			else if (node1->val == x)
			{
				condx = 0;
				nodex = NULL;
			}
		}
	}

	return nodey;


}

struct TreeNode* recoverTree(struct TreeNode *root)
{
	struct TreeNode *curr = root;

	stack<struct TreeNode*> stk;

	struct TreeNode *node1 = NULL;
	struct TreeNode *node2 = NULL;

	struct TreeNode *lnode = NULL;
	struct TreeNode *rnode = NULL;

	struct TreeNode *parent = NULL;
	struct TreeNode *gparent = NULL;

	int cond1 = 1;
	int cond2 = 1;
	int cond3 = 1;

	int maxval = pow(2,sizeof(int)*8-1)-1;
	int minval = (-1) * maxval;

	int lval = minval;
	int rval = maxval;
	int valToFind;
	int valObt;

	while (cond1)
	{
		if (curr->left != NULL)  /// seg0 start
		{
			while (curr != NULL && cond1 ==1)  //// seg1 start
			{
				if (curr->right == NULL)  // if right node is null -- seg2 start
				{
					lnode = curr->left;

					if (curr->val < lnode->val)   
					{
						node1 = curr;
						node2 = lnode;
						cond1 = 0;
					}
					else
					{
						if (lval <= curr->val && curr->val <= rval)
						{
							stk.push(curr);
							rval = curr->val;
							curr = lnode;
						}
						else
						{
							cond1 = 0;
							if (curr->val < lval)
							{
								node1 = curr;
								cond2 = 0;
								valObt = curr->val;
								valToFind = lval;
							}
							else
							{
								node1 = curr;
								cond2 = 0;
								valObt = curr->val;
								valToFind = rval;
							}
						}
					}
				}   // seg2 ends 
				else  // if right node is not null  -- seg3 starts
				{
					lnode = curr->left;
					rnode = curr->right;

					if (curr->val < lnode->val || curr->val > rnode->val)
					{
						cond1 = 0;
						if (curr->val < lnode->val)
						{
							node1 = curr;
							node2 = lnode;
						}
						else
						{
							node1 = curr;
							node2 = rnode;
						}
					}
					else
					{
						if (lval <= curr->val && curr->val <= rval)
						{
							stk.push(curr);
							rval = curr->val;
							curr = lnode;
						}
						else
						{
							cond1 = 0;

							if (curr->val < lval)
							{
								node1 = curr;
								cond2 = 0;
								valObt = curr->val;
								valToFind = lval;
							}
							else
							{
								node1 = curr;
								cond2 = 0;
								valObt = curr->val;
								valToFind = rval;
							}
						}
					}
				}  //// seg3 ends
			}  //// seg1 ends

			if (cond1 == 0)  
				break;

			if (curr == NULL && !stk.empty())
			{
				parent = stk.top();
				stk.pop();
				lval = parent->val;
			}

			while(parent->right == NULL && !stk.empty())
			{
				parent = stk.top();
				lval = parent->val;
				stk.pop();
			}

			if (parent->right != NULL)
			{
				if (stk.empty())
					rval = maxval;
				else
				{
					gparent = stk.top();
					rval = gparent->val;
				}

				rnode = parent->right;

				if (rnode->val < parent->val)
				{
					cond1 = 0;
					node1 = parent;
					node2 = curr;
				}
				else
				{
					if (lval <= rnode->val && rnode->val <= rval)
					{
						curr=rnode;
					}
					else
					{
						cond1 = 0;

						if (rnode->val < lval)
						{
							node1 = rnode;
							cond2 = 0;
							valObt = rnode->val;
							valToFind = lval;
						}
						else
						{
							node1 = rnode;
							cond2 = 0;
							valObt = rnode->val;
							valToFind = rval;
						}
					}
				}
			}

			if (cond1 == 0)
				break;

		}  //// seg0 ends
	    else
	    {
	    	if (curr->right !=NULL)
	    	{
	    		rnode = curr->right;

	    		if (curr->val > rnode->val)
	    		{
	    			node1 = curr;
	    			node2 = rnode;
	    			cond1 = 0;
	    		}
	    		else
	    		{
	    		    if (lval <= curr->val && curr->val <= rval)
	    		    {
	    		    	lval = curr->val;
	    		    	curr = rnode;
	    		    }
	    		    else
	    		    {
	    		    	cond1 = 0;
	    		    	cond2 = 0;
	    		    	if (lval > curr->val)
	    		    	{
	    		    		node1 = curr;
	    		    		valObt = curr->val;
	    		    		valToFind = lval;
	    		    	}
	    		    	else
	    		    	{
	    		    		node1 = curr;
	    		    		valObt = curr->val;
	    		    		valToFind = rval;
	    		    	}
	    		    }

	    		}
	    	}
	    	else
	    		cond1 = 0;
	    }
	}

	int tempval;

	if (cond2 == 1)
	{
		tempval = node1->val;
		node1->val = node2->val;
		node2->val = tempval;
	}
	else
	{
		node2 = getSecondNode(root,valObt,valToFind);

		if (node2 != NULL)
		{
			tempval = node1->val;
			node1->val = node2->val;
			node2->val = tempval;			
		}

	}
	return root;
}

/////////////////////////////////////////////////////////////////

int main()
{
	struct TreeNode *root = NULL;
	struct TreeNode *rootl = NULL;
	struct TreeNode *rootr = NULL;
	struct TreeNode *root1 = NULL;
	struct TreeNode *root2 = NULL;
	struct TreeNode *root3 = NULL;
	struct TreeNode *root4 = NULL;
	struct TreeNode *result = NULL;

	// Tree example 1
	// root1 = newNode(2);
	// rootl = merge(3, NULL,root1);
	// root = merge(1, rootl, NULL);

	// Tree example 2
	rootl = newNode(1);

	root1 = newNode(2);
	rootr = merge(4, NULL, root1);

	root = merge(3, rootl, rootr);
    
	cout<<" Preorder of the binary tree --- "<<endl;
	preorder(root);
	cout<<endl;

	cout<<endl;
	cout<<" 99. Recover Binary Search Tree "<<endl;
	cout<<endl;

	result = recoverTree(root);

	cout<<endl;
	cout<<" Preorder of the output binary tree-- "<<endl;
	preorder(result);
	cout<<endl;
}