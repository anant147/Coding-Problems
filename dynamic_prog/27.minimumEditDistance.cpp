#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// dynamic programming video 27
//  minimum edit distance problem  - find the minimum edit distance between the given source and target string so that source string can be converted into target string by insertion, deletion and substitution
// time complexity - o ( n * n )
// space complexity - o ( n )

int minval(int a,int b)
{
	if (a<b)
	return a;
	else
	return b;
}

int minval3(int a,int b,int c)
{
	return minval(a,minval(b,c));
}

int minimumEditDistance(string source,string target)
{
	int i,j,k,x,y,val,u,v;

	int n = source.length();
	int m = target.length();

	int temp[m+1][n+1];

	for (i=0;i<=n;i++)
		temp[0][i]=i;

	for (i=1;i<=m;i++)
		temp[i][0]=i;

	for (i=1;i<=m;i++)
	{
		for (j=1;j<=n;j++)
		{
			if (target[i-1] == source[j-1])
				temp[i][j] = temp[i-1][j-1];
			else
				temp[i][j] = 1 + minval3(temp[i-1][j],temp[i-1][j-1],temp[i][j-1]);
			    // temp[i-1][j] -- case of insertion
			    // temp[i-1][j-1] -- case of substitution 
			    // temp[i][j-1] -- case of deletion 
		}
	}

	int answer = temp[m][n];
    
	// printing the temp matrix
	cout<<endl;
	cout<<" printting the temp matrix --- "<<endl;

	for (i=0;i<=m;i++)
	{
		for (j=0;j<=n;j++)
			cout<<temp[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
    
    int tinsert = 0;
    int tsubstitute = 0;
    int tdelete = 0;
    int nchange = 0;
    x = m;
    y = n;
	// tracking the  minimum edit distance procedure

	while (true)
	{
		if (x==0 && y == 0)
			break;
		else
		{
			if (x==0)
			{
				y=y-1;
				tdelete++;
				cout<<" character "<<source[y]<<" of source string  is deleted "<<endl;
			}
			else if (y==0)
			{
				x=x-1;
				tinsert++;
				cout<<" character "<<target[x]<<" of target string is inserted "<<endl;
			}
			else if ((target[x-1] == source[y-1]) && temp[x][y]==temp[x-1][y-1])
			{
              x=x-1; y=y-1; nchange++;
              cout<<"character "<<target[x]<<" is same in both target and source string "<<endl;
			}
			else
			{
				if (temp[x][y] == (1+temp[x-1][y-1]))
				{
					x=x-1; y=y-1; tsubstitute++;
					cout<<source[y]<<" of source string is changed to "<<target[x]<<" of target string "<<endl;
				}
				else if (temp[x][y] == (1+temp[x][y-1]))
				{
					y=y-1; tdelete++;
					cout<<" character "<<source[y]<<" of source string  is deleted "<<endl;
				}
				else if (temp[x][y] == (1+temp[x-1][y]))
				{
					x=x-1; tinsert++;
					cout<<" character "<<target[x]<<" of target string is inserted "<<endl;
				}
			}

		}
	}
    
    cout<<endl;
	cout<<" total no change -- "<<nchange<<endl;
	cout<<" total insertion -- "<<tinsert<<endl;
	cout<<" total substitution -- "<<tsubstitute<<endl;
	cout<<" total deletion -- "<<tdelete<<endl;
	cout<<endl; 


	return answer;
}

int main()
{
	int i,j,k;

	// string source = "abcdef";
	// string target = "azced";

	// string source = "andant";
	// string target = "ajain";

	// string source = "andant";
	// string target = "akrjain";

    string source = "anant";
	string target = "dpshnt";

	cout<<" minimum edit distance problem "<<endl;
	cout<<" source string = "<<source<<endl;
	cout<<" target string = "<<target<<endl;

	int answer = minimumEditDistance(source,target);
	cout<<" answer = "<<answer<<endl;
}