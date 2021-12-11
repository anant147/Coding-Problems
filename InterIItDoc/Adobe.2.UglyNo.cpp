#include<bits/stdc++.h>
using namespace std;

int nthUglyNumber(int n)
{
    
   long int i,j,k,l,u,v,x,y,z;
    
   long int maxval = pow(2,sizeof(int)*8-1)-1;
    
    vector<long int> vec2;
    vector<long int> vec3;
    vector<long int> vec5;
    
    k = 1;
    vec2.push_back(k);
    
    while(true)
    {
        l = vec2.size();
        k = vec2[l-1];
        
        k = k*2;
        if (k<=maxval)
            vec2.push_back(k);
        else
            break;
    }
    
    k = 1;
    vec3.push_back(k);
    
    while(true)
    {
        l = vec3.size();
        k = k*3;
        
        if (k<=maxval)
            vec3.push_back(k);
        else
            break;
    }
    
    k=1;
    vec5.push_back(k);
    
    while(true)
    {
        l = vec5.size();
        k = k*5;
        
        if (k<=maxval)
            vec5.push_back(k);
        else
            break;
    }
    
    vector<long int> vec23;
    vector<long int> vec25;
    vector<long int> vec35;
    
    for (i=0;i<vec2.size();i++)
    {
        for (j=0;j<vec3.size();j++)
        {
            k = vec2[i] * vec3[j];
            
            if (k<=maxval)
                vec23.push_back(k);
        }
    }
    
    for (i=0;i<vec2.size();i++)
    {
        for (j=0;j<vec5.size();j++)
        {
            k = vec2[i] * vec5[j];
            
            if (k<=maxval)
                vec25.push_back(k);
        }
    }
    
    
    for (i=0;i<vec3.size();i++)
    {
        for (j=0;j<vec5.size();j++)
        {
            k = vec3[i] * vec5[j];
            
            if (k<=maxval)
                vec35.push_back(k);
        }
    }
    
    sort(vec23.begin(),vec23.end());
    sort(vec25.begin(),vec25.end());
    sort(vec35.begin(),vec35.end());
    
    vector<long int> vec235;
    
    for (i=0;i<vec23.size();i++)
    {
        for (j=0;j<vec5.size();j++)
        {
            k = vec23[i] * vec5[j];
            
            if (k<=maxval)
                vec235.push_back(k);
        }
    }
    
    sort(vec235.begin(),vec235.end());
    
    u = vec235[n-1];
    
    int ans = int(u);
    
    return ans;
    

}

int main()
{
	cout<<" Adobe question 2"<<endl;
	cout<<" Leetcode 264. Ugly Number II "<<endl;
	cout<<endl;

	// Write a program to find the n-th ugly number.
	// Ugly numbers are positive numbers whose prime factors only include 2, 3, and 5

	int n = 10;
	cout<<" n = "<<n<<endl;

	int answer = nthUglyNumber(n);

	cout<<" answer = "<<answer<<endl;
}