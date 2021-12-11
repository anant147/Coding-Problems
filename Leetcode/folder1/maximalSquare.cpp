#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<stack>
#include<utility>
using namespace std;

int maxSqre(int a,int b)
{
  if (a<b)
    return (a*a);
  else
    return (b*b);
}

int maxval(int a,int b)
{
	if (a<b)
		return b;
	else
		return a;
}

int getArea(int temp[],int n)
{
    int i,j,k,u,v,x,y,max;
    int zpt,spt,ar;

    stack<pair<int,int>> st;
    pair<int,int> pr,sp;

    for (i=0;i<n;i++)
    {
    	if (temp[i]!=0)
    	{
    		st.push(make_pair(temp[i],i));
    		break;
    	}
    }

    max=0;
    zpt=0;

    while (!st.empty() || i<n)
    {
    	if (i<n)
    	{
          if (temp[i]==0)
          {
          	while(!st.empty())
          	{
             sp = st.top();
             x=sp.first;
             y=sp.second;

             ar=maxSqre(x,i-y);
             max=maxval(max,ar);

             st.pop();
          	}
          	i++;
          	zpt=i;
          }
          else if (st.empty())
          {
          	if (temp[i]!=0)
          	{
          		st.push(make_pair(temp[i],i));
          		i++;
          	}
          	else
          	{
          		i++;
          		zpt=i;
          	}	
          }
          else
          {
          	sp = st.top();
          	x = sp.first;
          	y = sp.second;

          	if (x<temp[i])
          	{
             st.push(make_pair(temp[i],i));
             i++;
          	}
          	else
          	{
                spt=zpt;
          		while(true)
          		{
          			if (st.empty())
          				break;

          			pr = st.top();
          			u = pr.first;
          			v = pr.second;

          			if (u>temp[i])
          			{
                  ar = maxSqre(u,i-v);
          				max=maxval(max,ar);
          				spt=v;
          			}
          			else if (u==temp[i])
          			{
                  ar = maxSqre(u,i-v+1);
          				max=maxval(max,ar);
          				spt=v;
          			}
          			else
          				break;

          			st.pop();
          		}

          		st.push(make_pair(temp[i],spt));
          		i++;
          	}

          }
    	}
    	else
    	{
          while(!st.empty())
          {
          	pr = st.top();
          	x = pr.first;
          	y=pr.second;
            
            ar = maxSqre(x,n-y);
          	max=maxval(max,ar);
          	st.pop();
          } 
    	}
    }

    // cout<<" area = "<<max<<endl;
	return max;
}

int maximalSquare1(vector<vector<char>>& matrix)
{
	int i,j,k,u,v,x,y,z,len;

	int n = matrix.size();

	if (n==0)
		return 0;

	int m = matrix[0].size();

	if (m==0)
		return 0;

	int temp[m];

	int max =0;

	for (i=0;i<n;i++)
	{
		if (i==0)
		{
			for (j=0;j<m;j++)
			{
				if (matrix[i][j]=='1')
					temp[j]=1;
				else
					temp[j]=0;
		    }
		}
		else
		{
			for (j=0;j<m;j++)
			{
				if (matrix[i][j]=='1')
					temp[j]=temp[j]+1;
				else
					temp[j]=0;
		    }
		}

		k = getArea(temp,m);

		if (max<k)
			max=k;

		// for (j=0;j<m;j++)
		// 	cout<<temp[j]<<" ";
		// cout<<endl;
		// cout<<endl;
	}
	// cout<<endl;
	// cout<<" final max area = "<<max<<endl;

	return max;
}

int minval(int a,int b)
{
  if (a<b)
    return a;
  else
    return b;
}

int minval3(int a,int b,int c)
{
  return minval(a,minval(b,c));
}

int maximalSquare2(vector<vector<char>>& matrix)
{
  int i,j,k,u,v,x,y,z,len;

  int n = matrix.size();

  if (n==0)
    return 0;

  int m = matrix[0].size();

  if (m==0)
    return 0;

  int temp[n][m];

  for (i=0;i<n;i++)
  {
    if (matrix[i][0]=='1')
      temp[i][0]=1;
    else
      temp[i][0]=0;
  }


  for (i=0;i<m;i++)
  {
    if (matrix[0][i]=='1')
      temp[0][i]=1;
    else
      temp[0][i]=0;
  }


  for (i=1;i<n;i++)
  {
    for (j=1;j<m;j++)
    {
      if (matrix[i][j]=='1')
        temp[i][j]=minval3(temp[i-1][j-1],temp[i-1][j],temp[i][j-1])+1;
      else
        temp[i][j]=0;
    }
  }

  int max=0;
  // cout<<endl;
  // cout<<" temp matrix -- "<<endl;

  for (i=0;i<n;i++)
  {
    for (j=0;j<m;j++)
    {
      // cout<<temp[i][j]<<" ";

      if (max<temp[i][j])
        max=temp[i][j];
    }
    // cout<<endl;
  }
  // cout<<endl;


  return max;

}

int main()
{
	int i,j,k,u,v,x,y;

	char cmatrix[4][6] = {"10100","10111","11111","10010"};
	// char cmatrix[5][7] = {"101110","111111","011110","001110","111111"};

   // int n = matrix.size();
   // int m = matrix[0].size();

   int n = 4;
   int m = 5;

   // int n = 5;
   // int m = 6;                            

   cout<<" maximal Rectangle problem -- "<<endl;
   cout<<" n = "<<n<<endl;
   cout<<" m = "<<m<<endl;
   cout<<" elements of the cmatrix -- "<<endl;

   vector<vector<char>> matrix;

   for (i=0;i<n;i++)
   {
   	vector<char> vchar;
   	for (j=0;j<m;j++)
   	{
   		cout<<cmatrix[i][j]<<" ";

   		vchar.push_back(cmatrix[i][j]);
   	}
   	matrix.push_back(vchar);
   	vchar.clear();

   	cout<<endl;
   }

   cout<<endl;
   

   cout<<" elements of the matrix vec of vec"<<endl;
   for (i=0;i<matrix.size();i++)
   {
   	for (j=0;j<matrix[i].size();j++)
   		cout<<matrix[i][j]<<" ";
   	cout<<endl;
   }
   cout<<endl;

   // int answer = maximalSquare1(matrix);

   // cout<<" answer = "<<answer<<endl;

   cout<<endl;
   cout<<" 2nd method -- "<<endl;

   int answer2 = maximalSquare2(matrix);

   cout<<" answer2 = "<<answer2<<endl;
   

}