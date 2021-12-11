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

int maxval(int a, int b)
{
	if (a>b)
		return a;
	else
		return b;
}

int minval(int a, int b)
{
	if (a>b)
		return b;
	else
		return a;
}

int longestAwesome(string s)
{
	vector<int> dp(1024,s.size());

	int i,j,k,u,v,x,y,z;

	int ans = 0;
	int mask = 0;

	dp[0] = -1;

	for (i=0;i<s.size();i++)
	{
		mask = mask^(1<<(s[i]-'0'));
		ans = maxval(ans, i-dp[mask]);

		for (j=0;j<10;j++)
			ans = maxval(ans, i-dp[mask^(1<<j)]);

		dp[mask] = minval(dp[mask],i);
	}

	return ans;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////  n square solution             ///////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int getMaxLen(vector<int>& temp)
{
	int i,j,k,u,v,x,y,z;

	priority_queue<int> pq;

	int sum = 0;
	int cond = 0;

	for (i=0;i<temp.size();i++)
	{
		u = temp[i];

		if (u!=0)
		{
			if (u%2==0)
				sum = sum + u;
			else
				pq.push(u);
		}
	}

	while(!pq.empty())
	{
		u = pq.top();
		pq.pop();

		if (cond==0)
		{
			cond=1;
			sum = sum + u;
		}
		else
			sum = sum + (u-1);
	}

	return sum;
}

int longestAwesome1(string s)
{
	int i,j,k,u,v,x,y,z;

	int n = s.size();

	vector<vector<int>> digstor;
	digstor.resize(n, vector<int> (10,0));

	char ctemp;

	for (i=0;i<n;i++)
	{
		ctemp = s[i];
		u = (int)(ctemp)-48;

		if (i==0)
			digstor[i][u]++;
		else
		{
			for (j=0;j<10;j++)
			{
				if (j==u)
					digstor[i][j] = digstor[i-1][j]+1;
				else
					digstor[i][j] = digstor[i-1][j];
			}
		}
		
	}

	int sum = 0;
	priority_queue<int> pq;
	int cond1,cond2;

	vector<int> temp;
	temp.resize(10,0);

	int len;

	cond1 = 0;
	int maxlen = 0;

	for (len=n;len>=1;)
	{
		if (len==n)
		{
			for (i=0;i<10;i++)
				temp[i] = digstor[n-1][i];

			sum = getMaxLen(temp);

			maxlen = sum;

			if (maxlen==len)
				cond1=1;
			else
				len = maxlen;
		}
		else
		{
			maxlen = 0;

			for (i=0;i<n-len+1;i++)
			{
				j = i+len-1;

				if (i==0)
				{
					for (k=0;k<10;k++)
						temp[k] = digstor[j][k];
				}
				else
				{
					for (k=0;k<10;k++)
						temp[k] = digstor[j][k] - digstor[i-1][k];
				}

				sum = getMaxLen(temp);

				if (maxlen<sum)
					maxlen = sum;

				if (maxlen==len)
					break;
			}

			if (maxlen==len)
			{
				cond1=1;
			}
			else
				len = maxlen;
		}

		if (cond1==1)
			break;
	}

	return maxlen;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	cout<<" 1542. Find Longest Awesome Substring "<<endl;

	// example 1
	// string s = "3242415";

	// example 2
	// string s = "12345678";

	// example 3
	// string s = "213123";

	// example 4
	string s = "00";

	// example 5
	// string s = "9498331";

	cout<<" s = "<<s<<endl;

	int answer = longestAwesome(s);

	cout<<" answer = "<<answer<<endl;


}