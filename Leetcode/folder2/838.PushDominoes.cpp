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

string pushDominoes(string s)
{
	int i,j,k,u,v,x,y,z;

	int n = s.size();

	if (n<=1)
		return s;

	string temp = s;

	vector<pair<int,int>> vboth;
	vector<int> vleft, vright;

	int cond = 0;
	u = -1;
	v = -1;

	for (i=0;i<n;i++)
	{
		if (cond==0)
		{
			if (temp[i]=='L')
				vleft.push_back(i);
			else if (temp[i]=='R')
			{
				cond = 1;
				u = i;
			}
		}
		else
		{
			if (temp[i]=='L')
			{
				vboth.push_back(make_pair(u,i));
				u = -1;
				cond = 0;
			}
			else if (temp[i]=='R')
			{
				vright.push_back(u);
				u = i;
			}
		}
	}

	if (u != -1)
		vright.push_back(u);

	// cout<<" printing the vboth vector :- "<<endl;
	// for (i=0;i<vboth.size();i++)
	// 	cout<<vboth[i].first<<" , "<<vboth[i].second<<endl;
	// cout<<endl;

	// cout<<" printing the vleft vector :- "<<endl;
	// for (i=0;i<vleft.size();i++)
	// 	cout<<vleft[i]<<" ";
	// cout<<endl;

	// cout<<" printing the vright vector :- "<<endl;
	// for (i=0;i<vright.size();i++)
	// 	cout<<vright[i]<<" ";
	// cout<<endl;

	for (i=0;i<vboth.size();i++)
	{
		u = vboth[i].first; 
		v = vboth[i].second;

		if ((v-u)%2==0)
		{
			u++;
			v--;

			while((v-u)>=2)
			{
				temp[u] = 'R';
				temp[v] = 'L';
				u++;
				v--;
			}
		}
		else
		{
			u++;
			v--;

			while ((v-u)>=1)
			{
				temp[u] = 'R';
				temp[v] = 'L';
				u++;
				v--; 
			}
		}
	}

	for (i=0;i<vleft.size();i++)
	{
		x = vleft[i];
		x--;

		while (x>=0)
		{
			if (temp[x]!='R' && temp[x]!='L')
			{
				temp[x]='L';
				x--;
			}
			else
				break;
		}
	}

	for (i=0;i<vright.size();i++)
	{
		x=vright[i];
		x++;

		while (x<n)
		{
			if (temp[x]!='R' && temp[x]!='L')
			{
				temp[x]='R';
				x++;
			}
			else
				break;
		}
	}

	return temp;
}

int main()
{
	cout<<" 838. Push Dominoes "<<endl;

	// example 1
	// string s = ".L.R...LR..L..";

	// example 2
	string s = "RR.L";

	cout<<" s = "<<s<<endl;

	string answer = pushDominoes(s);

	cout<<" answer = "<<answer<<endl;
}
