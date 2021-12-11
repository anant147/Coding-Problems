#include <iostream>
#include <vector>

using namespace std;

int max(int val1,int val2)
{
	if(val1>val2)
		return val1;
	else
		return val2;
}

vector<int> maxSlidingWindow(vector<int>& nums,int k)
{
    int i,j,u,v,x,y;

    int sz = nums.size();

    int logval[sz+1];

    for(i=0;i<=sz;i++)
    {
    	if(i==0 || i==1)
    		logval[i]=0;
    	else
    		logval[i]=logval[i/2]+1;
    }

    int col=sz;
    int row=logval[sz]+1;

    int maxstor[row][col];

    int curlen;

    for(i=0;i<=logval[sz];i++)
    {
    	curlen=1<<i;

    	for(j=0;(j+curlen)<=sz;j++)
    	{
    		if(curlen==1)
    			maxstor[i][j]=nums[j];
    		else
    			maxstor[i][j]=max(maxstor[i-1][j],maxstor[i-1][j+(curlen/2)]);

    	}
    }

    vector<int> result;

    int left=0; 
    int right=k-1;

    for(i=0;i<=(sz-k);i++)
    {
    	int p = logval[k];
    	int plen = 1<<p;

    	int m = max(maxstor[p][left],maxstor[p][right-plen+1]);

    	result.push_back(m);

    	left++;
    	right++;
    }

	vector<int> result1={0};

    return result;
}


int main()
{
	vector<int> arr= {1,3,-1,-3,5,3,6,7};
	int k=3;

	vector<int> result = maxSlidingWindow(arr,k);

	for(int i=0;i<result.size();i++)
		cout<<"for i = "<<(i+1)<<" val = "<<result[i]<<endl;
}
