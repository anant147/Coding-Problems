#include <bits/stdc++.h> 
using namespace std;

struct Node
{ 
    int data; 
    Node *left, *right; 
};

Node* getNode(int data) 
{ 
    // allocate space 
    Node* newNode = (Node*)malloc(sizeof(Node)); 
  
    // put in the data 
    newNode->data = data; 
    newNode->left = newNode->right = NULL; 
    return newNode; 
}

int sumOfLeafNodesAtMinLevel(struct Node *root)
{
	if (root == NULL)
		return 0;

	if (root->left == NULL && root->right == NULL)
		return root->data;

	queue<Node*> q;
	q.push(root);

	int flag = 0;
	int sum = 0;

	while (flag == 0)
	{
		int sz = q.size();

		while (sz>0)
		{
			sz--;

			Node *temp = q.front();
			q.pop();

			if (temp->left == NULL && temp->right == NULL)
			{
				sum += temp->data;
				flag = 1;
			}
			else
			{
				if (temp->left != NULL)
					q.push(temp->left);
				
				if (temp->right != NULL)
					q.push(temp->right);
			}
		}
	}

	return sum;
}


int main()
{
	cout<<" JPMC question :-"<<endl;
	cout<<" Sum of leaf nodes at minimum level "<<endl;

	// binary tree creation 
    Node* root = getNode(1); 
    root->left = getNode(2); 
    root->right = getNode(3); 
    root->left->left = getNode(4); 
    root->left->right = getNode(5); 
    root->right->left = getNode(6); 
    root->right->right = getNode(7); 
    root->left->right->left = getNode(8); 
    root->right->left->right = getNode(9); 
  
    cout << "Sum = "<<sumOfLeafNodesAtMinLevel(root)<<endl;

}