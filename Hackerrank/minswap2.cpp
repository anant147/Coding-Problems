// min swap 2

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int minimumSwaps(vector<int> arr) {

unordered_map<int,int> store;
int i,j,cnt=0,temp,loc,val1;

    for(i=0;i<arr.size();i++)
    {
     store[arr[i]]=i;
    }
    
    for(i=0;i<arr.size();i++)
    {
     if(arr[i]!=i+1)
     {
      val1=arr[i];
      loc = store[i+1];
      
      store[i+1]=i;
      store[val1]=loc;
      
      arr[i]=i+1; arr[loc]=val1;
      cnt++;
     }
     
    }
    
    

return cnt;

}

int main()
{
 //int a[7]={7, 1, 3, 2, 4, 5, 6};

// vector<int> arr(a,a+7);

// int a[4]={4,3,1,2};
 // vector<int> arr(a,a+4);
 
  // int a[5]={2,3,4,1,5};
 // vector<int> arr(a,a+5);
 
 int a[7]={1,3,5,2,4,6,7};
 vector<int> arr(a,a+7);
  
 

 int result=minimumSwaps(arr);

 cout<<result<<endl;
}