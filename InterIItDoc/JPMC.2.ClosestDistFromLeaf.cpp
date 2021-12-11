#include <bits/stdc++.h> 
using namespace std; 

struct Node 
{ 
    char key; 
    struct Node* left, *right; 
}; 

Node *newNode(char k) 
{ 
    Node *node = new Node; 
    node->key = k; 
    node->right = node->left = NULL; 
    return node; 
} 

int getMin(int x, int y) 
{ 
    return (x < y)? x :y; 
}

int closestDown(struct Node *root)
{
	if (root == NULL)
		return INT_MAX;

	if (root->left==NULL && root->right==NULL)
		return 0;

	return 1 + getMin(closestDown(root->left), closestDown(root->right));
}

int findClosestUtil( struct Node *root, char k, struct Node *ancestors[], int index)
{
	if (root == NULL)
		return INT_MAX;

	if (root->key == k)
	{
		int res = closestDown(root);

		for (int i=index-1;i>=0;i--)
			res = getMin(res, index-i+closestDown(ancestors[i]));

		return res;
	}

	ancestors[index] = root;

	return getMin( findClosestUtil(root->left, k, ancestors, index+1), findClosestUtil(root->right, k, ancestors, index+1));
}

int findClosest(struct Node *root, char k)
{
	struct Node *ancestors[100];

	return findClosestUtil(root, k, ancestors, 0);
}

int main()
{
	cout<<" JPMC question "<<endl;
	cout<<" Closest distance from a leaf of binary tree "<<endl;

	struct Node *root        = newNode('A'); 
    root->left               = newNode('B'); 
    root->right              = newNode('C'); 
    root->right->left        = newNode('E'); 
    root->right->right       = newNode('F'); 
    root->right->left->left  = newNode('G'); 
    root->right->left->left->left  = newNode('I'); 
    root->right->left->left->right = newNode('J'); 
    root->right->right->right      = newNode('H'); 
    root->right->right->right->left = newNode('K'); 

    char k = 'H'; 
    cout << "Distance of the closest key from " << k << " is "
         << findClosest(root, k) << endl; 
    cout<<endl;

    k = 'C'; 
    cout << "Distance of the closest key from " << k << " is "
         << findClosest(root, k) << endl; 
    cout<<endl;

    k = 'E'; 
    cout << "Distance of the closest key from " << k << " is "
         << findClosest(root, k) << endl; 
    cout<<endl;

    k = 'B'; 
    cout << "Distance of the closest key from " << k << " is "
         << findClosest(root, k) << endl; 

    cout<<endl;
}