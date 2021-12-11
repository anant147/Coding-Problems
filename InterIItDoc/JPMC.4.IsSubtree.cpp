#include <bits/stdc++.h> 
using namespace std; 

struct node 
{ 
    int data; 
    struct node* left; 
    struct node* right; 
}; 

struct node* newNode(int data) 
{ 
    struct node* node =  (struct node*)malloc(sizeof(struct node)); 
    node->data  = data; 
    node->left  = NULL; 
    node->right = NULL; 
    return(node); 
}

bool areIdentical(struct node *root1, struct node *root2)
{
	if (root1==NULL && root2==NULL)
		return true;

	if (root1==NULL || root2==NULL)
		return false;

	return ( (root1->data == root2->data) && areIdentical(root1->left, root2->left) && areIdentical(root1->right, root2->right) );
}

bool isSubtree(struct node *t, struct node *s)
{
	if (s==NULL)
		return true;

	if (t==NULL)
		return NULL;

	if ( areIdentical(t, s))
		return true;

	return ( isSubtree(t->left, s) || isSubtree(t->right, s));
}

int main()
{
	cout<<" JPMC question 1 "<<endl;
	cout<<" is subtree question "<<endl;

	// example 1
	struct node *t        = newNode(26); 
    t->right              = newNode(3); 
    t->right->right       = newNode(3); 
    t->left               = newNode(10); 
    t->left->left         = newNode(4); 
    t->left->left->right  = newNode(30); 
    t->left->right = newNode(6);

    struct node *s    = newNode(10); 
    s->right          = newNode(6); 
    s->left           = newNode(4); 
    s->left->right    = newNode(30); 

    bool answer = isSubtree( t, s);

    if (answer)
    	cout<<" given s is subtree of t"<<endl;
    else
    	cout<<" given s is not subtree of t"<<endl;


}