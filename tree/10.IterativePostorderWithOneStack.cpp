#include<iostream>
#include<utility>
#include<algorithm>
#include<stack>
using namespace std;

// Postorder traversal of binary tree with one stack
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

void iterativePostorderWithOneStack(struct Node *root)
{
	stack<struct Node*> s1;
	struct Node *current = root;

	while (current != NULL || !s1.empty())
	{
		if (current != NULL)
		{
			s1.push(current);
			current = current->left;
		}
		else
		{
			struct Node *temp = (s1.top())->right;

			if (temp==NULL)
			{
				temp = s1.top();
				s1.pop();
				cout<<temp->data<<" ";

				while (!s1.empty() && temp == (s1.top())->right)
				{
					temp = s1.top();
					s1.pop();
					cout<<temp->data<<" ";
				}
			}
			else
			{
				current = temp;
			}
		}
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
	// root1 = newNode(8);
	// rootl = merge(-6,NULL,root1);

	// rootr = newNode(15);

	// root = merge(10,rootl,rootr);

	// Tree example 2
	root1 = newNode(4);
	root2 = newNode(6);
	root2 = merge(5,root2,NULL);
	rootl = merge(2,root1,root2);

	root1 = newNode(8);
	root1 = merge(7,NULL,root1);
	rootr = merge(3,NULL,root1);

	root = merge(1,rootl,rootr);
	
	cout<<" Iterative postorder traversal of the binary tree with one stack -- "<<endl;
	iterativePostorderWithOneStack(root);
	cout<<endl;

}