#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;

int dfsForCourse(vector<int> varr[],vector<int>& visited,vector<int>& tempvisit,int point,int numCourses)
{
	int i,j,k,u,v,x,y,z;

	visited[point]=1;
	tempvisit[point]=1;

	int cond = 0;
	int val;

	for (i=0;i<varr[point].size();i++)
	{
		y = varr[point][i];

		if (tempvisit[y]==0)
		{
			if (visited[y]==0)
			{
				val = dfsForCourse(varr,visited,tempvisit,y,numCourses);

				if (val==0)
					cond=1;
			}
		}
		else
		{
			return 0;
		}

		if (cond==1)
			return 0;
	}

	tempvisit[point]=0;

	return 1;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
{
	int i,j,k,u,v,x,y,z;

	vector<int> vpreq;
	vector<int> visited;
	vector<int> tempvisit;

	vector<int> varr[numCourses];

	vpreq.resize(numCourses,0);
	visited.resize(numCourses,0);
	tempvisit.resize(numCourses,0);

	int cond = 0;

	for (i=0;i<prerequisites.size();i++)
	{
		u = prerequisites[i][0];
		v = prerequisites[i][1];

		if (vpreq[u]==0)
			vpreq[u]=1;

		varr[u].push_back(v);
	}

	int val;

	// cout<<" printing the varr array of vector "<<endl;
	// for (i=0;i<numCourses;i++)
	// {
	// 	cout<<" for i ="<<i<<endl;
	// 	for (j=0;j<varr[i].size();j++)
	// 		cout<<varr[i][j]<<" ";
	// 	cout<<endl;
	// }
	// cout<<endl;

	for (i=0;i<numCourses;i++)
	{
		if (vpreq[i]==1 && visited[i]==0)
		{
			val = dfsForCourse(varr,visited,tempvisit,i,numCourses);

			if (val==0)
				cond=1;
		}

		if (cond==1)
			break;
	}

	if (cond==1)
		return false;
	else
		return true;
}

int main()
{
	cout<<" 207. Course Schedule "<<endl;
	// int numCourses = 2;
	// vector<vector<int>> prerequisites = {
 //                                         {1,0}
	//                                      };
	// vector<vector<int>> prerequisites = {
 //                                         {1,0},
 //                                         {0,1}
	//                                      };

	// int numCourses = 7;
	// vector<vector<int>> prerequisites = {
 //                                        {1,0},
 //                                        {0,3},
 //                                        {0,2},
 //                                        {3,2},
 //                                         {2,5},
 //                                        {4,5},
 //                                        {5,6},
 //                                        {2,4}
 //                                        };

	int numCourses = 3;
	vector<vector<int>> prerequisites = {
                                        {0,1},
                                        {1,2},
                                        {2,0}
	                                    };


    
    cout<<" number of courses :- "<<numCourses<<endl;
    cout<<" printing prerequisites :- "<<endl;
    for (int i=0;i<prerequisites.size();i++)
    {
    	cout<<prerequisites[i][0]<<" "<<prerequisites[i][1]<<endl;
    }
    cout<<endl;

    bool answer = canFinish(numCourses,prerequisites);

    if (answer)
    	cout<<" All courses can be finished."<<endl;
    else
    	cout<<" All courses cannot be finished."<<endl;

}