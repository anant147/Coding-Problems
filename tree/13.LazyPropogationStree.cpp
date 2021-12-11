#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int maxValue = pow(2,sizeof(int)*8-1)-1;
int minValue = (-1) * maxValue;

void constructSegtree(int input[], int segtree[], int low, int high, int pos)
{
	if (low == high)
	{
		segtree[pos] = input[low];
		return;
	}

	int mid = (low + high)/2;

	constructSegtree(input,segtree,low,mid,2*pos+1);
	constructSegtree(input,segtree,mid+1,high, 2*pos+2);
	segtree[pos] = min(segtree[2*pos+1],segtree[2*pos+2]);
}

void updateRangeInStree(int segtree[], int lazytree[], int strange, int edrange, int val, int low, int high, int pos)
{
	if (low>high)
		return;

	if (lazytree[pos]!=0)
	{
		segtree[pos] += lazytree[pos];
		if (low != high)
		{
			lazytree[2*pos+1] += lazytree[pos];
			lazytree[2*pos+2] += lazytree[pos];
		}
		lazytree[pos] = 0;
	}

	if (strange > high || low > edrange) // case of no overlap 
		return;

	if (strange <= low && high <= edrange) // case of total overlap
	{
		segtree[pos] += val;
		if (low != high)
		{
			lazytree[2*pos+1] += val;
			lazytree[2*pos+2] += val;
		}
		return;
	}

	int mid = (low + high)/2; // case of partial overlap

	updateRangeInStree(segtree, lazytree, strange, edrange, val, low, mid, 2*pos+1);
	updateRangeInStree(segtree, lazytree, strange, edrange, val, mid+1, high, 2*pos+2);
	segtree[pos] = min(segtree[2*pos+1], segtree[2*pos+2]);
}

int rangeMinQuery(int segtree[], int lazytree[], int qlow, int qhigh, int low, int high, int pos)
{
	if (low > high)
		return maxValue;

	if (lazytree[pos]!=0)
	{
		segtree[pos] += lazytree[pos];

		if (low != high)
		{
			lazytree[2*pos+1] += lazytree[pos];
			lazytree[2*pos+2] += lazytree[pos];
		}
		lazytree[pos] = 0;
	}

	if (qlow > high || low > qhigh) // case of no overlap
		return maxValue;

	if (qlow<=low && high <= qhigh) // case of total overlap
		return segtree[pos];

	int mid = (low + high)/2; // case of partial overlap

	return min( rangeMinQuery(segtree, lazytree, qlow, qhigh, low, mid, 2*pos+1), 
		rangeMinQuery(segtree, lazytree, qlow, qhigh, mid+1, high, 2*pos+2));
}

int main()
{
	int n = 4;
	int input[n] = {2, 3, -1, 4};
	int x = 2 * (int)(ceil(log2(n)));
	int m = 2 * x -1;
	int i, strange, edrange, val , qlow, qhigh;

	int segtree[m];
	int lazytree[m];

	for (i=0;i<m;i++)
	{
	  segtree[i] = maxValue;
	  lazytree[i] = 0;
	}

	cout<<" no. of elements in the array -- "<<n<<endl;
	cout<<" elements of the array -- "<<endl;
	for (i=0;i<n;i++)
	  cout<<input[i]<<" ";
	cout<<endl;
	cout<<endl;
  
	constructSegtree(input,segtree,0,n-1,0);

	cout<<" no. of elements in the segment tree array  -- "<<m<<endl;
	cout<<" elements of the segment tree array -- "<<endl;
	for (i=0;i<m;i++)
	  cout<<segtree[i]<<" ";
	cout<<endl;
	cout<<endl;

	cout<<" no. of elements in the lazy array -- "<<n<<endl;
	cout<<" elements of the lazy array -- "<<endl;
	for (i=0;i<m;i++)
	  cout<<lazytree[i]<<" ";
	cout<<endl;
	cout<<endl;

	strange = 0;
	edrange = 3;
	val = 2;
	cout<<"val between range of ("<<strange<<" , "<<edrange<<") to be incremented with val of "<<val<<endl;
	updateRangeInStree(segtree,lazytree,strange, edrange, val, 0, n-1, 0);
	cout<<endl;

	strange = 2;
	edrange = 2;
	val = 4;
	cout<<"val between range of ("<<strange<<" , "<<edrange<<") to be incremented with val of "<<val<<endl;
	updateRangeInStree(segtree,lazytree,strange, edrange, val, 0, n-1, 0);
	cout<<endl;

	cout<<" no. of elements in the segment tree array  -- "<<m<<endl;
	cout<<" elements of the segment tree array -- "<<endl;
	for (i=0;i<m;i++)
	  cout<<segtree[i]<<" ";
	cout<<endl;
	cout<<endl;

	cout<<" no. of elements in the lazy array -- "<<n<<endl;
	cout<<" elements of the lazy array -- "<<endl;
	for (i=0;i<m;i++)
	  cout<<lazytree[i]<<" ";
	cout<<endl;
	cout<<endl;

	qlow = 1;
	qhigh = 2;
	cout<<" Minimum value in the range of ("<<qlow<<" , "<<qhigh<<") is "<<rangeMinQuery(segtree,lazytree,qlow, qhigh, 0, n-1, 0)<<endl;
}