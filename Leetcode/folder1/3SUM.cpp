class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
     int i,j,k;
     int iszero=0;
     int count = 0;  
     int w,x,y,z;   
     int cnta,cntb,a,b,u;
     int cond;   
        
     vector<vector<int>> vtripl;
        
     vector<int> pos;
     vector<int> neg;   
        
     int poslen,neglen,cnts;   
        
     //map<int,bool> mp;   
     
     sort(nums.begin(),nums.end());
          
         for(i=0;i<nums.size();i++)
         {
             k=nums[i];

             if(k<0)
             {
                 neg.push_back(k);
             }
             else if(k==0)
             {
                 iszero++;
             }
             else
             {
                 pos.push_back(k);
             }
         }
        
//         for(i=0;i<nums.size();)
//         {
//             mp[nums[i]]=true;
            
//             cnts=0;
//             for(j=i+1;j<nums.size();)
//             {
                
//             }
//         }
        
        if(iszero>0)
        {
            neg.push_back(0);
            
            if(iszero>=3)
            {
                vector<int> v;
                v.push_back(0);v.push_back(0);v.push_back(0);
                
                vtripl.push_back(v);
                count++;
            }
        }
        
        poslen = pos.size();
        neglen = neg.size();
        
        if(poslen==0 || neglen==0 ||(poslen==1 && neglen==1))
        {
            return vtripl;
        }
        else if(poslen==1 && neglen>1)
        {
            w=pos[0];
            cond=0;
            
            for(i=0;i<neg.size()-1;i++)
            {
                for(j=i+1;j<neg.size();j++)
                {
                    a=neg[i];b=neg[j];
                    
                    if((a+b+w)==0)
                    {
                        vector<int> v;
                        
                        v.push_back(a); v.push_back(b); v.push_back(w);
                        
                        vtripl.push_back(v);
                        cond=1;
                        break;
                    }
                }
                
                if(cond==1)
                    break;
            }
            
            return vtripl;
        }
        else if(poslen>1 && neglen==1)
        {
         w=neg[0];
            cond=0;
            
            for(i=0;i<pos.size()-1;i++)
            {
                for(j=i+1;j<pos.size();j++)
                {
                    a=pos[i];b=pos[j];
                    
                    if((a+b+w)==0)
                    {
                        vector<int> v;
                        
                         v.push_back(w); v.push_back(a); v.push_back(b);
                        
                        vtripl.push_back(v);
                        cond=1;
                        break;
                    }
                }
                
                if(cond==1)
                    break;
            }
            
            return vtripl;   
            
            
        }
        else
        {
        
        for(i=0;i<neg.size()-1;i++)
        {
            for(j=i+1;j<neg.size();j++)
            {
                w=neg[i]+neg[j];
                
                if(binary_search(pos.begin(),pos.end(),-w))
                {
                    vector<int> v;
                    v.push_back(neg[i]);
                    v.push_back(neg[j]);
                    v.push_back(-w);
                    
                    count++;
                    vtripl.push_back(v);
                    
                    b=neg[j];
                    cntb=0;
                    
                    for(u=j+1;u<neg.size();u++)
                    {
                        if(neg[u]==b)
                            cntb++;
                        else
                            break;
                    }
                    
                    j=j+cntb;
                }
                
            
            }
            
            a=neg[i];
            cnta=0;
            
            for(u=i+1;u<neg.size();u++)
            {
                if(neg[u]==a)
                    cnta++;
                else
                    break;
            }
            i=i+cnta;
        }
        
         
        for(i=0;i<pos.size();i++)
        {
            for(j=i+1;j<pos.size();j++)
            {
                w=pos[i]+pos[j];
                
                if(binary_search(neg.begin(),neg.end(),-w))
                {
                    vector<int> v;
                    v.push_back(-w); v.push_back(pos[i]); v.push_back(pos[j]);
                    
                    count++;
                    
                    vtripl.push_back(v);
                    
                    b=pos[j];
                    cntb=0;
                    
                    for(u=j+1;u<pos.size();u++)
                    {
                        if(pos[u]==b)
                            cntb++;
                        else
                            break;
                    }
                    j=j+cntb;
                    
                    
                }
                
            }
            
            a=pos[i];
            cnta=0;
            
            for(u=i+1;u<pos.size();u++)
            {
                if(pos[u]==a)
                    cnta++;
                else
                    break;
            }
            i=i+cnta;
        }
        
        
        return vtripl;
            
        }      
        
    }
};