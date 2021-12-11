#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// dynamic programming video 10
// count total number of bsts given n
// time complexity - o (n*n)

int countTotalBst(int n)
{
 int i,j,k;

 int t[n+1];

 // initializing t array
 for (i=0;i<=n;i++)
 {
 	if(i==0 || i==1)
 		t[i]=1;
 	else
 		t[i]=0;
 }
 
 // maincode
 for (i=2;i<=n;i++)
 {
 	for(j=0;j<i;j++)
 		t[i]=t[i]+(t[j]*t[i-j-1]); // catalan number
 }

 // print the t array
 cout<<"printing the t array "<<endl;

 for(i=0;i<=n;i++)
 	cout<<t[i]<<" ";
 cout<<endl;

 k=t[n];

 return k;
}

int main()
{
	int n=10;
	cout<<"n = "<<n<<endl;
	int answer = countTotalBst(n);
	cout<<"answer - "<<answer<<endl;
}