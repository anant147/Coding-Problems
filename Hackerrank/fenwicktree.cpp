#include <iostream>
#include <vector>

using namespace std;

void add(vector<int> &tree,int val,int k,int n)
{
	int j=k;
	while(j<=n)
	{
     tree[j]+=val;

     j+=(j&(-j));
	}
}

int sum_aggre(vector<int> &tree,int k)  // getting the sum till value of k
{
	int sum=0;

	int j=k;

	while(j>=1)
	{
		sum+=tree[j];

		j-=(j&(-j));
	}

	return sum;
}

int main()
{
	vector<int> a={1,3,4,8,6,1,4,2};

	int n=a.size();

	int i,j;

	vector<int> tree(n+1,0);

    
	for(i=0;i<a.size();i++)
	{  
        add(tree,a[i],i+1,n); // adding value in the tree
	}

	for(i=0;i<n;i++)
	{
		cout<<"for i = "<<(i+1)<<" , val = "<<a[i]<<" , sum till now = "<<tree[i+1]<<endl;
	}
    
    vector<int> left = {2,4,5,3};
    vector<int> right = {6,4,8,7};

    int ans;

    for(i=0;i<left.size();i++)
    {
    	int l=left[i];
    	int r=right[i];


    	if(l==1)
    	{
         ans = sum_aggre(tree,r);
    	}
    	else
    	{
         ans = sum_aggre(tree,r)-sum_aggre(tree,l-1);
    	}

    	cout<<"for i = "<<(i+1)<<" , l = "<<l<<" , r = "<<r<<" , ans = "<<ans<<endl;
    }

    vector<int> pos={2,4,6,8};
    vector<int> valch={5,10,5,6};

    for(i=0;i<pos.size();i++)  // trying to update value in the array 
    {
    	int pos1 = pos[i];
    	int newval = valch[i];

    	int k=newval-a[pos1-1];

    	a[pos1-1]=newval;

    	add(tree,k,pos1,n);
    }

    for(i=0;i<n;i++)
	{
		cout<<"for i = "<<(i+1)<<" , val = "<<a[i]<<" , sum till now = "<<tree[i+1]<<endl;
	}



}