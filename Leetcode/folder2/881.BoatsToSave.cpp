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

int numRescueBoats(vector<int>& people, int limit)
{
	int i,j,x,y;

	int n = people.size();

	sort(people.begin(),people.end());

	// cout<<" printing the people vector :- "<<endl;
	// for (i=0;i<people.size();i++)
	// 	cout<<people[i]<<" ";
	// cout<<endl;
	// cout<<endl;

	int count = 0;

	i=0;
	j=n-1;

	while (i<=j)
	{
		// cout<<" i = "<<i<<" , j = "<<j<<endl;

		if (i==j)
		{
			if (people[i]<=limit)
				count++;

			i++;
			j--;
		}
		else
		{
			x = people[i]+people[j];
			// cout<<" 2. x = "<<x<<endl;

			if (x == limit)
			{
				count++;
				i++;
				j--;
			}
			else if (x>limit)
			{
				count++;
				j--;
			}
			else if (x < limit)
			{
				count++;
				i++;
				j--;
			}
		}
	}

	return count;
}

int main()
{
	cout<<" 881. Boats to Save People "<<endl;

	// example 1
	// vector<int> people = {1,2};
	// int limit = 3;

	// example 2
	// vector<int> people = {3,2,2,1};
	// int limit = 3;

	// example 3
	// vector<int> people = {3,5,3,4};
	// int limit = 5;

	// example 
	// vector<int> people = {1,2,4,5};
	// int limit = 6;

	// example 
	vector<int> people = {2,49,10,7,11,41,47,2,22,6,13,12,33,18,10,26,2,6,50,10};
	int limit = 50;

	cout<<" printing the people vector :- "<<endl;
	for (int i=0;i<people.size();i++)
		cout<<people[i]<<" ";
	cout<<endl;
	cout<<endl;

	cout<<" limit = "<<limit<<endl;

	int answer = numRescueBoats(people,limit);

	cout<<" answer = "<<answer<<endl;




}