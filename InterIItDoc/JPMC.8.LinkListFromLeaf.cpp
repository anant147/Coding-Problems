#include <bits/stdc++.h> 
using namespace std;

typedef struct TreeNode
{
    struct TreeNode *left, *right, *next;
    int data;

}TreeNode;

typedef TreeNode * Tree;

inline  TreeNode * makeTreeNode(int data)
{
    TreeNode *n = (TreeNode*)malloc(sizeof(TreeNode));
    n->data = data;

    return n;
}


void leafLinked(Tree t, TreeNode **head, TreeNode **prevLeaf)
{
	if (t != NULL)
	{
		if (t->left == NULL && t->right == NULL)
		{
			if (*head == NULL)
				*head = t;
			else if (*prevLeaf)
				(*prevLeaf)->next = t;

			*prevLeaf = t; 

		}
		else
		{
			leafLinked(t->left, head, prevLeaf);
			leafLinked(t->right, head, prevLeaf);
		}
	}
}

inline void printList(Tree t)
{
    while(t)
    {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}



int main()
{
	cout<<" JPMC question 8"<<endl;
	cout<<"  Create a singly linked list of Leaf nodes from a binary tree  "<<endl;

	// level 0
	Tree t = makeTreeNode(10);

    /*level 1*/
    t->left = makeTreeNode(20);
    t->right = makeTreeNode(30);


    /*level 2*/
    t->left->left = makeTreeNode(40);
    t->left->right = makeTreeNode(70);
    t->right->left = makeTreeNode(50);
    t->right->right = makeTreeNode(60);

    /*level 3*/
    t->left->left->left = makeTreeNode(70);
    t->right->right->left = makeTreeNode(60);
    t->right->right->right = makeTreeNode(160);

    TreeNode *head = NULL;
    TreeNode *prevLeaf = NULL;

    leafLinked(t, &head, &prevLeaf);

    cout<<" printing the leaf nodes of the tree :- "<<endl;
    printList(head);
}