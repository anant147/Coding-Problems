#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

vector<TreeNode*> generateTrees(int n)
{
	vector<TreeNode*> anstree = {};

	return anstree;
}

int main()
{
	int n = 3;

	cout<<" 95. Unique Binary Search Trees II "<<endl;
	vector<TreeNode*> anstree = generateTrees(n);

	cout<<" size of anstree"<<anstree.size()<<endl;
}