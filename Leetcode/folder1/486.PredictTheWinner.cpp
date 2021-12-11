#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

bool PredictTheWinner(vector<int>& nums)
{
	int i,j,k,u,v,x,y,p,q,answer,len;

	int n = nums.size();

	if (n==0 || n==1)
		return true;

	int temp[n][n][2];

	for (i=0;i<n;i++)
	{
		temp[i][i][0]=nums[i];
		temp[i][i][1]=0;
	}

	for (len=2;len<=n;len++)
	{
		for (i=0;i<(n-len+1);i++)
		{
			j=i+len-1;

			if ((nums[i]+temp[i+1][j][1]) > (nums[j]+temp[i][j-1][1]))
			{
				temp[i][j][0] = nums[i]+temp[i+1][j][1];
				temp[i][j][1] = temp[i+1][j][0];
			}
			else
			{
				temp[i][j][0] = nums[j]+temp[i][j-1][1];
				temp[i][j][1] = temp[i][j-1][0];
			}
		}
	}

	p = temp[0][n-1][0];
	q = temp[0][n-1][1];

	// cout<<" printing the temp matrix -- "<<endl;
	// for (i=0;i<n;i++)
	// {
	// 	for (j=i;j<n;j++)
	// 		cout<<" ("<<temp[i][j][0]<<" , "<<temp[i][j][1]<<") ";
	// 	cout<<endl;
	// }

	if (p>=q)
		return true;
	else
		return false;
}

int main()
{
	int i,j,k,u,v,x,y;
	// vector<int> nums = {1,5,2};
	vector<int> nums = {1, 5, 233, 7};


	int n = nums.size();
	cout<<" 486. Predict the winner "<<endl;
	cout<<" the size of nums vector --- "<<n<<endl;
	for (i=0;i<n;i++)
		cout<<nums[i]<<" ";
	cout<<endl;

	bool answer = PredictTheWinner(nums);
	if (answer)
		cout<<" first player is the winner "<<endl;
	else
		cout<<" second player is the winner "<<endl;


}