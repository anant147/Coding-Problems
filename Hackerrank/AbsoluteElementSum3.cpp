#include<iostream>
#include<vector>
using namespace std;

// (n+q) solution

// Complete the playingWithNumbers function below.
vector<long long> playingWithNumbers(vector<int> arr, vector<int> queries) {

  long long i,j,k,u,v;


  long long elm[4001],cnt[4001];
  long long forsum[4001],bcksum[4001];
  long long forcnt[4001],bckcnt[4001];
  long long forelm[4001],bckelm[4001];

  for(i=0;i<4001;i++)
  {
    elm[i]=0; cnt[i]=0; forsum[i]=0; bcksum[i]=0; forcnt[i]=0; bckcnt[i]=0;
    forelm[i]=-2010;    bckelm[i]=2010;
  }


  // for storing elements and their count
  for(i=0;i<arr.size();i++)
  {
   u=arr[i]; 
   elm[2000+u]=u;
   cnt[2000+u]++;
  }


  // for printing elemnts
  for(i=0;i<4001;i++)
  {
    if((elm[i]+2000)==i && cnt[i]!=0)
    {
      cout<<"for pos = "<<i<<" val = "<<elm[i]<<" cnt = "<<cnt[i]<<endl;
    }
  }

  cout<<endl;

  // for storing forward count
  for(i=0;i<4001;i++)
  {
    if(i==0)
      forcnt[i]=cnt[i];
    else
    {
      forcnt[i]=forcnt[i-1]+cnt[i];
    }

    if((elm[i]+2000)==i && cnt[i]!=0)
    {
      cout<<"for pos = "<<i<<" forcnt = "<<forcnt[i]<<endl;
    }
  }

  
  cout<<endl;
  
  // for storing backward count
  for(i=4000;i>=0;i--)
  {
    if(i==4000)
      bckcnt[i]=cnt[i];
    else
      bckcnt[i]=bckcnt[i+1]+cnt[i];

    if((elm[i]+2000)==i && cnt[i]!=0)
    {
      cout<<"for pos = "<<i<<" bckcnt = "<<bckcnt[i]<<endl;
    }

  }

  cout<<endl;

  // for storing forward sum 
  for(i=0;i<4001;i++)
  {
    u=i-2000;

    if(i==0)
      forsum[i]=u*cnt[i];
    else
      forsum[i]=forsum[i-1]+(u*cnt[i]);

    if((elm[i]+2000)==i && cnt[i]!=0)
    {
      cout<<"for pos = "<<i<<" forsum = "<<forsum[i]<<endl;
    }
  }

  cout<<endl;
  
  // for storing backward sum
  for(i=4000;i>=0;i--)
  {
    u=i-2000;

    if(i==4000)
      bcksum[i]=u*cnt[i];
    else
      bcksum[i]=bcksum[i+1]+(u*cnt[i]);

    if((elm[i]+2000)==i && cnt[i]!=0)
    {
      cout<<"for pos = "<<i<<" bcksum = "<<bcksum[i]<<endl;
    }
  }

  cout<<endl;
  
  // for storing forward element
  for(i=0;i<4001;i++)
  {
    if(i==0)
    {
      if((elm[i]+2000)==i && cnt[i]!=0)
      {
        forelm[i]=elm[i];
        k=elm[i];
      }
      else
        k=forelm[i];
    }
    else
    {
      if((elm[i]+2000)==i && cnt[i]!=0)
      {
        forelm[i]=elm[i];
        k=elm[i];
      }
      else
      {
        forelm[i]=k;
      }
    }

    if((elm[i]+2000)==i && cnt[i]!=0)
    {
      cout<<"for pos "<<i<<" forelm "<<forelm[i]<<" "<<forelm[i-1]<<" "<<forelm[i+1]<<endl;
    }
  }

  cout<<endl;

  // for storing backward element

  for(i=4000;i>=0;i--)
  {
    if(i==4000)
    {
      if((elm[i]+2000)==i && cnt[i]!=0)
      {
       bckelm[i]=elm[i];
       k=elm[i];
      }
      else
      {
       k=bckelm[i];
      }
    }
    else
    {
      if((elm[i]+2000)==i && cnt[i]!=0)
      {
        bckelm[i]=elm[i];
        k=elm[i];
      }
      else
      {
        bckelm[i]=k;
      }
    }

    if((elm[i]+2000)==i && cnt[i]!=0)
    {
      cout<<" for pos "<<i<<" bckelm "<<bckelm[i]<<" "<<bckelm[i-1]<<" "<<bckelm[i+1]<<endl;
    }
  }

  
  for(i=1996;i<=2003;i++)
  {
    if((elm[i]+2000)==i && cnt[i]!=0)
      cout<<"ele present"<<endl;
    cout<<"for i "<<i<<" "<<forelm[i]<<" "<<bckelm[i]<<endl;
  }


  // cout<<"for i = 0"<<" forsum "<<forsum[0]<<endl;
  // cout<<"for i = 0"<<" bcksum "<<bcksum[0]<<endl;
  // cout<<"for i = 0"<<" forcnt "<<forcnt[0]<<endl;
  // cout<<"for i = 0"<<" bckcnt "<<bckcnt[0]<<endl;
  // cout<<"for i = 0"<<" forelm "<<forelm[0]<<endl;
  // cout<<"for i = 0"<<" bckelm "<<bckelm[0]<<endl;

  // cout<<"for i = 4000"<<" forsum "<<forsum[4000]<<endl;
  // cout<<"for i = 4000"<<" bcksum "<<bcksum[4000]<<endl;
  // cout<<"for i = 4000"<<" forcnt "<<forcnt[4000]<<endl;
  // cout<<"for i = 4000"<<" bckcnt "<<bckcnt[4000]<<endl;
  // cout<<"for i = 4000"<<" forelm "<<forelm[4000]<<endl;
  // cout<<"for i = 4000"<<" bckelm "<<bckelm[4000]<<endl;

  long long leftpos,rightpos;
  long long leftcnt,rightcnt;
  long long leftval,rightval;
  long long leftsum,rightsum,position;
  long long sum;
  
  long long qsum=0;
  vector<long long> result;
  long long mval;

  for(i=0;i<queries.size();i++)
  {
    qsum+=queries[i];
    mval=(-1)*qsum;
    
    position = 2000+mval;

    if(position<0)
    {
     rightcnt=bckcnt[0];  rightval = bcksum[0];
     sum = rightval + (rightcnt * qsum);

     if(sum<0)
      sum=(-1)*sum;
    }
    else if(position>4000)
    {
     leftcnt = forcnt[4000];  leftval = forsum[4000];
     sum = leftval + (leftcnt * qsum);

     if(sum<0)
      sum=(-1)*sum;
    }
    else if(elm[position]==mval && cnt[position]!=0)
    {
      if(position==0)
      {
        rightcnt=bckcnt[position+1];   rightval = bcksum[position+1];
        sum = rightval + (rightcnt*qsum);

        if(sum<0)
          sum=(-1)*sum;

        cout<<"case -1"<<endl;
      }
      else if(position==4000)
      {
        leftcnt=forcnt[position-1];    leftval = forsum[position-1];
        sum = leftval + (leftcnt*qsum);

        if(sum<0)
          sum=(-1)*sum;

        cout<<"case -2"<<endl;
      }
      else if(forelm[position-1]==-2010)
      {
        rightpos=bckelm[position+1]+2000;
        rightcnt=bckcnt[rightpos];    rightval = bcksum[rightpos];
        sum= rightval + (rightcnt * qsum);

        if(sum<0)
          sum=(-1)*sum;

        cout<<"case -3"<<endl;
      }
      else if(bckelm[position+1]==2010)
      {
       leftpos=forelm[position-1]+2000;
       leftcnt=forcnt[leftpos];      leftval = forsum[leftpos];
       sum = leftval + (leftcnt* qsum);

       if(sum<0)
          sum=(-1)*sum;

        cout<<"case -4"<<endl;
      }
      else
      {
       leftpos = forelm[position-1]+2000;   leftcnt = forcnt[leftpos];  leftval = forsum[leftpos];
       leftsum = leftval + (leftcnt * qsum);

       if(leftsum<0)
        leftsum = (-1)*leftsum;

      rightpos = bckelm[position+1]+2000;  rightcnt = bckcnt[rightpos];  rightval = bcksum[rightpos];
      rightsum = rightval + (rightcnt * qsum);

      if(rightsum<0)
        rightsum = (-1)*rightsum;

      sum=leftsum+rightsum;

      cout<<"case - 5"<<endl;
      }
    }
    else
    {
      if(forelm[position]==-2010)
      {
         rightpos=bckelm[position]+2000;  rightcnt = bckcnt[rightpos];  rightval = bcksum[rightpos];
         sum = rightval + (rightcnt * qsum);

         if(sum<0)
         sum=(-1)*sum;

         cout<<"case - 6"<<endl;  
      }
      else if(bckelm[position]==2010)
      {
        leftpos=forelm[position]+2000; leftcnt = forcnt[leftpos];  leftval = forsum[leftpos];
        sum = leftval + (leftcnt*qsum);

        if(sum<0)
        sum=(-1)*sum; 
        cout<<"case - 7"<<endl;  
      }
      else
      {
       leftpos = forelm[position]+2000;  leftcnt = forcnt[leftpos];   leftval = forsum[leftpos];
       leftsum = leftval + (leftcnt * qsum);

       if(leftsum<0)
       leftsum=(-1)*leftsum;

       rightpos = bckelm[position]+2000; rightcnt = bckcnt[rightpos];  rightval = bcksum[rightpos];
       rightsum = rightval + (rightcnt * qsum);

       if(rightsum<0)
        rightsum = (-1)*rightsum;

      sum=leftsum+rightsum;

      cout<<"case -8"<<endl;
      }

    }

    result.push_back(sum);

    cout<<sum<<endl;


  }

  for(i=0;i<result.size();i++)
    cout<<result[i]<<" ";

cout<<endl;


  

  

 return result;

}

int main()
{
 int n=3;
 int q=3;

 vector<int> arr={-1,2,-3};
 vector<int> queries={1,-2,3};

 vector<long long> result = playingWithNumbers(arr,queries);

 for(int i=0;i<result.size();i++)
 	cout<<result[i]<<endl;



}