#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

int deleteAndEarn(vector<int>& nums)
{
	int i,j,k,u,v,x,y,p,q,answer,len;

	int m = nums.size();
	int cond;

	if (m==0)
		return 0;
	else if (m==1)
		return nums[0];

	int count[10001];

	for (i=0;i<=10000;i++)
		count[i]=0;

	for (i=0;i<m;i++)
	{
		u = nums[i];
		count[u]++;
	}

	vector<int> elem;
	vector<int> elemval;

	for (i=0;i<=10000;i++)
	{
		if (count[i]!=0)
		{
			elem.push_back(i);
			elemval.push_back(count[i]*i);
		}
	}

	int n = elem.size();

	int temp[n][n];

	for (i=0;i<n;i++)
	{
		temp[i][i]=elemval[i];
	}

	for (len=2;len<=n;len++)
	{
		for(i=0;i<(n-len+1);i++)
		{
			j=i+len-1;

			if (len==2)
			{
				if (elem[j]==(elem[i]+1))
				{
					if (elemval[i]>elemval[j])
						temp[i][j]=elemval[i];
					else
						temp[i][j]=elemval[j];
				}
				else
					temp[i][j]=temp[i][i]+temp[j][j];
			}
			else if (len==3)
			{
				cond=0;

				if (elem[i+1]==(elem[i]+1) && elem[i+1]==(elem[j]-1))
					cond=1;
				else if (elem[i+1]==(elem[i]+1))
					cond=2;
				else if (elem[i+1]==(elem[j]-1))
					cond=3;

				if (cond==0)
				{
					temp[i][j]=elemval[i]+temp[i+1][j];
				}
				else if (cond==1)
				{
					u=elemval[i+1];
					v=elemval[i]+elemval[j];

					if (u<v)
						temp[i][j]=v;
					else
						temp[i][j]=u;
				}
				else if (cond==2)
				{
					u=elemval[i]+elemval[j];
					v=temp[i+1][j];

					if (u<v)
						temp[i][j]=v;
					else
						temp[i][j]=u;
				}
				else if (cond==3)
				{
					u=elemval[i]+elemval[j];
					v=temp[i][i+1];

					if (u<v)
						temp[i][j]=v;
					else
						temp[i][j]=u;
				}
			}
			else
			{
				cond=0;

				if (elem[i+1]==(elem[i]+1) && elem[i+1]==(elem[i+2]-1))
					cond=1;
				else if (elem[j-1]==(elem[j-2]+1) && elem[j-1]==(elem[j]-1))
					cond=2;
				else if (elem[i+1]==(elem[i]+1))
					cond=3;
				else if (elem[j-1]==(elem[j]-1))
					cond=4;

				if (cond==0)
				{
					temp[i][j]=elemval[i] + temp[i+1][j];
				}
				else if (cond==1)
				{
					u=elemval[i] + temp[i+2][j];
					v=elemval[i+1] + temp[i+3][j];

					if (u<v)
						temp[i][j]=v;
					else
						temp[i][j]=u;
				}
				else if (cond==2)
				{
					u = elemval[j] + temp[i][j-2];
					v = elemval[j-1] + temp[i][j-3];

					if (u<v)
						temp[i][j]=v;
					else
						temp[i][j]=u;
				}
				else if (cond==3)
				{
					u = elemval[i] + temp[i+2][j];
					v = temp[i+1][j];

					if (u<v)
						temp[i][j]=v;
					else
						temp[i][j]=u;
				}
				else if (cond==4)
				{
					u = elemval[j] + temp[i][j-2];
					v = temp[i][j-1];

					if (u<v)
						temp[i][j]=v;
					else
						temp[i][j]=u;
				}

			}
		}
	}

	// cout<<" print temp matrix -- "<<endl;
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
	// vector<int> nums = {3, 4, 2};
	vector<int> nums = {2, 2, 3, 3, 3, 4};
	
	cout<<" 740. Delete And Earn problem "<<endl;
	int n =nums.size();
	cout<<" size of vector --- "<<endl;
	for (i=0;i<n;i++)
		cout<<nums[i]<<" ";
	cout<<endl;

	int answer = deleteAndEarn(nums);
	cout<<" answer = "<<answer<<endl;
}