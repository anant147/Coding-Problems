#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int maxValue = pow(2,sizeof(int)*8-1)-1;
int minValue = (-1)*maxValue;

void constSegmentTree(int input[],int segtree[],int low, int high, int pos)
{
	if (low==high)
	{
		segtree[pos]=input[low];
		return;
	}

	int mid = (low + high)/2;

	constSegmentTree(input, segtree, low, mid,2*pos+1);
	constSegmentTree(input, segtree, mid+1, high, 2*pos+2);
	segtree[pos] = min(segtree[2*pos+1],segtree[2*pos+2]);
}

int rangeMinQuery(int segtree[], int qlow, int qhigh, int low, int high, int pos)
{
	if (qlow <=low && high <= qhigh)
		return segtree[pos];

	if (qlow > high || qhigh < low )
		return maxValue;

	int mid = (low + high)/2;

	return min(rangeMinQuery( segtree, qlow, qhigh, low, mid, 2 * pos + 1) ,
		       rangeMinQuery( segtree, qlow, qhigh, mid+1, high, 2 * pos + 2));
}

void updateValInStree(int segtree[], int low, int high, int index, int val, int pos)
{
	if ( low>index || index>high)
		return;

	if (low==high)
		segtree[pos]=val;
	else
	{
		int mid = (low + high)/2;

		updateValInStree(segtree, low, mid, index,val, 2*pos+1);
		updateValInStree(segtree, mid+1, high, index, val, 2*pos+2);

		segtree[pos] = min(segtree[2*pos+1], segtree[2*pos+2]);
	}
}

void updateVal(int input[],int segtree[],int low, int high, int index,int val)
{
	input[index] = val;
	updateValInStree(segtree,low,high,index,val,0);
}

int main()
{
    int n = 4;
	int input[n] = {-1, 2, 4, 0};
	int x = (int)(ceil(log2(n)));
	int i;

	int m = 2*((int)pow(2,x))-1;
	int segtree[m];
	for ( i=0;i<m;i++)
		segtree[i] = maxValue;

	cout<<" No. of elements in the given array -- "<<n<<endl;
	cout<<" Elements of the given array -- "<<endl;
	for (i=0;i<n;i++)
		cout<<input[i]<<" ";
    cout<<endl;

    constSegmentTree(input,segtree,0,n-1,0);

	cout<<" No. of elements in the segment tree array -- "<<m<<endl;
	cout<<" Elements of the segment tree array -- "<<endl;
	for (i=0;i<m;i++)
		cout<<segtree[i]<<" ";
	cout<<endl;

	int qlow;
	int qhigh;

	qlow=1;
	qhigh=3;
	cout<<" Minimum in the range of qlow = "<<qlow<<" , qhigh = "<<qhigh<<" is "<<rangeMinQuery(segtree,qlow,qhigh,0,n-1,0)<<endl;
	cout<<endl;

	qlow=0;
	qhigh=2;
	cout<<" Minimum in the range of qlow = "<<qlow<<" , qhigh = "<<qhigh<<" is "<<rangeMinQuery(segtree,qlow,qhigh,0,n-1,0)<<endl;
	cout<<endl;

	qlow=1;
	qhigh=2;
	cout<<" Minimum in the range of qlow = "<<qlow<<" , qhigh = "<<qhigh<<" is "<<rangeMinQuery(segtree,qlow,qhigh,0,n-1,0)<<endl;
	cout<<endl;

	updateVal(input,segtree,0,n-1,3,-2);

	cout<<endl;
	cout<<" Elements of the segment tree array -- "<<endl;
	for (i=0;i<m;i++)
		cout<<segtree[i]<<" ";
	cout<<endl;
}