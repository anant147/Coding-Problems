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

int numSteps(string s)
{
	int i,j,k,u,v;

	int n = s.size();

	if (n==1)
	{
		if (s=="0")
			return 1;
		else
			return 0;
	}

	string st = s;

	int count = 0;

	while (true)
	{
		n = st.size();
		// cout<<" st = "<<st<<endl;
		// cout<<"n = "<<n<<endl;
		// cout<<" hello1"<<endl;

		if (st[n-1]=='0')
		{
			// cout<<"even "<<endl;
			st.pop_back();
		}
		else
		{
			st[n-1]='0';
			// cout<<"odd"<<endl;

			i = n-2;
			u=1;

			while (i>=0)
			{
				// cout<<"hello3"<<endl;
				if (u==1)
				{
					if (st[i]=='1')
						st[i]='0';
					else
					{
						st[i]='1';
						u=0;
					}
				}

				if (u==0)
					break;

				i--;
			}

			if (u==1 && i==-1)
				st = '1'+st;
		}

		count++;

		if (st=="1")
			break;
	}

	return count;
}

int main()
{
	cout<<" 1404. Number of Steps to Reduce a Number in Binary Representation to One "<<endl;

	// example1 
	// string s = "1101";

	// example 2
	// string s = "10";

	// example3
	string s = "1";

	int answer = numSteps(s);

	cout<<" answer = "<<answer<<endl;
}