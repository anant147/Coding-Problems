#include<iostream>
#include<vector>
#include<cstring>
#include<utility>
#include<algorithm>
using namespace std;

int numDecodings(string s)
{
  int i,j,k,u,v,x,y,z,answer;

  int n = s.length();

  if(n==0)
  	return 0;

  int ways[n];

  for (j=0;j<n;j++)
  {
  	if (s[j]=='0')
  		return 0;
  	else
  		break;
  }
  // cout<<"j = "<<j<<endl;

  ways[0]=1;
  // j++;

  for (i=1;i<n;i++)
  {
  	x=(int)s[i-1]-48;
  	y=(int)s[i]-48;
  	z=x*10+y;

  	if (z%10 == 0)
  	{
  		k=z/10;

  		if (k!=1 && k!=2)
  			return 0;
  	}
  	// cout<<" x = "<<x<<endl;

    if (s[i-1]=='0' && s[i]=='0')
    	return 0;
  	else if (i==1)
  	{
  		if (z>26 || z==10 || z==20)
  		{
         ways[i]=ways[i-1];
  		}
  		else
  			ways[i]=ways[i-1]+1;
  	}
  	else
  	{
  		u = (int)s[i-2]-48;
  		v = u*10+x;
         
        if (z==10 || z==20)
        	ways[i]=ways[i-2]; 
  		else if (z>26 ||v==10 || v==20)
  			ways[i]=ways[i-1];
  		else
  			ways[i]=ways[i-1]+ways[i-2];
  	}
  }

  // // print ways array --
  // cout<<" printing ways array -- "<<endl;
  // for (i=0;i<n;i++)
  // 	cout<<ways[i]<<" ";
  // cout<<endl;

  return ways[n-1];
}

int main()
{
	// string s = "12";
	// string s = "226";
	// string s = "2265";
	// string s = "0";
	// string s = "10";
	// string s = "01";
	// string s = "100";
	// string s = "101";
	// string s = "110";
	string s = "230";
	cout<<" ways of decodings -- "<<endl;
	cout<<" string s = "<<s<<endl;

	int answer = numDecodings(s);
	cout<<"answer = "<<answer<<endl;
}