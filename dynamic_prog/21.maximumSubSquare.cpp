#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <cstring>
#include <utility>
using namespace std;

// dynamic programming video 21
//  maximum sub square  problem - find the side of maximum sub square in given matrix  of 0s and 1s with all 1s

// method 1
// time complexity - o ( row * col)
// space complexity - o (row * col)

// method 2
// time complexity - o ( row * col)
// space complexity - o (col)

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

               //    method 1     //

int minval2(int a,int b)
{
    if (a<b)
        return a;
    else
        return b;
}

int minval3(int a,int b,int c)
{
    return minval2(a,minval2(b,c));
}

int maximumSubSquare1(int *mat,int row,int col)
{
    int i,j,k,val,answer,x,y;


    // printing the mat matrix
    cout<<" printing the temp matrix in the function "<<endl;
    for (i=0;i<row;i++)
    {
    	for(j=0;j<col;j++)
    	{
    		val = *((mat+i*col)+j);
    		cout<<val<<" ";
    	}
    	cout<<endl;
    }

    int temp[row+1][col+1];

    for (i=0;i<=row;i++)
        temp[i][0]=0;

    for (i=0;i<=col;i++)
        temp[0][i]=0;

    answer=0;
    x=-1;
    y=-1;

    for (i=1;i<=row;i++)
    {
      for (j=1;j<=col;j++)
      {
        val = *((mat+(i-1)*col)+(j-1));

        if (val == 0)
            temp[i][j]=0;
        else
            temp[i][j]=1+minval3(temp[i-1][j-1],temp[i-1][j],temp[i][j-1]);

        if (answer < temp[i][j])
        {
            answer = temp[i][j];
            x=i;
            y=j;
        }

      }
    }

    cout<<endl;
    // printing the temp matrix 
    cout<<" printing the temp matrix "<<endl;

    for ( i=0;i<=row;i++)
    {
        for(j=0;j<=col;j++)
            cout<<temp[i][j]<<" ";
        cout<<endl;
    }

    cout<<endl;
    x=x-1;
    y=y-1;
    cout<<" coordinates of the sub square "<<endl;
    cout<<"first coordinate (x0,y0)  -- ( "<<(x-answer+1)<<" , "<<(y-answer+1)<<" ) "<<endl;
    cout<<"second coordinate (x1,y1)  -- ( "<<(x-answer+1)<<" , "<<(y)<<" ) "<<endl;
    cout<<"third coordinate (x2,y2)  -- ( "<<(x)<<" , "<<(y-answer+1)<<" ) "<<endl;
    cout<<"fourth coordinate (x3,y3)  -- ( "<<(x)<<" , "<<(y)<<" ) "<<endl;
    cout<<endl;


	return answer;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            // method 2 //  same method used for maximum rectangle problem with some modification

int maxval(int a,int b)
{
    if (a<b)
        return b;
    else
        return a;
}

 int getHistogramMaxSquareArea(int temp[],int n)
 {
    stack<pair<int,int>> st;

    int i,j,k,u,v,answer,maxAr,localAr,min;
    int x,y;

    pair<int,int> p1,p2,p3;

    for (i=0;i<n;i++)
    {
        if(temp[i]!=0)
        {
            // cout<<"inside loop i = "<<i<<endl;
            st.push(make_pair(temp[i],i));
            maxAr=1;
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
                        x = minval2((k-u+1),v);
                        localAr = x*x;
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
                        i++;
                    }

              }
              else if (temp[i]>p1.first)
              {
                   x = minval2(min,(i-j+1));
                   localAr = x*x;
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
                     x = minval2((k-u+1),v); 
                     localAr = x*x;
                     maxAr = maxval(localAr,maxAr);

                     st.pop();

                     if (st.empty())
                        break;

                     p1=st.top();
                     v=p1.first;

                     if (v<temp[i])
                        break;

                    }
                    
                    x = minval2((i-u+1),temp[i]); 
                    localAr = x*x;
                    maxAr = maxval(localAr,maxAr);

                    if (st.empty())
                    {
                        min = temp[i];
                        st.push(make_pair(temp[i],i));
                        x = minval2(min,(i-j+1));
                        maxAr=maxval(maxAr,x*x);
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
                x=minval2(v,(k-u+1));
                localAr = x*x;
                maxAr = maxval(localAr,maxAr);
                st.pop();
            }
        }
    }

    cout<<"maximum histogram area answer = "<<maxAr<<endl;

    return maxAr;
 }

int maximumSubSquare2(int *mat,int row,int col)
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

    int localAr = getHistogramMaxSquareArea(temp,col);

    if (localAr > maxAr)
        maxAr = localAr;

    cout<<" for i = "<<i<<" elements of temp array -- "<<endl;

    for (j=0;j<col;j++)
        cout<<temp[j]<<" ";
    cout<<endl;
    cout<<" max area  = "<<maxAr<<endl;
    cout<<" side of the square = "<<sqrt(maxAr)<<endl;
    cout<<endl;
 }

 cout<<" finally , max area of the square = "<<maxAr<<endl;
 int answer = sqrt(maxAr);


 return answer;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



int main()
{
	// int row=4;
	// int col=5;
	// int mat[row][col]={{0,0,1,1,1},
 //                       {1,0,1,1,1},
 //                       {0,1,1,1,1},
 //                       {1,0,1,1,1}};

    // int row = 4;
    // int col = 6;

    // int mat[row][col]= {{1,0,0,1,1,1},
    //                     {1,0,1,1,0,1},
    //                     {0,1,1,1,1,1},
    //                     {0,0,1,1,1,1}};

    int row = 7;
    int col = 6;

    int mat[row][col] = {{1,1,1,0,0,1},
                         {1,1,1,1,1,0},
                         {0,1,1,1,0,1},
                         {0,1,1,1,1,1},
                         {0,1,1,1,1,1},
                         {0,0,1,1,1,1},
                         {1,0,0,0,1,1}};

    cout<<" maximum sub square problem by method1 "<<endl;
    cout<<" row = "<<row<<endl;
    cout<<" col = "<<col<<endl;
    cout<<" elements of the mat matrix -- "<<endl;
    for (int i=0;i<row;i++)
    {
    	for(int j=0;j<col;j++)
    		cout<<mat[i][j]<<" ";
    	cout<<endl;
    }

    cout<<endl;                   

    int answer1 = maximumSubSquare1((int *)mat,row,col);
    cout<<" answer1 = "<<answer1<<endl;

    cout<<endl;
    cout<<endl;

    cout<<" maximum sub square problem by method2 (with maximumRectangle problem with some modifications ) "<<endl;

    int answer2 =  maximumSubSquare2((int *)mat,row,col);

    cout<<"answer2 = "<<answer2<<endl;                  


}