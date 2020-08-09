https://leetcode.com/problems/distribute-coins-in-binary-tree/discuss/221939/C%2B%2B-with-picture-post-order-traversal

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
    
    int count = 0;
    void search(TreeNode* t, int budget, int costSoFar)
    {
        TreeNode* l = t->left;
        TreeNode* r = t->right;
        
        if (!(budget >= t->val && t->val != 0))
        {
            costSoFar = 2 * costSoFar + 1;
        }
        std::cout << costSoFar;
        count += costSoFar;
        
        if (l) search(l, t->val, costSoFar);
        if (r) search(l, t->val, costSoFar);

    };
    
    int distributeCoins(TreeNode* root) {
        
        search(root, root->val, 0);
        return count;
    }
};