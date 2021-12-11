/**

Binary Tree preorder traversal
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
    vector<int> preorderTraversal(TreeNode* root) {
    
        TreeNode *curr;
        unordered_map <TreeNode *,int> cont;
        vector<int> pre;
        
        stack<TreeNode *> stk;
        int i=0;
        curr=root;
        if(curr==NULL)
            return {};
        
        int v;
        v=curr->val;
        
        stk.push(curr);
        pre.push_back(v);
        cout<<"for i = "<<i++<<" value inserted = "<<v<<endl;    
        cont.insert({curr,1});
                
        while(!stk.empty())
        {
            curr=stk.top();
            if(cont[curr]==1)  // ( it has visited once)
            {
                if(curr->left!=NULL)
                {
                    cont[curr]=2;
                    curr=curr->left;
                    v=curr->val;
                    
                    pre.push_back(v);
                    cout<<"for i = "<<i++<<" value inserted = "<<v<<endl; 
                    stk.push(curr);
                    cont.insert({curr,1});
                    
                }
                else if(curr->right!=NULL)
                {
                    cont[curr]=2;
                    stk.pop();
                    curr=curr->right; 
                    v=curr->val;
                    pre.push_back(v);
                    cout<<"for i = "<<i++<<" value inserted = "<<v<<endl; 
                    stk.push(curr);
                    cont.insert({curr,1});
                }
                else
                {
                    stk.pop();
                }
            }
            else
            {
                if(curr->right!=NULL)
                {
                    cont[curr]=3;
                    stk.pop();
                    curr=curr->right; 
                    v=curr->val;
                    pre.push_back(v);
                    cout<<"for i = "<<i++<<" value inserted = "<<v<<endl; 
                    stk.push(curr);
                    cont.insert({curr,1});
                    
                }
                else
                {
                    stk.pop();
                }
            }
        }
            
        return pre;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        
        vector<int> ret = Solution().preorderTraversal(root);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
