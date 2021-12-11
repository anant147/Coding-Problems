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

int countNumbersWithUniqueDigits(int n)
{
	int i,k;

	vector<int> ctr;
	ctr.resize(9,1);

	ctr[1] = 9;

	k = 9;
	i = 2;
	while (i<9)
	{
		ctr[i] = ctr[i-1] * k;
		k--;
		i++;
	}

	int sum = 0;

	for (i=0;i<=n;i++)
		sum = sum + ctr[i];

	return sum;
}

int main()
{
	cout<<" 357. Count Numbers with Unique Digits "<<endl;

	// example 1
	// int n = 2;

	// example 2
	int n = 3;

	cout<<" n = "<<n<<endl;

	int answer = countNumbersWithUniqueDigits(n);

	cout<<" answer = "<<answer<<endl;
}