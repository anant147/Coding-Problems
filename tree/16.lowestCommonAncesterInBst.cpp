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

struct Node* newNode (int data)
{
	struct Node *root = (struct Node*)malloc(sizeof(struct Node));

	root->data = data;
	root->left = NULL;
	root->right = NULL;

	return root;
}

struct Node* insert(struct Node *root,int data)
{
	struct Node *newnod = newNode(data);

	if (root == NULL)
	{
	  // cout<<"0"<<endl;
	  return newnod;
	}

	struct Node *parent = NULL;
	struct Node *curr = root;

	while(curr!=NULL)
	{
		parent = curr;

		if (data < curr->data)
			curr = curr->left;
		else
			curr = curr->right;
	}

	if (data < parent->data)
	{
		parent->left = newnod;
		// cout<<"1"<<endl;
	}
	else
	{
		parent->right = newnod;
		// cout<<"2"<<endl;
	}

	return root;
}

bool searchInBst(struct Node *root,int data)
{
	if (root == NULL)
	{
		cout<<" given val = "<<data<<" is not in the bst"<<endl;
		return false;
	}
	else if (root->data == data)
	{
		cout<<" given val = "<<data<<" is in the bst"<<endl;
		return true;
	}
	else if (data < root->data)
		return searchInBst(root->left,data);
	else
		return searchInBst(root->right,data);
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

struct Node* lowestCommonAncestorInBst(struct Node *root, int data1, int data2)
{
	if (root->data > max(data1,data2))
		return lowestCommonAncestorInBst(root->left, data1, data2);
	else if (root->data < min(data1,data2))
		return lowestCommonAncestorInBst( root->right, data1, data2);
	else
		return root;
}

int main()
{
	struct Node *root = NULL;

	root = insert(root,10);
	root = insert(root,-10);
	root = insert(root,8);
	root = insert(root,6);
	root = insert(root,9);

	root = insert(root,30);
	root = insert(root,25);
	root = insert(root,28);
	root = insert(root,60);
	root = insert(root,78);

	cout<<" Preorder of the given binary search tree -- "<<endl;
	preorder(root);
	cout<<endl;
	cout<<endl;

	int val1,val2;
	bool tval1,tval2;
	struct Node *answer;

	val1 = 28;
	val2 = 78;
	tval1 = searchInBst(root,val1);
	tval2 = searchInBst(root,val2);
	if (tval1 && tval2)
	{
		answer = lowestCommonAncestorInBst(root,val1,val2);
		cout<<" lowest common ancestor of "<<val1<<" and "<<val2<<" is "<<answer->data<<endl;
		cout<<endl;
	}


	val1 = 6;
	val2 = 9;
	tval1 = searchInBst(root,val1);
	tval2 = searchInBst(root,val2);
	if (tval1 && tval2)
	{
		answer = lowestCommonAncestorInBst(root,val1,val2);
		cout<<" lowest common ancestor of "<<val1<<" and "<<val2<<" is "<<answer->data<<endl;
		cout<<endl;
	}

	val1 = 30;
	val2 = 78;
	tval1 = searchInBst(root,val1);
	tval2 = searchInBst(root,val2);
	if (tval1 && tval2)
	{
		answer = lowestCommonAncestorInBst(root,val1,val2);
		cout<<" lowest common ancestor of "<<val1<<" and "<<val2<<" is "<<answer->data<<endl;
		cout<<endl;
	}

	val1 = 16;
	val2 = 91;
	tval1 = searchInBst(root,val1);
	tval2 = searchInBst(root,val2);
	if (tval1 && tval2)
	{
		answer = lowestCommonAncestorInBst(root,val1,val2);
		cout<<" lowest common ancestor of "<<val1<<" and "<<val2<<" is "<<answer->data<<endl;
		cout<<endl;
	}

}