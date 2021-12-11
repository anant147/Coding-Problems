#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

// root to leaf sum problem -- given a sum value, we have to tell whether there is a path from root to leaf such that sum of path is equal to given sum value
// time complexity  -- o(n)
// space complexity -- o(n)

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};

struct Node* newNode(int data)
{
	struct Node *root = (struct Node*)malloc(sizeof(struct Node));

	root->data = data;
	root->left = NULL;
	root->right = NULL;

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
	if (root != NULL)
	{
	  cout<<root->data<<" ";
	  preorder(root->left);
	  preorder(root->right);
	}
}

bool rootToLeafSum(struct Node *root, int sum , vector<int>& result)
{
	if (root == NULL)
		return false;

	if (root->left == NULL && root->right == NULL)
	{
		if (sum == root->data)
		{
			result.push_back(root->data);
			return true;
		}
		else
			return false;
	}

	if (rootToLeafSum(root->left, sum-(root->data),result))
	{
		result.push_back(root->data);
		return true;
	}

	if (rootToLeafSum(root->right, sum-(root->data),result))
	{
		result.push_back(root->data);
		return true;
	}

	return false;
}

int main()
{
   struct Node *root = NULL;
   struct Node *rootl = NULL;
   struct Node *rootr = NULL;
   struct Node *root1 = NULL;
   struct Node *root2 = NULL;
   struct Node *root3 = NULL;
   struct Node *root4 = NULL;

   root1 = newNode(-3);
   rootl = merge(16, NULL, root1);

   root1 = newNode(6);
   root2 = newNode(11);
   rootr = merge(5,root1,root2);

   root = merge(10, rootl, rootr);

   // int sum = 26;
   // int sum = 21;
   int sum = 33;
   vector<int> result;

   cout<<" Preorder of the given bianry tree --- "<<endl;
   preorder(root);
   cout<<endl;
   cout<<endl;

   bool answer = rootToLeafSum(root,sum,result);

   if (answer)
   {
   	cout<<" sum of given value = "<<sum<<" is found from leaf to root. "<<endl;
   	cout<<endl;
   	cout<<" Elements for leaf to root path for which sum is equal to sum in this path -- "<<endl;
   	for (int i=0;i<result.size();i++)
   		cout<<result[i]<<" ";
   	cout<<endl;
   }
   else
   {
   	cout<<" sum of given value = "<<sum<<" is not found from leaf to root. "<<endl;
   }

}