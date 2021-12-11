// Array manipulation

#include <iostream>
#include <vector>
using namespace std;

long arrayManipulation(int n, vector<vector<int> > queries) {

	long i,j,max;
	long sld;
    long low,upp,val;

	vector<long> cont(n,0);
	vector<long> adder(n,0);
	vector<long> subt(n,0);

	cout<<cont.size()<<adder.size()<<subt.size()<<endl;

	for(i=0;i<queries.size();i++)
	{
     low=queries[i][0]-1;  upp=queries[i][1]-1; val=queries[i][2];

     adder[low]+=val; subt[upp]+=val;
	}

	for(i=0;i<adder.size();i++)
	{
		cout<<adder[i]<<" \t"<<subt[i]<<endl;
	}

	sld=0;
	max=-1;

	for(i=0;i<cont.size();i++)
	{
      if(adder[i]!=0)
      	sld+=adder[i];

      cont[i]=sld;

      if(max<sld)
      	max=sld;



      if(subt[i]!=0)
      	sld-=subt[i];
	}

	
	cout<<"max = "<<max<<endl;

return max;

}

int main()
{
 // int n=10;

 // int a1[3]={1,5,3};
 // int a2[3]={4,8,7};
 // int a3[3]={ 6,9,1};

 int n=5;

 int a1[3]={1,2,100};
 int a2[3]={2,5,100};
 int a3[3]={ 3,4,100};

 vector<int> v1(a1,a1+3);
 vector<int> v2(a2,a2+3);
 vector<int> v3(a3,a3+3);



 vector<vector<int> > queries;

 queries.push_back(v1);
 queries.push_back(v2);
 queries.push_back(v3);


 long result =  arrayManipulation(n,queries);
 
 cout<<result<<endl;

}