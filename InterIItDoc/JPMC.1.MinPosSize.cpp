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

// my approach
int getLength1(vector<int>& nums, int k)
{
	int n = nums.size();

	if (n<=2)
		return n;

	int i,j,u,v,x,y,z;

	while (n>=3)
	{
		int cond = 0;

		i = n-1;
		while (i>=2)
		{
			if ( ( nums[i]-nums[i-1] == k) && ( nums[i-1] - nums[i-2] == k) )
			{
				cond = 1;
				nums.erase(nums.begin() + (i-2));
				nums.erase(nums.begin() + (i-2));
				nums.erase(nums.begin() + (i-2));
				break;
			}
			else
			{
				i--;
			}
		}

		n = nums.size();

		if (cond==0)
			break;
	}

	return n;
}

///////////////////////
// geeks for geeks dp appraoch

int minval(int a, int b)
{
	if (a<b)
		return a;
	else
		return b;
}

int minSizeRec(vector<int>& nums, vector<vector<int>>& dp, int low, int high, int k)
{


	if ((high-low+1) < 3)
		return (high-low+1);

	if (dp[low][high] != -1)
		return dp[low][high];

	int res = 1 + minSizeRec(nums, dp, low+1, high, k);

	for (int i = low+1; i<=(high-1); i++)
	{
		for (int j = i+1; j<=high;j++)
		{
			if (nums[i]==(nums[low]+k) && nums[j]==(nums[low]+2*k) &&  minSizeRec(nums, dp, low+1,i-1,k) == 0 && minSizeRec(nums, dp, i+1,j-1, k) == 0)
			{
				res = minval(res, minSizeRec(nums, dp, j+1, high, k));
			}
		}
	}

	cout<<"res = "<<res<<endl;
	cout<<" low = "<<low<<endl;
	cout<<" high = "<<high<<endl;

	return (dp[low][high]=res);
}

int getLength2(vector<int>& nums, int k)
{
	int n = nums.size();

	if (n<=2)
		return n;

	vector<vector<int>> dp;
	dp.resize(n, vector<int> (n,-1));

	int answer = minSizeRec(nums, dp, 0, n-1, k);

	cout<<" printing the dp vector :- "<<endl;
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
			cout<<dp[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;

	return answer;
}



// C++ program to find size of minimum possible array after 
// removing elements according to given rules 
#include <bits/stdc++.h> 
using namespace std; 
#define MAX 1000 
  
// dp[i][j] denotes the minimum number of elements left in 
// the subarray arr[i..j]. 
int dp[MAX][MAX]; 
  
int minSizeRec(int arr[], int low, int high, int k) 
{ 
    // If already evaluated 
    if (dp[low][high] != -1) 
        return dp[low][high]; 
  
    // If size of array is less than 3 
    if ( (high-low + 1) < 3) 
        return high-low +1; 
  
    // Initialize result as the case when first element is 
    // separated (not removed using given rules) 
    int res = 1 + minSizeRec(arr, low+1, high, k); 
  
    // Now consider all cases when first element forms a triplet 
    // and removed. Check for all possible triplets (low, i, j) 
    for (int i = low+1; i<=high-1; i++) 
    { 
        for (int j = i+1; j <= high; j++ ) 
        { 
            // Check if this triplet follows the given rules of 
            // removal. And elements between 'low' and 'i' , and 
            //  between 'i' and 'j' can be recursively removed. 
            if (arr[i] == (arr[low] + k) && 
                arr[j] == (arr[low] + 2*k) && 
                minSizeRec(arr, low+1, i-1, k) == 0 && 
                minSizeRec(arr, i+1, j-1, k) == 0) 
            { 
                 res = min(res, minSizeRec(arr, j+1, high, k)); 
            } 
        } 
    } 
  
    // Insert value in table and return result 
    return (dp[low][high] = res); 
} 
  
// This function mainlu initializes dp table and calls 
// recursive function minSizeRec 
int minSize(int arr[], int n, int k) 
{ 
    memset(dp, -1, sizeof(dp)); 
    return minSizeRec(arr, 0, n-1, k); 
} 

int main()
{
	cout<<" JPMC question :-  "<<endl;
	cout<<" Find minimum possible size of array with given rules for removing elements "<<endl;

	// example 1
	// vector<int> nums = {2, 3, 4, 5, 6, 4};
	// int k = 1;

	// example 2
	vector<int> nums = {2, 3, 4, 7, 6, 4};
	int k = 1;

	cout<<" printing the nums vector :- "<<endl;
	for (int i=0;i<nums.size();i++)
		cout<<nums[i]<<" ";
	cout<<endl;
	cout<<endl;

	cout<<" k = "<<k<<endl;

	// My approach
	cout<<" my approach - "<<endl;
	int answer1 = getLength1( nums, k);

	cout<<" answer1 = "<<answer1<<endl;

	//Geeks for geeks approach
	cout<<endl;
	cout<<" geeks for geels approach"<<endl;
	// example 1
	// nums = {2, 3, 4, 5, 6, 4};

	// example 2
	nums = {2,3,4,7,6,4};
	cout<<" printing the nums vector :- "<<endl;
	for (int i=0;i<nums.size();i++)
		cout<<nums[i]<<" ";
	cout<<endl;
	cout<<endl;

	int answer2 = getLength2(nums, k);
	cout<<endl;
	cout<<" answer2 = "<<answer2<<endl;
}