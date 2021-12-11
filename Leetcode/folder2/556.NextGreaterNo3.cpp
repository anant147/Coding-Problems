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

int nextGreaterElement(int n)
{
	int i,j,k,u,v,x,y,z;

	vector<int> dval;

	k = n;

	while (k!=0)
	{
		u = k%10;
		dval.push_back(u);
		k = k/10;
	}

	if (dval.size()==1)
		return -1;

	int m = dval.size();

	vector<int> nval;

	for (i=m-1;i>=0;i--)
	{
		k = dval[i];
		nval.push_back(k);
	}

	// cout<<" printing the nval vector :-"<<endl;
	// for (i=0;i<m;i++)
	// 	cout<<nval[i]<<" ";
	// cout<<endl;

	int temp;
	int cond = 0;

	for (i=m-1;i>=1;i--)
	{
		for (j=i;j>=1;j--)
		{
			if (nval[j-1] < nval[j])
			{
				k = j;
				x = nval[j-1];
				// y = nval[k];

				while(k<m && x<nval[k])
					k++;

				k--;

				cond = 1;
				temp = nval[j-1];
				nval[j-1] = nval[k];
				nval[k] = temp;

				for (u=j;u<m;u++)
				{
					for (v=u+1;v<m;v++)
					{
						if (nval[u]>nval[v])
						{
							temp = nval[u];
							nval[u]= nval[v];
							nval[v] = temp;
						}
					}
				}

				break;
			}
		}

		if (cond==1)
			break;
	}

	// cout<<" cond = "<<cond<<endl;

	if (cond==0)
		return -1;
	else
	{
		int sum = 0;

		for (i=0;i<nval.size();i++)
			sum = sum*10 + nval[i];

		return sum;
	}
}

int main()
{
	cout<<" 556. Next Greater Element III "<<endl;

	// example1
	// int n = 12;

	// example 2
	// int n = 21;

	// example 3
	// int n = 230241;

	// example 4
	int n = 12443322;

	cout<<" n = "<<n<<endl;

	int answer = nextGreaterElement(n);

	cout<<" answer = "<<answer<<endl;
}