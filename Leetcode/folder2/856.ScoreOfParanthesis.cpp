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

int scoreOfParentheses(string s)
{
	int i,j,k,u,v,x,y,z;

	int n = s.size();

	if (n==2)
	{
		if (s=="()")
			return 1;
		else
			return 0;
	}

	vector<vector<int>> vstor,vtemp1,vtemp2;
	vector<int> temp,temp1,temp2;

	for (i=0;i<n-1;)
	{
		if (s[i]=='(' && s[i+1]==')')
		{
			temp.push_back(i);  temp.push_back(i+1); temp.push_back(1);
			vstor.push_back(temp);
			temp.clear();
			i=i+2;
		}
		else
			i++;
	}

	int sum = 0;

	int answer;

	while(true)
	{

		for (i=0;i<vstor.size();i++)
		{
			x = vstor[i][0]; y = vstor[i][1], u = vstor[i][2];
			// cout<<"case 1 - x = "<<x<<" , y = "<<y<<" , u = "<<u<<endl;
			x--;
			y++;
			while (x>=0 && y<n && s[x]=='(' && s[y]==')')
			{
				u = u*2;
				x--;
				y++;
			}

			x++;
			y--;

			temp.push_back(x); temp.push_back(y); temp.push_back(u);
			// cout<<"case 2 - x = "<<x<<" , y = "<<y<<" , u = "<<u<<endl;
			vtemp1.push_back(temp);
			temp.clear();
		}

		vstor.clear();

		if (vtemp1.size()==1 && vtemp1[0][0]==0 && vtemp1[0][1]==n-1)
		{
			answer = vtemp1[0][2];
			break;
		}

		for (i=0;i<vtemp1.size(); )
		{
			k = i;
			j = k+1;

			sum = vtemp1[k][2];

			while (j<vtemp1.size())
			{
				if (vtemp1[k][1]+1 == vtemp1[j][0])
				{
					sum = sum + vtemp1[j][2];
					k++;
					j++;
				}
				else
					break;
			}

			x = vtemp1[i][0];      y = vtemp1[k][1];    u = sum;
			// cout<<"case 3 - x = "<<x<<" , y = "<<y<<" , u = "<<u<<endl;
			temp.push_back(x);     temp.push_back(y);   temp.push_back(u);
			vtemp2.push_back(temp);
			temp.clear();

			i = j;
		}

		vtemp1.clear();
		vstor = vtemp2;
		vtemp2.clear();

		if (vstor.size()==1 && vstor[0][0]==0 && vstor[0][1]==n-1)
		{
			answer = vstor[0][2];
			break;
		}
	}
	
	return answer;
}

int main()
{
	cout<<" 856. Score of Parentheses "<<endl;

	// example 1
	// string s = "()";

	// example 2
	// string s = "(())";

	// example 3
	// string s = "()()";

	// example 4
	string s = "(()(()))";

	cout<<" s = "<<s<<endl;

	int answer = scoreOfParentheses(s);

	cout<<" answer = "<<answer<<endl;
}