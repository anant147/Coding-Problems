// Maximum Subarray Sum

// Given an n element array of integers,a , and an integer, m, determine the maximum value of the sum of any of its subarrays modulo m

#include <iostream>
#include <vector>
using namespace std;

long long maxval(long long val1,long long val2)
{
	if(val1<val2)
		return val2;
	else 
		return val1;
}

long long maxSubCrossMod(vector<long long> v,long long st,long long mid,long long ed,long long m)
{
	long long i,j,k,lsum,rsum,sum;

   	lsum = -1;
	sum = 0;

	for(i = mid;i>=st;i--)
	{
		sum = (sum + v[i])%m;

		if(sum > lsum)
			lsum = sum;

		if (lsum == (m-1))
			break;
	}

	long long lsum2 = -1;
	sum = 0;

	for (i=st;i<=mid;i++)
	{
		sum = (sum + v[i])%m;

		if (sum > lsum2)
			lsum2 = sum;

		if (lsum2 == (m-1))
			break;
	}



	rsum =-1;
    sum = 0;

    for (i=mid+1;i<=ed;i++)
    {
    	sum = (sum + v[i])%m;

    	if(sum > rsum)
    		rsum = sum;

    	if (rsum == (m-1))
    		break;
    }


    long long rsum2 = -1;
    sum = 0;

    for (i=ed;i>=(mid+1);i--)
    {
    	sum = (sum + v[i])%m;

    	if (sum > rsum2)
    		rsum2 = sum;

    	if (rsum2 == (m-1))
    		break;
    }

    if(lsum==(m-1) || rsum == (m-1) || lsum2 == (m-1) || rsum2 == (m-1))
    	return (m-1);
    else
    {
    	long long tsum = (lsum+rsum)%m;

    	long long lrsum = lsum;
        long long nsum = lsum;

        for (i=mid+1;i<=ed;i++)
        {
        	nsum = (nsum + v[i])%m;

        	if (nsum > lrsum)
        		lrsum = nsum;

        	if (lrsum == (m-1))
        		break;
        }

        long long rlsum = rsum;
        nsum = rsum;

        for (i=mid;i>=st;i--)
        {
        	nsum = (nsum+v[i])%m;

        	if (nsum > rlsum)
        		rlsum=nsum;

        	if (rlsum == (m-1))
        		break;
        }

        return maxval(lsum2,maxval(rsum2,maxval(tsum,maxval(lrsum,rlsum))));
    }
}

long long maxSubArrayMod(vector<long long> v,long long st,long long ed,long long m)
{
 long long mid = (st+ed)/2;

 if (st==ed) // start and end point are equal then equal
 {
   // cout<<"cond 1"<<endl;
   return v[st];
 }
 else if ((ed - st) == 1) // two elements are in given range
 {
   long long s1 = (v[st]+v[ed])%m;
   // cout<<"cond 2"<<endl;

   return maxval(s1,maxval(v[st],v[ed]));
 }
 else if ((ed - st) == 2) // three elements are in given range
 {
  long long s2 = (v[st]+v[st+1])%m;
  long long s3 = (v[st+1]+v[ed])%m;
  long long s4 = (v[st]+v[st+1]+v[ed])%m;

  // cout<<"cond 3"<<endl;

  return  maxval(s4,maxval(s3,maxval(s2,maxval(v[st+1],maxval(v[st],v[ed])))));
 }
 else // more than 3 elements are present in given range.
 {

   // cout<<"cond 4"<<endl;

   long long s5 = maxSubArrayMod(v,st,mid,m);
   long long s6 = maxSubArrayMod(v,mid+1,ed,m);
   long long s7 = maxSubCrossMod(v,st,mid,ed,m);

   return maxval(s5,maxval(s6,s7));
 }

}

long long maximumSum(vector<long long> v, long long m)
{
	long long i,j,k;
	long long n = v.size();

	long long ans =-1;

	for(i=0;i<n;i++)
	{
		v[i] = (v[i])%m;

		if(v[i]==(m-1))
		{
         ans = m-1;
         break;
		}
	}

	if (ans== -1)
		ans = maxSubArrayMod(v,0,n-1,m);

	// cout<<"final answer -- "<<ans<<endl;

	return ans;
}

int main()
{
	long long a[5] = {3,3,9,9,5};

	vector<long long> v(a,a+5);

	long long m = 7;



	long long ans = maximumSum(v,m);

	cout<<ans<<endl;
}