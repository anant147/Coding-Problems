#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <cstring>
#include <utility>
using namespace std;

// dynamic programming video 20
//  maximum size rectangle problem - find the area of maximum rectangle area containing all 1's
// time complexity - o ( row * col)
// space complexity - o (col)

int maxval(int a,int b)
{
	if (a<b)
		return b;
	else
		return a;
}

 int getHistogramMaxArea(int temp[],int n)
 {
 	stack<pair<int,int>> st;

 	int i,j,k,u,v,answer,maxAr,localAr,min;

 	pair<int,int> p1,p2,p3;

    for (i=0;i<n;i++)
    {
    	if(temp[i]!=0)
    	{
    		// cout<<"inside loop i = "<<i<<endl;
    		st.push(make_pair(temp[i],i));
    		maxAr=temp[i];
    		min=temp[i];
    		break;
    	}

    }
    j=i;
    i=i+1;

    // cout<<"ouside loop i = "<<i<<endl;
    localAr=0;

    while (!st.empty())
    {
    	if (i<n)
    	{
	          p1 = st.top();

	          if (temp[i]==0)
	          {
		            k=p1.second;

		            while(!st.empty())
		            {
		            	p1=st.top();
		            	u=p1.second;
		            	v=p1.first;
		            	localAr = (k-u+1)*v;
		            	maxAr = maxval(localAr,maxAr);
		            	st.pop();
		            }
		            
		            while(i<n && temp[i]==0)
		            	i++;

		            if(i<n)
		            {
		            	j=i;
		            	min = temp[i];
		            	st.push(make_pair(temp[i],i));
		            	maxAr=maxval(temp[i],maxAr);
		            	i++;
		            }

	          }
	          else if (temp[i]>p1.first)
	          {
		           localAr = maxval((i-j+1)*min,temp[i]);
		           maxAr=maxval(maxAr,localAr);

		           st.push(make_pair(temp[i],i));

		           i++;
	          }
	          else
	          {
	          	k=p1.second;
	          	v=p1.first;

		            while (true)
		            {	
		             u=p1.second;

		             localAr = (k-u+1)*v;
		             maxAr = maxval(localAr,maxAr);


		             st.pop();

		             if (st.empty())
		             	break;

		             p1=st.top();
		             v=p1.first;

		             if (v<temp[i])
		             	break;

		            }

		            localAr = (i-u+1)*temp[i];
		            maxAr = maxval(localAr,maxAr);

		            if (st.empty())
		            {
		            	min = temp[i];
		            	st.push(make_pair(temp[i],i));
		            	maxAr=maxval(maxAr,(i-j+1)*min);
		            	i++;
		            }
	          }

    	}
    	else
        {
        	p1=st.top();
            k=p1.second;

            while(!st.empty())
            {
            	p1=st.top();
            	u=p1.second;
            	v=p1.first;
            	localAr = (k-u+1)*v;
            	maxAr = maxval(localAr,maxAr);
            	st.pop();
            }
    	}
    }

    cout<<"maximum histogram area answer = "<<maxAr<<endl;

 	return maxAr;
 }

int maximumRectangle(int *mat,int row,int col)
{
 int i,j,k,u,v,val,len;

 int temp[col]={0};

 // printing the mat matrix in the maximum rectangle function 
 cout<<" printing the mat matrix "<<endl;

 for (i=0;i<row;i++)
 {
 	for (j=0;j<col;j++)
 		cout<<*((mat+i*col)+j)<<" ";
 	cout<<endl;
 }
 cout<<endl;

 int maxAr = 0;

 for (i=0;i<row;i++)
 {
 	for (j=0;j<col;j++)
 	{
 		val = *((mat+i*col)+j);
 		if (val == 0)
 			temp[j]=0;
 		else
 			temp[j]+=val;

 	}

 	int localAr = getHistogramMaxArea(temp,col);

 	if (localAr > maxAr)
 		maxAr = localAr;

 	cout<<" for i = "<<i<<" elements of temp array -- "<<endl;

 	for (j=0;j<col;j++)
 		cout<<temp[j]<<" ";
 	cout<<endl;
 	cout<<" max area  = "<<maxAr<<endl;
 	cout<<endl;
 }

 int answer = maxAr;


 return maxAr;
}

int main()
{
	// int row = 4;
	// int col = 6;

	// int mat[row][col]= {{1,0,0,1,1,1},
 //                        {1,0,1,1,0,1},
 //                        {0,1,1,1,1,1},
 //                        {0,0,1,1,1,1}};

	int row = 7;
	int col = 6;

	int mat[row][col] = {{1,1,1,0,0,1},
                         {1,1,1,1,1,0},
                         {0,1,1,1,0,1},
                         {0,1,1,1,1,1},
                         {0,1,1,1,1,1},
                         {0,0,1,1,1,1},
                         {1,0,0,0,1,1}};

    cout<<" maximum size rectangle problem "<<endl;
    cout<<" row = "<<row<<endl;
    cout<<" col = "<<col<<endl;
    cout<<" elements of mat array --- "<<endl;

    for (int i=0;i<row;i++)
    {
    	for (int j=0;j<col;j++)
    		cout<<mat[i][j]<<" ";
    	cout<<endl;
    }

    int answer1 = maximumRectangle((int *)mat,row,col);
    cout<<" answer1 = "<<answer1<<endl;
    cout<<endl;
    cout<<endl;                    
    cout<<"part 2 - maximum histogram area problem -- "<<endl;
    
    // int n=5;
    // // int temp[] = {1,2,3,4,5};

    // int n=5;
    // int temp[] = {5,4,3,2,1};

    int n=5;
    int temp[] = {3,2,1,2,3};
    cout<<"size of the array -- "<<n<<endl;
    cout<<" elements of the temp array -- "<<endl;
    for (int i=0;i<n;i++)
    	cout<<temp[i]<<" ";
    cout<<endl;

    int answer2 = getHistogramMaxArea(temp,n); 

    cout<<" answer2 = "<<answer2<<endl;                    
}