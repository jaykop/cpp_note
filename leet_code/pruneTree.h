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
    
    TreeNode* dfs (TreeNode* tree) {
        
        if (!tree->val// tree val is 0,
           && !tree->right
           && !tree->left) {
            delete tree;
            return nullptr;
        }
        else {
            if (tree->left)
                tree->left = dfs(tree->left);
            if (tree->right)
                tree->right = dfs(tree->right);
            
            if (!tree->val// tree val is 0,
            && !tree->right
            && !tree->left) {
                delete tree;
                return nullptr;
            }
            return tree;
        }
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        
        dfs(root);
        return root;
    }
};