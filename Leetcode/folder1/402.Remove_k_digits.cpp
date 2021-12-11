#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<stack>
#include<cstring>
using namespace std;

string removeKdigits(string num,int k)
{
	int i,j,u,v,x,y,z;

	stack<char> st;
	int count = 0;

	int n = num.size();

	string answer = "";
	char temp;

	for (i=0;i<num.size();i++)
	{
		if (i==0)
			st.push(num[i]);
		else 
		{
			if (count != k)
			{
				if (!st.empty())
				{
					temp = st.top();
					u = int(temp)-48;
					v = int(num[i])-48;

					while(!st.empty() && (u>v))
					{
						st.pop();
						count++;

						if (st.empty() || count==k)
							break;

						temp = st.top();
						u = int(temp)-48;
					}

					st.push(num[i]); 
				}
				else
					st.push(num[i]);
			}
			else
				st.push(num[i]);
		}
	}

	if (count != k)
	{
		while(count != k)
		{
			st.pop();
			count++;
		}
	}

	int cond=0;

	stack<char> st1;

	while(!st.empty())
	{
		temp = st.top();
		st.pop();
		st1.push(temp);
	}

	while(!st1.empty())
	{
		temp = st1.top();
		st1.pop();

		if (cond==0)
		{
			if (temp!='0')
			{
				cond=1;
				answer = answer+temp;
			}

		}
		else
		{
			answer = answer+temp;
		}
	}

	if (answer.size()==0)
		answer = "0";

	return answer;
}

int main()
{
	cout<<" 402. Remove K Digits "<<endl;
	// string num = "1432219";
	// int k = 3;
	// // string num = "10200";
	// // int k = 1;
	string num = "10";
	int k =2;

	int i,j;

	cout<<" num string = "<<num<<endl;
	cout<<" k = "<<k<<endl;
	string answer = removeKdigits(num,k);

	cout<<" answer = "<<answer<<endl;
}