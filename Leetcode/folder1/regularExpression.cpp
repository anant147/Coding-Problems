#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

bool isMatch(string s,string p)
{
    int i,j,k,u,v,x,y;

    int n = s.length();
    int m = p.length();

    if (n==0 && m==0)
    	return true;

    bool temp[n+1][m+1];

    temp[0][0]=true;

    for(i=1;i<=n;i++)
    	temp[i][0]=false;

    for(i=1;i<=m;i++)
    {
    	if (p[i-1]=='*')
    		temp[0][i]=temp[0][i-2];
    	else
    		temp[0][i]=false;
    }

    for(i=1;i<=n;i++)
    {
    	for(j=1;j<=m;j++)
    	{
    		if(s[i-1]==p[j-1] || (p[j-1]=='.'))
    			temp[i][j]=temp[i-1][j-1];
    		else if(p[j-1]=='*')
    		{
             temp[i][j]=temp[i][j-2];

             if (s[i-1]==p[j-2]  || (p[j-2]=='.') )
             	temp[i][j] = temp[i][j] | temp[i-1][j];
    		}
    		else
    			temp[i][j]=false;
    	}
    }

    // cout<<"print temp matrix "<<endl;
    // for (i = 0; i <=n; ++i)
    // {
    //   for(j=0;j<=m;j++)
    //   	cout<<temp[i][j]<<" ";
    //   cout<<endl;
    // }


	return temp[n][m];
}

int main()
{
	string s="aa";
	string p="a*";
	// string s = "aab";
	// string p = "c*a*b";

	cout<<"regular expression matching -- "<<endl;
	cout<<" text = "<<s<<endl;
	cout<<" pattern = "<<p<<endl;

	bool answer = isMatch(s,p);

	cout<<"answer = "<<answer<<endl;
}