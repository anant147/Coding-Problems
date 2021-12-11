#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;

// dp video 38
// text justification problem - given few strings and width of screen , we have to tell optimal space between the words
// time complexity - o(n * n)
// space complexty -  o(n * n)

int textJustification(vector<string> vstr,int width)
{
	int i,j,k,u,v,x,y,answer,len,val;
	int n = vstr.size();

	int temp[n][n];
	int cost[n];
	int seq[n];

	for(i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
			temp[i][j]=-1;
	}

	int maxvl = pow(2,sizeof(int)*8-1)-1;

	for (i=0;i<n;i++)
	{
		len=0;
		for (j=i;j<n;j++)
		{
          if (i==j)
          	len=len+vstr[j].size();
          else
          	len=len+vstr[j].size()+1;

          if (len<=width)
          	temp[i][j]=pow(width-len,2);
          else
          	temp[i][j]=maxvl;

		}
	}

	// printing the temp matrix
	cout<<endl;
	cout<<"printing the temp matrix -- "<<endl;
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
			cout<<temp[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;

	// cost[n-1] = temp[n-1][n-1];
	// seq[n-1] = n;

	for (i=n-1;i>=0;i--)
	{
		cost[i]=maxvl;
		for (j=n-1;j>=i;j--)
		{
			if (j==(n-1))
			{
				if (temp[i][j]!=maxvl)
				{
				  cost[i] = temp[i][j];
				  seq[i] = j+1;
				}
			}
			else
			{
				if (temp[i][j]!=maxvl)
				{
                 val=temp[i][j]+cost[j+1];

                 if (val<cost[i])
                 {
                 	cost[i]=val;
                 	seq[i]=j+1;
                 }
				}
			}

		}
	}

	// printing the cost and seq array
	cout<<" printing the cost array -- "<<endl;
	for (i=0;i<n;i++)
		cout<<cost[i]<<" ";
	cout<<endl;

	cout<<" printing the seq array -- "<<endl;
	for (i=0;i<n;i++)
		cout<<seq[i]<<" ";
	cout<<endl;

	x=0;
    cout<<endl;
    cout<<" printing the text in optimal order -- "<<endl;
	for (i=0;i<n;i++)
	{
		y=seq[i];

		if ((i==x) && x<y)
		{
			for (j=x;j<y;j++)
				cout<<vstr[j]<<" ";

			cout<<endl;
			x=y;
		}

		if (x==n)
			break;
	}

	cout<<endl;
	return cost[0];
}

int main()
{
	int i,j;
	// vector<string> vstr = {"Tushar","Roy","likes","to","code"};
	// int width = 10;

	vector<string> vstr = {"Either","you","die","a","hero","or","live","long","enough","to","become","a","villian"};
	int width = 12;

	int cond=1;
	int l;

	cout<<" text justification problem -- "<<endl;
	cout<<" given strings --"<<endl;
	for (i=0;i<vstr.size();i++)
	{
     l = vstr[i].size();
	 cout<<"for i = "<<i<<" , string = "<<vstr[i]<<" , of length -- "<<l<<endl;
	 if (l>width)
	 	cond=0;
	}
	cout<<endl;
	cout<<" screen width = "<<width<<endl;


    if (cond==0)
    {
     cout<<" given strings are not compattible with the screen length "<<endl;
    }
    else
    {
	int answer = textJustification(vstr,width);
	cout<<" answer = "<<answer<<endl;
    }
}