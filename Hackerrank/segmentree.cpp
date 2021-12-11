#include <iostream>
#include <vector>

using namespace std;
// implementation of segment tree in a simple way for sum query


int getsum(vector<int>& stree,int nsz, int l,int r)
{
	int sval=0;

	l=nsz-1+l;
	r=nsz-1+r;

	while(l<=r)
	{   
		if(l%2==1)
			sval+=stree[l++];

		if(r%2==0)
			sval+=stree[r--];

		l=l/2;
		r=r/2;

		if(l<r)
			break;
	}

	return sval;
}

void update(vector<int> &stree,int valch,int pst,int nsz)
{
	pst=pst+nsz-1;

	while(pst>=1)
	{
		stree[pst]+=valch;
		pst=pst/2;
	}
}



int main()
{
 vector<int> a={1,2,3,4,5};

 int i,j,k,u,v,x,y;

 int sz = a.size();

 int nsz = 1;

 while(sz>nsz)
 	nsz=nsz<<1;

for(i=0;i<(nsz-sz);i++)
	a.push_back(0);

vector<int> stree(2*nsz,0);

for(i=0;i<nsz;i++)
	stree[nsz+i]=a[i];

for(i=nsz-1;i>=1;i--)
	stree[i]=stree[2*i]+stree[2*i+1];

cout<<"array given :-"<<endl;

for(i=0;i<a.size();i++)
	cout<<a[i]<<" ";

cout<<endl;
cout<<endl;

for(i=1;i<stree.size();i++)
  cout<<stree[i]<<" ";

cout<<endl;

vector<int> left={1,2,3,4};
vector<int> right={3,4,5,4};

for(i=0;i<left.size();i++)
{
	int ans=getsum(stree,nsz,left[i],right[i]);
	cout<<"for i = "<<(i+1)<<" left = "<<left[i]<<" ,right = "<<right[i]<<" , ans = "<<ans<<endl;
}


vector<int> pos={5,4,2,1,3};
vector<int> val={3,5,3,2,9};

for(i=0;i<pos.size();i++)
{
	int pst=pos[i];

	int valch = val[i]-a[pst-1];

	a[pst-1]=val[i];

	update(stree,valch,pst,nsz);
}

cout<<endl;

for(i=0;i<a.size();i++)
	cout<<a[i]<<" ";

cout<<endl;
cout<<endl;

for(i=1;i<stree.size();i++)
  cout<<stree[i]<<" ";


}