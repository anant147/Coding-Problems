#include <iostream>
#include <vector>
using namespace std;

// dynamic programming video 25
//  maximum sum subsequence non adjacent problem   problem - find the maximum sum subsequence of given array of n elements such that elements in the sequence are non adjacent
// time complexity - o ( n )
// space complexity - o ( 1 )

int maxval(int a,int b)
{
	if (a<b)
		return b;
	else
		return a;
}

int maximumSumSubsequenceNonAdjacent(int a[],int n)
{
	int i,j,k,incl,excl,temp;

	incl=0;
	excl=0;

	

	for (i=0;i<n;i++)
	{
	 if (i==0)
	 {
	 	incl=a[i];
	 	excl=0;
	 }
	 else
	 {
	 	temp=incl;
	 	incl=maxval(incl,excl+a[i]);
	 	excl=temp;
	 }

	}

	cout<<"end value = "<<incl<<endl;
	return incl;
}

int main()
{
	// int a[]={4,1,1,4,2,1};
	int a[]={4,5,2,5,1,5,6};
	int n = sizeof(a)/sizeof(a[0]);

	cout<<" maximum sum subsequence non adjacent problem "<<endl;
	cout<<" size of the array = "<<n<<endl;
	cout<<" elements of the array -- "<<endl;
	for (int i=0;i<n;i++)
	 cout<<a[i]<<" ";
	cout<<endl;
	
	int answer = maximumSumSubsequenceNonAdjacent(a,n);

	cout<<" answer = "<<answer<<endl; 
}