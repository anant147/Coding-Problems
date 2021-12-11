#include<iostream>
#include<utility>
#include<algorithm>
using namespace std;

// morris inorder traversal of binary tree
// time complexity - o(n) , space complexity -- o(1)

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
	root->left  = NULL;
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

void inorder(struct Node *root)
{
	if (root!=NULL)
	{
	  inorder(root->left);
	  cout<<root->data<<" ";
	  inorder(root->right);
	}
}

void morrisInorderTraversal(struct Node *root)
{
	struct Node *curr;
	struct Node *pred;

	curr = root;

	while (curr != NULL)
	{
		if (curr->left == NULL)
		{
			cout<<curr->data<<" ";
			curr = curr->right;
		}
		else
		{
			pred = curr->left;

			while (pred->right != NULL && pred->right != curr)
			{
				pred = pred->right;
			}

			if (pred->right == NULL)
			{
				pred->right = curr;
				curr = curr->left;
			}
			else
			{
				pred->right = NULL;
				cout<<curr->data<<" ";
				curr = curr->right;
			}
		}
	}
	cout<<endl;
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

	// tree example 1
	// root1 = newNode(2);
	// root2 = newNode(7);
	// rootl = merge(5, root1, root2);

	// root1 = newNode(30);
	// rootr = merge(15, NULL, root1);

	// root = merge(10, rootl,rootr);

	// tree example 2
	root1 = newNode(-1);
	root1 = merge(2,root1,NULL);
	root1 = merge(-2,NULL,root1);
	root2 = newNode(8);
	root2 = merge(6,NULL,root2);
	rootl = merge(5,root1,root2);

	root1 = newNode(40);
	rootr = merge(30, NULL, root1);
	root = merge( 10, rootl, rootr);

	cout<<" Inorder traversal of bianry tree -- "<<endl;
	inorder(root);
	cout<<endl;
	cout<<endl;

	cout<<" Morris inorder traversal of binary tree -- "<<endl;
	morrisInorderTraversal(root);
	cout<<endl; 
}