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

int maxval(int a,int b)
{
	if (a>b)
		return a;
	else
		return b;
}

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

int heightOfBtree(struct Node *root)
{
	if (root==NULL)
		return 0;

	int leftHeight = heightOfBtree(root->left);
	int rightHeight = heightOfBtree(root->right);

	return (1 + maxval(leftHeight,rightHeight));
}

void preorder(struct Node *root)
{
	if (root!=NULL)
	{
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}

int main()
{
    struct Node *root = NULL;
    struct Node *root1 = NULL;
    struct Node *root2 = NULL;
    struct Node *rootl = NULL;
    struct Node *rootr = NULL;

    // tree example 1
    // rootl = newNode(5);

    // root1 = newNode(4);
    // root1 = merge(7, NULL, root1);
    // root2 = newNode(8);
    // rootr = merge(6, root2, root1);

    // root = merge(10, rootl, rootr);

    // tree example 2
    root1 = newNode(4);
    root1 = merge(5,root1,NULL);
    root1 = merge(6,root1,NULL);
    root1 = merge(7,root1,NULL);
    rootl = root1;

    root1 = newNode(10);
    root1 = merge(11,NULL,root1);
    root1 = merge(12,NULL,root1);
    root2 = newNode(13);
    root1 = merge(14,root2,root1);
    rootr = root1;

    root = merge(16,rootl,rootr);


    int answer = heightOfBtree(root);

    cout<<" height of the binary tree -- "<<answer<<endl;

    cout<<endl;
    cout<<" preorder of the given tree -- "<<endl;
    preorder(root);
    cout<<endl;
}