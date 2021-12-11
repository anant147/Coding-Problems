#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node *next;
};

void push(Node** head_ref, int new_data)
{
	Node* new_node = new Node();

	new_node->data = new_data;

	new_node->next = (*head_ref);

	(*head_ref) = new_node;
}

bool detectLoop(Node* list)
{
	Node *slow = list;
	Node *fast = list;

	cout<<" printing the value of nodes in the list :-"<<endl;
	while (slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		cout<<slow->data<<" ";

		if (slow == fast)
		{
			cout<<endl;
			return true;
		}
	}
	cout<<endl;
	return false;
}

int main()
{
	cout<<" Samsung question 8 : "<<endl;
	cout<<" Find a cycle in LinkedList. "<<endl;
	cout<<endl;

	Node* head = NULL;

	push(&head, 20);
	push(&head, 4);
	push(&head, 15);
	push(&head, 10);

	head->next->next->next->next = head;

	if (detectLoop(head))
		cout<<" Loop found "<<endl;
	else
		cout<<" Loop not found "<<endl;

}