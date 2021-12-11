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

int minNumberOfFrogs(string croakOfFrogs)
{
	int i,j,k,u,v,x,y,z;

	int n = croakOfFrogs.size();

	if ((n%5) != 0)
		return -1;

	vector<int> alphstor[5];
	vector<int> ctr;
	ctr.resize(5,0);

	int cond = 0;
	for (i=0;i<n;i++)
	{
		if ( croakOfFrogs[i] == 'c')
		{
			alphstor[0].push_back(i);
			ctr[0]++;
		}
		else if (croakOfFrogs[i] == 'r')
		{
			alphstor[1].push_back(i);
			ctr[1]++;
		}
		else if (croakOfFrogs[i] == 'o')
		{
			alphstor[2].push_back(i);
			ctr[2]++;
		}
		else if (croakOfFrogs[i] == 'a')
		{
			alphstor[3].push_back(i);
			ctr[3]++;
		}
		else if ( croakOfFrogs[i] == 'k')
		{
			alphstor[4].push_back(i);
			ctr[4]++;
		}
		else
		{
			cond=1;
			break;
		}
	}

	if (cond==1)
		return -1;

	u = ctr[0];
	cond = 0;

	for (i=1;i<ctr.size();i++)
	{
		if (u != ctr[i])
		{
			cond = 1;
			break;
		}
	}

	if (cond==1)
		return -1;

	// cout<<" printing the ctr vector :"<<endl;
	// for (i=0;i<ctr.size();i++)
	// 	cout<<ctr[i]<<" ";
	// cout<<endl;

	// cout<<" printing the alphstor vector :"<<endl;
	// for (i=0;i<5;i++)
	// {
	// 	for (j=0;j<alphstor[i].size();j++)
	// 		cout<<alphstor[i][j]<<" ";
	// 	cout<<endl;
	// }
	// cout<<endl;

	int clen = alphstor[0].size();
	cond = 0;

	for (i=0;i<clen;i++)
	{
		if ( !( (alphstor[0][i] < alphstor[1][i]) && (alphstor[1][i] < alphstor[2][i]) && (alphstor[2][i] < alphstor[3][i]) && (alphstor[3][i] < alphstor[4][i]) ) )
		{
			cond = 1;
			break;
		}
	}

	if (cond==1)
		return -1;

	int tlen = 0;

	int nlen = 0;

	for (i=0;i<clen;)
	{
		k = i;
		j= k+1;

		nlen = 1;

		while (j<clen)
		{
			if ( alphstor[0][j] < alphstor[4][k])
			{
				j++;
				nlen++;
			}
			else
				break;
		}

		if (tlen < nlen)
			tlen = nlen;

		if (j==clen)
			break;

		i = j;
	}

	return tlen;
}

int main()
{
	cout<<" 1419. Minimum Number of Frogs Croaking "<<endl;

	// example 1
	string croakOfFrogs = "croakcroak";

	// example 2
	// string croakOfFrogs = "crcoakroak";

	// example 3
	// string croakOfFrogs = "croakcrook";

	// example 4
	// string croakOfFrogs = "croakcroa";

	cout<<" croakOfFrogs = "<<croakOfFrogs<<endl;

	int answer = minNumberOfFrogs(croakOfFrogs);

	cout<<" answer = "<<answer<<endl;

}