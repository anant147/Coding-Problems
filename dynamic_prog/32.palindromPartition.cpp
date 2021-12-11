#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

// dp video 32
// pallindrome partitioning problem for given string of length n
// time complexity - o(n*n*n)
// space complexty - o(n*n)

bool isPalindrome(string input,int st,int ed)
{
 int i,j,k;

 i=st;
 j=ed;

 int cond=1;

 while(i<=j)
 {
 	if (input[i]==input[j])
 	{
 		i++;
 		j--;
 	}
 	else
 	{
 		cond=0;
 		break;
 	}
 }

 if (cond==1)
 	return true;
 else
 	return false;
}

void printPalindromePart(int *temp,int *tracer,string input,int n,int st,int ed)
{
 int val = *((temp + st*n)+ed);

 if (val==0)
 {
  int len = ed-st+1;
  cout<<"part of input string -- "<<input.substr(st,len)<<endl;
  return;
 }
 else
 {
 	int k = *((tracer + st*n)+ed);
    
    printPalindromePart((int *)temp,(int *)tracer,input,n,st,k);
    printPalindromePart((int *)temp,(int *)tracer,input,n,k+1,ed);
 }
}

int pallindromPartitionNumber(string input)
{
	int i,j,k,u,v,answer,len,val;

	int n = input.length();

	int temp[n][n];
	int tracer[n][n];

	int maxvl = pow(2,sizeof(int)*8-1)-1;

	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			temp[i][j]=-1;
			tracer[i][j]=-1;
		}
	}
    
    for (i=0;i<n;i++)
    {
    	temp[i][i]=0;
    	tracer[i][i]=i;
    }
	// main code

	for (len=2;len<=n;len++)
	{
		for (i=0;i<(n-len+1);i++)
		{
			j=i+len-1;

			if (isPalindrome(input,i,j))
			{
				temp[i][j]=0;
				tracer[i][j]=-1;
			}
			else
			{
              temp[i][j]=maxvl;

              for (k=i;k<j;k++)
              {
              	val = 1 + temp[i][k] + temp[k+1][j];

              	if (val < temp[i][j])
              	{
              		temp[i][j]=val;
              		tracer[i][j]=k;
              	}

              }
			}
		}
	}

    cout<<endl;
	// printing the temp and tracer matrix 
	cout<<" printing the temp matrix -- "<<endl;
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
			cout<<temp[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	cout<<" printing the tracer matrix -- "<<endl;
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
			cout<<tracer[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
    
    cout<<" printing the all partitions of the string -- "<<endl;
	printPalindromePart((int *)temp,(int *)tracer,input,n,0,n-1);
	cout<<endl;
	// cout<<"part of input string asjj-- "<<input.substr(0,0)<<endl;

	return temp[0][n-1];
}

int main()
{
	int i,j;
	// string input = "abcbm";
	// string input = "rorhahbbcc"; 
	string input = "akjain";
	int n = input.length();
	cout<<" pallindrome partitioning problem "<<endl;
	cout<<" length of the input string -- "<<n<<endl;
	cout<<" input string -- "<<input<<endl;
	int answer = pallindromPartitionNumber(input);
	cout<<" final answer -- "<<answer<<endl;

}