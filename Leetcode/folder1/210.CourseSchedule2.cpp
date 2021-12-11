#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<queue>
#include<stack>
using namespace std;

bool topoSort(vector<int> courel[],vector<int>& visited, vector<int>& tempvisit, stack<int>& st,int point,int n)
{
	int i,j,k,u,v,x,y,z;
	// cout<<" point = "<<point<<endl;

	visited[point]=1;
	tempvisit[point]=1;

	bool cond = true;
	bool temp;

	for (i=0;i<courel[point].size();i++)
	{
		// cout<<" hello1 "<<endl;
		k = courel[point][i];
		if (visited[k]==0)
		{
			// cout<<"for point ="<<point<<" , cond 0 with k = "<<k<<endl;
			temp = topoSort(courel, visited, tempvisit, st, k, n);

			if (temp==false)
				cond=false;
		}
		else
		{
			if (tempvisit[k]==1)
			{
				// cout<<"for point ="<<point<<" , cond 1 with k = "<<k<<endl;
				temp=false;
				cond=false;
			}
		}

		if (cond==false)
			return false;
	}

	tempvisit[point]=0;

	st.push(point);
	return true;
}

vector<int> findOrder(int numCourses,vector<vector<int>>& prerequisites)
{
	int i,j,k,u,v,x,y,z;

	if (prerequisites.size()==0)
	{
		vector<int> tempvec;

		for (i=0;i<numCourses;i++)
			tempvec.push_back(i);

		return tempvec;
	}

	vector<int> courel[numCourses];

	for (i=0;i<prerequisites.size();i++)
	{
		u = prerequisites[i][0];
		v = prerequisites[i][1];

		courel[v].push_back(u);
	}

	stack<int> st;
	vector<int> visited,tempvisit;
	visited.resize(numCourses,0);
	tempvisit.resize(numCourses,0);

	bool cond;

	for (i=0;i<numCourses;i++)
	{
		if (visited[i]==0)
		{
		cond = topoSort(courel,visited,tempvisit,st,i,numCourses);

		if (cond==false)
		{
			// cout<<" in loop "<<endl;
			return {};
		}

		}
	}

	vector<int> answer;

	if (st.size() != numCourses)
	{
		// cout<<" in if cond"<<endl;
		return {};
	}
	else
	{
		while(!st.empty())
		{
			k = st.top();
			st.pop();
			answer.push_back(k);
		}

		return answer;
	}
}

int main()
{
	cout<<" 210. Course Schedule II "<<endl;

	// example 1
	// int numCourses = 2;
	// vector<vector<int>> prerequisites = {{1,0}};

	// example 2
	// int numCourses = 4;
	// vector<vector<int>> prerequisites = {{1,0},{2,0},{3,1},{2,1}};

	// example 3
	// int numCourses = 1;
	// vector<vector<int>> prerequisites = {};

	// example 4
	int numCourses = 2;
	vector<vector<int>> prerequisites = {{0,1},{1,0}};

	cout<<" numCourses = "<<numCourses<<endl;
	cout<<" relation of different courses : "<<endl;
	int i,j,k;

	for (i=0;i<prerequisites.size();i++)
	{
		cout<<prerequisites[i][0]<<" "<<prerequisites[i][1]<<endl;
	}
	cout<<endl;

	vector<int> answer = findOrder(numCourses,prerequisites);

	if (answer.size()==0)
		cout<<" all the courses cannot be returned "<<endl;
	else
	{
		cout<<" printing answer vector : -"<<endl;
		for (i=0;i<answer.size();i++)
			cout<<answer[i]<<" ";
		cout<<endl;
    }
}