#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
#include<cstring>
using namespace std;

vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries)
{
	int i,j,k,u,v,x,y,z;

	if (queries.size()==0)
		return {};

	int n = arr.size();

	vector<vector<int>> bitstor;
	vector<int> temp;

	for (i=0;i<arr.size();i++)
	{
		k = arr[i];
		temp.resize(31,0);
		j = 0;

		while (j<31 && k!=0)
		{
			temp[j] = k%2;
			k = k/2;
			j++;
		}

		bitstor.push_back(temp);
		temp.clear();
	}

	vector<vector<int>> bitsum;

	for (i=0;i<n;i++)
	{
		temp.resize(31,0);

		if (i==0)
		{
			for (j=0;j<temp.size();j++)
				temp[j] = bitstor[i][j];
		}
		else
		{
			for (j=0;j<temp.size();j++)
				temp[j] = bitsum[i-1][j] + bitstor[i][j];
		}

		bitsum.push_back(temp);
		temp.clear();
	}

	// cout<<" printing the bitsum vector :- "<<endl;

	// for (i=0;i<bitsum.size();i++)
	// {
	// 	for (j=0;j<bitsum[i].size();j++)
	// 		cout<<bitsum[i][j]<<" ";
	// 	cout<<endl;
	// }
	// cout<<endl;

	vector<int> answer;

	int sum;

	for (i=0;i<queries.size();i++)
	{
		u = queries[i][0]; v = queries[i][1];
		temp.resize(31,0);

		if (u==0)
		{
			for (j=0;j<temp.size();j++)
				temp[j] = bitsum[v][j];
		}
		else
		{
			for (j=0;j<temp.size();j++)
				temp[j] = bitsum[v][j] - bitsum[u-1][j];
		}

		sum = 0;

		for (j=0;j<temp.size();j++)
		{
			x = temp[j]%2;

			if (x==1)
				sum = sum + pow(2,j);
		}

		answer.push_back(sum);

		temp.clear();
	}


	return answer;

}

int main()
{
	cout<<" 1310. XOR Queries of a Subarray "<<endl;

	// example 1
	// vector<int> arr = {1,3,4,8};

	// vector<vector<int>> queries = {
	// 	                          {0,1},
	// 	                          {1,2},
	// 	                          {0,3},
	// 	                          {3,3}
	// 	                          };

    // example 2
    vector<int> arr = {4,8,2,10};
    vector<vector<int>> queries = {
    	                          {2,3},
    	                          {1,3},
    	                          {0,0},
    	                          {0,3}
    	                          };

	cout<<" printing the arr vector :- "<<endl;
	for (int i=0;i<arr.size();i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	cout<<endl;

	cout<<" printing the queries vector :- "<<endl;
	for (int i=0;i<queries.size();i++)
		cout<<queries[i][0]<<" , "<<queries[i][1]<<endl;
	cout<<endl;
	cout<<endl;

	vector<int> answer = xorQueries(arr, queries);

	cout<<" printing the answer vector :- "<<endl;
	for (int i=0;i<answer.size();i++)
		cout<<answer[i]<<" ";
	cout<<endl;
	cout<<endl;


}