#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

void addIntoFtree(int fenwick[],int val,int x,int n)
{
	int y;

	while(x<=n)
	{
		fenwick[x]=fenwick[x]+val;
		x = x+ (x&-x);
	}
}

int getPrefixSum(int fenwick[],int x,int n)
{
	int sum=0;

	while(x!=0)
	{
		sum = sum + fenwick[x];
		x = x - (x&-x);
	}

	return sum;
}

int rangeQuerySum(int fenwick[],int x,int y,int n)
{
	int answer;
	y=y+1;

	if (y>n)
		y=n;

	if (x==0)
		answer = getPrefixSum(fenwick,y,n);
	else
		answer = getPrefixSum(fenwick,y,n) - getPrefixSum(fenwick,x,n);

	return answer;
}

void updateValInFtree(int fenwick[],int arr[],int index,int newVal,int n)
{
	if (index<0 || index >=n)
		return;

	int val = newVal-arr[index];
	arr[index] = newVal;
	index=index+1;

	addIntoFtree(fenwick,val,index,n);
}

int main()
{
  int n = 11;
  int i;
  int arr[n] = {3, 2, -1, 6, 5, 4, -3, 3, 7, 2, 3};

  int fenwick[n+1];

  for (i=0;i<=n;i++)
  	fenwick[i]=0;

  for (i=0;i<n;i++)
  	addIntoFtree(fenwick,arr[i],i+1,n);

  cout<<" elements of the arr array -- "<<endl;
  for (i=0;i<n;i++)
  	cout<<arr[i]<<" ";
  cout<<endl;
  cout<<endl;

  cout<<" elements of the fenwick array  -- "<<endl;
  for (i=0;i<=n;i++)
  	cout<<fenwick[i]<<" ";
  cout<<endl;
  cout<<endl;

  cout<<" range sum queries -- "<<endl;

  cout<<" for st = 0, ed = 7, val = "<<rangeQuerySum(fenwick,0,7,n)<<endl;
  cout<<endl;

  cout<<" for st = 3, ed = 10, val = "<<rangeQuerySum(fenwick,3,10,n)<<endl;
  cout<<endl;

  cout<<" for st = 1, ed = 6, val = "<<rangeQuerySum(fenwick,1,6,n)<<endl;
  cout<<endl;

  cout<<" for st = 6, ed = 9, val = "<<rangeQuerySum(fenwick,6,9,n)<<endl;
  cout<<endl;

  cout<<" for st = 5, ed = 5, val = "<<rangeQuerySum(fenwick,5,5,n)<<endl;
  cout<<endl;

  cout<<" update queries -- "<<endl;
  int index;
  int newVal;
  
  index = 2;
  newVal = 1;
  cout<<" value to be updated for index = "<<index<<" with value = "<<newVal<<endl;
  updateValInFtree(fenwick,arr,index,newVal,n);
  cout<<endl;

  index = 0;
  newVal = 2;
  cout<<" value to be updated for index = "<<index<<" with value = "<<newVal<<endl;
  updateValInFtree(fenwick,arr,index,newVal,n);
  cout<<endl;

  index = 10;
  newVal = 5;
  cout<<" value to be updated for index = "<<index<<" with value = "<<newVal<<endl;
  updateValInFtree(fenwick,arr,index,newVal,n);
  cout<<endl;

  cout<<endl;
  cout<<" elements of the arr array -- "<<endl;
  for (i=0;i<n;i++)
  	cout<<arr[i]<<" ";
  cout<<endl;
  cout<<endl;

  cout<<" elements of the fenwick array  -- "<<endl;
  for (i=0;i<=n;i++)
  	cout<<fenwick[i]<<" ";
  cout<<endl;
  cout<<endl;

}