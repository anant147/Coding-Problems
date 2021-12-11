#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<utility>
#include<algorithm>
using namespace std;

struct Node
{
  int key;
  struct Node *left;
  struct Node *right;	
};

struct Node* newNode(int key)
{
	struct Node *root = (struct Node*)malloc(sizeof(struct Node));

	root->key = key;
	root->left = NULL;
	root->right = NULL;

	return root;
}

// code for insertion in binary tree
struct Node* insert(struct Node *root,int key)
{
	struct Node *newNod = newNode(key);

	if (root == NULL)
		return newNod;

	struct Node *parent = NULL;
	struct Node *current = root;

	while (current!=NULL)
	{
		parent = current;

		if (current->key <= key)
			current = current->right;
		else
			current = current->left;
	}

	if (parent->key <= key)
		parent->right = newNod;
	else
		parent->left = newNod;

	return root;
}

// code for searching in binary search tree
void searchInBSt(struct Node *root, int key)
{
	if (root==NULL)
	{
		cout<<" value - "<<key<<" is not in this bst "<<endl;
		return;
	}
	else if (root->key == key)
	{
		cout<<" value - "<<key<<" is in this bst "<<endl;
		return;
	}
	else if (root->key <= key)
		searchInBSt(root->right,key);
	else
		searchInBSt(root->left,key);
} 

void preorder(struct Node *root)
{
   if (root!=NULL)
   {
     cout<<root->key<<" ";
     preorder(root->left);
     preorder(root->right);
   }	
}

void inorder(struct Node *root)
{
   if (root!=NULL)
   {
     inorder(root->left);
     cout<<root->key<<" ";
     inorder(root->right);
   }	
}

void postorder(struct Node *root)
{
   if (root!=NULL)
   {
     postorder(root->left);
     postorder(root->right);
     cout<<root->key<<" ";
   }	
}

int main()
{
	struct Node *root = NULL;

	root = insert(root,10);
	root = insert(root,-5);
	root = insert(root,16);
	root = insert(root,-8);
	root = insert(root,18);
	root = insert(root,7);
	root = insert(root,6);

	cout<<" printing preorder of the given binary search tree -- "<<endl;
	preorder(root);
	cout<<endl;

	cout<<" printing inorder of the given binary search tree -- "<<endl;
	inorder(root);
	cout<<endl;

	cout<<" printing postorder of the given binary search tree -- "<<endl;
	postorder(root);
	cout<<endl;

	cout<<" searching value in the binary search tree -- "<<endl;
	cout<<" value to be searched -- 6"<<endl;
	searchInBSt(root,6);
	cout<<" value to be searched -- 6"<<endl;
	searchInBSt(root,12);
	cout<<" value to be searched -- 6"<<endl;
	searchInBSt(root,-8);		

}