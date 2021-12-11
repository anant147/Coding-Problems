#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

static bool sortPairbySec(pair<int,int> p1, pair<int,int> p2)
{
   return (p1.second>=p2.second);
}

vector<int> topKFrequent(vector<int>& nums, int k)
{
    int i,j,u,v,x,y,z;

    vector<pair<int,int>> mvec;

    vector<int> result;

    if (nums.size()==1 && k==1)
      return nums;

    sort(nums.begin(),nums.end());
    int cnt = 0;

    for (i=0;i<nums.size();)
    {
    	u = nums[i];
    	j=i;

    	while(nums[j]==u)
    	{
    		cnt++;
    		j++;
    	}

    	mvec.push_back(make_pair(u,cnt));
    	cnt=0;
    	i=j;
    }

    sort(mvec.begin(),mvec.end(),sortPairbySec);

    // cout<<" print count of each type of elements"<<endl;
    // for (i=0;i<mvec.size();i++)
    // 	cout<<mvec[i].first<<" "<<mvec[i].second<<endl;

    // cout<<endl;

    for (i=0;i<k;i++)
     {
     	result.push_back(mvec[i].first);
     }

    return result;    
}

int main()
{
	cout<<" 347. Top K Frequent Elements "<<endl;

	// vector<int> nums = {1,1,1,2,2,3};
	// int k = 2;
	vector<int> nums = {-1,-1};
	int k = 1;
	int i;

	cout<<" elements of the nums vector -- "<<endl;
	for ( i = 0;i<nums.size();i++)
		cout<<nums[i]<<" ";
	cout<<endl;
	cout<<" k = "<<k<<endl;
	cout<<endl;

	vector<int> result = topKFrequent(nums,k);

	for (i=0;i<result.size();i++)
		cout<<result[i]<<" ";
	cout<<endl;
}