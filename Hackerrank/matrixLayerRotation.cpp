// Matrix layer rotation

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> getRect(int fr,int fc,int row,int col)
{
	vector<int> v1;
	int r,c,lowr,uppr,lowc,uppc;

	int sr=row-1-fr;
	int sc=col-1-fc;
    
    if(fr<sr)
    	r=fr;
    else
    	r=sr;

    if(fc<sc)
    	c=fc;
    else
    	c=sc;

    if(r<c)
    {
     lowr=r;  uppr=row-1-lowr;
     lowc=r;  uppc=col-1-lowc;
    }
    else
    {
      lowc=c;  uppc=col-1-lowc;
      lowr=c;  uppr=row-1-lowr;
    }

    v1={lowr,uppr,lowc,uppc};

   
	return v1;
}

vector<int> getcord(vector<int> coord,int r,int c,int d)
{
	vector<int> v1;
	int x,y;

	if(d==0)
	{
		v1.push_back(r);
		v1.push_back(c);
		return v1;
	}

	if(r==coord[0])
	{
	      if(c!=coord[2])
	      {
             if((c-coord[2])>=d)
             {
               y=c-d;
               v1.push_back(r);
               v1.push_back(y);
               return v1;
             }
             else
             {
               y=c-coord[2];
               d=d-y;
               c=coord[2];
             }
	      }

	      if(c==coord[2])
	      {
              if((coord[1]-r)>=d)
              {
              	x=r+d;
              	v1.push_back(x);
              	v1.push_back(c);
              	return v1;
              }
              else
              {
              	x=coord[1]-r;
              	d=d-x;
              	return getcord(coord,coord[1],coord[2],d);
              }
	      }
	}
	else if(c==coord[2])
	{
         if(r!=coord[1])
         {
         	if((coord[1]-r)>=d)
         	{
         		x=r+d;
         		v1.push_back(x);
         		v1.push_back(c);
         		return v1;
         	}
         	else
         	{
              x=coord[1]-r;
              d=d-x;
              r=coord[1];
         	}
         }

         if(r==coord[1])
         {
         	if((coord[3]-c)>=d)
         	{
         		y=c+d;
         		v1.push_back(r);
         		v1.push_back(y);
         		return v1;
         	}
         	else
         	{
         		y=coord[3]-c;
         		d=d-y;
         		return getcord(coord,coord[1],coord[3],d);
         	}
         }
	}
	else if(r==coord[1])
	{
       if(c!=coord[3])
       {
        if((coord[3]-c)>=d)
        {
          y=c+d;
          v1.push_back(r);
          v1.push_back(y);
          return v1;
        }
        else
        {
         y=coord[3]-c;
         d=d-y;
         c=coord[3];
        }

       }

       // v1.push_back(0);
       // v1.push_back(0);
       // return v1;

       if(c==coord[3])
       {
         if((r-coord[0])>=d)
         {
           x=r-d;
           v1.push_back(x);
           v1.push_back(c);
           return v1;
         }
         else
         {
           x=r-coord[0];
           d=d-x;
           return getcord(coord,coord[0],coord[3],d);
         }
       }
	}
	else if(c==coord[3])
	{
      if(r!=coord[0])
      {
        if((r-coord[0])>=d)
        {
          x=r-d;
          v1.push_back(x);
          v1.push_back(c);
          return v1;
        }
        else
        {
          x=r-coord[0];
          d=d-x;
          r=coord[0];
        }
      }

      if(r==coord[0])
      {
        if((c-coord[2])>=d)
        {
          y=c-d;
          v1.push_back(r);
          v1.push_back(y);
          return v1;
        }
        else
        {
          y=c-coord[2];
          d=d-y;
          return getcord(coord,coord[0],coord[2],d);
        }
      }
	}
}

void matrixRotation(vector<vector<int>> matrix, int r) {

  int i,j,k;
  vector<int> coord;
  int m;
  int d;
  int posx,posy;
  int row=matrix.size();
  if(row==0)
  	return;

  int col=matrix[0].size();

  vector<vector<int>> result(row,vector<int>(col,0));

  for(i=0;i<row;i++)
  {
  	for(j=0;j<col;j++)
  	{
  		// cout<<"for i = "<<i<<" j = "<<j<<" val = "<<matrix[i][j]<<endl;

        vector<int> coord = getRect(i,j,row,col);

        // cout<<coord[0]<<" "<<coord[1]<<" "<<coord[2]<<" "<<coord[3]<<endl;
        
        m=2*(coord[1]+coord[3]-coord[2]-coord[0]);
        d=r%m;

        vector<int> realcord = getcord(coord,i,j,d);

        // cout<<realcord[0]<<realcord[1]<<endl;
        posx = realcord[0];
        posy = realcord[1];
        
        result[posx][posy] = matrix[i][j];

        // cout<<"d = "<<d<<endl;
        // cout<<"m = "<<m<<endl;

  	}

  	// cout<<endl;
  }

  // cout<<endl;

  


  for(i=0;i<row;i++)
  {
  	for(j=0;j<col;j++)
  		cout<<result[i][j]<<"\t";

  	cout<<endl;
  }

}

int main()
{
	int r=21;

	vector<vector<int>> matrix = {{1,2,3,4},
                                 {5,6,7,8},
                                 {9,10,11,12},
                                 {13,14,15,16},
                                 {17,18,19,20}

                             };

    matrixRotation(matrix,r);
   
   cout<<"hoga"<<endl;

}