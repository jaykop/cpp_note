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
    TreeNode* searchBST(TreeNode* root, int val) {
        
        if (root->val != val) {
            
            TreeNode* left = nullptr;
            TreeNode* right = nullptr;
            
            if (root->left)
                left = searchBST(root->left, val);
            if (root->right)
                right = searchBST(root->right, val);
            
            return left == nullptr ? right : left;
        }
        else 
            return root;
    }
};