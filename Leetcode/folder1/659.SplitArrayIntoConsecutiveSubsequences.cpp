#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
using namespace std;

bool isPossible(vector<int>& nums)
{
	int i,j,k,u,v,x,y,z;

	vector<vector<int>> numstor;
	int count;

	int n = nums.size();

	for (i=0;i<nums.size();)
	{
		k = nums[i];

		j=i;
		count = 0;

		while((j<n) && nums[j]==k)
		{
			j++; count++;
		}

		numstor.push_back({k,count});
		i=j;
	}

	priority_queue<pair<int,int>> pq1;
	vector<pair<int,int>> vtemp;
	pair<int,int> pt1,pt2,pt3,pt4;
	int val1,val2,val3,val4;
	int cnt1,cnt2,cnt3,cnt4;

	if (numstor.size()<3)
		return false;

	for (i=0;i<numstor.size();i++)
	{
		u = numstor[i][0], v = numstor[i][1];
		pq1.push(make_pair(u,v));
	}

	int cond=0;

	while(pq1.size()!=0)
	{
		pt1 = pq1.top();  pq1.pop();  val1 = pt1.first;  cnt1 = pt1.second;
		// cout<<" val1 = "<<val1<<" , cnt1 = "<<cnt1<<endl;

		if (pq1.size()==0)
		{
			cond=1; break;
		}

		pt2 = pq1.top();  pq1.pop();  val2 = pt2.first; cnt2 = pt2.second;
		// cout<<" val2 = "<<val2<<" , cnt2 = "<<cnt2<<endl;

		if (pq1.size()==0)
		{
			cond=1; break;
		}

		pt3 = pq1.top(); pq1.pop();  val3 = pt3.first; cnt3 = pt3.second;
		// cout<<" val3 = "<<val3<<" , cnt3 = "<<cnt3<<endl;

		if ( (val1 == (val2+1) ) && (val2 == (val3+1) ) )
		{
			cnt1--; cnt2--; cnt3--;
		}
		else
		{
			cond=1; break; 
		}

		if (cnt1!=0)
			vtemp.push_back(make_pair(val1,cnt1));

		if (cnt2!=0)
			vtemp.push_back(make_pair(val2,cnt2));

		if (cnt3!=0)
			vtemp.push_back(make_pair(val3,cnt3));

		if (pq1.size()==0 && vtemp.size()==0)
			break;

		if (pq1.size()!=0)
		{
			pt4 = pq1.top(); val4 = pt4.first; cnt4 = pt4.second;

			while(val3==(val4+1) && (cnt3 == 0 || cnt4>1))
			{
				pq1.pop();
				// cout<<" val4 = "<<val4<<" , cnt4 = "<<cnt4<<endl;
				cnt4--;

				if (cnt4!=0)
					vtemp.push_back(make_pair(val4,cnt4));

				if (pq1.size()==0)
					break;

				val3=val4;
				cnt3=cnt4;
				pt4 = pq1.top();
				val4 = pt4.first;
				cnt4 = pt4.second;
			}
	    }

	    for (i=0;i<vtemp.size();i++)
	    	pq1.push(vtemp[i]);

	    vtemp.clear();
	}

	if (cond==0)
		return true;
	else
		return false;
}


int main()
{
	cout<<" 659. Split Array into Consecutive Subsequences "<<endl;

	// example 1
	// vector<int> nums = {1,2,3,3,4,5};

	// example 2
	// vector<int> nums = {1,2,3,3,4,4,5,5};

	// example 3
	vector<int> nums = {1,2,3,4,4,5};

	// example 4
	// vector<int> nums = {4,5,6,7,7,8,8,9,10,11};

	int i;

	cout<<" printing the nums vector :- "<<endl;
	for (i=0;i<nums.size();i++)
	  cout<<nums[i]<<" ";
	cout<<endl;

	bool answer = isPossible(nums);

	if (answer)
		cout<<" it can be Splitted. "<<endl;
	else
		cout<<" it cannot be Splitted. "<<endl;
}