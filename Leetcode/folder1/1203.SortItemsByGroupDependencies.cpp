#include<iostream>
#include<vector>
#include<utility>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

bool sortVect(const vector<int>& v1,const vector<int>& v2)
{
	return (v1[1]>v2[1]);
}

bool topoSort(vector<int> rel[], vector<int>& gdup, vector<int>& visited, vector<int>& tempvisit, stack<int>& st, int point, int n)
{
	int i,j,k,u,v,x,y,z;

	visited[point] = 1;
	tempvisit[point] = 1;

	int gval1 = gdup[point];
	int gval2;

	bool cond=true;
	bool temp;

	for (i=0;i<rel[point].size();i++)
	{
		k = rel[point][i];
		gval2 = gdup[k];

		if (gval1==gval2)
		{
			if (visited[k]==0)
			{
				temp = topoSort(rel,gdup,visited,tempvisit,st,k,n);

				if (temp == false)
					cond= false;
			}
			else
			{
				if (tempvisit[k]==1)
				{
					temp = false;
					cond = false;
				}
			}
		}

		if (cond==false)
			return false;
	}

	tempvisit[point] = 0;
	st.push(point);
	return true;
}

bool tSortComp(vector<int> gcomp[], vector<int>& visitcomp, vector<int>& tempcomp, stack<int>& stcomp, int point, int u)
{
	int i,j,k,x,y;

	visitcomp[point]=1;
	tempcomp[point]=1;

	bool cond = true;
	bool temp;

	for (i=0;i<gcomp[point].size();i++)
	{
		k = gcomp[point][i];

		if (visitcomp[k]==0)
		{
			temp = tSortComp(gcomp, visitcomp, tempcomp, stcomp, k, u);
			if (temp==false)
				cond = false;
		}
		else
		{
			if (tempcomp[k]==1)
			{
				temp = false;
				cond = false;
			}
		}
		if (cond==false)
			return false;
	}

	tempcomp[point] = 0;
	stcomp.push(point);
	return true;
}

vector<int> sortItems(int n,int m, vector<int>& group, vector<vector<int>>& beforeItems)
{
	int i,j,k,u,v,x,y,z;

	vector<int> gdup;

	for (i=0;i<group.size();i++)
		gdup.push_back(group[i]);

	vector<int> rel[n];

	for (i=0;i<beforeItems.size();i++)
	{
		for (j=0;j<beforeItems[i].size();j++)
		{
			k = beforeItems[i][j];

			rel[k].push_back(i);
		}
	}

	// cout<<" printing the rel vector :-"<<endl;

	// for (i=0;i<n;i++)
	// {
	// 	cout<<" for i = "<<i<<endl;
	// 	for (j=0;j<rel[i].size();j++)
	// 		cout<<rel[i][j]<<" ";
	// 	cout<<endl;
	// }
	// cout<<endl;

	vector<int> grel[2*n];

	u = m-1;

	for (i=0;i<n;i++)
	{
		k = group[i];

		if (k==-1)
		{
			u++;
			grel[u].push_back(i);
			gdup[i] = u;
		}
		else
			grel[k].push_back(i);
	}

	// cout<<" printing the gdup vector :- "<<endl;
	// for (i=0;i<n;i++)
	// 	cout<<gdup[i]<<" ";
	// cout<<endl;

	// cout<<" printing the grel vector :- "<<endl;
	// for (i=0;i<=u;i++)
	// {
	// 	for (j=0;j<grel[i].size();j++)
	// 		cout<<grel[i][j]<<" ";
	// 	cout<<endl;
	// }
	// cout<<endl;

	u=u+1;

	vector<int> gcomp[u];

	for (i=0;i<n;i++)
	{
		x = gdup[i];

		for (j=0;j<rel[i].size();j++)
		{
			k = rel[i][j];
			y = gdup[k];

			if (x != y)
			{
				gcomp[x].push_back(y);
			}
		}
	}

	// cout<<" printing the gcomp vector :- "<<endl;
	// for (i=0;i<u;i++)
	// {
	// 	cout<<" for group = "<<i<<endl;
	// 	for (j=0;j<gcomp[i].size();j++)
	// 		cout<<gcomp[i][j]<<" ";
	// 	cout<<endl;
	// }
	// cout<<endl;

	vector<int> visitcomp;
	vector<int> tempcomp;
	stack<int> stcomp;
	visitcomp.resize(u,0);
	tempcomp.resize(u,0);

	bool cond1 = 0;

	for (i=0;i<u;i++)
	{
		if (visitcomp[i]==0)
		{
			cond1 = tSortComp(gcomp,visitcomp, tempcomp, stcomp, i, u);

			if (cond1==false)
				return {};
		}
	}

	if (stcomp.size()!=u)
		return {};

	vector<int> comporder;

	while(!stcomp.empty())
	{
		k = stcomp.top();
		comporder.push_back(k);
		stcomp.pop();
	}

	// cout<<" printing the order of the comp :- "<<endl;
	// for (i=0;i<u;i++)
	// 	cout<<comporder[i]<<" ";
	// cout<<endl;

	vector<int> visited;
	vector<int> tempvisit;
	stack<int> st;
	visited.resize(n,0);
	tempvisit.resize(n,0);

	bool cond2;

	for (i=u-1;i>=0;i--)
	{
		k = comporder[i];

		for (j=0;j<grel[k].size();j++)
		{
			v = grel[k][j];

			if (visited[v]==0)
			{
				cond2 = topoSort( rel, gdup, visited, tempvisit, st, v, n);

				if (cond2==false)
					return {};
			}
		}
	}

	if (st.size()!=n)
		return {};

	vector<int> answer;

	while(!st.empty())
	{
		v = st.top();
		answer.push_back(v);
		st.pop();
	}

	return answer;
}

