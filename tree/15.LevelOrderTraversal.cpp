#include<iostream>
#include<queue>
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

void levelOrderTraversal(struct Node *root)
{
	if (root == NULL)
		return;

	queue<struct Node*> q1;
	q1.push(root);

	while( !q1.empty())
	{
		root = q1.front();
		q1.pop();

		cout<<root->data<<" ";

		if (root->left != NULL)
			q1.push(root->left);

		if (root->right != NULL)
			q1.push(root->right);
	}
	cout<<endl;
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
	// root1 = newNode(15);
	// root1 = merge(11, NULL, root1);
	// rootl = merge(9, root1, NULL);

	// root1 = newNode(18);
	// root1 = merge(16,root1,NULL);
	// root2 = newNode(19);
	// root2 = merge(21, NULL, root2);
	// rootr = merge(-10,root1,root2);

	// root = merge(10, rootl, rootr);

	// Tree example 2
	root1 = newNode(18);
	root1 = merge(15,root1,NULL);
	rootl = merge(21, NULL, root1);

	root1 = newNode(17);
	root2 = newNode(12);
	root1 = merge(-6, NULL, root1);
	root2 = merge(0, NULL, root2);
	rootr = merge(19,root1,root2);

	root = merge(10,rootl,rootr);

	cout<<" Level order traversal of the given binary tree -- "<<endl;
	levelOrderTraversal(root);
	cout<<endl;

	cout<<" Preorder of the given binary tree -- "<<endl;
	preorder(root);
	cout<<endl;
}