#include<iostream>
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
	root->left = left;
	root->right = right;

	return root;
}

int size(struct Node *root)
{
	if (root == NULL)
	return 0;

	if (root->left == NULL && root->right == NULL)
	return 1;

	int left = size(root->left);
	int right = size(root->right);

	return (left + right + 1);
}

void preorder(struct Node *root)
{
	if (root != NULL)
	{
	  cout<<root->data<<" ";
	  preorder(root->left);
	  preorder(root->right);
	}
}

int main()
{
   struct Node *root = NULL;
   struct Node *rootl = NULL;
   struct Node *rootr = NULL;
   struct Node *root1 = NULL;
   struct Node *root2 = NULL;
   struct Node *root3 = NULL;
   struct Node *root4 = NULL;

   // Tree example 1
   root1 = newNode(6);
   rootl = merge(2,root1,NULL);

   root1 = newNode(8);
   root2 = newNode(3);
   rootr = merge(5,root1,root2);

   root = merge(10,rootl,rootr);

   cout<<" Preorder of  the given binary tree --- "<<endl;
   preorder(root);
   cout<<endl;
   cout<<endl;

   int answer = size(root);
   cout<<" size of the given bianry tree -- "<<answer<<endl;


}