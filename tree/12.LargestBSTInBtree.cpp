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

struct treeInfo
{
	bool isBst;
	int count;
	int min;
	int max;
};

struct Node* newNode(int data)
{
	struct Node *root = (struct Node*)malloc(sizeof(struct Node));

	root->data = data;
	root->left = NULL;
	root->left = NULL;

	return root;
}

struct Node* merge(int data, struct Node *left, struct Node *right)
{
	struct Node *root = (struct Node*)malloc(sizeof(struct Node));

	root->data = data;
	root->left = left;
	root->right = right;

	return root;
}

void preorder(struct Node *root)
{
	if (root!=NULL)
	{
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}

struct treeInfo getLargestBSTInBtree(struct Node *root)
{
	struct treeInfo answer;

	if (root==NULL)
	{
		answer.isBst = true;
		answer.count = 0;
		answer.min = 0;
		answer.max = 0;

		return answer; 
	}

	if (root->left==NULL && root->right==NULL)
	{
		answer.isBst = true;
		answer.count = 1;
		answer.min = root->data;
		answer.max = root->data;

		return answer;
	}

	struct treeInfo ansleft = getLargestBSTInBtree(root->left);
	struct treeInfo ansright = getLargestBSTInBtree(root->right);

	if (ansleft.isBst == false && ansright.isBst == false)
	{
		if (ansleft.count >= ansright.count)
		{
			answer.isBst = false;
			answer.count = ansleft.count;
			answer.min = ansleft.min;
			answer.max = ansleft.max;
		}
		else
		{
			answer.isBst = false;
			answer.count = ansright.count;
			answer.min = ansright.min;
			answer.max = ansright.max;		
		}
	}
	else if ( ansleft.count == 0 || ansright.count == 0)
	{
		if (ansleft.count == 0)
		{
			if (root->data <= ansright.min)
			{
				answer.isBst = true;
				answer.count = 1 + ansright.count;
				answer.min = root->data;
				answer.max = ansright.max;
			}
			else
			{
				answer.isBst = false;
				answer.count = ansright.count;
				answer.min = ansright.min;
				answer.max = ansright.max;			
			} 
		}
		else if (ansright.count == 0)
		{
			if (ansleft.max <= root->data)
			{
				answer.isBst = true;
				answer.count = 1 + ansleft.count;
				answer.min = ansleft.min;
				answer.max = root->data;
		    }
		    else
		    {
		    	answer.isBst = false;
				answer.count = ansleft.count;
				answer.min = ansleft.min;
				answer.max = answer.max;
		    } 	
		}
	}
	else if (ansleft.isBst == true && ansright.isBst == true)
	{

		if ( (ansleft.max <= root->data) && (root->data <= ansright.min) )
		{
			answer.isBst = true;
			answer.count = 1 + ansleft.count + ansright.count;
			answer.min = ansleft.min;
			answer.max = ansright.max;
		}
		else
		{
			if (ansleft.count >= ansright.count)
			{
				answer.isBst = false;
				answer.count = ansleft.count;
				answer.min = ansleft.min;
				answer.max = ansleft.max;
			}
			else
			{
				answer.isBst = false;
				answer.count = ansright.count;
				answer.min = ansright.min;
				answer.max = ansright.max;		
			}
		}
	}
	else
	{
		if (ansleft.count >= ansright.count)
		{
			answer.isBst = false;
			answer.count = ansleft.count;
			answer.min = ansleft.min;
			answer.max = ansleft.max;
		}
		else
		{
			answer.isBst = false;
			answer.count = ansright.count;
			answer.min = ansright.min;
			answer.max = ansright.max;		
		}
	}

	return answer;
}

int main()
{
	struct Node *root = NULL;
	struct Node *root1 = NULL;
	struct Node *root2 = NULL;
	struct Node *root3 = NULL;
	struct Node *rootl = NULL;
	struct Node *rootr = NULL;

    // Tree example 1
	// root1 = newNode(15);
	// root1 = merge(19,NULL,root1);
	// root2 = newNode(18);
	// root3 = newNode(25);
	// root2 = merge(20,root2,root3);
	// rootl = merge(18,root1,root2);

	// root1 = newNode(25);
	// root1 = merge(20,NULL,root1);
	// root2 = newNode(40);
	// root1 = merge(35,root1,root2);
	// root2 = newNode(55);
	// root3 = newNode(70);
	// root2 = merge(60,root2,root3);
	// rootr = merge(50,root1,root2);

	// root = merge(25,rootl,rootr);

	// Tree example 2
	root1 = newNode(5);
	root2 = newNode(20);
	rootl = merge(30,root1,root2);

	root1 = newNode(45);
	root2 = newNode(65);
	root3 = newNode(80);
	root2 = merge(70,root2,root3);
	rootr = merge(60,root1,root2);

	root = merge(50,rootl,rootr);

	cout<<" Preorder of the given tree --- "<<endl;
	preorder(root);
	cout<<endl;
	cout<<endl;

	struct treeInfo answer = getLargestBSTInBtree(root);

	if (answer.isBst)
		cout<<" given binary tree is a binary search tree "<<endl;
	else
		cout<<" given binary tree is not a binary search tree "<<endl;

	cout<<" number of nodes in the bst obtained -- "<<answer.count<<endl;
	cout<<" range of elements in the bst obtained -- ("<<answer.min<<" , "<<answer.max<<")"<<endl;


}