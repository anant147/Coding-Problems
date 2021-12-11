#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// dynamic programming video 11
// count total number of binary trees  given length of preorder sequence
// time complexity - o (n*n)
// space complexity - o(n)

int countBinaryTreeGivenPreorderSeqLength(int n)
{
	int i,j,k;

	int T[n+1];

    // initialing t array
	for(i=0;i<=n;i++)
	{
		if (i==0 || i==1)
			T[i]=1;
		else
			T[i]=0;
	}
    
    // main code
	for(i=2;i<=n;i++)
	{
		for(j=0;j<i;j++)
			T[i]=T[i]+(T[j]*T[i-j-1]);
	}

	// print the t array

	cout<<"print the t array"<<endl;

	for(i=0;i<=n;i++)
		cout<<"for i = "<<i<<" , count - "<<T[i]<<endl;

	k=T[n];

	return k;

}

int main()
{
	// int n=5;
	// int n=6;
	// int n=7;
	int n=11;
	cout<<"n = "<<n<<endl;
	int answer = countBinaryTreeGivenPreorderSeqLength(n);
	cout<<"answer - "<<answer<<endl;
}