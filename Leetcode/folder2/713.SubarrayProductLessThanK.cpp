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

int numSubarrayProductLessThanK(vector<int>& nums, int k)
{
    int i,j,u,v,x,y,z;

	int n = nums.size();

	long long int mult = 1;
	long long int tmult = 1;
    long long int kdup = (long long int)k;
	int curlen = 0;
	int prevlen = 0;
	int cursum = 0;
	int prevsum = 0;

	int sum = 0;

	i=0;j=0;

	while(j<n)
	{
		while(j<n && mult<k)
		{
			tmult = tmult* (long long int)nums[j];

			if (tmult<kdup)
			{
				mult = mult * (long long int)nums[j];
				j++;
			}
			else
				break;
		}

		j--;

		curlen = j-i+1;
		if (curlen%2==1)
            cursum = curlen * ((curlen+1)/2);
        else
            cursum = (curlen/2) * (curlen+1);

		sum = sum + cursum - prevsum;

		if (curlen==0)
		{
			prevlen = 0;
			prevsum = 0;
			mult = 1;
			tmult = 1;
		}
		else
		{
			prevlen =  curlen - 1;
            
            if (prevlen%2==1)
                prevsum = prevlen * ((prevlen+1)/2);
            else
                prevsum = (prevlen/2) * (prevlen+1);
		
			mult = mult/ ((long long int)nums[i]);
			tmult = mult;
	    }

		i++;
		j++;

		if (j<i)
			j=i;

	}

	return sum;
}

int main()
{
	cout<<" 713. Subarray Product Less Than K "<<endl;

	// example 1
	// vector<int> nums = {10,5,2,6};
	// int k = 100;

	// example 2
	vector<int> nums = {2,3,4,5};
	int k = 121;

	cout<<" printing the nums vector :- "<<endl;
	for (int i=0;i<nums.size();i++)
		cout<<nums[i]<<" ";
	cout<<endl;
	cout<<endl;

	cout<<" k = "<<k<<endl;
	cout<<endl;

	int answer = numSubarrayProductLessThanK(nums, k);

	cout<<" answer = "<<answer<<endl;

}