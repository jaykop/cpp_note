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
    
    void rec(TreeNode* n, int sum, int add, bool& res)
    {       
        add += n->val;
        if (add == sum && !n->left && !n->right)
        {
            res = true;
            return;
        }
        
        if (!res && n->left)
            rec(n->left, sum, add, res);
        if (!res && n->right)
            rec(n->right, sum, add, res);
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        
        if (!root)
           return false;
        
        bool res = false;
        rec(root, sum, 0, res);
        return res;
    }
};