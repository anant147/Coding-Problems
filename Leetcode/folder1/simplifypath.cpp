// simplify path

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

string simplifyPath(string path)
{
 int i,j,k;
 stack<string> dirname;

 int ps = path.size();
  
 // cout<<"ps = "<<ps<<endl; 

 string result;

 for(i=0;i<path.size();)
 {
 	if(path[i]=='/')
 	{
     i++; 
     // cout<<" case 1 value of i = "<<i<<endl;
 	}
 	else if(i>0 && path[i-1]=='/' && path[i]=='.' && path[i+1]=='/')
 	{
 		i++; 
 		// cout<<"case 2 value of i = "<<i<<endl;
 	}
 	else if(i>0 && path[i-1]=='/' && path[i]=='.' && path[i+1]=='.' && path[i+2]=='/')
 	{
 		i=i+2;
        
        if(!dirname.empty())
 		dirname.pop(); 

 	    // cout<<"case 3 value of i = "<<i<<endl;
 	}
 	else if(i>0 && path[i-1]=='/' && path[i]=='.' && path[i+1]=='.' && (i+1)==(ps-1))
 	{
 		i=i+2;
        
        if(!dirname.empty())
 		dirname.pop(); 

 	    // cout<<"case 3 value of i = "<<i<<endl;
 	}
 	else
 	{
 	  string temp;

      for(j=i;j<path.size();j++)
      {
       if(path[j]!='/')
       	{
          temp.push_back(path[j]);
       	}
       	else
       		break;
      }
      
      dirname.push(temp); 

      i=j; 
      // cout<<"case 4 value of i = "<<i<<endl;
 	}

 	if(i==ps)
 	{
 		// cout<<"value of i at break = "<<i<<endl;
 		break;
 	}
 }

 if(dirname.empty())
 {
 	// cout<<"cond 1 satisfy"<<endl;
 	result="/"; 
 }
 else
 {
 	// cout<<"cond 2 satisfy"<<endl;
 	result="";

 	while(!dirname.empty())
 	{
 		string intmd = dirname.top();

 		dirname.pop();

 		result = "/"+intmd+result;

 		// cout<<"intermediate result = "<<result<<endl;
 	}
 }

  // cout<<"final result = "<<result<<endl;

 return result;
}

int main()
{
	// string path = "/home//foo/";

	// string path = "/home/";

	// string path = "/../";

	// string path = "/a/./b/../../c/";

	// string path = "/a/./b/../../c/";

	string path = "/a//b////c/d//././/..";





    string result = simplifyPath(path);

	cout<<result<<endl;
}