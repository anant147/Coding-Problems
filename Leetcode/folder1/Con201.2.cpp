#include<iostream>
#include<vector>
#include<cstring>
#include<utility>
#include<algorithm>
using namespace std;

char findKthBit(int n, int k) {
    
    int i,j,u,v,x,y,z;
    
    if (n==1 && k==1)
        return '0';
    
    vector<string> vstrg;
    
    vstrg.push_back("0");
    
    string temp = "";
    string temp2 = "";
    
    for (i=1;i<n;i++)
    {
        temp2 = vstrg[i-1];
        temp = temp2 + '1';
        // cout<<temp<<endl;
        
        for (j=temp2.length()-1;j>=0;j--)
        {
            if (temp2[j]=='0')
                temp = temp + '1';
            else
                temp = temp + '0';
        }
        
        vstrg.push_back(temp);
        temp = "";
    }
    
    return vstrg[n-1][k-1];
}

int main()
{
  int n=20;
  int k=1000000;	

  char ans = findKthBit(n,k);
  cout<<" ans -- "<<ans<<endl;
}