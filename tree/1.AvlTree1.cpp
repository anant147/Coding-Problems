#include<iostream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<utility>
#include<algorithm>
using namespace std;

struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	int height;
};

int maxval(int a,int b)
{
	if (a>=b)
		return a;
	else
		return b;
}

int height(struct Node *node)
{
	if (node==NULL)
		return 0;
	else
		return node->height;
}

struct Node* newNode(int key)
{
  struct Node* node = (struct Node*)malloc(sizeof(struct Node));

  node->key = key;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;

  return node;
}

struct Node* rotateRight(struct Node *root)
{
	struct Node* newRoot = root->left;
	root->left = newRoot->right;
	newRoot->right = root;
	root->height = 1+maxval(height(root->left),height(root->right));
	newRoot->height = 1+maxval(height(newRoot->left),height(newRoot->right));
	return newRoot;
}

struct Node* rotateLeft(struct Node *root)
{
	struct Node* newRoot = root->right;
	root->right = newRoot->left;
	newRoot->left = root;
	root->height = 1+maxval(height(root->left),height(root->right));
	newRoot->height = 1+maxval(height(newRoot->left),height(newRoot->right));
	return newRoot;
}

struct Node* insert(struct Node *root, int key)
{
	if (root==NULL)
		return (newNode(key));

	if (key < root->key)
		root->left = insert(root->left,key);
	else 
		root->right = insert(root->right,key);

	root->height = 1 + maxval(height(root->left),height(root->right));

	int balance = height(root->left) - height(root->right);

	if (balance>1)
	{
		if (height(root->left->left) > height(root->left->right))  // LL (left - left)
			return rotateRight(root);
		else  // LR (left - right)
		{
			root->left = rotateLeft(root->left);
			return rotateRight(root);
		}
	}

	if (balance<-1)
	{
		if (height(root->right->right) > height(root->right->left))  // RR ( right - right)
			return rotateLeft(root);
		else // RL (right - left)
		{
			root->right = rotateRight(root->right);
			return rotateLeft(root);
		}
	}


	return root;
}

void preorder(struct Node *root)
{
	if (root!=NULL)
	{
		cout<<" ("<<root->key<<","<<root->height<<") ";
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(struct Node *root)
{
	if (root!=NULL)
	{
		inorder(root->left);
		cout<<" ("<<root->key<<","<<root->height<<") ";
		inorder(root->right);
	}
}

void postorder(struct Node *root)
{
	if (root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout<<" ("<<root->key<<","<<root->height<<") ";
	}
}

void searchInTree(struct Node *root,int key)
{
	if (root==NULL)
	{
		cout<<"value = "<<key<<" is not in this tree"<<endl;
	}
	else if (root->key == key)
	{
		cout<<"value = "<<key<<" is  in this tree"<<endl;
	}
	else if (root->key > key)
		searchInTree(root->left,key);
	else
		searchInTree(root->right,key);
}

struct Node* minValueNode(struct Node *root)
{
	struct Node *current = root;

	while(current->left!=NULL)
		current=current->left;

	return current;
}

struct Node* deleteInTree(struct Node *root,int key)
{
	if (root == NULL)
		return root;

	if (key < root->key)
		root->left = deleteInTree(root->left,key);
	else if (key > root->key)
		root->right = deleteInTree(root->right,key);
	else
	{
		if (root->left==NULL || root->right==NULL) // has only one child , either left or right
		{
			struct Node *temp = root->left ? root->left : root->right;

			if (temp==NULL) // has no child
			{
				temp=root;
				root=NULL;
			}
			else
				*root=*temp;

			free(temp);
		}
		else // has two child
		{
			struct Node *temp = minValueNode(root->right);

			root->key = temp->key;

			root->right = deleteInTree(root->right,temp->key);
		}
	}

	if (root==NULL)
		return root;

	root->height = 1 + maxval(height(root->left),height(root->right));

	int balance = height(root->left) - height(root->right);

	if (balance > 1)
	{
		if (height(root->left->left) > height(root->left->right))  // LL (left - left)
			return rotateRight(root);
		else  // LR (left - right)
		{
			root->left = rotateLeft(root->left);
			return rotateRight(root);
		}
	}

	if (balance < -1)
	{
		if (height(root->right->right) > height(root->right->left))
			return rotateLeft(root);
		else
		{
			root->right = rotateRight(root->right);
			return rotateLeft(root);
		}
	}

	return root;
}



int main()
{
	struct Node *root = NULL;

	root = insert(root,10);
	root = insert(root,20);
	root = insert(root,30);
	root = insert(root,40);
	root = insert(root,50);
	root = insert(root,25);
	root = insert(root,5);
	root = insert(root,15);
	root = insert(root,55);


	cout<<" Preorder of the given tree -- "<<endl;
	preorder(root);
	cout<<endl;

	cout<<" Inorder of the given tree -- "<<endl;
	inorder(root);
	cout<<endl;

	cout<<" Postorder of the given tree -- "<<endl;
	postorder(root);
	cout<<endl;

	cout<<"searching some values in the tree -- "<<endl;
	searchInTree(root,25);
	searchInTree(root,35);
	searchInTree(root,40);
	searchInTree(root,55);

	cout<<" deletion in the tree -- "<<endl;
	root = deleteInTree(root,5);
	cout<<" 5 is deleted "<<endl;
	root = deleteInTree(root,30);
	cout<<" 30 is deleted "<<endl;
	root = deleteInTree(root,55);
	cout<<" 55 is deleted "<<endl;

	cout<<endl;
	cout<<endl;
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