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

bool searchInBtree(struct Node *root,int data)
{
	if (root == NULL)
		return false;
	if (root != NULL)
	{
	 if (root->data == data)
	 	return true;
	 else
	 	return (searchInBtree(root->left,data) || searchInBtree(root->right,data));
	}
}

struct Node *lowestCommonAncestorInBtree(struct Node *root, int data1, int data2)
{
	if (root == NULL)
		return NULL;

	if (root->data == data1 || root->data == data2)
		return root;

	struct Node *left = lowestCommonAncestorInBtree(root->left, data1, data2);
	struct Node *right = lowestCommonAncestorInBtree(root->right, data1, data2);

	if (left != NULL && right != NULL)
		return root;

	if (left == NULL && right == NULL)
		return NULL;

	if (left != NULL)
		return left;
	else
		return right;
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

	root1 = newNode(9);
	root2 = newNode(5);
	root1 = merge(11,root1,root2);
	root2 = newNode(2);
	rootl = merge(6,root2,root1);

	root1 = newNode(7);
	root1 = merge(13,root1,NULL);
	rootr = merge(8,NULL,root1);

	root = merge( 3,rootl,rootr);

	cout<<" Preorder of the given bianry tree -- "<<endl;
	preorder(root);
	cout<<endl;
	cout<<endl;

	int val1,val2;
	bool tval1,tval2;
	struct Node *answer;

	val1 = 2;
	val2 = 8;
	tval1 = searchInBtree(root,val1);
	tval2 = searchInBtree(root,val2);
	if (tval1 && tval2)
	{
		answer = lowestCommonAncestorInBtree(root,val1,val2);
		cout<<" lowest common ancestor of "<<val1<<" and "<<val2<<" is "<<answer->data<<endl;
		cout<<endl;
	}

	val1 = 2;
	val2 = 5;
	tval1 = searchInBtree(root,val1);
	tval2 = searchInBtree(root,val2);
	if (tval1 && tval2)
	{
		answer = lowestCommonAncestorInBtree(root,val1,val2);
		cout<<" lowest common ancestor of "<<val1<<" and "<<val2<<" is "<<answer->data<<endl;
		cout<<endl;
	}

	val1 = 9;
	val2 = 5;
	tval1 = searchInBtree(root,val1);
	tval2 = searchInBtree(root,val2);
	if (tval1 && tval2)
	{
		answer = lowestCommonAncestorInBtree(root,val1,val2);
		cout<<" lowest common ancestor of "<<val1<<" and "<<val2<<" is "<<answer->data<<endl;
		cout<<endl;
	}

	val1 = 7;
	val2 = 8;
	tval1 = searchInBtree(root,val1);
	tval2 = searchInBtree(root,val2);
	if (tval1 && tval2)
	{
		answer = lowestCommonAncestorInBtree(root,val1,val2);
		cout<<" lowest common ancestor of "<<val1<<" and "<<val2<<" is "<<answer->data<<endl;
		cout<<endl;
	}

	val1 = 9;
	val2 = 3;
	tval1 = searchInBtree(root,val1);
	tval2 = searchInBtree(root,val2);
	if (tval1 && tval2)
	{
		answer = lowestCommonAncestorInBtree(root,val1,val2);
		cout<<" lowest common ancestor of "<<val1<<" and "<<val2<<" is "<<answer->data<<endl;
		cout<<endl;
	}

	val1 = 2;
	val2 = 13;
	tval1 = searchInBtree(root,val1);
	tval2 = searchInBtree(root,val2);
	if (tval1 && tval2)
	{
		answer = lowestCommonAncestorInBtree(root,val1,val2);
		cout<<" lowest common ancestor of "<<val1<<" and "<<val2<<" is "<<answer->data<<endl;
		cout<<endl;
	}



}