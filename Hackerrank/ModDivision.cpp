#include <iostream>
#include <vector>

using namespace std;

// notes work only when m is prime

int gcdex(int a,int b,int *x,int *y)
{
  if(a==0)
  {
   *x=0; *y=1;
    return b;
  }

  int x1,y1;

  int g = gcdex(b%a,a,&x1,&y1);

  *x=y1-((b/a)*x1);
  *y=x1;
  
  // cout<<"*x1 = "<<(*x)<<" , *y1 = "<<(*y)<<endl;

  return g;
}

int moddiv(int a,int b,int m)
{
	int x,y;
	int g = gcdex(b,m,&x,&y);

    x=(x%m+m)%m;
  
	int result = (a * x)%m;

	return result;
}

int main()
{
	int a=3,b=3,m=1000000007;

	int result = moddiv(a,b,m);

	cout<<result<<endl;


}