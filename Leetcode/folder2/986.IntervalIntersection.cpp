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

vector<vector<int>> intervalIntersection(vector<vector<int>>& nums1, vector<vector<int>>& nums2)
{
	int i,j,k,u,v,x,y,z;

	int n = nums1.size();
	int m = nums2.size();

	vector<vector<int>> answer;
	vector<int> temp;

	i=0;
	j=0;

	while (i<n && j<m)
	{
		u = nums1[i][0]; v = nums1[i][1];
		x = nums2[j][0]; y = nums2[j][1];

		if (v < x)
			i++;
		else if (y < u)
			j++;
		else if (u<=x && y<=v)
		{
			temp.push_back(x);  temp.push_back(y);
			answer.push_back(temp);
			temp.clear();
			j++;
		}
		else if (x<=u && v<=y)
		{
			temp.push_back(u); temp.push_back(v);
			answer.push_back(temp);
			temp.clear();
			i++;
		}
		else if (u<x && x<=v && v<=y)
		{
			temp.push_back(x); temp.push_back(v);
			answer.push_back(temp);
			temp.clear();
			i++;
		}
		else if (x<u && u<=y && y<=v)
		{
			temp.push_back(u); temp.push_back(y);
			answer.push_back(temp);
			temp.clear();
			j++;
		}

	}

	return answer;
}

int main()
{
	cout<<" 986. Interval List Intersections "<<endl;

	vector<vector<int>> nums1 = {{0,2},{5,10},{13,23},{24,25}};
	vector<vector<int>> nums2 = {{1,5},{8,12},{15,24},{25,26}};

	cout<<" printing the nums1 vector :- "<<endl;
	for (int i=0;i<nums1.size();i++)
		cout<<nums1[i][0]<<" , "<<nums1[i][1]<<endl;
	cout<<endl;

	cout<<" printing the nums2 vector :- "<<endl;
	for (int i=0;i<nums2.size();i++)
		cout<<nums2[i][0]<<" , "<<nums2[i][1]<<endl;
	cout<<endl;

	vector<vector<int>> answer = intervalIntersection(nums1, nums2);

	cout<<" printing the answer vector :- "<<endl;
	for (int i=0;i<answer.size();i++)
		cout<<answer[i][0]<<" , "<<answer[i][1]<<endl;
	cout<<endl;
}