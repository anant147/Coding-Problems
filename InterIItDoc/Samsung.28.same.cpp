#include<bits/stdc++.h>
using namespace std;

int sumAtKthLevel(string tree, int k)
{
	int level = -1;
	int sum = 0;
	int n = tree.length();

	for (int i=0;i<n;i++)
	{
		if (tree[i] == '(')
			level++;
		else if ( tree[i] == ')')
			level--;
		else
		{
			if (level == k)
				sum += (tree[i]-'0');
		}
	}

	return sum;
}

int main()
{
	cout<<" samsung 28 :- another simple approach "<<endl;
	cout<<" Sum of nodes at k-th level in a tree represented as string :- "<<endl;
	cout<<endl;

	string tree = "(0(5(6()())(4()(9()())))(7(1()())(3()())))";
	int k = 2;

	int answer = sumAtKthLevel(tree, k);

	cout<<" answer = "<<answer<<endl;
	cout<<endl;
}