#include<iostream>
#include<stack>
#include<utility>
#include<algorithm>
using namespace std;

// Iterative preorder of the given binary tree
// time complexity -- o(n)
// space complexity -- o(h) where h = height of the tree (<= n)

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

struct Node *merge(int data, struct Node *left, struct Node *right)
{
	struct Node *root = (struct Node*)malloc(sizeof(struct Node));

	root->data = data;
	root->left = left;
	root->right = right;

	return root;
}

void iterativePreorder(struct Node *root)
{
	if (root == NULL)
		return;

	stack<struct Node*> s1;

	s1.push(root);

	while (!s1.empty())
	{
		root = s1.top();
		s1.pop();
		cout<<root->data<<" ";

		if (root->right != NULL)
			s1.push(root->right);

		if (root->left != NULL)
			s1.push(root->left);
	}
	cout<<endl;
}

int main()
{
	struct Node *root = NULL;
	struct Node *root1 = NULL;
	struct Node *root2 = NULL;
	struct Node *rootl = NULL;
	struct Node *rootr = NULL;

	// Tree example 1
	root1 = newNode(8);
	root1 = merge(2,NULL,root1);
	root2 = newNode(11);
	rootl = merge(5,root1,root2);

	root1 = newNode(-2);
	root2 = newNode(6);
	rootr = merge(19,root1,root2);

	root = merge(10,rootl,rootr);

	cout<<" Iterative preorder of the given binary tree -- "<<endl;
	iterativePreorder(root);
	cout<<endl;
}