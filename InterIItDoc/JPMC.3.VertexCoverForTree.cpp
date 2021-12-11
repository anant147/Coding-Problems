#include <bits/stdc++.h> 
using namespace std; 

struct Node 
{
	int data;
	int vc;
	struct Node *left;
	struct Node *right;
};

int minval(int a, int b)
{
	if (a<b)
		return a;
	else
		return b;
}

struct Node* newNode(int data)
{
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = data;
	temp->vc = 0;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

int getMinVCover(struct Node *root)
{
	// cout<<" hello "<<endl;

	if (root==NULL)
		return 0;

	if (root->left == NULL && root->right == NULL)
		return 0;

	if (root->vc != 0)
		return root->vc;

	int size_incl = 1 + getMinVCover(root->left) + getMinVCover(root->right);

	int size_excl = 0;

	if (root->left != NULL)
		size_excl += (1 + getMinVCover(root->left->left) + getMinVCover(root->left->right));

	if (root->right != NULL)
		size_excl += (1 + getMinVCover(root->right->left) + getMinVCover(root->right->left));

	root->vc = minval(size_incl, size_excl);

	return root->vc;
}

int main()
{
	cout<<" JPMC question :- "<<endl;
	cout<<" Vertex cover for tree "<<endl;

	struct Node *root         = newNode(20); 
    root->left                = newNode(8); 
    root->left->left          = newNode(4); 
    root->left->right         = newNode(12); 
    root->left->right->left   = newNode(10); 
    root->left->right->right  = newNode(14); 
    root->right               = newNode(22); 
    root->right->right        = newNode(25);

    int answer = getMinVCover(root);

    cout<<" answer = "<<answer<<endl;
}