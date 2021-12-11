#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *next;
}* head;

Node *findNode( Node *head, int search_for)
{
	Node *current = head;

	while (current != NULL)
	{
		if (current->data == search_for)
			break;

		current = current->next;
	}

	return current;
}

void insert()
{
	int n, i, value;
	Node *temp;

	scanf("%d", &n);

	for (int i=0;i<n;i++)
	{
		scanf("%d", &value);

		if (i==0)
		{
			head = (Node *)malloc(sizeof(Node));
			head->data = value;
			head->next = NULL;
			temp = head;
			continue;
		}
		else
		{
			temp->next = (Node *)malloc(sizeof(Node));
			temp = temp->next;
			temp->data = value;
			temp->next = NULL;
		}
	}
}

void deleteNode(Node *node)
{
	if (node == NULL)
	{
		return;
	}
	else if (node->next == NULL)
	{
		node = NULL;
	}
	else
	{
		node->data = node->next->data;
		node->next = node->next->next;
	}
}

void printList(Node *node)
{
	cout<<" Printing the elements in the given linked list :- "<<endl;

	while (node != NULL)
	{
		printf ("%d ", node->data);
		node = node->next;
	}
	printf("\n");
}

int main(void)
{
	cout<<" Samsung 34 question :- "<<endl;
	cout<<" delete the given node in the linked list "<<endl;
	cout<<endl;

	// You are given a pointer/reference to a node to be deleted in a
	 // linked list. The task is to delete the node. Pointer/reference 
	// to head node is not given. You may assume that the node to be 
	// deleted is not the last node.

	int t,k,n, value;

	scanf("%d",&t);

	while (t--)
	{
		insert();
		scanf("%d",&k);

		Node *del = findNode(head,k);

		if (del != NULL && del->next != NULL)
		{
			deleteNode(del);
		}

		printList(head);
	}





}