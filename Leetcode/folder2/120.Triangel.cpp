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

int minval(int a, int b)
{
	if (a<b)
		return a;
	else
		return b;
}

int minimumTotal(vector<vector<int>>& triangle)
{
	int i,j,u;

	int n = triangle.size();

	if (n==0)
		return 0;

	vector<int> prev, cur;

	for (i=0;i<triangle[0].size();i++)
		prev.push_back(triangle[0][i]);

	for (i=1;i<n;i++)
	{
		int tlen = triangle[i].size();

		for (j=0;j<tlen;j++)
		{
			if (j==0)
			{
				u = triangle[i][j] + prev[0];
				cur.push_back(u);
			}
			else if (j==(tlen-1))
			{
				u = triangle[i][j] + prev[tlen-2];
				cur.push_back(u);
			}
			else
			{
				u = triangle[i][j] + minval(prev[j-1], prev[j]);
				cur.push_back(u);
			}
		}

		prev.clear();
		prev = cur;
		cur.clear();
	}

	int answer = prev[0];

	for (i=1;i<prev.size();i++)
	{
		if (answer > prev[i])
			answer = prev[i];
	}


	return answer;
}

int main()
{
	cout<<" 120. Triangle "<<endl;

	// example 1
	// vector<vector<int>> triangle = {
	// 	                           {2},
 //                                   {3,4},
 //                                   {6,5,7},
 //                                   {4,1,8,3}
 //                                   };

    // example 2
    vector<vector<int>> triangle = {
    	                           {-1},
    	                           {2,3},
    	                           {1,-1,-3}
    	                           };

    cout<<" printing the triangle vector :- "<<endl;
    for (int i=0;i<triangle.size();i++)
    {
    	for (int j=0;j<triangle[i].size();j++)
    		cout<<triangle[i][j]<<" ";
    	cout<<endl;
    }
    cout<<endl;

    int answer = minimumTotal(triangle);

    cout<<" answer = "<<answer<<endl;
}