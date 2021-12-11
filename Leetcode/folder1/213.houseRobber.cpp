#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

int maxval(int a,int b)
{
	if (a<b)
		return b;
	else
		return a;
}

int maxval3(int a,int b,int c)
{
	return maxval(a,maxval(b,c));
}

int rob(vector<int>& nums)
{
	int i,j,k,u,v,x,y,p,q,answer,len;

	int n = nums.size();

	if (n==0)
		return 0;
	else if (n==1)
		return nums[0];

	int temp[n][n];

	for (i=0;i<n;i++)
		temp[i][i]=nums[i];

	for (len=2;len<=n;len++)
	{
		for (i=0;i<(n-len+1);i++)
		{
			j=i+len-1;

			if (n==len)
			{
				if (n==2)
				{
					u=temp[i][i];
					v=temp[j][j];
					temp[i][j]=maxval(u,v);
				}
				else if (n==3)
				{
					u=temp[i][i];
					v=temp[i+1][i+1];
					x=temp[j][j];

					temp[i][j]=maxval3(u,v,x);
				}
				else
				{
				   u=nums[i] + temp[i+2][j-1];
				   v = temp[i+1][j-2] + nums[j];
				   x = temp[i+1][j-1];

				   temp[i][j]=maxval3(u,v,x);	
				}
			}
			else if (len==2)
			{
				u=nums[i];
				v=nums[j];

				temp[i][j]=maxval(u,v);
			}
			else
			{
				u = nums[i] + temp[i+2][j];
				v = temp[i][j-2] + nums[j];
				x = temp[i+1][j-1];

				temp[i][j]=maxval3(u,v,x);
			}
		}
	}

	// cout<<" printing temp matrix -- "<<endl;
	// for (i=0;i<n;i++)
	// {
	// 	for (j=i;j<n;j++)
	// 		cout<<temp[i][j]<<" ";
	// 	cout<<endl;
	// }

	answer = temp[0][n-1];

	return answer;
}

int main()
{
	int i,j;
	// vector<int> nums = {2,3,2};
	vector<int> nums = {1,2,3,1};
	int n = nums.size();
	cout<<" 213. House Robber 2.. "<<endl;
	cout<<" size of nums vector -- "<<n<<endl;
	cout<<" element of nums vector -- "<<endl;
	for (i=0;i<n;i++)
	cout<<nums[i]<<" ";
	cout<<endl;

	int answer = rob(nums);
	cout<<" answer = "<<answer<<endl;
}