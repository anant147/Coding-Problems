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

int getSumFromFenwick(vector<int>& fenwick, int index)
{
	int sum = 0;

	index = index + 1;

	while (index > 0)
	{
		sum = sum + fenwick[index];

		index = index - (index & (-index));
	}

	return sum;
}

void updateVal(vector<int>& fenwick, int totval, int index)
{
	index = index+1;

	while (index <= totval)
	{
		fenwick[index]++;

		index = index + (index & (-index));
	}
}

vector<int> countSmaller(vector<int>& nums)
{
	int i,j,k,u,v,x;

	int n = nums.size();

	if (n==1)
		return {0};

	vector<int> answer;
	answer.resize(n,0);

	vector<int> arr, fenwick;
	int totval = 20001;
	arr.resize(totval,0);
	fenwick.resize(totval+1,0);

	for (i=n-1;i>=0;i--)
	{
		k = 10000 + nums[i];

		x = getSumFromFenwick(fenwick, k-1);

		answer[i] = x;

		arr[k]++;

		updateVal(fenwick,totval,k);
	}

	return answer;
}

int main()
{
	cout<<" 315. Count of Smaller Numbers After Self "<<endl;

	vector<int> nums = {5,2,6,1};

	cout<<" printing the nums vector :- "<<endl;

	int i;

	for (i=0;i<nums.size();i++)
		cout<<nums[i]<<" ";
	cout<<endl;

	vector<int> answer = countSmaller(nums);

	cout<<" printing the answer vector :- "<<endl;
	for (i=0;i<answer.size();i++)
		cout<<answer[i]<<" ";
	cout<<endl;
	cout<<endl;
}