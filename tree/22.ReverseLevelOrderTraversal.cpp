#include<iostream>
#include<stack>
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

void preorder(struct Node *root)
{
	if (root != NULL)
	{
	  cout<<root->data<<" ";
	  preorder(root->left);
	  preorder(root->right);
	}
}

void reverseLevelOrder(struct Node *root)
{
	if (root == NULL)
		return;

	stack<struct Node*> s1;
	queue<struct Node*> q1;

	q1.push(root);

	while(!q1.empty())
	{
		root = q1.front();
		q1.pop();

		if (root->right != NULL)
			q1.push(root->right);

		if (root->left != NULL)
			q1.push(root->left);

		s1.push(root);
	}

	while(!s1.empty())
	{
		root = s1.top();
		s1.pop();
		cout<<root->data<<" ";
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

	// tree example 1
	// root1 = newNode(70);
	// root2 = newNode(80);
	// root1 = merge(50,root1,root2);
	// root2 = newNode(40);
	// rootl = merge(20,root2,root1);

	// root1 = newNode(90);
	// root1 = merge(60,root1,NULL);
	// rootr = merge(30,NULL,root1);

	// root = merge(10,rootl,rootr);

	// tree example 2
	root1 = newNode(40);
	root2 = newNode(50);
	rootl = merge(20,root1,root2);

	root1 = newNode(60);
	root2 = newNode(70);
	rootr = merge(30,root1,root2);

	root = merge(10, rootl, rootr);

	cout<<" Preorder traversal of the binary tree -- "<<endl;
	preorder(root);
	cout<<endl;
	cout<<endl;

	cout<<" Reverse Level Order traversal of the binary tree -- "<<endl;
	reverseLevelOrder(root);
	cout<<endl;
}