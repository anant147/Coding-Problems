#include <bits/stdc++.h> 
using namespace std;

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct node* newNode(int data)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

struct node* insert(struct node *root, int data)
{
	if (root == NULL)
		return newNode(data);

	if ( data < root->data)
		root->left = insert(root->left, data);
	else
		root->right = insert(root->right, data);

	return root;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void inorderOfTree(struct node *root)
{
	if (root)
	{
		inorderOfTree(root->left);
		cout<<root->data<<" ";
		inorderOfTree(root->right);
	}
}

void getElemOfBstSort(struct node *root,vector<int>& nodval)
{
	if (root)
	{
		getElemOfBstSort(root->left, nodval);
		nodval.push_back(root->data);
		getElemOfBstSort(root->right, nodval);
	}
}

int kthLargElem(struct node *root, int k)
{
	if (root==NULL)
		return -1;

	if (root->left == NULL && root->right == NULL)
	{
		if (k==1)
			return root->data;
		else
			return -1;
	}

	vector<int> nodval;

	getElemOfBstSort(root, nodval);

	int n = nodval.size();

	if (n<k)
		return -1;

	vector<int> temp;
	for (int i=n-1;i>=0;i--)
		temp.push_back(nodval[i]);

	return temp[k-1];
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void kthLargestUtil(struct node *root, int k, int &c)
{
	if (root == NULL || c>=k)
		return;

	kthLargestUtil(root->right, k, c);

	c++;

	if (c==k)
	{
		cout<<" "<<k<<" th largest element is "<<root->data<<endl;
		cout<<endl;
		return;
	}

	kthLargestUtil(root->left, k, c);
}

void kthLargest2(struct node *root, int k)
{
	int c = 0;

	kthLargestUtil(root, k, c);
}

int main()
{
	cout<<" JPMC 10 question "<<endl;
	cout<<" K’th Largest Element in BST when modification to BST is not allowed "<<endl;

	struct node *root = NULL; 
    root = insert(root, 50); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80);

    cout<<" printing the inorder of given tree :- "<<endl;
    inorderOfTree(root);
    cout<<endl; 

    int k = 5;
    cout<<"method 1"<<endl;
    cout<<" k = "<<k<<endl;
    cout<<endl;
    int answer = kthLargElem(root, k);

    cout<<" answer = "<<answer<<endl;

    cout<<endl;
    cout<<endl;

    cout<<" gfg method 2"<<endl;
    k = 4;
    kthLargest2(root,k);

    k = 6;
    kthLargest2(root,k);
}