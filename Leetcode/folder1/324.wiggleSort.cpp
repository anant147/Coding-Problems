#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

void wiggleSort(vector<int>& nums)
{
	int i,j,k,u,v,x,y,z;

	int temp;

	for (i=0;i<nums.size()-1;i++)
	{
		if (i==0)
		{
			if (!(nums[0]<nums[1]))
			{
				if (nums[1]<nums[0])
				{
					temp=nums[0];
					nums[0]=nums[1];
					nums[1]=temp;
				}
				else
				{
					j=i+1;
					while(true)
					{
						if (j<nums.size() && nums[j]<nums[1])
							break;

						j++;
					}

					temp = nums[i];
					nums[i]=nums[j];
					nums[j]=temp;
				}
			}
		}
		else
		{
			if (i%2==0)
			{
				if (!(nums[i-1]>nums[i]))
				{
					if (nums[i-1]<nums[i])
					{
						temp = nums[i-1];
						nums[i-1] = nums[i];
						nums[i] = temp;
					}
					else
					{
						j=i+1;

						while(true)
						{
							if (j<nums.size() && nums[j]<nums[i-1])
								break;

							j++;
						}

						temp = nums[i];
						nums[i] = nums[j];
						nums[j] = temp;
					}
				}
			}
			else
			{
				if (!(nums[i-1]<nums[i]))
				{
					if (nums[i-1]>nums[i])
					{
						temp = nums[i-1];
						nums[i-1] = nums[i];
						nums[i]=temp;
					}
					else
					{
						j=i+1;

						while(true)
						{
							if(j<nums.size() && nums[j]>nums[i-1])
								break;

							j++;
						}

						temp = nums[i];
						nums[i]=nums[j];
						nums[j] = temp;
					}
				}
			}
		}
	}
}

int main()
{
	cout<<" 324. Wiggle Sort II "<<endl;
	// vector<int> nums = {1,5,1,1,6,4};
	vector<int> nums = {1, 3, 2, 2, 3, 1};

	cout<<" elements of the nums vector --> "<<endl;
	for (int i=0;i<nums.size();i++)
		cout<<nums[i]<<" ";
	cout<<endl;

	wiggleSort(nums);

	cout<<" elements of the wiggle sorted nums vector --> "<<endl;
	for (int i=0;i<nums.size();i++)
		cout<<nums[i]<<" ";
	cout<<endl;

}