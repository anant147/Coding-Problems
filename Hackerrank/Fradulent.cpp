/// Hackerrank - Fradulent activity selection 

#include <iostream>
#include <vector>
using namespace std;

int getdbmed(int record[],int d)
{
	int opos,epos1,epos2,val,i,cond;

	int k1,k2,result;

	// for(i=0;i<201;i++)
	// {
	// 	if(record[i]!=0)
	// 		cout<<i<<"\t"<<record[i]<<"\t"<<endl;
	// }
	// cout<<endl;

	if(d%2==1)
	{
     opos=d/2+1;
     val=0;

     for(i=0;i<201;i++)
     {
     	if(record[i]!=0)
     	{
     		val+=record[i];

     		if(val>=opos)
     		{
     		
     			 result=(2*i);
     			  // cout<<"result = "<<result<<endl;
     			break;
     		}
     	}
     }

	}
	else
	{
       epos1=d/2;epos2=d/2+1;
       val=0;
       cond=0;

       for(i=0;i<201;i++)
       {
       	if(record[i]!=0)
       	{
          val+=record[i];
          
          if(cond==0)
          {
          	if(val>epos1 && val>=epos2)
          	{
          		result=(2*i);
          		// cout<<"result = "<<result<<endl;
          		break;
          	}
          	else if(val==epos1 && val<epos2)
          	{
          		cond=1;k1=i;
          	}
          }
          else if(cond==1)
          {
             if(val>=epos2)
             {
             	k2=i;
             	result=(k1+k2);
             	// cout<<"result = "<<result<<endl;
             	break;
             }
          }

       	}
       }
	}
    
    return result;

}

int activityNotifications(vector<int> expenditure, int d) 
{
 int i,j,record[201],notification,expsize;
 int dbmed,k;

 for(i=0;i<201;i++)
 	record[i]=0;

 notification=0;

 for(i=0;i<expenditure.size();i++)
 {
 	if(i<d)
 	{
 		record[expenditure[i]]++;
 	}
 	if(i>=d)
 	{
      dbmed = getdbmed(record,d);
      
      if(expenditure[i]>=dbmed)
      	notification++;

      record[expenditure[i]]++;

      record[expenditure[i-d]]--;
 	}
 }

 // cout<<"notification = "<<notification<<endl;
 
 return notification;
}


int main()
{
	// int d=5;
	// int a[9]={2,3,4,2,3,6,8,4,5};

	// vector <int> expenditure(a,a+9);
    
    int d=4;
	int a[5]={1,2,3,4,4};
	vector <int> expenditure(a,a+5);
      
    cout<<d<<endl;
    for(int i=0;i<expenditure.size();i++)
    	cout<<expenditure[i];

    cout<<endl;
    
    int result = activityNotifications(expenditure, d);

    cout<<result<<endl;
}