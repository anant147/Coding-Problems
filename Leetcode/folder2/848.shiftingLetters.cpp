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

string shiftingLetters(string s, vector<int> shifts)
{
	int i,j,k,u,v,x,y,z;

	int n = shifts.size();

	vector<long long int> shtor;
	shtor.resize(n,0);

	for (i=n-1;i>=0;i--)
	{
		if (i==n-1)
			shtor[i] = shifts[i];
		else
			shtor[i] = shtor[i+1] + shifts[i];
	}

	string answer = "";

	long long int val;
	char ctemp;

	for (i=0;i<n;i++)
	{
		k = (int)(s[i])-97;
		val = shtor[i] + (long long int)k;
		val = val%26;
		u = (int)val;
		ctemp = (char)(u+97);
		answer.push_back(ctemp);
	}

	return answer;
}

int main()
{
	cout<<" 848. Shifting Letters "<<endl;

	string s = "abc";
	vector<int> shifts = {3,5,9};

	cout<<" s = "<<s<<endl;
	cout<<" printing the shifts vector :- "<<endl;
	for (int i=0;i<shifts.size();i++)
		cout<<shifts[i]<<" ";
	cout<<endl;

	string answer = shiftingLetters(s, shifts);

	cout<<" answer = "<<answer<<endl;
}