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
    vector<vector<int>> res;
    
    void rec(TreeNode* n, int sum, vector<int> v, int add)
    {
        v.emplace_back(n->val);
        add += v.back();
        
        if (!n->left && !n->right)
        {
            if (add == sum)
                res.emplace_back(v);
        }
        
        else {
            if (n->left)
                rec(n->left, sum, v, add);
            
            if (n->right)
                rec(n->right, sum, v, add);
        }
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        
        if (root) {
            vector<int> v;
            rec(root, sum, v, 0);
        }
        
        return res;
    }
};