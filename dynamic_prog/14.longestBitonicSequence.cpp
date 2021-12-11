#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// dynamic programming video 14
// longest bitonic sequence problem - find longest bitonic sequence for given element of array of length n
// time complexity - o (n*n)
// space complexity - o (n)

int maxval(int a,int b)
{
	if(a<b)
		return b;
	else
		return a;
}

int longestBitonicSequence(int a[],int n)
{
	int i,j,k,u,v,answer;

	int lr[n]; // array used to store longest increasing sequence for each element form left to right
	int rl[n]; // array used to store longest increasing sequence for each element form right to left
	
	for(i=0;i<n;i++)
	{
		lr[i]=1;rl[i]=1;
	}

	// code for storing longest increasing sequence from left to right
	for (i=1;i<n;i++)
	{
		k=lr[i];
		for(j=0;j<i;j++)
		{
          if(a[j]<a[i])
          {
            k=maxval(k,lr[j]+1);
          }
		}
		lr[i]=k;
	}

    // code for storing longest increasing sequence from right to left
	for (i=n-2;i>=0;i--)
	{
		k=rl[i];
		for(j=n-1;j>i;j--)
		{
           if(a[j]<a[i])
           	k=maxval(k,rl[j]+1);
		}
		rl[i]=k;
	}
    
    // printing longest increasing seq length form left to right
	cout<<"longest increasing seq length form left to right"<<endl;

	for(i=0;i<n;i++)
		cout<<lr[i]<<" ";
	cout<<endl;
    
    // printing longest increasing seq length form right to left
	cout<<"longest increasing seq length form right to left"<<endl;

	for(i=0;i<n;i++)
		cout<<rl[i]<<" ";
	cout<<endl;
    
    // printing bitonic sequence length for each point of array
	cout<<"bitonic sequence length for each point of array "<<endl;

	answer=0;

    // code for bitonic sequence of each element of the array
	for(i=0;i<n;i++)
	{
		k=lr[i]+rl[i]-1;
		cout<<"for i = "<<i<<" , bitonic sequence length = "<<k<<endl;
		answer=maxval(answer,k);
	}

	return answer;
}

int main()
{
	// int n=8;
	// int a[]={2,-1,4,3,5,-1,3,2};

	int n=8;
	int a[]={1,11,2,10,4,5,2,1};

	cout<<"longest bitonic sequence problem"<<endl;
	cout<<"arr size = "<<n<<endl;
	cout<<"elements of array "<<endl;
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;

	int answer = longestBitonicSequence(a,n);

	cout<<"answer = "<<answer<<endl;
}