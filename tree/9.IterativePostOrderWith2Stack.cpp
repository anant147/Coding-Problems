#include<iostream>
#include<stack>
#include<utility>
#include<algorithm>
using namespace std;

// iterative postorder of binary tree with two stacks
// space complexity -- o(n)
// time complexity -- o(n)

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

void iterativePostorderWith2Stack(struct Node *root)
{
	if (root==NULL)
		return;

	stack<struct Node*> s1;
	stack<struct Node*> s2;

	s1.push(root);

	while(!s1.empty())
	{
		root = s1.top();
		s1.pop();
		s2.push(root);

		if (root->left != NULL)
			s1.push(root->left);

		if (root->right != NULL)
			s1.push(root->right);
	}

	while(!s2.empty())
	{
		root = s2.top();
		s2.pop();
		cout<<root->data<<" ";
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
	// root1 = newNode(3);
	// root1 = merge(5,NULL,root1);
	// root1 = merge(-10,NULL,root1);
	// rootl = root1;

	// root1 = newNode(13);
	// root2 = newNode(16);
	// rootr = merge(11,root1,root2);

	// root = merge(1,rootl,rootr);

	// Tree example 2
	root1 = newNode(-2);
	root2 = newNode(5);
	root2 = merge(-3,NULL,root2);
	rootl = merge(-1,root1,root2);

	root1 = newNode(21);
	root2 = newNode(6);
	rootr = merge(11,root1,root2);

	root = merge(1,rootl,rootr);

	cout<<" Iterative postorder of the binary tree with 2 stacks --- "<<endl;
	iterativePostorderWith2Stack(root);
	cout<<endl;
}