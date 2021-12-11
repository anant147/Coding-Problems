#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

bool isMatch(string s, string p)
{
    int i,j,k,u,v;

    int n = s.length();
    int m = p.length();

    bool temp[n+1][m+1];

    temp[0][0]=true;

    for (i=1;i<=n;i++)
        temp[i][0]=false;

    for (i=1;i<=m;i++)
    {
        if(p[i-1]=='*')
            temp[0][i]=temp[0][i-1];
        else
            temp[0][i]=false;
    }

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            if (s[i-1]==p[j-1] || p[j-1]=='?')
                temp[i][j]=temp[i-1][j-1];
            else if (p[j-1]=='*')
                temp[i][j]=temp[i-1][j]|temp[i][j-1];
            else
                temp[i][j]=false;
        }
    }

    // print temp matrix
    cout<<endl;
    cout<<" printing the temp matrix -- "<<endl;
    for (i=0;i<=n;i++)
    {
        for (j=0;j<=m;j++)
            cout<<temp[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;

    return temp[n][m];
}

int main()
{
    int i,j;
    // string s = "acdcb";
    // string p = "a*c?b";

    string s = "adceb";
    string p = "*a*b";

    cout<<" wild card matching problem -- "<<endl;
    cout<<" s = "<<s<<endl;
    cout<<" p = "<<p<<endl;
    bool answer = isMatch(s,p);

    if (answer == true)
        cout<<" text matches with pattern"<<endl;
    else
        cout<<" text donot matches with string "<<endl;
}