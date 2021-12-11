#include<iostream>
#include<vector>
using namespace std;

// nlogn solution , out of 14,7 cases are passed.

int binsear(vector<int> eltv,int val)
{
    int low=0;
    int high=eltv.size()-1;
    int mid;
    int pos;

    while(low<=high)
    {
        mid=(low+high)/2;

        if((eltv[mid]+val)<0 && (eltv[mid+1]+val)>=0)
        {
            cout<<"case 5"<<" value obtained at pos "<<mid<<endl;
            pos=mid;
            break;
        }
        else if((eltv[mid]+val)<0)
        {
            low=mid+1;
        }
        else if((eltv[mid]+val)==0)
        {
          pos=mid-1;
          cout<<"case 5"<<" value obtained at pos "<<pos<<endl;
          break;
        }
        else
        {
            high=mid-1;
        }
    }

    return pos;
}

// Complete the playingWithNumbers function below.
vector<int> playingWithNumbers(vector<int> arr, vector<int> queries) {

int i,j,k,u,v;
 int cntneg[2005],cntpos[2005];

 for(i=0;i<2005;i++)
 {
     cntpos[i]=0;  cntneg[i]=0;
 }

 for(i=0;i<arr.size();i++)
 {
     if(arr[i]>=0)
     {
         cntpos[arr[i]]++;
     }
     else
     {
         v=arr[i]*(-1);
         cntneg[v]++;
     }
 }

 vector<int> eltv;
 vector<int> cntv;

 for(i=2000;i>=1;i--)
 {
   if(cntneg[i]!=0)
   {
       v=(-1)*i;
       eltv.push_back(v);
       cntv.push_back(cntneg[i]);
   }
 }

 for(i=0;i<2001;i++)
 {
     if(cntpos[i]!=0)
     {
         eltv.push_back(i);
         cntv.push_back(cntpos[i]);
     }
 }

 cout<<"element of vector = "<<endl;

 for(i=0;i<eltv.size();i++)
     cout<<eltv[i]<<" ";

 cout<<endl;

 cout<<"count of elements in vector = "<<endl;

 for(i=0;i<cntv.size();i++)
     cout<<cntv[i]<<" ";
 cout<<endl;

 int sz = eltv.size();

 vector<int> freltv(sz,0);
 vector<int> bckeltv(sz,0);
 vector<int> frcntv(sz,0);
 vector<int> bckcntv(sz,0);

 for(i=0;i<sz;i++)
 {
     if(i==0)
     {
      freltv[0]=eltv[0]*cntv[0];
      frcntv[0]=cntv[0];
     }
     else
     {
      freltv[i]=freltv[i-1]+(eltv[i]*cntv[i]);
      frcntv[i]=frcntv[i-1]+cntv[i];
     }
 }

 for(i=sz-1;i>=0;i--)
 {
     if(i==sz-1)
     {
      bckeltv[i]=(eltv[i]*cntv[i]);
      bckcntv[i]=cntv[i];
     }
     else
     {
      bckeltv[i]=bckeltv[i+1]+(eltv[i]*cntv[i]);
      bckcntv[i]=bckcntv[i+1]+cntv[i];
     }
 }

 for(i=0;i<sz;i++)
     cout<<freltv[i]<<" "<<bckeltv[i]<<" "<<frcntv[i]<<" "<<bckcntv[i]<<endl;


 
 int val1,val2,val3;
 int rval1,rval2,rval3,rval4,rval5;
 int rcnt1,rcnt2,rcnt3;


 val1 = 0;
 vector<int> result;

 for(i=0;i<queries.size();i++)
 {
   val1+=queries[i];
   cout<<"val1 = "<<val1<<endl;
   
   if((eltv[0]+val1)>0)  // all resultant elements will be greater than 0 
   {
    rval1 = bckeltv[0];
    rcnt1 = bckcntv[0];

    rval2 = rval1 + (rcnt1 * val1);

    if(rval2<0)
        rval2=(-1)*rval2;

    result.push_back(rval2);
    cout<<"case 1 "<<"for i = "<<i<<" value obtained = "<<rval2<<endl;
   }
   else if((eltv[0]+val1)==0) // all resultant elements except first will be greater than 0
   {
     rval1 = bckeltv[1];
     rcnt1 = bckcntv[1];

    rval2 = rval1 + (rcnt1 * val1);

    if(rval2<0)
        rval2=(-1)*rval2;

    result.push_back(rval2);
    cout<<"case 2 "<<"for i = "<<i<<" value obtained = "<<rval2<<endl;
   }
   else if((eltv[sz-1]+val1)<0) // all resultant elements are less than zero
   {
     rval1 = freltv[sz-1];
     rcnt1 = frcntv[sz-1];

     rval2 = rval1 + (rcnt1 * val1);

    if(rval2<0)
        rval2=(-1)*rval2;

    result.push_back(rval2);
    cout<<"case 3 "<<"for i = "<<i<<" value obtained = "<<rval2<<endl;
   }
   else if((eltv[sz-1]+val1)==0) /// all resultant elements except last will be less than 0
   {
    rval1 = freltv[sz-2];
    rcnt1 = frcntv[sz-2];

    rval2 = rval1 + (rcnt1 * val1);

    if(rval2<0)
        rval2=(-1)*rval2;

    result.push_back(rval2);
    cout<<"case 4 "<<"for i = "<<i<<" value obtained = "<<rval2<<endl; 
   }
   else
   {
       cout<<"case 5 started , for i = "<<i<<endl;
    int pos = binsear(eltv,val1);

    if((eltv[pos+1]+val1)!=0)
    {
      rval1 = freltv[pos];
      rcnt1 = frcntv[pos];

      rval2 = rval1 + (rcnt1 * val1);

      if(rval2<0)
          rval2 = (-1)*rval2;

      rval3 = bckeltv[pos+1];
      rcnt2 = bckcntv[pos+1];

      rval4 = rval3 + (rcnt2 * val1);

      if(rval4<0)
          rval4 = (-1)*rval4;

      rval5 = rval4+rval2;

      result.push_back(rval5);
      cout<<"case 5-a "<<"for i = "<<i<<" value obtained = "<<rval5<<endl;
    }
    else
    {
      rval1 = freltv[pos];
      rcnt1 = frcntv[pos];

      rval2 = rval1 + (rcnt1 * val1);

      if(rval2<0)
          rval2 = (-1)*rval2;

      rval3 = bckeltv[pos+2];
      rcnt2 = bckcntv[pos+2];

      rval4 = rval3 + (rcnt2 * val1);

      if(rval4<0)
          rval4 = (-1)*rval4;

      rval5 = rval4+rval2;

      result.push_back(rval5);
      cout<<"case 5-b "<<"for i = "<<i<<" value obtained = "<<rval5<<endl;
    }

   }

 }



 
 cout<<"in the function"<<endl;

 return result;
}

int main()
{
 int n=3;
 int q=3;

 vector<int> arr={-1,2,-3};
 vector<int> queries={1,-2,3};

 vector<int> result = playingWithNumbers(arr,queries);

 for(int i=0;i<result.size();i++)
 	cout<<result[i]<<endl;



}