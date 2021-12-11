#include <iostream>
#include <vector>

using namespace std;

long long gcdex(long long a,long long b,long long *x,long long *y)
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

long long shortPalindrome(string s) {

  long long mod=1000000007;

  long long i,j,k,m,u,v;
  long long fact[1000005];
  long long sz = s.size();

  long long stable[26][sz];
  long long atdance[26]={0};

  vector<long long> aprst;
  vector<long long> alpos[26];

  for(i=0;i<1000005;i++)
  {
    if(i==0)
      fact[i]=1;
    else
      fact[i]=(i*fact[i-1])%mod;
  }


  for(i=0;i<sz;i++)
  {
    u=s[i]-97;

    if(atdance[u]==0)
    {
      aprst.push_back(u);
      atdance[u]=1;
    }

      alpos[u].push_back(i);

    for(j=0;j<26;j++)
    {
      if(i==0)
      {
        if(j==u)
          stable[j][i]=1;
        else
          stable[j][i]=0;
      }
      else
      {
       if(j==u)
        stable[j][i]=stable[j][i-1]+1;
       else
        stable[j][i]=stable[j][i-1];

      }
    }
  }

  for(i=0;i<aprst.size();i++)
  {
    u = aprst[i];
    cout<<"for alpha = "<<u<<endl;

    for(j=0;j<sz;j++)
      cout<<stable[u][j]<<" ";

    cout<<endl;

    for(j=0;j<alpos[u].size();j++)
      cout<<alpos[u][j]<<" ";

    cout<<endl;
    cout<<endl;
  }

  long long sum=0;
  long long rem,quot;
  long long alpcnt;
  long long v1,v2,v3,v4,v5;
  long long u1,u2,u3,u4,u5;
  long long spc,pos1,pos2,pos3;

  for(i=0;i<aprst.size();i++)
  {
    v=aprst[i];

    if(alpos[v].size()>=4)
    {
     alpcnt=alpos[v].size();
     v1=fact[alpcnt]; 
     v2=fact[alpcnt-4];
     v3=fact[4];

     v4=(v2*v3)%mod;

     v5=moddiv(v1,v4,mod);

     sum=(sum+v5)%mod;

     // cout<<"case 1 - for v = "<<v<<" ,v5 = "<<v5<<" ,alpcnt = "<<alpcnt<<" , sum = "<<sum<<endl;
    }

    if(alpos[v].size()>=2)
    {

      for(j=0;j<alpos[v].size()-1;j++)
      {
        for(k=j+1;k<alpos[v].size();k++)
        {
          spc=alpos[v][k]-alpos[v][j];

          if(spc>2)
          {
            pos1=alpos[v][k]; 
            pos2=alpos[v][j];

            for(m=0;m<aprst.size();m++)
            {
              u=aprst[m];

              if(u!=v)
              {
                alpcnt=stable[u][pos1]-stable[u][pos2];

                if(alpcnt>=2)
                {
                  u1=fact[alpcnt];
                  u2=fact[alpcnt-2];
                  u3=fact[2];
                  u4=(u2*u3)%mod;

                  u5=moddiv(u1,u4,mod);

                  sum=(sum+u5)%mod;

                  // cout<<"case 2 - for v = "<<v<<" ,for u = "<<u<<" ,u5 = "<<u5<<" ,alpcnt = "<<alpcnt<<" , sum = "<<sum<<endl;

                }

              }
            }
          }


        }
      }
    }


    
  }


  // cout<<"final sum = "<<sum<<endl;




  // cout<<"in the function"<<endl;


return sum;
}

int main()
{
 // string s = "kkkkkkz";

  // string s = "abbaab";

 string s = "akakak";

 long long result = shortPalindrome(s);

 cout<<"result = "<<result<<endl; 

}