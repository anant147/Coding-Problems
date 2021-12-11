#include <bits/stdc++.h> 
using namespace std;

const char hashTable[10][5] = {"", "", "abc", "def", "ghi", "jkl", 
                               "mno", "pqrs", "tuv", "wxyz"};

void printWordsUtil(vector<int>& nums, int cur_digit, char output[], int n)
{
	int i;

	if (cur_digit == n)
	{
		printf("%s ", output);
		return;
	}

	for (i=0;i<strlen(hashTable[nums[cur_digit]]);i++)
	{
		// if (nums[cur_digit]==0 || nums[cur_digit]==1)
			// return;

		output[cur_digit] = hashTable[nums[cur_digit]][i];

		printWordsUtil(nums, cur_digit+1, output, n);

		if (nums[cur_digit]==0 || nums[cur_digit]==1)
			return;

	}
}

void printWords(vector<int>& nums, int n)
{
	char result[n+1];
	result[n] = '\0';

	printWordsUtil(nums,0,result,n);
	cout<<endl;
}

int main()
{
	cout<<" JPMC question 12 :- "<<endl;
	cout<<" Print all possible words from phone digits "<<endl;

	// example 1
	// vector<int> nums = {2,3,4};

	// example 2
	vector<int> nums = {2,0,4};
	int n = nums.size();

	cout<<"printing the nums vector :- "<<endl;
	for (int i=0;i<n;i++)
		cout<<nums[i]<<" ";
	cout<<endl;
	cout<<endl;

	printWords(nums, n);


}