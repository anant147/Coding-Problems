#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<utility>
#include<algorithm>
#include<cmath>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};

struct Node* newNode(int data)
{
	struct Node *root = (struct Node*)malloc(sizeof(struct Node));

	root->data = data;
	root->left = NULL;
	root->right = NULL;

	return root;
}

struct Node* merge(int data, struct Node *left, struct Node *right)
{
	struct Node *root = (struct Node*)malloc(sizeof(struct Node));

	root->data = data;
	root->left = left;
	root->right = right;

	return root;
}

bool isBST(struct Node *root,int min, int max)
{
	if (root==NULL)
		return true;

	if (root->data < min || root->data > max)
		return false;

	return isBST(root->left, min, root->data) && isBST(root->right, root->data, max);
}

void preorder(struct Node *root)
{
	if (root!=NULL)
	{
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}

int main()
{
    struct Node *root = NULL;
    struct Node *root1 = NULL;
    struct Node *root2 = NULL;
    struct Node *rootl = NULL;
    struct Node *rootr = NULL;

    int max = pow(2,sizeof(int)*8-1)-1;
    int min = (-1)*max;
  
    // Tree example 1
    // root1 = newNode(-5);
    // root2 = merge(10,root1,NULL);
    // rootl = root2;

    // root1 = newNode(17);
    // root2 = newNode(21);
    // root2 = merge(19,root1,root2);
    // rootr = root2;

    // root = merge(10,rootl,rootr);

    // Tree example 2
    // root1 = newNode(-1);
    // root2 = newNode(21);
    // root1 = merge(0,root1,root2);
    // rootl = root1;

    // root1 = newNode(16);
    // root2 = newNode(32);
    // root1 = merge(25,root1,root2);
    // rootr = root1;

    // root = merge(10,rootl,rootr);

    // bool answer = isBST(root,min,max);

    // Tree example 3
    root1 = newNode(-20);
    root2 = newNode(0);
    root1 = merge(-10,root1,root2);
    rootl = root1;

    root1 = newNode(17);
    root1 = merge(19,root1,NULL);
    rootr = root1;

    root = merge(10,rootl,rootr);

    bool answer = isBST(root,min,max);

    if (answer)
    	cout<<" given binary tree is a Binary search tree "<<endl;
    else
    	cout<<" given binary tree is not a binary search tree "<<endl;

    cout<<endl;
    cout<<" preorder of the given tree -- "<<endl;
    preorder(root);
    cout<<endl;


}