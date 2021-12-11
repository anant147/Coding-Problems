#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
using namespace std;

string frequencySort(string s)
{
	int i,j,k,u,v,x,y,z;

	int n = s.size();

	int arr[128];

	for (i=0;i<128;i++)
		arr[i]=0;

	for (i=0;i<n;i++)
	{
		k = (int)s[i];
		arr[k]++;
	}

	priority_queue<pair<int,int>> pqe;
	vector<pair<int,int>> vtemp;
	pair<int,int> pt1,pt2,pt3;

	for (i=0;i<128;i++)
	{
		if (arr[i]!=0)
			pqe.push(make_pair(arr[i],i));
	}

	string answer = "";
	char temp;

	while(!pqe.empty())
	{
		pt1 = pqe.top();
		pqe.pop();
		u = pt1.first;  v = pt1.second;
		cout<<" v = "<<v<<" , u = "<<u<<endl;
		temp = (char)v;

		for (j=0;j<u;j++)
			answer = answer + temp;
	}
	cout<<endl;

	return answer;
}

int main()
{
	cout<<" 451. Sort Characters By Frequency "<<endl;

	// example 1
	// string s = "tree";

	// example 2
	// string s = "cccaaa";

	// example 3
	string s = "Aabb";

	cout<<" s = "<<s<<endl;

	string answer = frequencySort(s);

	cout<<" answer = "<<answer<<endl;
}