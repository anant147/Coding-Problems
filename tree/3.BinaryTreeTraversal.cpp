#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<utility>
#include<algorithm>
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
	root->left=left;
	root->right=right;

	return root;
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

void inorder(struct Node *root)
{
	if (root!=NULL)
	{
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}

void postorder(struct Node *root)
{
	if (root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<" ";
	}
}

int main()
{
	struct Node *root = NULL;
	struct Node *root1 = NULL;
	struct Node *root2 = NULL;
	struct Node *rootl = NULL;
	struct Node *rootr = NULL;

	// Tree 1
	// root2 = newNode(5);
	// root2 = merge(3,root2,NULL);
	// root1 = newNode(6);
	// root2 = merge(15,root2,root1);
	// rootl=root2;

	// root2 = newNode(9);
	// root1 = newNode(8);
	// root2 = merge(2,root2,root1);
	// root2 = merge(30,NULL,root2);
	// rootr = root2;

	// root = merge(10,rootl,rootr);

	// Tree 2
	root2 = newNode(6);
	root2 = merge(2,root2,NULL);
	rootl = root2;

	root2 = newNode(8);
	root1 = newNode(3);
	root2 = merge(5,root2,root1);
	rootr = root2;

	root = merge(10,rootl,rootr);

	cout<<" Preorder of the given tree -- "<<endl;
	preorder(root);
	cout<<endl;

	cout<<" Inorder of the given tree -- "<<endl;
	inorder(root);
	cout<<endl;

	cout<<" Postorder of the given tree -- "<<endl;
	postorder(root);
	cout<<endl;	
}