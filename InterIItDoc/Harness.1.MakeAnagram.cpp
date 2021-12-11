#include <bits/stdc++.h> 
using namespace std;

int countManipulations(string s1, string s2)
{
	int n = s1.size();
	int m = s2.size();

	if (n != m)
		return -1;

	int i,k;
	vector<int> counter;
	counter.resize(26, 0);

	for (i=0;i<n;i++)
	{
		k = (int)(s1[i])-97;
		// cout<<"k = "<<k<<endl;
		counter[k]++;
	}

	for (i=0;i<m;i++)
	{
		k = (int)(s2[i])-97;
		// cout<<"k = "<<k<<endl;
		counter[k]--;
	}

	int sum = 0;

	for (i=0;i<26;i++)
	{
		if (counter[i] != 0)
			sum += abs(counter[i]);
	}

	return sum/2;
}

int main()
{
	cout<<" Harness question 1 :- "<<endl;
	cout<<" Minimum Number of Manipulations required to make two Strings Anagram Without Deletion of Character "<<endl;

	string s1 = "ddcf";
	string s2 = "cedk";

	cout<<" s1 = "<<s1<<endl;
	cout<<" s2 = "<<s2<<endl;

	int answer = countManipulations(s1, s2);

	cout<<" answer = "<<answer<<endl;
}