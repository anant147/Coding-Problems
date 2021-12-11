#include <iostream>
#include <vector>
using namespace std;

// dynamic programming video 17
// longest  increasing  sequence problem - find longest  increasing sequence for given array of n elements
// time complexity - o (n*n)
// space complexity - o (n)

int maxval(int a,int b)
{
	if(a<b)
		return b;
	else
		return a;
}

int longestIncreasingSubsequence(int a[],int n)
{
	int i,j,k,answer,pos,val;

	int temp[n];

	for(i=0;i<n;i++)
		temp[i]=1;

	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if (a[j]<a[i])
				temp[i]=maxval(temp[i],temp[j]+1);
		}
	}

	// print the temp array
    cout<<" printing the temp array "<<endl;
    answer=0;
    pos=-1;
	for(i=0;i<n;i++)
	{
		cout<<temp[i]<<" ";
		if(temp[i]>answer)
		{
			answer=temp[i];
			pos=i;
		}
	}
	cout<<endl;

	val=answer;
	vector<int> v;
	v.push_back(a[pos]);
	val=val-1;
	j=pos-1;

    // tracking the longest increasing subsequemce
	while(true)
	{
	 if((a[j]<a[pos]) && (temp[pos]==(temp[j]+1)))
	 {
	 	v.push_back(a[j]);
	 	pos=j;
	 	j=pos-1;
	 	val=val-1;
	 }
	 else if(j<0 || pos==0)
	 {
      break;
	 }
	 else
	 	j=j-1;

	}


	/// printing elements of longest increasing subsequence
	cout<<"printing elements of longest increasing subsequence"<<endl;
	for(i=v.size()-1;i>=0;i--)
		cout<<v[i]<<" ";
	cout<<endl;

	return answer;
}

int main()
{
	// int n=7;
	// int a[]={3,4,-1,0,6,2,3};
	// int n=9;
	// int a[]={3,4,-1,7,8,0,6,2,3};
	int n=13;
	int a[]={3,4,-1,7,8,10,0,6,1,2,3,4,5};
	cout<<"longest Increasing Subsequence Problem "<<endl;
	cout<<" size of the array = "<<n<<endl;
	cout<<"elements of the array -- "<<endl;
	for (int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;

	int answer = longestIncreasingSubsequence(a,n);
	cout<<"answer = "<<answer<<endl;
}