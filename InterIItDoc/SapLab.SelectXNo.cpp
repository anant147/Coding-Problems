#include<bits/stdc++.h>
using namespace std;

int getValue1(vector<int>& nums, int x, int m)
{
	int i,j,k,u,v;

	int sum = 0;

	for (i=0;i<nums.size() && i<x;i++)
	{
		int n = nums.size();

		int max1 = *max_element(nums.begin(), nums.begin() + min( (int)nums.size(), m));
		int index1 = max_element(nums.begin(), nums.begin() + min( (int)nums.size(), m)) - nums.begin();

		int max2 = *max_element( nums.begin()+max(0,m-n-2), nums.end());
		int index2 = max_element( nums.begin()+max(0,m-n-2), nums.end()) - nums.begin();

		// cout<<" max1 = "<<max1<<endl;
		// cout<<" index1 = "<<index1<<endl;
		// cout<<" max2 = "<<max2<<endl;
		// cout<<" index2 = "<<index2<<endl;

		if (max1 >= max2)
		{
			sum += max1;
			nums.erase( nums.begin() + index1);
		}
		else
		{
			sum += max2;
			nums.erase( nums.begin() + index2);
		}
	}

	return sum;
}


int getValue2(vector<int>& nums, int x, int m)
{
	int n = nums.size();

	cout<<"n = "<<n<<endl;

	priority_queue<pair<int,int>> pq;

	for (int i=0;i<m;i++)
		pq.push(make_pair(nums[i], i));

	int l = m-1;
	int r = n-m;

	cout<<" l = "<<l<<endl;
	cout<<" r = "<<r<<endl;

	if (r > l)
	{
		cout<<" cond satisfied "<<endl;

		for (int i=n-m;i<n;i++)
			pq.push(make_pair(nums[i], i));
	}
	else
	{
		cout<<" cond not satisfied "<<endl;
	}

	int sum = 0;

	while(l<r && x>0)
	{
		pair<int,int> temp = pq.top();
		pq.pop();

		sum += temp.first;
		cout<<" val = "<<temp.first<<endl;

		if (temp.second > l)
		{
			r--;

			if (r>l)
				pq.push(make_pair(nums[r], r));

			x--;
		}
		else if (temp.second < l)
		{
			l++;

			if (l<r)
				pq.push( make_pair( nums[l], l));

			x--;
		}
	}

	while (!pq.empty() && x>0)
	{
		sum += pq.top().first;
		pq.pop();
		x--;
	}

	return sum;
}


int main()
{
	cout<<" Sap lab question :- "<<endl;
	cout<<" select x numbers :- "<<endl;

	vector<int> nums = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

	int x = 5;
	int m = 3;

	cout<<" printing the nums vector :- "<<endl;
	for (int i=0;i<nums.size();i++)
		cout<<nums[i]<<" ";
	cout<<endl;
	cout<<endl;

	cout<<" x = "<<x<<endl;
	cout<<" m = "<<m<<endl;

	int answer1 = getValue1(nums, x, m);

	cout<<" answer1 = "<<answer1<<endl;

	nums = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	x = 2;
	m = 10;

	int answer2 = getValue2(nums, x, m);

	cout<<" answer2 = "<<answer2<<endl;
}