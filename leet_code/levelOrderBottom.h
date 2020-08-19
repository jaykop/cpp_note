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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        if (!root) return {};
        
        vector<vector<int>> res = {{root->val}};
        vector<int> lv;
        
        queue<TreeNode*> q;
        int next = 2;
        q.push(root);
        
        while (!q.empty())
        {
            TreeNode* n = q.front();
            q.pop();
                        
            if (!n->left)
                --next;
            
            if (!n->right)
                --next;
            
            if (lv.size() < next)
            {
                if (n->left)
                {
                    q.push(n->left);
                    lv.push_back(n->left->val);   
                }
                if (n->right)
                {
                    q.push(n->right);
                    lv.push_back(n->right->val);
                }
            }
            
            if (next && lv.size() == next)
            {
                res.push_back(lv);
                lv.clear();
                next *= 2;
            }
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};