#include<iostream>
#include<utility>
#include<algorithm>
#include<cmath>
#include<queue>
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

void levelByLevelPrintBtree1(struct Node *root)
{
	queue<struct Node*> q1;
	queue<struct Node*> q2;

	q1.push(root);

	while (!q1.empty() || !q2.empty())
	{
		if (q2.empty())
		{
			while (!q1.empty())
			{
				root = q1.front();
				cout<<root->data<<" ";
				q1.pop();

				if (root->left != NULL)
					q2.push(root->left);

				if (root->right != NULL)
					q2.push(root->right);
			}
			cout<<endl;
		}

		if (q1.empty())
		{
			while(!q2.empty())
			{
				root = q2.front();
				cout<<root->data<<" ";
				q2.pop();

				if (root->left != NULL)
					q1.push(root->left);

				if (root->right != NULL)
					q1.push(root->right);
			}
			cout<<endl;
		}
	}
}

void levelByLevelPrintBtree2(struct Node *root)
{
	queue<struct Node*> q1;

	q1.push(root);
	q1.push(NULL);

	while (!q1.empty())
	{
		root=q1.front();
		q1.pop();

		if (root == NULL)
		{
			cout<<endl;

			if (!q1.empty())
				q1.push(NULL);
		}
		else
		{
			cout<<root->data<<" ";

			if (root->left != NULL)
				q1.push(root->left);

			if (root->right != NULL)
				q1.push(root->right);
		}
	}
}

void levelByLevelPrintBtree3(struct Node *root)
{
	queue<struct Node*> q1;

	int levelcnt;
	int curcnt;

	q1.push(root);

	levelcnt = 1;
	curcnt = 0;

	while(levelcnt !=0 || curcnt != 0)
	{
		root = q1.front();
		q1.pop();
		levelcnt--;

		cout<<root->data<<" ";

		if (root->left != NULL)
		{
			curcnt++;
			q1.push(root->left);
		}

		if (root->right != NULL)
		{
			curcnt++;
			q1.push(root->right);
		}

		if (levelcnt==0)
		{
			cout<<endl;
			levelcnt = curcnt;
			curcnt = 0;
		}
	}
}

int main()
{
	struct Node *root = NULL;
	struct Node *rootl = NULL;
	struct Node *rootr = NULL;
	struct Node *root1 = NULL;
	struct Node *root2 = NULL;

	// Tree example 1
	root1 = newNode(8);
	root2 = newNode(9);
	root1 = merge(5,root1,root2);
	root2 = newNode(4);
	rootl = merge(2,root2,root1);

	root1 = newNode(10);
	root1 = merge(7,root1,NULL);
	root2 = newNode(6);
	rootr = merge(3,root2,root1);

	root = merge(1,rootl,rootr);

	cout<<" preorder of the given binary tree --- "<<endl;
	preorder(root);
	cout<<endl;
	cout<<endl;

	cout<<" Level by Level printing of binary tree by method 1 (two queues )--- "<<endl;
	levelByLevelPrintBtree1(root);
	cout<<endl;

	cout<<" Level by Level printing of binary tree by method 2 (one queue and one delimiter.i.e.NULL )--- "<<endl;
	levelByLevelPrintBtree2(root);
	cout<<endl;

	cout<<" Level by Level printing of binary tree by method 3 (one queue and two counters (levelCounter and currentCounter) )--- "<<endl;
	levelByLevelPrintBtree3(root);
	cout<<endl;

}