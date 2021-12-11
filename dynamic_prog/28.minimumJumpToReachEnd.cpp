#include <iostream>
#include <vector>
using namespace std;

// dynamic programming video 28
//  minimum number of jumps to reach end point for given array where each element represent number of jumps that can be taken from that point
// time complexity - o ( n * n )
// space complexity - o ( n )

int minimumJumpToReachEnd(int a[],int n)
{
	int i,j,k,x;

	int temp[n];
	int actseq[n];

	temp[0] = 0;
	actseq[0] = -1;
	int cond;

	// main code 
	for (i=1;i<n;i++)
	{
		cond=0;
		for (j=0;j<i;j++)
		{
			if (i <= (j+a[j]))
			{
				if (cond==0)
				{
                 temp[i] = temp[j]+1;
                 actseq[i] = j;
                 cond=1;
				}
				else
				{
                 if ((temp[j]+1)<temp[i])
                 {
                 	temp[i]=temp[j]+1;
                 	actseq[i]=j;
                 }
				}
			}
		}
	}
	cout<<endl;
	cout<<" answer --- "<<temp[n-1]<<endl;
	cout<<endl;

	// printing the temp and act array 
	cout<<" printing the temp array -- "<<endl;
	for (i=0;i<n;i++)
		cout<<temp[i]<<" ";
	cout<<endl;
	cout<<" printing the actseq array -- "<<endl;
	for (i=0;i<n;i++)
		cout<<actseq[i]<<" ";
	cout<<endl;

	vector<int> vpath;

	x=n-1;

	while(true)
	{
		vpath.push_back(x);
		x=actseq[x];

		if (x==-1)
			break;
	}

	// printing the path for minimum number of jumps to reach end point
	cout<<" printing the path for minimum number of jumps to reach end point -- "<<endl;
	for (i=vpath.size()-1;i>=0;i--)
	{
		if (i==0)
			cout<<vpath[i]<<endl;
		else
			cout<<vpath[i]<<" --> ";
	}

	cout<<endl;

	return temp[n-1];
}

int main()
{
	int i,j;

	// int a[] = {2,3,1,1,2,4,2,0,1,1};
	// int a[] = {3,2,4,2,0,3,2,1};

	int a[] = {1,3,1,1,5,1,4,4,1,1,2,3,2,1,1};
	int n = sizeof(a)/sizeof(a[0]);

	cout<<" minimum number of jumps to reach end point "<<endl;
	cout<<" size of the array -- "<<n<<endl;
	cout<<" elements of the array -- "<<endl;
	for (i=0;i<n;i++)
	 cout<<a[i]<<" ";
	cout<<endl;
	
	int answer = minimumJumpToReachEnd(a,n);

	cout<<" final answer = "<<answer<<endl; 
}