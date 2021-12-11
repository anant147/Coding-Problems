#include <iostream>
#include <vector>
using namespace std;

// dynamic programming video 23
//  maximum increasing subsequence  problem - find the maximum increasing subsequence of the given n elements i.e. sum of increasing subsequence is maximum
// time complexity - o (n * n)
// space complexity - o ( n )

int maxval(int a,int b)
{
	if (a<b)
		return b;
	else
		return a;
}

int maximumIncreasingSubsequence(int a[],int n)
{
	int i,j,k,u,v,answer,val;

	int temp[n];
	int tracer[n];
	int lenarr[n];


    // initializing the value of various array
	for (i=0;i<n;i++)
	{
		temp[i]=a[i];
		tracer[i]=i;
		lenarr[i]=1;
	}


	for (i=1;i<n;i++)
	{
		for (j=0;j<i;j++)
		{
			if (a[j]<a[i])
			{
				if (temp[i] < (temp[j]+a[i]) )
				{
					temp[i]=temp[j]+a[i];
					tracer[i]=j;
					lenarr[i]=lenarr[j]+1;
				}
			}
		}
	}

    int max=0;
    int index=-1;

    for (i=0;i<n;i++)
    {
    	if (max < temp[i])
    	{
    		max = temp[i];
    		index = i;
    	}
    }

    // printing the temp , tracer , lenarr array
     
    cout<<" printing the temp array "<<endl;
    for (i=0;i<n;i++)
    	cout<<temp[i]<<" ";
    cout<<endl;

    cout<<" printing the tracer array "<<endl;
    for (i=0;i<n;i++)
    	cout<<tracer[i]<<" ";
    cout<<endl;

    cout<<" printing the lenarr array "<<endl;
    for (i=0;i<n;i++)
    	cout<<lenarr[i]<<" ";
    cout<<endl;
    
    // tracing the elements that contribute to maximum increasing subsequence
    vector<int> velem;
    vector<int> vindex;

    int mindex = index;
   
    while(true)
    {
    	velem.push_back(a[index]);
    	vindex.push_back(index);

    	if (tracer[index]==index)
    		break;
    	else
    	{
    		index=tracer[index];
    	}
    }

    cout<<endl;
    cout<<" elements in the maximum increasing subsequence of given array --- "<<endl;

    for ( i=velem.size()-1;i>=0;i--)
    	cout<<"element val = "<<velem[i]<<" at index = "<<vindex[i]<<endl;
    cout<<endl;

    cout<<" maximum value of increasing subsequence = "<<max<<" , end at index "<<mindex<<" and is  of length "<<lenarr[mindex]<<endl;

	return max;
}

int main()
{
	int i,j;

	// int n=7;
	// int a[7] = {4,6,1,3,8,4,6};

	int n = 9;
	int a[n]={1,3,2,4,6,7,1,2,4};

	cout<<" maximum increasing subsequence problem "<<endl;
	cout<<" size of elements -- "<<n<<endl;
	cout<<" elements of the array -- "<<endl;
	for (i = 0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;

	int answer = maximumIncreasingSubsequence(a,n);

	cout<<" answer = "<<answer<<endl; 
}