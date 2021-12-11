#include<iostream>
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

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////// Main code starts///////////////////////////////////////////////////////////////////////////////

int minval(int a,int b)
{
	if (a<b)
		return a;
	else
		return b;
}

int maxval(int a,int b)
{
	if (a<b)
		return b;
	else
		return a;
}

int maxval3(int a, int b, int c)
{
	return maxval(a,maxval(b,c));
}

int getNodeCntLeft(TreeNode *root,int height)
{
  int i,j;

  int count = pow(2,height-1);
  int val = count;

  int k = height;

  while (k!=0 && root!=NULL)
  {
  	val = val/2;
  	if (root->left != NULL)
  		root = root->left;
  	else
  	{
      root = root->right;
      count = count - val;
  	}
  	k--;
  }

  return count;
}

int getNodeCntRight(TreeNode *root,int height)
{
  int count = pow(2,height-1);
  int val = count;
  int k = height;

  while(k!=0 && root!=NULL)
  {
  	val = val/2;

  	if (root->right != NULL)
  		root = root->right;
  	else
  	{
  		root = root->left;
  		count = count - val;
  	}
  	k++;
  }

  return count;
}

vector<int> getWidthOfBtree(TreeNode *root)
{
	vector<int> result;

	if (root == NULL)
	{
		result.push_back(0);
		result.push_back(0);
		return result;
	}
	else if (root->left == NULL && root->right == NULL)
	{
		result.push_back(1);
		result.push_back(1);
		return result;
	}
	else
	{
		vector<int> resleft = getWidthOfBtree(root->left);
		vector<int> resright = getWidthOfBtree(root->right);

		int height1 = minval(resleft[0],resright[0]);
		int heightmax = maxval(resleft[0],resright[0]);

		int width,width1,width2,width3;

		if (height1 == 0)
		{
			width = maxval(resleft[1],resright[1]);
		}
		else
		{
			if (resleft[0] == 0)
				width1 = 0;
			else
				width1 = getNodeCntLeft(root->left,height1);

			if (resright[0] == 0)
				width2 = 0;
			else
				width2 = getNodeCntRight(root->right,height1);

			width3 = width1 + width2;

			width = maxval3(width3,resleft[1],resright[1]);
		}

		int height2 = heightmax + 1;
		

		result.push_back(height2);
		result.push_back(width);

		return result;
	}
}

int widthOfBinaryTree1(TreeNode* root) 
{
   vector<int> result = getWidthOfBtree(root);

   if (result.size() < 2)
   	return 0;
   else
   	return result[1];
}

 int widthOfBinaryTree(TreeNode* root) {
        
        int i,j,k,x,y,u,v,l,r,st,ed,len;
        
        vector<vector<TreeNode*>> result;
        
        vector<TreeNode*> temp1;
        TreeNode* curr = NULL;
        
        if (root==NULL)
            return 0;
        else if (root->left==NULL && root->right==NULL)
            return 1;
        
        int count = 1;
        
        temp1.push_back(root);
        result.push_back(temp1);
        
        temp1.clear();
        
        int cond=1;
        
        while(cond)
        {
            l = result.size();
            r = result[l-1].size();
            
            st=r;
            for (i=0;i<r;i++)
            {
                curr=result[l-1][i];
                
                if (curr!=NULL && (curr->left!=NULL || curr->right!=NULL))
                {
                    st=i;
                    break;
                }
            }
            
            ed=-1;
            for (i=r-1;i>=0;i--)
            {
                curr = result[l-1][i];
                
                if (curr!=NULL && (curr->left!=NULL || curr->right!=NULL))
                {
                    ed=i;
                    break;
                }
            }
            
            if (ed==-1 || st==r)
               cond=0;
            else if (st==ed)
            {
                curr = result[l-1][st];
                
                if (curr->left==NULL && curr->right==NULL)
                    cond=0;
                else
                {
                    if (curr->left!=NULL)
                        temp1.push_back(curr->left);
                    
                    if (curr->right!=NULL)
                        temp1.push_back(curr->right);
                    
                    result.push_back(temp1);
                    len = temp1.size();
                    
                    if (count<len)
                        count=len;
                    
                    temp1.clear();
                }
            }
            else  // to write
            {
                for (i=st;i<=ed;i++)
                {
                    curr = result[l-1][i];
                    
                    if (i==st)
                    {
                     if (curr->left!=NULL)
                         temp1.push_back(curr->left);
                        
                     temp1.push_back(curr->right);
                    }
                    else if (i==ed)
                    {
                        temp1.push_back(curr->left);
                        
                        if (curr->right!=NULL)
                            temp1.push_back(curr->right);
                    }
                    else
                    {
                        if (curr==NULL)
                        {
                            temp1.push_back(NULL);
                            temp1.push_back(NULL);
                        }
                        else
                        {
                            temp1.push_back(curr->left);
                            temp1.push_back(curr->right);
                        }
                    }
                }
                
                result.push_back(temp1);
                len = temp1.size();
                
                if (count<len)
                    count = len;
                
                temp1.clear();
            } 
        }
        
        return count;
        
    }

//////////////////////////////////////////////// Main code ends ///////////////////////////////////////////////////////////////////////////////

int main()
{
	struct TreeNode *root = NULL;
	struct TreeNode *rootl = NULL;
	struct TreeNode *rootr = NULL;
	struct TreeNode *root1 = NULL;
	struct TreeNode *root2 = NULL;
	struct TreeNode *root3 = NULL;
	struct TreeNode *root4 = NULL;

	// // Tree example 1
	root1 = newNode(5);
	root2 = newNode(3);
	rootl = merge(3,root1,root2);

	root1 = newNode(9);
	rootr = merge(2,NULL,root1);

	root = merge(1,rootl,rootr);

	// Tree example 2
	// root1 = newNode(5);
	// root2 = newNode(3);
	// rootl = merge(3,root1,root2);

	// root = merge(1,rootl,NULL);

	// Tree example 3
	// root1 = newNode(5);
	// rootl = merge(3,root1,NULL);

	// rootr = newNode(2);

	// root = merge(1,rootl,rootr);

	// Tree example 4
	// root1 = newNode(6);
	// root1 = merge(5,root1,NULL);
	// rootl = merge(3,root1,NULL);

	// root1 = newNode(7);
	// root1 = merge(9,NULL,root1);
	// rootr = merge(2,NULL,root1);

	// root = merge(1,rootl,rootr);

	// Tree example 5
	// root1 = newNode(3);
	// rootl = merge(1,root1,NULL);

	// root1 = newNode(5);
	// rootr = merge(4,root1,NULL);

	// root = merge(1,rootl,rootr);

	cout<<"Preorder of given binary tree -- "<<endl;
	preorder(root);
	cout<<endl;

	// cout<<" 662. Maximum Width of Binary Tree "<<endl;
	// int answer = widthOfBinaryTree1(root);
	// cout<<" answer = "<<answer<<endl;

	int answer = widthOfBinaryTree(root);
	cout<<" max width of tree ---"<<answer<<endl;




}