#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<map>
#include<unordered_map>
#include<queue>
#include<stack>
#include<cmath>
#include<cstring>
using namespace std;

struct compare
{
	bool operator()(const string& s1, const string& s2)
	{
		return (s1.length() < s2.length());
	}
};

int find_length(string arr[], int n)
{
	vector<int> temp;
	temp.resize(n+1,1);

	sort(arr,arr+n, compare());

	map<string,int> m;

	int i;

	for (i=0;i<n;i++)
	{
		int p = arr[i].length();
		string q = arr[i];
		cout<<" new q = "<<q<<endl;
		m[q] = i+1;

		for (int j=0;j<p;j++)
		{
			char c = q[j];
			q.erase(q.begin()+j);
			cout<<" after erase , q = "<<q<<endl;

			if (m[q] != 0 && (temp[m[q]]+1) > temp[i+1])
				temp[i+1] = 1+temp[m[q]];

			q.insert(j,1,c);
			cout<<" after insert, q = "<<q<<endl;
		}
		cout<<endl;
	}

	int max = 1;

	for (i=1;i<=n;i++)
	{
		if (max < temp[i])
			max = temp[i];
	}

	return max;
}

int main()
{
	cout<<" Sap lab question 2018-18"<<endl;
	cout<<" String chain "<<endl;

	string arr[]={"i","as", "sa", "hi", "sash","ssahi","sashi", "ashi","shi"};

	cout<<" printing the string array :-"<<endl;
	for (int i = 0;i<9;i++)
		cout<<arr[i]<<" ";
	cout<<endl;

	cout<<"answer = "<<find_length(arr, 9)<<endl;

}