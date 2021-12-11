class Solution {
public:
    string removeDuplicateLetters(string s) {
        
 stack<char> stk1,stk2,stk3,stk4;
        int i,j,k;
        int cond1,cond2,cond3;
        int a1[26],a2[26];
        int pos1[26],pos2[26];
        
        int cond4,cond5,cond6,cond7;
        char tmpr1,tmpr2,tmpr3,tmpr4;
        int val1,val2,val3,val4;
        
        if(s.size()==0)
            return "";
        
        for(i=0;i<26;i++)
        {
            a1[i]=0;
            a2[i]=0;
            pos1[i]=-1;
            pos2[i]=-1;
        }
        
        int u,v;
        char tok,temp1,temp2,temp3,temp4;
        
        for(i=0;i<s.size();i++)
        {
            tok=s[i];
            u=s[i]-97;
            
            if(a1[u]==0)
            {
                stk1.push(tok);
                a1[u]=1;
                pos1[u]=i;
                cout<<"case 1  val inserted = "<<tok<<endl;
            }
            else
            {
             
             if(stk1.top()!=tok)
             {
                 cond1=0; // checking any element smaller than tok
                 temp1=stk1.top();
                 stk1.pop();
                 stk2.push(temp1);
                 
                 if(temp1<tok)
                 {
                     cond1=1;
                     cout<<"case 2 "<<" temp1 = "<<temp1<<" tok =   "<<tok<<endl;
                 }
                 cond2=0; // check while loop
                 cond3=0; // checking element is in right position or not
                 
                 while(!cond2)
                 {
                     temp2=stk1.top();
                     stk1.pop();
                     stk2.push(temp2);
                     
                     if(temp2==tok)
                     {
                         if(temp2>temp1)
                           cond3=1;
                         
                         cout<<"while loop end with c3= "<<cond3<<endl;
                         
                         cond2=1;
                     }
                     else
                     {
                         if(temp2<tok)
                         {
                             cond1=1;
                             cout<<"case 3 "<<" temp2 = "<<temp2<<" tok =   "<<tok<<endl;
                         }
                             
                     }
                     temp1=temp2;
                 }
                 
                 if(cond3==1) // adding element at proper place
                 {
                     stk2.pop();
                     
                     while(!stk2.empty())
                     {
                         temp1=stk2.top();
                         stk2.pop();
                         stk1.push(temp1);
                     }
                     
                     pos1[u]=i;
                     stk1.push(tok);
                     
                     cout<<"case 4 element added at last position = "<<tok<<endl;
                     
                 }
                 else
                 {
                     while(!stk2.empty())
                     {
                         temp1=stk2.top();
                         stk2.pop();
                         stk1.push(temp1);
                     }
                     
                     u=tok-97;
                     
                     if(cond1==1 && a2[u]==0)
                     {
                         a2[u]=1;pos2[u]=i;
                         stk3.push(tok);
                     }
                 }
                 
                 if(!stk3.empty() && cond3==1)
                 {
                     while(!stk3.empty())
                     {
                         temp1=stk3.top();
                         stk3.pop();
                         stk4.push(temp1);
                     }
                     
                     cout<<"stk4 is filled"<<endl;
                     //most impotant
                     
                     while(!stk4.empty())
                     {   
                         char tmpvr=stk4.top();
                         stk4.pop();
                         
                         if(stk1.top()!=tmpvr)
                         {
                           cond4=0;cond5=0;
                           temp1=stk1.top();
                           stk1.pop();
                           stk2.push(temp1);
                             
                           while(!cond4)
                           {
                               temp2=stk1.top();
                               stk1.pop();
                               stk2.push(temp2);
                               
                               if(temp2==tmpvr)
                               {
                                if(temp2>temp1)
                                {
                                    val1=temp1-97;
                                    val2=tmpvr-97;
                                    
                                    if(pos1[val1]<pos2[val2])
                                    {
                                        cond5=1;
                                    }
                                }
                                   cond4=1;
                               }
                               
                               temp1=temp2;
                               
                           }
                             
                           if(cond5==1)
                           {
                               stk2.pop();
                               temp1=stk2.top();
                               stk2.pop();
                               stk1.push(temp1);
                               cond6=0;
                               
                               while(!stk2.empty())
                               {
                                   temp1=stk2.top();
                                   stk2.pop();
                                   val3=temp1-97;
                                   
                                   if(cond6==0)
                                   {
                                       
                                    if(pos1[val3]<pos2[val2])
                                    {
                                        stk1.push(temp1);
                                    }
                                    else
                                    {
                                        cond6=1;
                                        stk1.push(tmpvr);
                                        stk1.push(temp1);
                                    }
                                   }
                                   else
                                   {
                                       stk1.push(temp1);
                                   }
                               }
                           }
                           else
                           {
                            stk3.push(tmpvr);
                            
                            while(!stk2.empty())
                            {
                               temp1=stk2.top();
                               stk2.pop();
                               stk1.push(temp1); 
                            }   
                           }   
                         }   
                     }       
                 }      
             }
            }
        }
        
        string result="";
        
        while(!stk1.empty())
        {
            temp1=stk1.top();
            result=temp1+result;
            stk1.pop();
        }
        
        cout<<"final result = "<<result<<endl;
        
        
      return result;  
        
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        string ret = Solution().removeDuplicateLetters(s);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}