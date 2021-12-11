#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;

// dynamic programming video 6
// coin change top down - minimum number of coin to form particular value

int coinChangeTopDown(int coin[],int tval,int n,map<int,int> mpcoin)
{
 int i,j,k,min,val,answer;

 if (tval == 0)
 	return 0;

 min = pow(2,8*sizeof(int)-1)-1;

 map<int,int>::iterator it;

 it=mpcoin.find(tval);

 if(it != mpcoin.end())
 	return it->second;

 for (i=0;i<n;i++)
 {
 	if (coin[i]>tval)
 	{
 		continue;
 	}

 	val = coinChangeTopDown(coin,tval-coin[i],n,mpcoin);

 	if(val<min)
 		min=val;
 }

 min = (min == pow(2,8*sizeof(int)-1)-1 ? (0) : (min+1));


 cout<<"tval - "<<tval<<" , count - "<<min<<endl;
 mpcoin[tval]=min;

 return min;
}


int main()
{
	int coin[] = {2,3,4,5,8};
	int n = 5;
	int tval = 10;
	map<int,int> mpcoin;
	int answer = coinChangeTopDown(coin,tval,n,mpcoin);
	cout<<"answer - "<<answer<<endl;



}