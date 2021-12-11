#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

string longestPalindrome(string s)
{
	int i,j,k,u,v,x,y,z,len;

	int n = s.length();

	if (n==0)
	return "";
	else if(n==1)
	return s;


	int temp[n][n];
	int tracer[n][n][2];
	bool ispdrome[n][n];


	for (i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			temp[i][j]=0;
			tracer[i][j][0] = -1;
			tracer[i][j][1] = -1;
			ispdrome[i][j] = false;
		}
	}

	for (i=0;i<n;i++)
	{
     temp[i][i] = 1;
     tracer[i][i][0] = i;
     tracer[i][i][1] = i;
     ispdrome[i][i]=true;
	}
    
    for (len=2;len<=n;len++)
    {
    	for(i=0;i<(n-len+1);i++)
    	{
    		j=i+len-1;

    		if ((i==(j-1) || ispdrome[i+1][j-1] ) &&  (s[i]==s[j]))
    		{
             temp[i][j]=2+temp[i+1][j-1];
             tracer[i][j][0]=i;
             tracer[i][j][1]=j;
             ispdrome[i][j]=true;
    		}
    		else
    		{
              if (temp[i][j-1]>=temp[i+1][j])
              {
               temp[i][j]=temp[i][j-1];
               tracer[i][j][0]=tracer[i][j-1][0];
               tracer[i][j][1]=tracer[i][j-1][1];
              }
              else
              {
               temp[i][j]=temp[i+1][j];
               tracer[i][j][0]=tracer[i+1][j][0];
               tracer[i][j][1]=tracer[i+1][j][1];
              }

    		}
    	}
    }

    // cout<<"print temp array -- "<<endl;
    // for (i=0;i<n;i++)
    // {
    // 	for(j=0;j<n;j++)
    // 	{
    // 		cout<<temp[i][j]<<" ";
    // 	}
    // 	cout<<endl;
    // }

    // cout<<endl;

    // cout<<"print ispdrome array -- "<<endl;
    // for (i=0;i<n;i++)
    // {
    // 	for(j=0;j<n;j++)
    // 	{
    // 		cout<<ispdrome[i][j]<<" ";
    // 	}
    // 	cout<<endl;
    // }

    // cout<<endl;

    // cout<<"print tracer array -- "<<endl;
    // for (i=0;i<n;i++)
    // {
    // 	for(j=0;j<n;j++)
    // 	{
    // 		cout<<" ( "<<tracer[i][j][0]<<" , "<<tracer[i][j][1]<<") ";
    // 	}
    // 	cout<<endl;
    // }
    // cout<<endl;

    x=tracer[0][n-1][0];
    y=tracer[0][n-1][1];

    int sz = y-x+1;
    string answer = s.substr(x,sz);
    return answer;
}

int main()
{
	int i,j,k;

	// string s = "babad";
	// string s = "cbbd";
	string s = "abcda";
	cout<<" longest palindrome problem -- "<<endl;
	cout<<"string s = "<<s<<endl;
	cout<<endl;

	string answer = longestPalindrome(s);
	cout<<endl;
	cout<<" answer = "<<answer<<endl;
}