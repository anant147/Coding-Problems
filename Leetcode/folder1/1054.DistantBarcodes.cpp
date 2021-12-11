#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<queue>
#include<cmath>
#include<stack>
using namespace std;

// bool prcomp(const pair<int,int>& a, const pair<int,int>& b)
// {
// 	return (a.second > b.second);
// }

vector<int> rearrangeBarcodes(vector<int>& barcodes)
{
	int i,j,k,u,v,x,y,z;

	if (barcodes.size()==1)
		return barcodes;

	int arr[10005];

	for (i=0;i<10005;i++)
		arr[i]=0;

	for (i=0;i<barcodes.size();i++)
		arr[barcodes[i]]++;

	priority_queue<pair<int,int>> pq;
	pair<int,int> temp,temp1,temp2;

	for (i=0;i<10005;i++)
	{
		if (arr[i]!=0)
		{
			pq.push(make_pair(arr[i],i));
		}
	}

	vector<int> answer;
	vector<pair<int,int>> vtemp;

	int n = barcodes.size();
	int count = 0;
	int sz;

	while (!pq.empty() && count!=n)
	{
		sz = answer.size();

		if (sz==0)
		{
			temp = pq.top();
			pq.pop();

			u = temp.first; v = temp.second;
			answer.push_back(v);
			count++;

			if (u>1)
				pq.push(make_pair(u-1,v));
		}
		else
		{
			temp = pq.top();
			u = temp.first; v = temp.second;

			while(!pq.empty() && answer[sz-1]==v)
			{
				pq.pop();
				vtemp.push_back(temp);
				temp = pq.top();
				u = temp.first; v = temp.second;
			}

			answer.push_back(v);
			pq.pop();
			count++;

			if (u>1)
				vtemp.push_back(make_pair(u-1,v));

			for (i=0;i<vtemp.size();i++)
				pq.push(vtemp[i]);

			vtemp.clear();
		}
	}

	return answer;

}

int main()
{
	cout<<" 1054. Distant Barcodes "<<endl;

	// example 1
	// vector<int> barcodes = {1,1,1,2,2,2};

	// example 2
	vector<int> barcodes = {1,1,1,1,2,2,3,3};

	cout<<" printing the barcodes vector :-"<<endl;
	for (int i=0;i<barcodes.size();i++)
	   cout<<barcodes[i]<<" ";
	cout<<endl;

	vector<int> answer = rearrangeBarcodes(barcodes);
	cout<<" printing the answer vector :- "<<endl;
	for (int i=0;i<answer.size();i++)
	   cout<<answer[i]<<" ";
	cout<<endl;


}