// CPP program to demonstrate working of STL stack 
#include <iostream> 
#include <stack> 
using namespace std; 
  
bool isValid(string s) {
        
        stack <char> stk;
        
        int i,j,k,n,cond;
        
        n=s.size();
        
        if(s=="")
        return true;
        else if(n%2==1)
        return false;
        else 
        {
         cond=0;
         
             for(i=0;i<n;i++)
             {
                   if(s[i]=='(')
                   stk.push('(');
                   else if(s[i]=='[')
                   stk.push('[');
                   else if(s[i]=='{')
                   stk.push('{');
                   else if(s[i]==')')
                   {
                        if(stk.top()=='(' && !stk.empty())
                        stk.pop();
                        else
                        {
                        cond=1;break;
                        }
                   }
                   else if(s[i]==']')
                   {
                        if(stk.top()=='[' && !stk.empty())
                        stk.pop();
                        else
                        {
                        cond=1;break;
                        }
                   }
                   else if(s[i]=='}')
                   {
                        if(stk.top()=='{' && !stk.empty())
                        stk.pop();
                        else
                        {
                        cond=1;break;
                        }
                   }
                   
             }
             
             if(cond==0 && stk.empty())
             return true;
             else 
             return false;
         
        }
        
        
    }
  
int main () 
{ 
   
   int i,j,k;
   
   string s;
   
   cin>>s;
   
   k=s.size();
   
   bool val = isValid(s);
   
   cout<<val<<endl;
   
} 
