#include<iostream>
#include<stack>
#include<deque>
#include<utility>
#include<algorithm>
using namespace std;

// spiral traversal of the bianry tree 
// time complexity -- o(n)
// space complexity -- o(n)

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

void spiralTraversalByTwoStack1(struct Node *root)
{
	if (root == NULL)
		return;

	stack<struct Node*> st1;
	stack<struct Node*> st2;

	st1.push(root);

	while(!st1.empty() || !st2.empty())
	{
		while(!st1.empty())
		{
			root = st1.top();
			cout<<root->data<<" ";
			st1.pop();

			if (root->left != NULL)
				st2.push(root->left);

			if (root->right != NULL)
				st2.push(root->right);
		}

		while(!st2.empty())
		{
			root = st2.top();
			cout<<root->data<<" ";
			st2.pop();

			if (root->right != NULL)
				st1.push(root->right);

			if (root->left != NULL)
				st1.push(root->left);
		}
	}
	cout<<endl;
}

void spiralTraversalByDeqAndNull2(struct Node *root)
{
	if (root == NULL)
		return;

	deque<struct Node*> dq;

	dq.push_front(NULL);
	dq.push_front(root);

	while(dq.size() != 1)
	{
		while(dq.front() != NULL)
		{
			root = dq.front();
			cout<<root->data<<" ";
			dq.pop_front();

			if (root->left != NULL)
				dq.push_back(root->left);

			if (root->right != NULL)
				dq.push_back(root->right);
		}

		while (dq.back() != NULL)
		{
			root = dq.back();
			cout<<root->data<<" ";
			dq.pop_back();

			if (root->right != NULL)
				dq.push_front(root->right);

			if (root->left != NULL)
				dq.push_front(root->left);
		}
	}

	dq.pop_front();
	cout<<endl;
}

void spiralTraversalByDeqAndTwoCnt3(struct Node *root)
{
	if (root == NULL)
		return;

	deque<struct Node*> dq;
	int levelcnt = 0;
	int curcnt = 0;
	dq.push_front(root);
	levelcnt++;

	int dir = 0;

	while (dq.size() != 0)
	{
		if (dir==0)
		{
			while(levelcnt != 0)
			{
				levelcnt--;
				root = dq.front();
				cout<<root->data<<" ";
				dq.pop_front();

				if (root->left != NULL)
				{
					curcnt++;
					dq.push_back(root->left);
				}

				if (root->right != NULL)
				{
					curcnt++;
					dq.push_back(root->right);
				}
			}

			levelcnt = curcnt;
			curcnt = 0;
			dir = 1;
		}
		else
		{
			while (levelcnt != 0)
			{
				levelcnt--;
				root = dq.back();
				cout<<root->data<<" ";
				dq.pop_back();

				if (root->right != NULL)
				{
					curcnt++;
					dq.push_front(root->right);
				}

				if (root->left != NULL)
				{
					curcnt++;
					dq.push_front(root->left);
				}
			}

			levelcnt = curcnt;
			curcnt = 0;
			dir = 0;
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

	// Tree example 1
	// root1 = newNode(8);
	// root1 = merge(4,root1,NULL);
	// root2 = newNode(9);
	// root2 = merge(5,root2,NULL);
	// rootl = merge(2,root1,root2);

	// root1 = newNode(6);
	// root2 = newNode(10);
	// root2 = merge(7,NULL,root2);
	// rootr = merge(3,root1,root2);

	// root = merge(1,rootl,rootr);

	// Tree example 2


	cout<<" Preorder of the binary tree --- "<<endl;
	preorder(root);
	cout<<endl;
	cout<<endl;

	cout<<" Spiral traversal of bianry tree by first method - (by use of two stack) "<<endl;
	spiralTraversalByTwoStack1(root);
	cout<<endl;

	cout<<" Spiral traversal of bianry tree by second method - (by use of one dequeue and NULL delimiter) "<<endl;
	spiralTraversalByDeqAndNull2(root);
	cout<<endl;	

	cout<<" Spiral traversal of bianry tree by second method - (by use of one dequeue and two variable (levelcount and currentcount)) "<<endl;
	spiralTraversalByDeqAndTwoCnt3(root);
	cout<<endl;


}