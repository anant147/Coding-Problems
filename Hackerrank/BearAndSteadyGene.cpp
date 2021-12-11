#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>

// #include<bits/stdc++.h> 
using namespace std;

bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
    return (a.second > b.second); 
} 

int steadyGene(string s)
{
 int i,j,k,u,v,extsum;
 int sz = s.size();
 int lim = sz/4;
 
 int stable[4][sz]={0};
 int cnt[4]={0};
 int ext[4]={0};

 unordered_map<char,int> mp;

 char cr;

 mp['A']=0;
 mp['C']=1;
 mp['G']=2;
 mp['T']=3;

 for(i=0;i<sz;i++)
 {
   cr=s[i];

   u=mp[cr];
   cnt[u]++;

   if(i==0)
   {

     for(j=0;j<4;j++)
     {
     	if(j==u)
     		stable[j][i]=1;
     	else
     		stable[j][i]=0;
     }
   }
   else
   {
    for(j=0;j<4;j++)
    {
    	if(j==u)
    		stable[j][i]=stable[j][i-1]+1;
    	else
    		stable[j][i]=stable[j][i-1];
    }
   }
 }

 extsum=0;

 vector<int> extpos;

 for(i=0;i<4;i++)
 {
 	if(cnt[i]>lim)
 	{
 		ext[i]=cnt[i]-lim;
    extsum+=ext[i];
    extpos.push_back(i);
 	}
 }

 // cout<<"extsum = "<<extsum<<endl;

 // for(i=0;i<4;i++)
 // {
 // 	for(j=0;j<sz;j++)
 // 		cout<<stable[i][j]<<" ";

 // 	cout<<endl;
 // }


 int left=0;
 int right=extsum-1;
 int cond=1;
 int minlen=sz+1;
 int satisfy=0;
 int mncnd,rncnd,kncnd,pncnd;
 int obtlen;
 int val;
 int endcnd=0;
 int cnter=0;


 // cout<<"case 1- cond = "<<cond<<endl;

 while(cond)
 {
  // cout<<"start "<<cnter<<" , left = "<<left<<" , right = "<<right<<" , minlen = "<<minlen<<endl;
  
  if(satisfy==0)
  {

      mncnd=1;
     
     for(j=0;j<extpos.size();j++)
     {
       i=extpos[j];

      if(left==0)
        val=stable[i][right];
      else
        val=stable[i][right]-stable[i][left-1];

      if(ext[i]!=0)
      {
        if(ext[i]>val)
        {
         mncnd=0; break;
        }
      }
     }

     if(mncnd==0)
     {

      if(right!=(sz-1))
      {
      right++;
      }
      else
      {
        satisfy=1;

        if(left!=(sz-extsum))
        {
          left++;
        }
        else
          endcnd=1;

      }
     }
     else
     {
       
       satisfy=1;
       obtlen=right-left+1;

       if(obtlen<minlen)
        minlen=obtlen;

      if(left!=(sz-extsum))
        left++;
      else
        {
          satisfy=0;
          
          if(right!=(sz-1))
            right++;
          else
            endcnd=1;

        }
     }

    }
    else
    {
      mncnd=1;

      for(j=0;j<extpos.size();j++)
      {
        i=extpos[j];

        if(left==0)
          val=stable[i][right];
        else
          val=stable[i][right]-stable[i][left-1];

        if(ext[i]!=0)
        {
          if(ext[i]>val)
          {
            mncnd=0; break;
          }
        }
      }

      if(mncnd==0)
      {
       if(right!=(sz-1))
       {
        satisfy=0; right++;
       }
       else
       {
        if(left!=(sz-extsum))
          left++;
        else
          endcnd=1;

       }
      }
      else
      {
        obtlen=right-left+1;

        if(obtlen<minlen)
          minlen=obtlen;

        if(left!=(sz-extsum))
          left++;
        else
        {
          if(right!=(sz-1))
            right++;
          else
            endcnd=1;
        }
      }

    }

    // cout<<"end "<<cnter<<" , left = "<<left<<" , right = "<<right<<" , minlen = "<<minlen<<endl;

    // cnter++;

    if(endcnd==1)
    {
      cond=0;
      // cout<<"condition ended"<<endl;
       break;
    }

 }



 // cout<<"final minlen = "<<minlen<<endl;


 return minlen;
}


int main()
{
 int i,j,k;

 // string s = "GAAATAAA";	


 // string s = "ACTGAAAG";

 string s = "TGATGCCGTCCCCTCAACTTGAGTGCTCCTAATGCGTTGC";

 cout<<s<<endl;

 int result = steadyGene(s);

 cout<<"result = "<<result<<endl;
}