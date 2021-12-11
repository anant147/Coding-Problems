#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm> 
using namespace std;

// dynamic programming video 3
// box stalking

bool sortvect(const vector<int>& a1,const vector<int>& a2)
{
  if (a1[3]==a2[3])
  {
     if (a1[0]==a2[0])
     	return a1[1]>a2[1];
     else
     	return a1[0]>a2[0];
  }
  else
  {
  	return a1[3]>a2[3];
  }
}


int boxStacking(int a[][3],int n)
{
	int i,j,k,m,o,l,s1,s2,s3;
	int barea;

	vector<vector<int>> v;

	// start of for loop - all configuration formation start
	for (i=0;i<n;i++)
	{
      s1=a[i][0]; s2=a[i][1]; s3 = a[i][2];
      vector<int> v1;

      if (s1==s2 && s2==s3) // all sides of cuboid  are same
      {
       barea = s1*s2;
      
       v1.push_back(s1);  v1.push_back(s2);  v1.push_back(s3); v1.push_back(barea);
       cout<<" cond1 "<<endl;

       v.push_back(v1);

       v1.clear();

      }
      else if (s1==s2 || s2==s3 || s1==s3) // two sides of cuboid are same
      {

         if (s1==s2) 
         {

		       barea = s1*s2;
		       
		       v1.push_back(s1);  v1.push_back(s2);  v1.push_back(s3); v1.push_back(barea);
		       cout<<" cond2 "<<endl;

		       v.push_back(v1);

		       v1.clear();

		       if (s1<s3) // if s3 is grater than s1
		       {
		        barea = s1*s3;
		       
		       v1.push_back(s3);  v1.push_back(s1);  v1.push_back(s2); v1.push_back(barea);
		       cout<<" cond3 "<<endl;

		       v.push_back(v1);

		       v1.clear();
		       }
		       else
		       {
		        barea = s1*s3;
		      
		       v1.push_back(s1);  v1.push_back(s3);  v1.push_back(s2); v1.push_back(barea);
		       cout<<" cond4 "<<endl;

		       v.push_back(v1);

		       v1.clear();
		       }
         }
         else if (s2==s3)
         {
             barea = s2 * s3;

             v1.push_back(s2);  v1.push_back(s3);  v1.push_back(s1); v1.push_back(barea);
             cout<<" cond5 "<<endl;

             v.push_back(v1);
             v1.clear();

             if (s2 < s1) // if s1 is grater than s2
             {
               barea = s2 * s1;

               v1.push_back(s1);  v1.push_back(s2);  v1.push_back(s3); v1.push_back(barea);
               cout<<" cond6 "<<endl;
               v.push_back(v1);
               v1.clear();

             }
             else
             {
              barea = s2 * s1;

              v1.push_back(s2); v1.push_back(s1);  v1.push_back(s3); v1.push_back(barea);
              cout<<" cond7 "<<endl;
              v.push_back(v1);
              v1.clear();
             }


         }
         else // s1==s3
         {
             barea = s1 * s3;

             v1.push_back(s1);  v1.push_back(s3);  v1.push_back(s2); v1.push_back(barea);
             cout<<" cond8 "<<endl;

             v.push_back(v1);
             v1.clear();

             if (s2 < s1) // if s3 is grater than s1
             {
               barea = s2 * s1;

               v1.push_back(s1);  v1.push_back(s2);  v1.push_back(s3); v1.push_back(barea);
               v.push_back(v1);
               v1.clear();

             }
             else
             {
              barea = s2 * s1;

              v1.push_back(s2); v1.push_back(s1);  v1.push_back(s3); v1.push_back(barea);
              cout<<" cond9 "<<endl;
              v.push_back(v1);
              v1.clear();
             }
         }
      }
      else // no sides of the cube are same
      {
           if (s1 < s2)
           {
               barea = s2 * s1;

               v1.push_back(s2);  v1.push_back(s1);  v1.push_back(s3); v1.push_back(barea);
               cout<<" cond10 "<<endl;
               v.push_back(v1);
               v1.clear();

           }
           else
           {
               barea = s2 * s1;

               v1.push_back(s1);  v1.push_back(s2);  v1.push_back(s3); v1.push_back(barea);
               cout<<" cond11 "<<endl;
               v.push_back(v1);
               v1.clear();

           }

           if (s2 < s3)
           {
             barea = s2 * s3;

             v1.push_back(s3);  v1.push_back(s2);  v1.push_back(s1); v1.push_back(barea);
             cout<<" cond12 "<<endl;

             v.push_back(v1);
             v1.clear();
           }
           else
           {
             barea = s2 * s3;

             v1.push_back(s2);  v1.push_back(s3);  v1.push_back(s1); v1.push_back(barea);
             cout<<" cond13 "<<endl;

             v.push_back(v1);
             v1.clear();
           }

           if (s1 < s3)
           {
            barea = s1*s3;
		       
		    v1.push_back(s3);  v1.push_back(s1);  v1.push_back(s2); v1.push_back(barea);
		    cout<<" cond14 "<<endl;

		    v.push_back(v1);
		    v1.clear();
           }
           else
           {
             barea = s1*s3;
		       
		     v1.push_back(s1);  v1.push_back(s3);  v1.push_back(s2); v1.push_back(barea);
		     cout<<" cond15 "<<endl;

		     v.push_back(v1);

		     v1.clear();
           }
      }

	}

	// end of for loop - all configuration formation done

	cout<<"printing all config before required sorting"<<endl;


	for (i=0;i<v.size();i++)
	{
		cout<<"for conf - "<<i<<" val -- "<<v[i][0]<<" , "<<v[i][1]<<" , "<<v[i][2]<<" , "<<v[i][3]<<endl;
	}

	cout<<endl;
	
	sort(v.begin(),v.end(),sortvect);

	cout<<"printing all config after required sorting"<<endl;
	

	for (i=0;i<v.size();i++)
	{
		cout<<"for conf - "<<i<<" val -- "<<v[i][0]<<" , "<<v[i][1]<<" , "<<v[i][2]<<" , "<<v[i][3]<<endl;
	}

	cout<<endl;

	// initializing max and result array

	int size = v.size();

	int maximum[size];
	int result[size];

	for (i=0;i<size;i++)
	{
		maximum[i]=v[i][2];
		result[i]=i;
	}

	cout<<"initial value of maximum and result array :- "<<endl;

	for (i=0;i<size;i++)
	{
		cout<<"for i - "<<i<<" value -- "<<maximum[i]<<" , "<<result[i]<<endl;
	}

	for (i=1;i<size;i++)
	{
		for (j=0;j<i;j++)
		{
          if (v[j][0]>v[i][0] && v[j][1]>v[i][1])
          {
          	if ((maximum[j]+v[i][2]) > maximum[i])
          	{
          		maximum[i] = maximum[j]+v[i][2];
          		result[i] = j;
          	}
          }
		}
	}

	cout<<"final value of maximum and result array :- "<<endl;

	for (i=0;i<size;i++)
	{
		cout<<"for i - "<<i<<" value -- "<<maximum[i]<<" , "<<result[i]<<endl;
	}

	int maxresult = -1;
	int index = -1;

	// finding the maximum height obtained

	for (i=0;i<size;i++)
	{
		if(maxresult < maximum[i])
		{
			maxresult = maximum[i];
			index = i;
		}
	}

	// finding the element contributing to maximum height

	int cond=1;

	k = index;

	vector<int> elist;

	while (cond == 1)
	{

      elist.push_back(k);

      if (k==result[k])
      {
      	cond=0;
      	break;
      }

      k = result[k];
	}


    // print element and their height
	cout<<" element and their height"<<endl;

	for (i=0;i<elist.size();i++)
	{
		k = elist[i];

		cout<<"for element - "<<k<<" ,height - "<<v[k][2]<<" , length - "<<v[k][0]<<" , width - "<<v[k][1]<<endl;
	}

	cout<<"final max value - "<<maxresult<<endl;



	return maxresult;


}

int main()
{
	// int n = 2;
	// int a[2][3] = {{1,2,4},{3,2,5}};

	// int n = 3;
	// int a[3][3] = {{1,2,4},{3,2,5},{4,4,4}};

	int n = 3;
	int a[3][3] = {{1,2,4},{3,2,5},{4,5,4}};


	int answer = boxStacking(a,n);

	cout<<"answer = "<<answer<<endl;
}