#include <bits/stdc++.h> 
using namespace std;

struct node
{
	int val;
	struct node *left;
	struct node *right;
};

struct node* newNode(int val)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->val = val;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

int getTreePathSum(struct node *root, int val)
{
	if (root == NULL)
		return 0;

	val = (val*10)+root->val;

	if (root->left == NULL && root->right == NULL)
		return val;

	return getTreePathSum(root->left,val) + getTreePathSum(root->right, val);
}

int treePathsSum(struct node *root)
{
	return getTreePathSum(root, 0);
}

int main()
{
	cout<<" JPMC question 9 "<<endl;
	cout<<"  Sum of all the numbers that are formed from root to leaf paths "<<endl;

	struct node *root = newNode(6);  
    root->left = newNode(3);  
    root->right = newNode(5);  
    root->left->left = newNode(2);  
    root->left->right = newNode(5);  
    root->right->right = newNode(4);  
    root->left->right->left = newNode(7);  
    root->left->right->right = newNode(4);  

    cout<<"Sum of all paths is "<<treePathsSum(root);  
   

}