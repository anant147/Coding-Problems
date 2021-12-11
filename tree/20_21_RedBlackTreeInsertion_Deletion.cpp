#include<iostream>
#include<utility>
#include<algorithm>
using namespace std;

enum Color { Black, Red};

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	struct Node *parent;
	Color color;
	bool isNUllLeaf;
};

struct Node* createBlackNode(int data)
{
	struct Node *root = (struct Node*)malloc(sizeof(struct Node));
	root
}



int main()
{
 struct Node root = NULL;	
}