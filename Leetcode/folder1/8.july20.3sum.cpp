#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<utility>
#include<algorithm>
using namespace std;


    int binsearch(vector<int>& nums,int x)
    {
        int low,high,mid;
        
        low = 0;
        high = nums.size()-1;
        
        while(low<=high)
        {
            mid = (low+high)/2;
            
            if (nums[mid]==x)
                return 1;
            else if (nums[mid]<x)
                low = mid+1;
            else if (nums[mid]>x)
                high = mid-1;
        }
        
        return 0;
    }

    int binsearchPos(vector<int>& numPos,int x)
    {
        int low,high,mid;
        
        low = 0;
        high = numPos.size()-1;
        
        while(low<=high)
        {
            mid = (low+high)/2;
            
            if (numPos[mid]==x)
                return 1;
            else if (numPos[mid]<x)
                low = mid+1;
            else if (numPos[mid]>x)
                high = mid-1;
        }
        
        return 0;
    }

    int binsearchNeg(vector<int>& numNeg,int x)
    {
        int low,high,mid;
        
        low = 0;
        high = numNeg.size()-1;
        
        while(low<=high)
        {
            mid = (low+high)/2;
            
            if (numNeg[mid]==x)
                return 1;
            else if (numNeg[mid]<x)
                low = mid+1;
            else if (numNeg[mid]>x)
                high = mid-1;
        }
        
        return 0;
    }

    // vector<vector<int>> threeSum(vector<int>& nums) {
        
    //     int i,j,k,u,v,x,y,z;
        
    //     vector<vector<int>> result;
        
    //     if (nums.size()==0)
    //         return {};
        
    //     sort(nums.begin(),nums.end());

    //     // for (i=0;i<nums.size();i++)
    //     // 	cout<<nums[i]<<" ";
    //     // cout<<endl;
        
    //     vector<int> numPos;
    //     vector<int> numNeg;
        
    //     int n = nums.size();
        
    //     vector<int> temp;
        
    //     for (i=0;i<n;)
    //     {
    //     	// cout<<"i = "<<i<<endl;
    //         if (nums[i]<0)
    //         {
    //         	k = nums[i];
    //             numNeg.push_back(k);
                
    //             if (i<(n-1))
    //             {
    //                 if (nums[i]!=nums[i+1])
    //                     i++;
    //                 else
    //                 {
    //                     u = nums[i]+nums[i];
    //                     x = (-1)*u;
                        
    //                     v = binsearch(nums,x);
    //                     // cout<<v<<endl;
                        
    //                     if (v==1)
    //                     {
    //                         temp.push_back(nums[i]);
    //                         temp.push_back(nums[i]);
    //                         temp.push_back(x);
                            
    //                         result.push_back(temp);
    //                         temp.clear();
    //                     }
                        
    //                     j=i+1;
    //                     while(true)
    //                     {
    //                         if (nums[i]==nums[j] && j<n)
    //                             j++;
    //                         else
    //                             break;
    //                     }
                        
    //                     i=j;
                        
    //                 }
    //             }
    //             else
    //             	i++;
            
    //         }
    //         else
    //         {
    //            k = nums[i];
    //            numPos.push_back(k);

    //             if (i<(n-1))
    //             {
    //                 if (nums[i]!=nums[i+1])
    //                     i++;
    //                 else
    //                 {
    //                     u = nums[i]+nums[i];
    //                     x = (-1)*u;
                        
    //                     v = binsearch(nums,x);
    //                     // cout<<v<<endl;
                        
    //                     if (v==1)
    //                     {
    //                         temp.push_back(x);
    //                         temp.push_back(nums[i]);
    //                         temp.push_back(nums[i]);
                            
    //                         result.push_back(temp);
    //                         temp.clear();
    //                     }
                        
    //                     j=i+1;
    //                     while(true)
    //                     {
    //                         if (nums[i]==nums[j] && j<n)
    //                             j++;
    //                         else
    //                             break;
    //                     }
                        
    //                     i=j;
                        
    //                 }
    //             }
    //             else
    //                 i++;                
            
    //         }
    //     }
    //     // cout<<"loop end"<<endl;
        
    //     if (numNeg.size()==0 || numPos.size()==0)
    //     {
    //     	// cout<<"cond1"<<endl;
    //         return result;
    //     }

    //     // cout<<"numPos"<<endl;
    //     // for (i=0;i<numPos.size();i++)
    //     // 	cout<<numPos[i]<<" ";
    //     // cout<<endl;

    //     // cout<<endl;
    //     // cout<<"numNeg"<<endl;
    //     // for (i=0;i<numNeg.size();i++)
    //     // 	cout<<numNeg[i]<<" ";
    //     // cout<<endl;

        
    //     n = numNeg.size();
        
    //     for (i=0;i<n;i++)
    //     {
    //         for (j=i+1;j<n;j++)
    //         {
    //             u = numNeg[i] + numNeg[j];
    //             x = u*(-1);
                
    //             v = binsearchPos(numPos,x);
    //             // cout<<v<<endl;
                
    //             if (v==1)
    //             {
    //                 temp.push_back(numNeg[i]);
    //                 temp.push_back(numNeg[j]);
    //                 temp.push_back(x);
                    
    //                 result.push_back(temp);
    //                 temp.clear();
    //             }
                
    //         }
    //     }
        
    //     n = numPos.size();
        
    //     for (i=0;i<n;i++)
    //     {
    //         for (j=i+1;j<n;j++)
    //         {
    //             u = numPos[i] + numPos[j];
    //             x = u*(-1);
                
    //             v = binsearchNeg(numNeg,x);
    //             // cout<<v<<endl;
                
    //             if (v==1)
    //             {
    //                 temp.push_back(x);
    //                 temp.push_back(numPos[i]);
    //                 temp.push_back(numPos[j]);
                    
    //                 result.push_back(temp);
    //                 temp.clear();
    //             }
    //         }
    //     }
        
    //     return result;
        
    // }


    /////////////////////////

    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int i,j,k,u,v,x,y,z;
        
        vector<vector<int>> result;
        
        if (nums.size()<=2)
            return {};
        
        sort(nums.begin(),nums.end());

        // for (i=0;i<nums.size();i++)
        // 	cout<<nums[i]<<" ";
        // cout<<endl;
        
        vector<int> numPos;
        vector<int> numNeg;
        
        int n = nums.size();
        
        vector<int> temp;
        
        for (i=0;i<n;)
        {
        	// cout<<"i = "<<i<<endl;
            if (nums[i]<0)
            {
            	k = nums[i];
                numNeg.push_back(k);
                
                if (i<(n-1))
                {
                    if (nums[i]!=nums[i+1])
                        i++;
                    else
                    {
                        u = nums[i]+nums[i];
                        x = (-1)*u;
                        
                        v = binsearch(nums,x);
                        // cout<<v<<endl;
                        
                        if (v==1)
                        {
                            temp.push_back(nums[i]);
                            temp.push_back(nums[i]);
                            temp.push_back(x);
                            
                            result.push_back(temp);
                            temp.clear();
                        }
                        
                        j=i+1;
                        while(true)
                        {
                            if (nums[i]==nums[j] && j<n)
                                j++;
                            else
                                break;
                        }
                        
                        i=j;
                        
                    }
                }
                else
                	i++;
            
            }
            else
            {
               k = nums[i];
               numPos.push_back(k);

                if (i<(n-1))
                {
                    if (nums[i]!=nums[i+1])
                        i++;
                    else if (nums[i]==0)
                    {
                        int cnt=0;
                        
                        j=i;
                        while(true)
                        {
                            if (nums[j]==0 && j<n)
                            {
                                j++;
                                cnt++;
                            }
                            else
                                break;
                        }
                        
                        // if (cnt>=3)
                        // {
                        //     temp.push_back(0);
                        //     temp.push_back(0);
                        //     temp.push_back(0);
                            
                        //     result.push_back(temp);
                        //     temp.clear();
                        // }
                        
                        i=j;
                    }
                    else
                    {
                        u = nums[i]+nums[i];
                        x = (-1)*u;
                        
                        v = binsearch(nums,x);
                        // cout<<v<<endl;
                        
//                         if (v==1)
//                         {
//                             temp.push_back(x);
//                             temp.push_back(nums[i]);
//                             temp.push_back(nums[i]);
                            
//                             result.push_back(temp);
//                             temp.clear();
//                         }
                        
                        j=i+1;
                        while(true)
                        {
                            if (nums[i]==nums[j] && j<n)
                                j++;
                            else
                                break;
                        }
                        
                        i=j;
                        
                    }
                }
                else
                    i++;                
            
            }
        }
        // cout<<"loop end"<<endl;
        
        if (numNeg.size()==0 || numPos.size()==0)
        {
        	// cout<<"cond1"<<endl;
            return result;
        }
        else if (numNeg.size()<2 && numPos.size()<2)
            return result;

        // cout<<"numPos"<<endl;
        // for (i=0;i<numPos.size();i++)
        // 	cout<<numPos[i]<<" ";
        // cout<<endl;

        // cout<<endl;
        // cout<<"numNeg"<<endl;
        // for (i=0;i<numNeg.size();i++)
        // 	cout<<numNeg[i]<<" ";
        // cout<<endl;

        
        n = numNeg.size();
        
        for (i=0;i<n;i++)
        {
            for (j=i+1;j<n;j++)
            {
                u = numNeg[i] + numNeg[j];
                x = u*(-1);
                
                v = binsearchPos(numPos,x);
                // cout<<v<<endl;
                
                if (v==1)
                {
                    temp.push_back(numNeg[i]);
                    temp.push_back(numNeg[j]);
                    temp.push_back(x);
                    
                    result.push_back(temp);
                    temp.clear();
                }
                
            }
        }
        
        n = numPos.size();
        
        for (i=0;i<n;i++)
        {
            for (j=i+1;j<n;j++)
            {
                u = numPos[i] + numPos[j];
                x = u*(-1);
                
                v = binsearchNeg(numNeg,x);
                // cout<<v<<endl;
                
                if (v==1)
                {
                    temp.push_back(x);
                    temp.push_back(numPos[i]);
                    temp.push_back(numPos[j]);
                    
                    result.push_back(temp);
                    temp.clear();
                }
            }
        }
        
        return result;
    }

int main()
{
	// vector<int> nums = {-1, 0, 1, 2, -1, -4};
	vector<int> nums = {0,0,0,0};

	vector<vector<int>> result = threeSum(nums);

	int i,j;

	if (result.size()==0)
		cout<<"zero condition"<<endl;

	for (i=0;i<result.size();i++)
		{
			for (j=0;j<result[i].size();j++)
				cout<<result[i][j]<<" ";
			cout<<endl;
		}
}