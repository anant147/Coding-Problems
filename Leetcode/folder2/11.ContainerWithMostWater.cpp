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

int minval(int a, int b)
{
	if (a<b)
		return a;
	else
		return b;
}

int maxval(int a, int b)
{
	if (a<b)
		return b;
	else
		return a;
}

int maxArea(vector<int>& height)
{
	int i,j,k,u,v,x,y,z;

	int n = height.size();

	if (n==2)
		return minval(height[0], height[1]);

	i = 0;
	j = n-1;

	int val = (j-i)*minval(height[i],height[j]);

	while (i < j)
	{
		x = (j-i)*minval(height[i],height[j]);
		// cout<<"j = "<<j<<" , i = "<<i<<" , x = "<<x<<endl;

		if (val < x)
			val = x;

		if (height[i] > height[j])
		{
			j--;
		}
		else if (height[i] < height[j])
		{
			i++;
		}
		else if (height[i]==height[j])
		{
			i++;
		}
	}

	return val;
}

int main()
{
	cout<<" 11. Container With Most Water "<<endl;

	// example 1
	// vector<int> height = {1,8,6,2,5,4,8,3,7};

	// example 2
	// vector<int> height = {1,1};

	// example 3
	vector<int> height = {4,3,2,1,4};

	// example 4
	// vector<int> height = {1,2,1};

	// example 5
	// vector<int> height = {1,3,2,5,25,24,5};

	int i,j;

	cout<<" printing the height vector :- "<<endl;
	for (i=0;i<height.size();i++)
		cout<<height[i]<<" ";
	cout<<endl;
	cout<<endl;

	int answer = maxArea(height);

	cout<<" answer = "<<answer<<endl;
}