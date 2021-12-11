#include<iostream>
#include<stack>
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

void iterativeInorder(struct Node *root)
{
	stack<struct Node*> s;

	while(true)
	{
		if (root!=NULL)
		{
			s.push(root);
			root=root->left;
		}
		else
		{
			if (s.empty())
				break;

			root = s.top();
			s.pop();
			cout<<root->data<<" ";
			root = root->right;
		}
	}
}

int main()
{
	struct Node *root = NULL;
	struct Node *root1 = NULL;
	struct Node *root2 = NULL;
	struct Node *rootl = NULL;
	struct Node *rootr = NULL;

    // Tree example 1
	root1 = newNode(5);
	root2 = newNode(6);
	root1 = merge(0,root1,root2);
	rootl = root1;

	root1 = newNode(11);
	root1 = merge(-10,NULL,root1);
	rootr = root1;

	root = merge(10,rootl,rootr);

	cout<<" Iterative inorder of the given bianry tree -- "<<endl;
	iterativeInorder(root);
	cout<<endl;

}