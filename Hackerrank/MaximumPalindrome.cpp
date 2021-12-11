#include <iostream>
#include <vector>
#include <string>
using namespace std;

long long fact[100005];
long long stable[26][100005];


void initialize(string s)
{
  long long i,j,k;
  long long mod=1000000007;

  for(i=0;i<100005;i++)
  {
      if(i==0)
      fact[i]=1;
    else
    fact[i]=(fact[i-1]*i)%mod;     
  }

  for(j=0;j<s.size();j++)
  {
      k=s[j]-97;

      for(i=0;i<26;i++)
      {
          if(j==0)
          {
          if(i==k)
              stable[i][j]=1;
          else
              stable[i][j]=0;
          }
          else
          {
          if(i==k)
              stable[i][j]=stable[i][j-1]+1;
          else
              stable[i][j]=stable[i][j-1];
          }

        //   if(stable[i][j]!=0 && i==k)
        //       cout<<"for j = "<<j<<" char = "<<s[j]<<" at i = "<<i<<" val = "<<stable[i][j]<<endl;
      }
  }

//   cout<<"case 1"<<endl;
}

long long gcdex(long long a,long b,long long *x,long long *y)
{
  if(a==0)
  {
   *x=0; *y=1;
    return b;
  }

  long long x1,y1;

  long long g = gcdex(b%a,a,&x1,&y1);

  *x=y1-((b/a)*x1);
  *y=x1;
  
  // cout<<"*x1 = "<<(*x)<<" , *y1 = "<<(*y)<<endl;

  return g;
}

long long moddiv(long long a,long long b,long long m)
{
    long long x,y;
    long long g = gcdex(b,m,&x,&y);

    x=(x%m+m)%m;
  
    long long result = (a * x)%m;

    return result;
}

long long answerQuery(string s,long long l,long long r)
{
  long long i,j,k;
  long long mod = 1000000007;

  long long u,v,x,y,z;

  long long left=l-1;
  long long right=r-1;
  

  long long even=0;
  long long  odd=0;
  long long rem,quot;

  long long denoval,numval;
  long long ans;
  long long result;

  vector<long long> deno;

  for(i=0;i<26;i++)
  {

      if(left==0)
    v=stable[i][right];
    else
    {
        v=stable[i][right]-stable[i][left-1];
        
        // if(v!=0)
        // cout<<"case k "<<stable[i][right]<<" "<<stable[i][left-1]<<endl;
    }

    quot=v/2;
    even+=quot;

    rem=v%2;
    odd+=rem;

    if(quot>1)
    {
      deno.push_back(quot);

    //   cout<<"case 1 for i = "<<i<<" ,v = "<<v<<" quot = "<<quot<<" ,rem = "<<rem<<endl; 
    }        


  }

  denoval=1;

  if(deno.size()!=0)
  {
      for(i=0;i<deno.size();i++)
      {
          u=deno[i];
          denoval=(denoval * fact[u])%mod;
      }
  }


  if(even==0)
  {
    result=odd;
  }
  else
  {
    if(odd==0)
    {
     numval=fact[even];
     ans = moddiv(numval,denoval,mod);
     result = ans;
    }
    else
    {
     numval = fact[even];
     ans = moddiv(numval,denoval,mod);
     ans = (ans * odd)%mod;
     result = ans;
    }

  }

//   cout<<"denoval = "<<denoval<<" , even = "<<even<<" ,odd = "<<odd<<", result = "<<result<<endl;

  return result;
}

int main()
{
	string s = "week";

	

	initialize(s);

	vector<int> l={1,2};
	vector<int> r={4,3};

	for(int i=0;i<l.size();i++)
	{
		long long result = answerQuery(s,l[i],r[i]);
        
        cout<<endl;
		cout<<"for i = "<<" for l = "<<l[i]<<" r = "<<r[i]<<" , answer = "<<result<<endl;
		cout<<endl;
	}

    cout<<endl;

}