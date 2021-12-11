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

int numSubarraysWithSum(vector<int>& nums, int s)
{
    int i,j,k,u,v,x,y,z;

	int n = nums.size();

	if (n==0)
		return 0;
        
    int cond = 0;

	for (i=0;i<n;i++)
	{
		if (nums[i]==1)
		{
			cond = 1;
			break;
		}
	}

	if (cond==0)
	{
		if (s==0)
		{
			if (n%2==0)
				return (n/2)*(n+1);
			else
				return ((n+1)/2)*n;
		}
		else
			return 0;
	}
        
    if (s==0)
    {
        int sum = 0;
        
        int cnt = 0;
        
        for (i=0;i<n;i++)
        {
            if (nums[i]==0)
                cnt++;
            else if (nums[i]==1)
            {
                if (cnt!=0)
                {
                  if (cnt%2==0)
                      sum = sum + ((cnt/2)*(cnt+1));
                  else
                      sum = sum + ((cnt+1)/2)*cnt;
                    
                  cnt=0;
                }
            }
        }
        
        if (cnt!=0)
        {
            if (cnt%2==0)
               sum = sum + ((cnt/2)*(cnt+1));
            else
               sum = sum + ((cnt+1)/2)*cnt;
        }
        
        return sum;
    }

	vector<int> index;

	for (i=0;i<n;i++)
	{
		if (nums[i]==1)
			index.push_back(i);
	}


	if (index.size()<s)
		return 0;
	else
	{
		int sum = 0;

		int cnt1,cnt2;

		int ilen = index.size();

		if (s==1)
		{
			if (ilen==1)
			{
				cnt1 = index[0]+1;
				cnt2 = n - index[0];
				sum = cnt1 * cnt2;
			}
			else
			{
				for (i=0;i<ilen;i++)
				{
					if (i==0)
					{
						cnt1 = index[0]+1;
						cnt2 = index[1] - index[0];
					}
					else if (i==ilen-1)
					{
						cnt1 = index[i] - index[i-1];
						cnt2 = n - index[i];
					}
					else
					{
						cnt1 = index[i] - index[i-1];
						cnt2 = index[i+1] - index[i];
					}

					sum = sum + (cnt1 * cnt2);
				}
			}
		}
		else
		{
			for (i=0;i<ilen-s+1;i++)
			{
				j = i+s-1;

				if (i==0)
				{
					cnt1 = index[0]+1;

					if (j==(ilen-1))
						cnt2 = n - index[j];
					else
						cnt2 = index[j+1] - index[j];
				}
				else
				{
					cnt1 = index[i] - index[i-1];

					if (j==(ilen-1))
						cnt2 = n - index[j];
					else
						cnt2 = index[j+1] - index[j];
				}

				sum = sum + (cnt1*cnt2);
			}
		}

		return sum;
	}
}

int main()
{
	cout<<" 930. Binary Subarrays With Sum "<<endl;

	// example 1
	// vector<int> nums = {1,0,1,0,1};
	// int s = 2;

	// example 2
	// vector<int> nums = {1,0,0,1,0,0,1};
	// int s =2;

	// example 3
	// vector<int> nums = {0,0,0,0,0,0,1,0,0,0};
	// int s = 0;

	// example 4
	vector<int> nums = {0,0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0};
	int s = 3;

	cout<<" printing the nums vector :- "<<endl;
	for (int i=0;i<nums.size();i++)
		cout<<nums[i]<<" ";
	cout<<endl;
	cout<<" s = "<<s<<endl;

	int answer = numSubarraysWithSum(nums, s);

	cout<<" answer = "<<answer<<endl;
}