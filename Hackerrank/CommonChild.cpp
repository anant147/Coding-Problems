#include <iostream>
#include <vector>

using namespace std;

//  note :- solutioin with 2d array of 5000*5000 gibving segmentation fault 
// maximum limit of allocation is 8mb, but it is greater , so result in stack ovewrflow.

// note :- solution with array of 2*5000 possible i.e O(n) space .very good space compleity


int maxval(int u,int v)
{
	if(u>v)
		return u;
	else
		return v;
}

int commonChild(string s1,string s2)
{
	int i,j,k,u;
	int n = s1.size();
	int m = s2.size();

	int stable[m+1];

	for(i=0;i<(m+1);i++)
		stable[i]=0;

	for(i=0;i<n;i++)
	{
		for(j=1;j<(m+1);j++)
		{
            if(j==1)
            {	
            u=stable[0];
            k=stable[1];
            }
            else
            {
             k=stable[j]; 	
            } 	
             	
			if(s1[i]==s2[j-1])
			{
             stable[j]=u+1;
             // cout<<"pos i = "<<i+1<<" , j = "<<j<<" , val = "<<stable[j]<<endl;
			}
			else
			{
             stable[j]=maxval(stable[j-1],stable[j]);
			}

			u=k;

		}
	}

	int result = stable[m];

	// cout<<"required result = "<<result<<endl;

	return result;

}

// int commonChild(string s1,string s2)  // correct soln
// {
// 	int i,j,k;
// 	int n = s1.size();
// 	int m = s2.size();

// 	int stable[2][m+1];

// 	for(i=0;i<2;i++)
// 	{
// 		for(j=0;j<(m+1);j++)
// 			stable[i][j]=0;
// 	}

//     for(i=1;i<(n+1);i++)
//     {
//     	for(j=1;j<(m+1);j++)
//     	{
//     		if(s1[i-1]==s2[j-1])
//     		{
//     			stable[1][j]=stable[0][j-1]+1;
//     			// cout<<"pos i = "<<i<<" , j = "<<j<<" , val = "<<stable[1][j]<<endl;
//     		}
//     		else
//     		{
//     			stable[1][j] = maxval(stable[0][j],stable[1][j-1]);
//     		}
//     	}

//     	for(j=1;j<(m+1);j++)
//     		stable[0][j]=stable[1][j];
//     }

//     int result = stable[1][m];

//     // cout<<" a - required value  = "<<result<<endl;
    
// 	return result;
// }

// int commonChild(string s1,string s2) // 2d array of 5000 * 5000 giving segmentation fault 
// {
// 	int i,j,k;
//     int n = s1.size();
//     int m = s2.size();

//     int stable[n+1][m+1];

//     for(i=0;i<(m+1);i++)
//     	stable[0][i]=0;

//     for(i=0;i<(n+1);i++)
//     	stable[i][0]=0;

//     for(i=1;i<(n+1);i++)
//     {
//     	for(j=1;j<(m+1);j++)
//     	{
//     		if(s1[i-1]==s2[j-1])
//     		{
//     		stable[i][j]=stable[i-1][j-1]+1;
//     		cout<<"pos i = "<<i<<" , j = "<<j<<" , val = "<<stable[i][j]<<endl;
//          	}
//     	    else 
//     	    stable[i][j] = maxval(stable[i][j-1],stable[i-1][j]);	
//     	}
//     }

//     int result = stable[n][m];

//     cout<<"required value = "<<stable[n][m]<<endl;
    

// return result;
// }

int main()
{
	// string s1 = "HARRY";
	// string s2 = "SALLY";

	
	string s1 = "ABCDEF";
	string s2 = "FBDAMN";

	int result = commonChild(s1,s2);

	cout<<result<<endl;
}
