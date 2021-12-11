#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<unordered_map>
#include<queue>
#include<stack>
#include<cmath>
#include<cstring>
using namespace std;

int numTrees(int n)
{
	if (n==1)
		return 1;

	int k = (2*n);

	int cnt = 0;

	int answer = 1;

	while (cnt<n)
	{
		answer = answer * k;
		answer = answer/(cnt+1);
		k--;
		cnt++;
	}

	answer = answer/(n+1);

	return answer;
}

int main()
{
	cout<<" 96. Unique Binary Search Trees "<<endl;

	// example 1
	// int n = 3;

	// example 2
	// int n = 4;

	// example 3
	int n = 5;

	cout<<" n = "<<n<<endl;

	int answer = numTrees(n);

	cout<<" answer = "<<answer<<endl;
}