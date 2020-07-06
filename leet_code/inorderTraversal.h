#pragma once
class Solution {
public:
    
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> ans;
    
        stack<TreeNode*> s;
        TreeNode* node = root;
        
        while (!s.empty() || node)
        {
            if (node)
            {
                s.push(node);
                node = node->left;
            }
            
            else
            {
                node = s.top();
                ans.push_back(node->val);
                s.pop();
                node = node->right;
            }
        }

        return ans;
    }
};