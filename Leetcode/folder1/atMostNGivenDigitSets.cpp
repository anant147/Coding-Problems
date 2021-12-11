#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

int binsearch(vector<int>& num1,int N)
{
	int st,ed,mid;
	int val = (N/10)+1;

	st=0;
	ed=num1.size()-1;

	while(st<=ed)
	{
     mid = (st+ed)/2;

     if (num1[mid]==val)
     	return mid;
     else if (num1[mid]<val)
     	st=mid+1;
     else
     	ed=mid-1;
	}

	return mid;
}

int atMostNGivenDigitSet1(vector<string>& D, int N)
{
	 int i,j,k,u,v,x,y,p,q,r,s,pos;

	 int total = 0;
	 int m = N;
	 int cond=0;
        
    // r = pow(10,9);    

	while (m!=0)
	{
		m=m/10;
		total++;
	}

	// cout<<"total digit -- "<<total<<endl;

	vector<int> digit;

	for (i=0;i<D.size();i++)
	{
		string str = D[i];
        
        k=0;
		for (j=0;j<str.size();j++)
		{
			k=k*10+int(str[j]-48);
		}
		digit.push_back(k);

	}

	sort(digit.begin(),digit.end());
	int dsize = digit.size();

	// cout<<" size -- "<<digit.size()<<endl;

	vector< int> num1;
	vector< int> num2;

	int tsum=0;

	for (i=0;i<total;i++)
	{
		if (i==0)
		{
          for (j=0;j<digit.size();j++)
          {
          	if (digit[j]<=N)
          	{
          		tsum++;
          		num1.push_back(digit[j]);
          	}
          	else
          		break;
          }
		}
		else if (i==total-1)
		{
          pos = binsearch(num1,N);

          for (j=pos;j>=0;j--)
          {
          	u=num1[j];

          	if (u<=100000000)
          	{
          		v=u*10;
          		y=v+digit[dsize-1];

          		if (y<=N)
          		{
          			cond=1;
          			tsum=tsum+((j+1)*dsize);
          			break;
          		}
          		else
          		{
          			for (k=0;k<digit.size();k++)
          			{
          				x=v+digit[k];

          				if (x<=N)
          					tsum++;
          				else
          					break;
          			}
          		}
          	}
          	else
          		break;

          	if (cond==1)
          		break;
          }
		}
		else
		{
          for (j=0;j<num1.size();j++)
          {
          	u=num1[j];

          	if (u<=100000000)
          	{
          	  v=u*10;	
              for (k=0;k<digit.size();k++)
              {
              	x=v+digit[k];

              	if (x<=N)
              	{
              		tsum++;
              		num2.push_back(x);
              	}
              	else
              		break;
              }
          	}
          	else
          		break;
          }

          num1.clear();
          num1=num2;
          num2.clear();
		}
	}
	
	return tsum;
}

int atMostNGivenDigitSet2(vector<string>& D, int N)
{

	 int i,j,k,u,v,x,y,p,q,r,s,pos;

	 int total = 0;
	 int m = N;
	 int cond=0;
        
    // r = pow(10,9);

    vector<int> nval;    

	while (m!=0)
	{
		u=m%10;
		m=m/10;
		nval.push_back(u);
		total++;
	}

	int ndig[total];

	for (i=0;i<total;i++)
	{
		ndig[i]=nval[total-1-i];
	}
	// cout<<"total digit -- "<<total<<endl;

	vector<int> digit;
	int flag[10]={0};
	int count[10]={0};


	for (i=0;i<D.size();i++)
	{
		string str = D[i];
        
        k=0;
		for (j=0;j<str.size();j++)
		{
			k=k*10+int(str[j]-48);
		}
		if (k<=N)
		{
			digit.push_back(k);
			flag[k]=1;
		}
	}

	for (i=1;i<10;i++)
	{
		if (flag[i]==0)
			count[i]=count[i-1];
		else
			count[i]=count[i-1]+1;
	}

	// cout<<" printing flag array -- "<<endl;
	// for (i=0;i<10;i++)
	// 	cout<<flag[i]<<" ";
	// cout<<endl;

	// cout<<" printing count array -- "<<endl;
	// for (i=0;i<10;i++)
	// 	cout<<count[i]<<" ";
	// cout<<endl;

	// cout<<" printing ndig array -- "<<endl;
	// for (i=0;i<total;i++)
	// 	cout<<ndig[i]<<" ";
	// cout<<endl;

	sort(digit.begin(),digit.end());
	int dsize = digit.size();

	if (total==1)
		return dsize;

	int tsum=0;

	for (i=1;i<=total;i++)
	{
      if (i!=total)
      {
      	tsum=tsum+pow(dsize,i);
      }
      else
      {
       for (j=0;j<total;j++)
       {
	       	x=ndig[j];

	       	if (x==0)
	       		break;

	       	u=count[x];

	       	if (j==total-1)
	       	{
	       		tsum=tsum+u;
	       	}
	       	else if (flag[x]==0)
	       	{
	       	  tsum=tsum+(u*pow(dsize,total-1-j));
	       	  break;
	       	}
	       	else
	       	{
	       		if (u>1)
	       		{
	       			v=u-1;
	       			tsum=tsum+(v*pow(dsize,total-1-j));
	       		}
	       	}
       } 
      }

	}
	return tsum;
}

int main()
{
	// vector<string> D = {"1","3","5","7"};
	// int N = 100;

	// vector<string> D = {"1","4","9"};
	// int N = 1000000000;

	// vector<string> D = {"3","5"};
	// int N = 4;

	// vector<string> D = {"3","4","5","7","8","9"};
 //    int N = 819407090;

	// vector<string> D = {"1","2","3","4","5","6","7","8","9"};
	// int N = 899894860;

	// vector<string> D = {"5","7","8"};
	// int N = 59;

	vector<string> D ={"1","7"};
	int N = 231;

	cout<<" 902. Numbers At Most N Given Digit Set "<<endl;
	int k = D.size();
	cout<<" digits given -- "<<endl;
	for (int i=0;i<k;i++)
	cout<<D[i]<<" ";
	cout<<endl;

	cout<<" N = "<<N<<endl;

	// int answer1 = atMostNGivenDigitSet1(D,N);

	// cout<<" answer1 = "<<answer<<endl;

	// cout<<pow(2,5)<<endl;

	int answer2 = atMostNGivenDigitSet2(D,N);



	cout<<" answer2 = "<<answer2<<endl;
}