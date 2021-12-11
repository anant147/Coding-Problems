// Largest Rectangle in histogram

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int getCorPos1(vector<int> heights,int dir1[],int sz,int pos1,int pos2)
{
 int val = heights[pos1];
 int i,j,k;

 int cond=0;
 int result;

 int mainpos = dir1[pos2];

 while(cond==0)
 {
 	if(mainpos+1==sz)
 	{
 		cond=1; result=mainpos;
 	}
 	else if(val>heights[mainpos+1])
 	{
 		cond=1; result=mainpos;
 	}
 	else if(val == heights[mainpos+1])
 	{
 		cond=1; result=dir1[mainpos+1];
 	}
 	else if(val<heights[mainpos+1])
 	{
 		mainpos=dir1[mainpos+1];
 	}
 }

 return result;

 // if(mainpos+1 == sz)
 // 	return mainpos;
 // else if(val>heights[mainpos+1])
 // 	return mainpos;
 // else if(val==heights[mainpos+1])
 // 	return dir1[mainpos+1];
 // else 
 // {
 // 	//getCorPos1(heights,dir1,sz,pos1,mainpos+1);
    

 // }
}

int getCorPos2(vector<int> heights,int dir2[],int sz,int pos1,int pos2)
{
	int val = heights[pos1];
	int i,j,k;

	int cond=0;
	int result;

	int mainpos = dir2[pos2];

	while(cond==0)
	{
		if(mainpos-1==-1)
		{
			cond=1; result=mainpos;
		}
		else if(val>heights[mainpos-1])
		{
			cond=1; result=mainpos;
		}
		else if(val==heights[mainpos-1])
		{
			cond=1; result=dir2[mainpos-1];
		}
		else
		{
			mainpos=dir2[mainpos-1];
		}
	}

	return result;



	// if(mainpos-1 == -1)
	// 	return mainpos;
	// else if(val>heights[mainpos-1])
	// 	return mainpos;
	// else if(val == heights[mainpos-1])
	// 	return dir2[mainpos-1];
	// else
	// 	getCorPos2(heights,dir2,sz,pos1,mainpos-1);

}


int largestRectangleArea(vector<int>& heights) {

	int i,j,k;
    int sz = heights.size();
    
    int ar[sz];
    int dir1[sz],dir2[sz];
    int max;
    int val;
    int pos,corpos1,corpos2;
    int itmax;

    for(i=0;i<sz;i++)
    {
    	dir1[i]=i;dir2[i]=i;
    }

    if(sz==0)
    {
    	return 0;
    }
    if(sz==1)
    {
     return heights[0];
    }
    else 
    {
    	for(i=sz-2;i>=0;i--)
    	{
    		j=i+1;
            if(heights[i]<=heights[j])
            {
               pos = dir1[j];

               if(pos+1 == sz)
               	dir1[i]=pos;
               else if(heights[i]>heights[pos+1])
               	dir1[i]=pos;
               else if(heights[i]==heights[pos+1])
               	dir1[i]=dir1[pos+1];
               else if(heights[i]<heights[pos+1])
               {
                  corpos1= getCorPos1(heights,dir1,sz,i,pos+1); 

                  dir1[i]=corpos1;


               }

            } //

            
    	} // end of first loop

    	for(i=0;i<sz;i++)
    		cout<<dir1[i]<<"\t";

    	cout<<endl;

    	for(i=1;i<sz;i++)
    	{
    		j=i-1;

    		if(heights[i]<=heights[j])
    		{
    			pos=dir2[j];

    			if(pos-1==-1)
    				dir2[i]=pos;
    			else if(heights[i]>heights[pos-1])
    				dir2[i]=pos;
    			else if(heights[i]==heights[pos-1])
    				dir2[i]=dir2[pos-1];
    			else if(heights[i]<heights[pos-1])
    			{
    				corpos2 = getCorPos2(heights,dir2,sz,i,pos-1);
    				dir2[i]=corpos2;    			}
    		}
    	}

    	for(i=0;i<sz;i++)
    		cout<<dir2[i]<<"\t";

    	cout<<endl;

    	max=-1;

    	for(i=0;i<sz;i++)
    	{
          itmax=(dir1[i]-dir2[i]+1)*heights[i];

          if(max<itmax)
          	max=itmax;

          cout<<"for i = "<<i<<" itmax = "<<itmax<<endl;
    	}
    	cout<<endl;

    	cout<<"max = "<<max<<endl;

    	return max;
    }

}

int main()
{
 // int a[6]={2,1,5,6,2,3};

 // vector<int> heights(a,a+6);

	vector<int> heights = {2,1,5,6,2,3};

	// int a[5]={1,2,3,4,5};
	// vector<int> heights(a,a+5);

 int result = largestRectangleArea(heights);

 cout<<result<<endl;
}