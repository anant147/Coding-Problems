#include <iostream>
#include <vector>

using namespace std;

// for maximum

int max(int val1,int val2)
{
  if(val1 > val2)
    return val1;
  else
    return val2;
}

void buildseg(int a[],int segtree[],int v,int l,int r)
{
 if(a[l]==a[r])
 {
 	segtree[v]=a[l];
 	// cout<<"case 1"<<endl;
 }
 else
 {

 int mid = (l+r)/2;
 // cout<<"case 2"<<endl;
 buildseg(a,segtree,2*v,l,mid);
 //cout<<"case 3"<<endl;
 buildseg(a,segtree,2*v+1,mid+1,r);
 // cout<<"case 4"<<endl;

 segtree[v]=max(segtree[2*v],segtree[2*v+1]);
 // /cout<<"case 5"<<endl;
 }
}


int maximum(int a[],int segtree[],int v,int al,int ar, int ql,int qr)
{
	if(al==ql && qr == ar)
	{
		// cout<<"case 1 ,al = " <<al<<" ,ar = "<<ar<<" , ql = "<<ql<<" qr = "<<qr<<endl;
		return segtree[v];
	}
    else
    {

	int mid = (al+ar)/2;
	

	if(qr<=mid)
	{
		// cout<<"case 2 ,al = " <<al<<" ,ar = "<<ar<<" , ql = "<<ql<<" qr = "<<qr<<endl;
		int val = maximum(a,segtree,v*2,al,mid,ql,qr); 
		return val;
		
	}
	else if((mid+1)<=ql)
	{
		// cout<<"case 3 ,al = " <<al<<" ,ar = "<<ar<<" , ql = "<<ql<<" qr = "<<qr<<endl;
		int val = maximum(a,segtree,(v*2)+1,mid+1,ar,ql,qr);
		return val;
	}
	else
	{
	   // cout<<"case 4 -a ,al = " <<al<<" ,mid = "<<mid<<" , ql = "<<ql<<endl;
	   // cout<<"case 4 -b ,mid+1 = " <<mid+1<<" ,ar = "<<ar<<" qr = "<<qr<<endl;
       int val1 = maximum(a,segtree,v*2,al,mid,ql,mid);
       
       int val2 = maximum(a,segtree,v*2+1,mid+1,ar,mid+1,qr);
       int val = max(val1,val2);
       
       return val;

	 }	

    }
}

void update(int a[],int segtree[],int v,int al,int ar,int position,int value)
{
	if(al==ar)
	{
     segtree[v]=value;
	}
	else
	{
      int mid = (al+ar)/2;

      if(position<=mid)
      {
       update(a,segtree,2*v,al,mid,position,value);
      }
      else
      {
       update(a,segtree,2*v+1,mid+1,ar,position,value);
      }

      segtree[v]=max(segtree[v*2],segtree[v*2+1]);
	}
}


int main()
{
  int a[]={1,2,3,4,5,6};	
  
  int n = sizeof(a)/sizeof(a[0]);

  cout<<"n = "<<n<<endl;

  int segtree[4*n];

  buildseg(a,segtree,1,0,n-1);
  cout<<"build done "<<endl;

  vector<int> left = {0,0,3,0,3,2,1,0};
  vector<int> right = {5,2,5,1,4,4,4,4}; 

  for(int i=0;i<left.size();i++)
  {
  	int res = maximum(a,segtree,1,0,n-1,left[i],right[i]);

  	cout<<"for i = "<<i<<" left = "<<left[i]<<" , right = "<<right[i]<<" , output = "<<res<<endl;

  	cout<<endl;
  }

  vector<int> pos={0,1,2,3,4,5};
  vector<int> val={6,5,4,3,2,1};

  for(int i=0;i<pos.size();i++)
  {
  	int position=pos[i];
  	int value=val[i];

  	a[position]=value;

  	update(a,segtree,1,0,n-1,position,value);
  }
  
  cout<<endl;
  cout<<"new results :- "<<endl;
  cout<<endl;

  for(int i=0;i<left.size();i++)
  {
  	int rest = maximum(a,segtree,1,0,n-1,left[i],right[i]);

  	cout<<"for i = "<<i<<" left = "<<left[i]<<" , right = "<<right[i]<<" , output = "<<rest<<endl;

  	cout<<endl;
  }

}