#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<queue>
#include<cmath>
#include<stack>
using namespace std;

typedef pair<int,vector<int>> reqpr;

int kthSmallest(vector<vector<int>>& mat, int k)
{
	int i,j,u,v,x,y,z;

	int m = mat.size();
	int n = mat[0].size();

	if (m==1)
		return mat[0][0];

	int sum = 0;

	for (i=0;i<mat.size();i++)
		sum = sum + mat[i][0];

	if (n==1 || k==1)
		return sum;

	vector<int> svec;
	svec.resize(m,0);

	vector<int> temp1,temp2,temp3;
	reqpr ptemp1,ptemp2,ptemp3;

	priority_queue< reqpr, vector<reqpr> , greater<reqpr>> pq;
	pq.push(make_pair(sum, svec));

	int count = 0;
	int val;

	int cond1,cond2,i1,j1;

	vector<vector<int>> vstor;
	vector<int> vsum;
	vstor.push_back(svec);
	vsum.push_back(sum);

	while (!pq.empty() && count!=k)
	{
		ptemp1 = pq.top();
		pq.pop();

		sum = ptemp1.first; temp1 = ptemp1.second;

		val = sum;
		// cout<<" val = "<<val<<endl;
		count++;

		if (count==k)
			break;

		for (i=0;i<m;i++)
			temp2.push_back(temp1[i]);

		for (i=0;i<m;i++)
		{
			if (temp1[i]<(n-1))
			{
				u = temp1[i]; v = u+1;

				z = sum + mat[i][v] - mat[i][u];
				temp2[i]++;

				cond1 = 0;

				for (i1=0;i1<vstor.size();i1++)
				{
					cond2 = 0;

					if (vsum[i1]==z)
					{
						for (j1=0;j1<vstor[i1].size();j1++)
						{
							if (vstor[i1][j1] != temp2[j1])
							{
								cond2 = 1; break;
							}
						}

						if (cond2==0)
						{
							cond1 = 1;
							break;
						}
				    }
				}

				if (cond1==0)
				{
					vstor.push_back(temp2);
					vsum.push_back(z);
					pq.push(make_pair(z, temp2));
				}

				temp2[i]--;
			}
		}
		temp2.clear();
	    
	}

	return val;
}

int main()
{
	cout<<" 1439. Find the Kth Smallest Sum of a Matrix With Sorted Rows "<<endl;

	// example 1
	// vector<vector<int>> mat= {{1,2,11},{2,4,6}};
	// int k = 5;

	// example 2
	// vector<vector<int>> mat = {{1,3,11},{2,4,6}};
	// int k = 9;

	// example 3;
	vector<vector<int>> mat = {{1,10,10},{1,4,5},{2,3,6}};
	int k = 7;


	int i,j;

	cout<<" printing the mat vector :- "<<endl;
	for (i=0;i<mat.size();i++)
	{
		for (j=0;j<mat[i].size();j++)
			cout<<mat[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;

	cout<<" k = "<<k<<endl;

	int answer = kthSmallest(mat, k);
	cout<<" answer = "<<answer<<endl;


}