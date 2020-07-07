/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        
        vector<int> v;
        stack<TreeNode*> s;
        TreeNode* n = root;
        while (!s.empty() || n)
        {
            if (n)
            {
                s.push(n);
                n = n->left;
                // if (n && s.top()->val < n->val) return false;
            }
            else 
            {
                //n = s.top();
                TreeNode* next = s.top();
                v.push_back(next->val);
                n = next->right;
                //if (n && next->val < n->val) return false;
                s.pop();
            }
        }
         for (int i = 1; i < v.size(); ++i)
             if (v[i-1] >= v[i]) return false;
        return true;
    }
};