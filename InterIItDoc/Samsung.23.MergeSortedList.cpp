#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node* next;
};

void MoveNode(Node** destRef, Node** sourceRef);  



Node* SortedMerge(Node* a, Node* b)
{
	Node dummy;

	Node* tail = &dummy;

	dummy.next = NULL;

	while (1)
	{
		if (a==NULL)
		{
			tail->next = b;
			break;
		}
		else if (b==NULL)
		{
			tail->next = a;
			break;
		}

		if (a->data <= b->data)
			MoveNode(&(tail->next), &a);
		else
			MoveNode(&(tail->next), &b);

		tail = tail->next;
	}

	return (dummy.next);
}

void MoveNode(Node** destRef, Node** sourceRef)
{
	Node *new_node = *sourceRef;

	assert(new_node != NULL);

	*sourceRef = new_node->next;

	new_node->next = *destRef;

	*destRef = new_node;
}

void push(Node** head_ref, int new_data)
{
	Node* new_node = new Node();

	new_node->data = new_data;

	new_node->next = (*head_ref);

	(*head_ref) = new_node;
}

void printList(Node *node)
{
	while (node != NULL)
	{
		cout<<node->data<<" ";
		node = node->next;
	}
}



void MoveNode(Node** destRef, Node **sourceRef);


int main()
{
    cout<<" Samsung question 23 :- "<<endl;
    cout<<" Merge two sorted linked list :- "<<endl;
    cout<<endl;

	Node* res = NULL;
	Node*a = NULL;
	Node*b = NULL;

	push(&a, 15);
	push(&a, 10);
	push(&a, 5);

	push(&b, 20);
	push(&b, 3);
	push(&b,2);

	res = SortedMerge(a, b);

	cout<<" Merged linked list is : "<<endl;
	printList(res);

	cout<<endl;

}