#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;

int maxval(int a,int b)
{
	if (a<b)
		return b;
	else
		return a;
}

int maxval3(int a,int b,int c)
{
	return maxval(a,maxval(b,c));
}

int getMaxSeq1(int *temp,int n,int m,int p,int q)
{
	int k = *((temp+p*m)+q);
	// cout<<" k = "<<k<<endl;

	if (k>0)
	{
		if (p==0 || q==0)
			return k;
		else
			return maxval3(k+getMaxSeq1(temp,n,m,p-1,q-1), getMaxSeq1(temp,n,m,p,q-1), getMaxSeq1(temp,n,m,p-1,q));
	}
	else
	{
		if (p==0 && q==0)
			return 0;
		else if (p==0)
			return getMaxSeq1(temp,n,m,p,q-1);
		else if (q==0)
			return getMaxSeq1(temp,n,m,p-1,q);
		else
			return maxval3(getMaxSeq1(temp,n,m,p-1,q-1), getMaxSeq1(temp,n,m,p,q-1), getMaxSeq1(temp,n,m,p-1,q));
	}
}

int getMaxSeq(int *temp,int *rtemp,int n,int m,int p,int q,int maximum)
{
	int i,j,k,u,v,x,y,answer;

	for (i=0;i<n;i++)
	{
		k = *(temp+i*m);
		if (i==0)
		{
			if (k<=0)
				*(rtemp + i*m) = 0;
			else
				*(rtemp + i*m) = k;
		}
		else
		{
			u = *(rtemp + (i-1)*m);
			if (k<=0)
				*(rtemp + i*m) = u;
			else
				*(rtemp + i*m) = maxval(u,k);
		}
	}

	for (i=1;i<m;i++)
	{
		k=*(temp + i);
		u=*(rtemp + i -1);

		if (k<=0)
			*(rtemp + i) = u;
		else
			*(rtemp + i) = maxval(u,k);
	}

	for (i=1;i<n;i++)
	{
		for (j=1;j<m;j++)
		{
			k = *((temp + i*m) + j);

			u = *((rtemp + (i-1) * m ) + (j-1));
			v = *((rtemp + i*m) + (j-1));
			x = *((rtemp + (i-1)*m) + j);

			if (k<=0)
				*((rtemp + i*m ) + j) = maxval3(u,v,x);
			else
				*((rtemp + i*m ) + j) = maxval3(u+k,v,x);
		}
	}

	answer = *((rtemp + p*m)+q);

	return answer;
}



int maxDotProduct(vector<int>& nums1, vector<int>& nums2)
{
	int i,j,k,u,v,x,y,answer1,answer;

	int n = nums1.size();
	int m = nums2.size();

	int maximum = pow(2,sizeof(int)*8-1)-1;
	// cout<<" maximum = "<<maximum<<endl;

	if (n==0 || m==0)
		return 0;

	int temp[n][m];
	int rtemp[n][m];

	int max = -10000;

	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++)
		{
			temp[i][j]=nums1[i]*nums2[j];
			rtemp[i][j]=maximum;

			if (temp[i][j]>max)
				max = temp[i][j];
		}
	}

	if (max<=0)
		return max;

	// cout<<" temp matrix -- "<<endl;
	// for (i=0;i<n;i++)
	// {
	// 	for (j=0;j<m;j++)
	// 		cout<<temp[i][j]<<" ";
	// 	cout<<endl;
	// }
	// cout<<endl;

	answer = getMaxSeq((int *)temp,(int *)rtemp,n,m,n-1,m-1,maximum);

	// cout<<" answer2 -- "<<answer2<<endl;
	// cout<<endl;

	// cout<<" new rtemp matrix -- "<<endl;
	// for (i=0;i<n;i++)
	// {
	// 	for (j=0;j<m;j++)
	// 		cout<<rtemp[i][j]<<" ";
	// 	cout<<endl;
	// }
	// cout<<endl;

    return answer;
}

int main()
{
	int i,j,k;
	// vector<int> nums1 = {2,1,-2,5};
	// vector<int> nums2 = {3,0,-6};

	vector<int> nums1 = {3,-2};
	vector<int> nums2 = {2,-6,7};

	// vector<int> nums1 = {-1,-1};
	// vector<int> nums2 = {1,1};


	int n = nums1.size();
	int m = nums2.size();

	cout<<" 1458. Max Dot Product of Two Subsequences "<<endl;
	cout<<" elements  of  nums1 -- "<<endl;
	for (i=0;i<n;i++)
	cout<<nums1[i]<<" ";
	cout<<endl;

	cout<<" elements  of  nums2 -- "<<endl;
	for (i=0;i<m;i++)
	cout<<nums2[i]<<" ";
	cout<<endl;

	int answer = maxDotProduct(nums1,nums2);
	cout<<" answer = "<<answer<<endl;
}