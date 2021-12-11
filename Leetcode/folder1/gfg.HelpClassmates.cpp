#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<stack>
using namespace std;

vector<int> help_classmate(vector<int>& array,int n)
{
	int i,j,k,u,v,x,y,z;

	if (n==1)
		return {-1};

	stack<int> st;
	vector<int> temp;
	temp.resize(n,-1);

	// cout<<" print temp vector :- "<<endl;
	// for (i=0;i<n;i++)
	// 	cout<<temp[i]<<" ";
	// cout<<endl;

	for (i=0;i<n;i++)
	{
		if (i==0)
		{
			if (array[i] > array[i+1])
				temp[i] = array[i+1];
			else
				st.push(i);
		}
		else if (i==(n-1))
		{
			if (!st.empty())
			{
				while(!st.empty())
				{
					u = st.top();

					if (array[u] > array[i])
					{
						temp[u]=array[i];
						st.pop();
					}
					else
						break;
				}
			}
		}
		else
		{
			if (!st.empty())
			{
				while(!st.empty())
				{
					u = st.top();

					if (array[u] > array[i])
					{
						temp[u]=array[i];
						st.pop();
					}
					else
						break;
				}
			}

			if (array[i] > array[i+1])
				temp[i]=array[i+1];
			else
				st.push(i);
		}
	}

	return temp;
}

int main()
{
	cout<<" Help Classmates "<<endl;

	int n = 5;
	vector<int> array = {3,8,5,2,25};
	// int n = 4;
	// vector<int> array = {1,2,3,4};

	cout<<" print array vector :- "<<endl;
	for (int i=0;i<n;i++)
		cout<<array[i]<<" ";
	cout<<endl;

	vector<int> answer = help_classmate(array,n);

	cout<<" printing answer vector :- "<<endl;
	for (int i=0;i<answer.size();i++)
		cout<<answer[i]<<" ";
	cout<<endl;
}