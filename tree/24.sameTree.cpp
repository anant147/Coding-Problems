#include<iostream>
#include<vector>
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

bool isSameTree(struct Node *root1, struct Node *root2)
{
	if (root1 == NULL && root2 == NULL)
		return true;

	if (root1 == NULL || root2 == NULL)
		return false;

	return (root1->data == root2->data) && isSameTree(root1->left, root2->left) && isSameTree(root1->right,root2->right);
}

int main()
{
	struct Node *rootl = NULL;
	struct Node *rootr = NULL;

	struct Node *root1 = NULL;
	struct Node *root2 = NULL;

	struct Node *root3 = NULL;
	struct Node *root4 = NULL;
	struct Node *root5 = NULL;
	struct Node *root6 = NULL;
     
    // Example1
 //    // tree1
	// rootl = newNode(16);
	// root3 = newNode(18);
	// rootr = merge(15,root3,NULL);

	// root1 = merge(10,rootl,rootr);

	// // tree2
	// rootl = newNode(16);
	// root3 = newNode(18);
	// rootr = merge(15,root3,NULL);

	// root2 = merge(10,rootl,rootr);

	// Example 2
	// // tree 1
	// rootl = newNode(12);
	// root3 = newNode(16);
	// root3 = merge(15,NULL,root3);
	// root4 = newNode(14);
	// rootr = merge(13,root3,root4);

	// root1 = merge(10,rootl,rootr);

	// // tree 2
	// rootl = newNode(12);
	// root3 = newNode(16);
	// root3 = merge(15,NULL,root3);
	// root4 = newNode(14);
	// rootr = merge(13,root3,root4);

	// root2 = merge(10,rootl,rootr);

	// Example 3
	// tree 1
	rootl = newNode(12);
	root3 = newNode(16);
	root3 = merge(15,NULL,root3);
	root4 = newNode(14);
	rootr = merge(13,root3,root4);

	root1 = merge(10,rootl,rootr);

	// tree 2
	rootl = newNode(12);
	root3 = newNode(18);
	root3 = merge(15,NULL,root3);
	root4 = newNode(14);
	rootr = merge(13,root3,root4);

	root2 = merge(10,rootl,rootr);

	cout<<" Preorder of tree 1 --- "<<endl;
	preorder(root1);
	cout<<endl;
	cout<<endl;

	cout<<" Preorder of tree 2 --- "<<endl;
	preorder(root2);
	cout<<endl;
	cout<<endl;

	bool answer = isSameTree(root1,root2);

	if (answer)
		cout<<" given two trees are same."<<endl;
	else
		cout<<" given two trees are not same."<<endl;

}