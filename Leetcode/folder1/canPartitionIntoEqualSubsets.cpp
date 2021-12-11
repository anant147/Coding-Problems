#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

bool canPartition(vector<int>& nums)
{
	int i,j,k,u,v,x,y,len,answer;

	int n = nums.size();

	if (n==0)
		return true;

	if (n==1)
		return false;

	sort(nums.begin(),nums.end());

	int sum = 0;

	for (i=0;i<n;i++)
		sum=sum+nums[i];

	if (sum%2==1)
		return false;

	int m = sum/2;

	bool temp[n][m+1];

	for (i=0;i<n;i++)
		temp[i][0]=true;

	for (i=0;i<n;i++)
	{
		for (j=1;j<=m;j++)
		{
			if (i==0)
			{
				if (j==nums[i])
					temp[i][j]=true;
				else
					temp[i][j]=false;
			}
			else
			{
               if (j<nums[i])
               	temp[i][j]=temp[i-1][j];
               else
               	temp[i][j]=temp[i-1][j] | temp[i-1][j-nums[i]];
			}
		}
	}

	// printing temp matrix
	cout<<" printing the temp matrix -- "<<endl;
	// for (i=0;i<n;i++)
	// {
	// 	for (j=0;j<=m;j++)
	// 		cout<<temp[i][j]<<" ";
	// 	cout<<endl;
	// }
	// cout<<endl;

	return temp[n-1][m];
}

int main()
{
	int i,j,k;
	// vector<int> nums = {1,5,5,11};
	// vector<int> nums = {1, 2, 3, 5};
	vector<int> nums = {23,13,11,7,6,5,5};
	cout<<"  Partition Equal Subset Sum problem "<<endl;
	int n = nums.size();

	cout<<" n = "<<n<<endl;
	cout<<" elements of the nums vector -- "<<endl;
	for (i=0;i<n;i++)
	cout<<nums[i]<<" ";
	cout<<endl;

	bool answer = canPartition(nums);

	if (answer)
	cout<<" given elements can be partitioned "<<endl;
	else
	cout<<" given elements cannot be partitioned "<<endl;
}