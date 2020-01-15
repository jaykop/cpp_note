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
    
    int dfs (TreeNode* tree, 
              int gp, int p){
        
        if (!tree) return 0;
        
        int val = tree->val;
        int num = 0;
        gp % 2 == 0 ? num += val : num;
        num += dfs(tree->left, p, val);
        num += dfs(tree->right, p, val);
        
        return num;
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        
        int sum = 0;
        sum = dfs(root, -1, -1);
        
        return sum;
    }
};