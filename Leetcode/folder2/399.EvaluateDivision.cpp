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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////  wrong method -- good effort ////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////// /////////////////////////////////////////////////////////////////////////

double getDival(vector<vector<double>>& eqstor, vector<vector<int>>& validPos, vector<int>& visited, int x, int y, double score)
{
	int i,j,k,u,v,z;

	visited[x] = 1;

	double dval1,dval2;

	for (i=0;i<eqstor[x].size();i++)
	{
		if ( x!=i && validPos[x][i]==1 && visited[i]==0)
		{
			if (i==y)
			{
				dval1 = score * eqstor[x][i];
				return dval1;
			}
			else
			{
				dval1 = getDival(eqstor, validPos, visited, i, y, score*eqstor[x][i]);

				if (dval1 != -1.0)
					return dval1;
			}
		}
	}

	visited[x] = 0;

	return -1.0;
}

vector<double> calcEquation1(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)
{
	int i,j,k,u,v,x,y,z;

	int n = 0;

	unordered_map<string,int> mp;

	string stemp1,stemp2;

	for (i=0;i<equations.size();i++)
	{
		stemp1 = equations[i][0];  stemp2 = equations[i][1];

		if (mp.find(stemp1) == mp.end())
		{
			mp[stemp1] = n;  n++;
		}

		if (mp.find(stemp2) == mp.end())
		{
			mp[stemp2] = n;  n++;
		}
	}

	cout<<endl;
	// cout<<" n = "<<n<<endl;

	vector<vector<int>> validPos;
	vector<vector<double>> eqstor;

	validPos.resize(n, vector<int>(n,0));
	eqstor.resize(n, vector<double> (n,0.0));

	for (i=0;i<n;i++)
	{
		validPos[i][i] = 1;
		eqstor[i][i] = 1.0;
	}

	double dval;

	for (i=0;i<equations.size();i++)
	{
		dval = values[i];

		stemp1 = equations[i][0];  stemp2 = equations[i][1];

		x = mp[stemp1]; y = mp[stemp2];

		eqstor[x][y] = dval;
		validPos[x][y] = 1;
	}

	// cout<<endl;
	// cout<<" printing the eqstor vector :- "<<endl;
	// for (i=0;i<n;i++)
	// {
	// 	for (j=0;j<n;j++)
	// 		cout<<eqstor[i][j]<<" ";
	// 	cout<<endl;
	// }
	// cout<<endl;

	// cout<<" printing the validPos vector :- "<<endl;
	// for (i=0;i<n;i++)
	// {
	// 	for (j=0;j<n;j++)
	// 		cout<<validPos[i][j]<<" ";
	// 	cout<<endl;
	// }
	// cout<<endl;

	vector<double> result;

	vector<int> visited;
	visited.resize(n,0);

	for (i=0;i<queries.size();i++)
	{
		stemp1 = queries[i][0]; stemp2 = queries[i][1];

		if (mp.find(stemp1) != mp.end() && mp.find(stemp2) != mp.end())
		{
			x = mp[stemp1]; y = mp[stemp2];

			if (validPos[x][y]==1)
				result.push_back(eqstor[x][y]);
			else if (validPos[y][x]==1)
				result.push_back((1.0/eqstor[y][x]));
			else
			{
				dval = getDival(eqstor, validPos, visited, x, y,1.0);

				if (dval != -1.0)
					result.push_back(dval);
				else
				{
					dval = getDival(eqstor, validPos, visited,  y, x, 1.0);
					
					if (dval==-1.0)
						result.push_back(-1.0);
					else
						result.push_back((1.0/dval));
				}
			}
		}
		else
		{
			result.push_back(-1.0);
		}
	}

	return result;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////  wrong method -- good effort  ///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

vector<double> calcEquation1(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)
{
	int i,j,k,u,v,x,y,z;

	int n = 0;

	unordered_map<string,int> mp;

	string stemp1,stemp2;

	for (i=0;i<equations.size();i++)
	{
		stemp1 = equations[i][0];  stemp2 = equations[i][1];

		if (mp.find(stemp1) == mp.end())
		{
			mp[stemp1] = n;  n++;
		}

		if (mp.find(stemp2) == mp.end())
		{
			mp[stemp2] = n;  n++;
		}
	}


}

int main()
{
	cout<<" 399. Evaluate Division "<<endl;

	// example 1
	// vector<vector<string>> equations = {
	// 	                               {"a","b"},
	// 	                               {"b","c"}
	// 	                               };

 //    vector<double> values = {2.0,3.0};

 //    vector<vector<string>> queries = {
 //    	                             {"a","c"},
 //    	                             {"b","a"},
 //    	                             {"a","e"},
 //    	                             {"a","a"},
 //    	                             {"x","x"}
 //    	                             };

	// example 2
	// vector<vector<string>> equations = {
	// 	                               {"a","b"},
	//                                    {"b","c"},
 //                                  	   {"bc","cd"}
 //                                  	   };

	// vector<double> values = {1.5,2.5,5.0};

	// vector<vector<string>> queries = {
	// 	                             {"a","c"},
 //                                   	 {"c","b"},
	//                                  {"bc","cd"},
 //                  	                 {"cd","bc"}
 //                  	                 };

	// example 3
	vector<vector<string>> equations = {{"a","b"}};

	vector<double> values = {0.5};

	vector<vector<string>> queries = {
		                             {"a","b"},
		                             {"b","a"},
		                             {"a","c"},
		                             {"x","y"}
		                             };

    vector<vector<string>> equations = {
    	                               {"a","e"},
    	                               {"b","e"}
    	                               };
[4.0,3.0]
[["a","b"],["e","e"],["x","x"]]
    cout<<" printing equations vector :- "<<endl;
    int i,j,k,u,v,x,y,z;

    for (i=0;i<equations.size();i++)
    	cout<<equations[i][0]<<" , "<<equations[i][1]<<endl;
    cout<<endl;

    cout<<" printting the values vector :- "<<endl;
    for (i=0;i<values.size();i++)
    	cout<<values[i]<<" ";
    cout<<endl;

    cout<<endl;

    cout<<" printing the queries vector :- "<<endl;
    for (i=0;i<queries.size();i++)
    	cout<<queries[i][0]<<" , "<<queries[i][1]<<endl;
    cout<<endl;

    vector<double> answer = calcEquation(equations, values, queries);
    for (i=0;i<answer.size();i++)
    	cout<<answer[i]<<" ";
    cout<<endl;
}