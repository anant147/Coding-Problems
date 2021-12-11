#include<iostream>
#include<vector>
#include<cstring>
#include<utility>
using namespace std;

int minCut(string s)
{
    int i,j,k,u,v,x,y,answer;

    int n = s.length();

    if (n==0)
        return 0;
    else if (n==1)
        return 1;

    int temp[n][n]={0};
    bool ispdrome[n][n]={false};

    for (i=0;i<n;i++)
    {
        ispdrome[i][i]=true;
    }

    int maxval = n;

    int len;

    for (len=2;len<=n;len++)
    {
        for (i=0;i<(n-len+1);i++)
        {
            j=i+len-1;

            if (len==2)
            {
                if(s[i]==s[j])
                {
                    ispdrome[i][j]=true;
                }
                else
                {
                    temp[i][j]=1;
                    ispdrome[i][j]=false;
                }
            }
            else
            {
                if(s[i]==s[j] && ispdrome[i+1][j-1]==true)
                {
                    ispdrome[i][j]=true;
                }
                else
                {
                    temp[i][j]=maxval;
                    ispdrome[i][j]=false;

                    for (k=i;k<j;k++)
                    {
                        u=temp[i][k]+temp[k+1][j]+1;

                        if (u<temp[i][j])
                            temp[i][j]=u;
                    }
                }
            }
        }
    }

    // print temp and ispdrome matrix
    // cout<<" printing temp matrix -- "<<endl;
    // for (i=0;i<n;i++)
    // {
    //     for (j=0;j<n;j++)
    //         cout<<temp[i][j]<<" ";
    //     cout<<endl;
    // }
    // cout<<endl;

    // cout<<" printing ispdrome matrix -- "<<endl;
    // for (i=0;i<n;i++)
    // {
    //     for (j=0;j<n;j++)
    //         cout<<ispdrome[i][j]<<" ";
    //     cout<<endl;
    // }
    // cout<<endl;
    return temp[0][n-1];
}

int main()
{
    int i,j,k,u,v,amswer;

    string s = "aab";
    int n = s.length();
    cout<<" palindrome partitioning of string -- "<<endl;
    cout<<" string s = "<<s<<endl;
    cout<<" n = "<<n<<endl;

    cout<<endl;

    int answer = minCut(s);

    cout<<" answer = "<<answer<<endl;
}