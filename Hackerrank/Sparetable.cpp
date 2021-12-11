#include <iostream>
#include <vector>

using namespace std;

//  program of sparse table

int min(int val1,int val2)
{
	if(val1<val2)
		return val1;
	else
		return val2;
}

vector<int> minval(vector<int> & arr,vector<int> & left,vector<int> & right)
{
 int i,j,k,u,v,x,y,row;

 int sz = arr.size();

 int logval[sz+1];

 for(i=0;i<=sz;i++)
 {
 	if(i==0 || i==1)
 		logval[i]=0;
 	else
 		logval[i]=logval[i/2]+1;
 }

 int col=sz;
 row=logval[sz]+1;

 int minstor[row][col]={0};

 int curlen;
 
 for(i=0;i<=logval[sz];i++)
 {
 	curlen = 1<<i;

 	for(j=0;(j+curlen)<=sz;j++)
 	{
 		if(curlen==1)
 			minstor[i][j]=arr[j];
 		else
 			minstor[i][j]=min(minstor[i-1][j],minstor[i-1][j+(curlen/2)]);
 	}
 }

 vector<int> result; 

 for(i=0;i<left.size();i++)
 {
  int l1=left[i];
  int r1=right[i];

  int len = r1-l1+1;

  int p = logval[len];
  int plen = 1<<p;

  int m = min(minstor[p][l1],minstor[p][r1-plen+1]);

  result.push_back(m);
 }
  
 return result;
}


int main()
{
	vector<int> arr={1,7,2,9,3,5,8,3,7};

	vector<int> left={0,3,2,5,8,5};
	vector<int> right={7,5,6,8,8,6};

	vector<int> result = minval(arr,left,right);

	for(int i=0;i<result.size();i++)
	{
		cout<<"for i = "<<(i+1)<<" val = "<<result[i]<<endl;
	}




}