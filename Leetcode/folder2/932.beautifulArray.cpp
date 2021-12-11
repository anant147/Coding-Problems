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

vector<int> beautifulArray(int n)
{
	if (n==1)
		return {1};

	int i;

	vector<int> result = {1};
	vector<int> temp;

	while (result.size() < n)
	{
		for (i=0;i<result.size();i++)
		{
			if ((2*result[i]) <= n)
				temp.push_back(2*result[i]);
		}

		for (i=0;i<result.size();i++)
		{
			if ((2*result[i]-1) <= n)
				temp.push_back(2*result[i]-1);
		}

		result.clear();
		result = temp;
		temp.clear();
	}

	return result;
}

int main()
{
	cout<<" 932. Beautiful Array  "<<endl;

	// example 1
	// int n = 4;

	// example 2
	int n = 5;

	cout<<" n = "<<n<<endl;

	vector<int> answer = beautifulArray(n);
	int i,j;

	cout<<" printing the answer vector :- "<<endl;
	for (i=0;i<answer.size();i++)
		cout<<answer[i]<<" ";
	cout<<endl;
}