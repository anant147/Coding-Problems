#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<stack>
#include<climits>
#include<queue>
#include<cmath>
#include<cstring>
using namespace std;

struct Node
{
	struct Node *left;
	struct Node *right;
};

struct Node* newNode()
{
	struct Node *root = (struct Node*)malloc(sizeof(struct Node));
	
	root->left = NULL;
	root->right = NULL;

	return root;
}

void insert(struct Node *root,int n)
{
	struct Node *curr = root;

	for (int i=31;i>=0;i--)
	{
		int b = ((n>>i)&(1));

		if (b==0)
		{
			if (curr->left == NULL)
				curr->left = newNode();
			curr = curr->left;
		}
		else
		{
			if (curr->right == NULL)
				curr->right = newNode();
			curr = curr->right;
		}
	}
}

int maxval(int a,int b)
{
	if (a>b)
		return a;
	else
		return b;
}

int findMaximumXOR(vector<int>& nums)
{
	int i,j,k,u,v,x,y,z;

	struct Node *root = newNode();

	for (i=0;i<nums.size();i++)
		insert(root,nums[i]);

	int curxor;
	int maxxor = 0;

	for (i=0;i<nums.size();i++)
	{
		struct Node *curr = root;
		k = nums[i];
		curxor = 0;

		for (j=31;j>=0;j--)
		{
			int b = ((1<<j)&k);

			if (b==0)
			{
				if (curr->right != NULL)
				{
					curxor = curxor + (1<<j);
					curr = curr->right;
				}
				else
					curr = curr->left;
			}
			else
			{
				if (curr->left != NULL)
				{
					curxor = curxor + (1<<j);
					curr = curr->left;
				}
				else
					curr = curr->right;
			}
		}

		maxxor = maxval(maxxor, curxor);
	}

	return maxxor;

}

int main()
{
	cout<<"  421. Maximum XOR of Two Numbers in an Array "<<endl;

	// example 1
	// vector<int> nums = {3,10,5,25,2,8};

	// example 2
	// vector<int> nums = {0};

	// example 3
	// vector<int> nums = {2,4};

	// example 4
	// vector<int> nums = {8,10,2};

	// example 5
	vector<int> nums = {14,70,53,83,49,91,36,80,92,51,66,70};

	cout<<" printing the nums vector :- "<<endl;
	for (int i=0;i<nums.size(); i++)
		cout<<nums[i]<<" ";
	cout<<endl;
	cout<<endl;

	int answer = findMaximumXOR(nums);

	cout<<" answer = "<<answer<<endl;
}