int main()
{
	cout<<" 1203. Sort Items by Groups Respecting Dependencies "<<endl;
	int i,j,k,u,v;

	// example 1
	// int n = 8;
	// int m = 2;
	// vector<int> group = {-1,-1,1,0,0,1,0,-1};
	// vector<vector<int>> beforeItems = {
	// 	                              {},
	// 	                              {6},
	// 	                              {5},
	// 	                              {6},
	// 	                              {3,6},
	// 	                              {},
	// 	                              {},
	// 	                              {}
	// 	                              };

	// example 2
	int n = 8;
	int m = 2;
	vector<int> group = {-1,-1,1,0,0,1,0,-1};
	vector<vector<int>> beforeItems = {
		                              {},
		                              {6},
		                              {5},
		                              {6},
		                              {3},
		                              {},
		                              {4},
		                              {}
		                              };

	// example 3
    // int n = 4;
    // int m = 1;
    // vector<int> group = {-1,0,0,-1};
    // vector<vector<int>> beforeItems = {
    // 	                              {},
    // 	                              {0},
    // 	                              {1,3},
    // 	                              {2}
    // 	                               };    

    // example 4
    int n = 5;
    int m = 5;


    cout<<" n = "<<n<<endl;
    cout<<" m = "<<m<<endl;
    cout<<" printing the group val :-"<<endl;
    for (i=0;i<n;i++)
    	cout<<group[i]<<" ";
    cout<<endl;
    cout<<" printing the beforeItems vector :- "<<endl;
    for (i=0;i<n;i++)
    {
    	cout<<" for i :-"<<i<<endl;
    	for (j=0;j<beforeItems[i].size();j++)
    		cout<<beforeItems[i][j]<<" ";
    	cout<<endl;
    }
    cout<<endl;

    vector<int> answer = sortItems(n,m,group,beforeItems);

    if (answer.size()==0)
    	cout<<" size of answer vector is zero"<<endl;
    else
    {
	    cout<<" printing the answer vector :-"<<endl;
	    for (i=0;i<answer.size();i++)
	    	cout<<answer[i]<<" ";
	    cout<<endl;
    }

}