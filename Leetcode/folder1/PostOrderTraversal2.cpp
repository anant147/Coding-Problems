/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        
    stack<TreeNode *> stk;
    vector<int> oppres; 
    vector<int> result;
    TreeNode *curr;
    TreeNode *temp;
        
    int i,v,k=0;
    int cnt=0;
    
    if(root==NULL)
        return {};
        
    curr=root;
        
    stk.push(curr);
    v=curr->val;
    oppres.push_back(v);
    // cout<<"sit "<<cnt++<<"val inserted = "<<v<<endl;    
        
        
    while(!stk.empty())
    {
        curr=stk.top();
        
        while(curr->right!=NULL)
        {
            curr=curr->right;
            v=curr->val;
            oppres.push_back(v);
            // cout<<"sit "<<cnt++<<" (case 1 )val inserted = "<<v<<endl;
            stk.push(curr);
        }
        
        while(curr->left==NULL)
        {
            stk.pop();
            // cout<<"sit "<<cnt++<<" (case 2) val popped"<<endl;
            if(stk.empty())
            {
                k=1;break;
            }
            curr=stk.top();
        }
        
        if(k==1)
            break;
        
        if(curr->left!=NULL)
        {
            curr=curr->left;
            stk.pop();
            // cout<<"sit "<<cnt++<<" (case 3) val popped"<<endl;
            v=curr->val;
            oppres.push_back(v);
            stk.push(curr);
            // cout<<"sit "<<cnt++<<" (case 4 )val inserted = "<<v<<endl;
        }
        
    }
        
    for(i=oppres.size()-1;i>=0;i--)
    {
        // cout<<oppres[i]<<" ";
        result.push_back(oppres[i]);
    }
    // cout<<endl;    
        
    return result; 
        
    }
};