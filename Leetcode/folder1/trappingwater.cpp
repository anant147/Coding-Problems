// Trapping Rain Water

#include<iostream>
#include<vector>
#include<stack> 
using namespace std;

int trap(vector<int>& height)
{
   stack<int> stk;

   int i,j,k,sum,max,cond,cnt;
   int itmsum;
   int htsiz;
   int maxpos,secpos;
   int topval;

   cond=0;
   
   htsiz=height.size();

   if(htsiz==0 || htsiz==1)
   	return 0;


   stk.push(height[0]);
   max=height[0];maxpos=0;

   itmsum=0; cnt=0;

   sum=0;

   for(i=1;i<height.size();i++)
   {
    if(cond==0)
    {
      topval=stk.top();


      if(topval<height[i])
      {
       stk.pop();       stk.push(height[i]);        max=height[i];  maxpos=i;
      }
      else if(topval==height[i])
      {
        maxpos=i;
      }
      else
      {
        cond=1; itmsum=topval-height[i]; cnt++; stk.push(height[i]);
        cout<<" cond 0 max = "<<max<<endl;
        cout<<" cond 0 itm sum = "<<itmsum<<endl;
        cout<<endl;
      }
    }
    else if(cond==1)
    {
      if(max>height[i])
      {
      	itmsum+=(max-height[i]); cnt++; stk.push(height[i]);
        
        cout<<" cond 1 max = "<<max<<endl;
        cout<<" cond 1 itm sum = "<<itmsum<<endl;
        cout<<endl;
      }  
      else if(max<=height[i])
      {
      	cout<<" cond 2 max = "<<height[i]<<endl;
      	cout<<" cond 2 itm sum = "<<itmsum<<endl;
      	sum+=itmsum; 
      	itmsum=0;

      	cout<<" cond 2  sum = "<<sum<<endl;
      	cout<<endl;

      	while(!stk.empty())
      	{
      		stk.pop();
      	}

      	stk.push(height[i]);
      	max=height[i]; 
      }
    }

   }
   cout<<"before stack oper sum = "<<sum<<endl;

   cout<<"size of stack = "<<stk.size()<<endl;


   if(stk.size()>2)
   {

   max=stk.top();
   stk.pop();

   itmsum=0;
   cond=0;
   cnt=0;

   while(!stk.empty())
   {
    cnt++;

   	cout<<"top of stack = "<<stk.top()<<" \t"<<"cnt = "<<cnt<<endl;
   	if(cond==0)
   	{
   		topval=stk.top();
        stk.pop();

   		if(max<topval)
   		{
         max=topval;
   		}
   		else if(max>topval)
   		{
          cond=1;
          itmsum=max-topval;
          cout<<"stk cond 0 itmsum = "<<itmsum<<endl;
          cout<<"stk cond 0 max = "<<max<<endl;
   		}
   	}
   	else if(cond==1)
   	{
      topval=stk.top();
       stk.pop();

       if(max>topval)
       {
       	itmsum+=(max-topval); 

       	cout<<"stk cond 1 itmsum = "<<itmsum<<endl;
       	cout<<"stk cond 1 max = "<<max<<endl;
       }
       else
       {
       	sum+=itmsum;
       	itmsum=0;
       	max=topval;

       	cout<<"stk cond 2 itmsum = "<<itmsum<<endl;
       	cout<<"stk cond 2 max = "<<max<<endl;

       	cout<<"stk cond 2 sum = "<<sum<<endl;
       }
   	}

   }

   }

   cout<<"after stack , sum = "<<sum<<endl;


   return sum;
}

int main()
{
 // int a[8]={0,1,0,2,1,0,1,3};
 // vector<int> height(a,a+8);

 // int a[12]={0,1,0,2,1,0,1,3,2,1,2,1};
 // vector<int> height(a,a+12);

 int a[3]={4,2,3};
 vector<int> height(a,a+3);

 int result=trap(height);

 cout<<result<<endl;

}