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

int integerBreak(int n)
{
	int i,k,u,v,x;

	if (n==0)
		return 0;
	else if (n==1 || n==2)
		return 1;

	if (n%2==0)
		k = n/2;
	else
		k = n/2+1;

	int answer = 1;
	x = 1;


	i=2;
	while (i<=k)
	{
		u = n/i;
		v = n%i;

		if (v==0)
		{
			x = pow(u,i);
		}
		else
		{
			x = pow(u+1,v) * pow(u,i-v);
		}

		if (answer < x)
			answer = x;

		i++;
	}

	return answer;
}

int main()
{
	cout<<" 343. Integer Break "<<endl;

	// example 1
	// int n = 2;

	// example 2
	// int n = 10;

	// example 3
	// int n = 3;

	// example 4
	int n = 58;

	cout<<" n = "<<n<<endl;

	int answer = integerBreak(n);

	cout<<" answer = "<<answer<<endl;
}