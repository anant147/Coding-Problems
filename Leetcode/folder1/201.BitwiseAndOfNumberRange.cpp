#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
#include<cstring>
using namespace std;

int rangeBitwiseAnd(int m, int n)
{
	int i,j,k,u,v,x,y,z;

	if (m==n)
		return m;

	vector<int> powstor;

	for (i=0;i<31;i++)
		powstor.push_back(pow(2,i));

	vector<int> valstor;
	valstor.push_back(m);
	valstor.push_back(n);

	int maxval = pow(2,sizeof(int)*8-1)-1;
	long long int temp; 

	u = m;
	v = n;

	i=0;
	while (i<31)
	{
		temp = u + powstor[i];

		if (temp <= v)
		{
			x = (int)temp;
			valstor.push_back(x);
		}
		else
			break;

		i++;
	}

	i=0;
	while (i<31)
	{
		temp = v - powstor[i];

		if (temp >= u)
		{
			x = (int)temp;
			valstor.push_back(x);
		}
		else
			break;

		i++;
	}

	int val = m;

	for (i=0;i<valstor.size();i++)
		val = val & valstor[i];

	return val;
}

int main()
{
	cout<<" 201. Bitwise AND of Numbers Range "<<endl;

	// example 1
	// int m = 5;
	// int n = 7;

	// example 2
	int m = 0;
	int n = 1;

	cout<<" m = "<<m<<endl;
	cout<<" n = "<<n<<endl;

	int answer = rangeBitwiseAnd(m,n);

	cout<<" answer = "<<answer<<endl;

}