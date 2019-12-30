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
    
    void dfsSum(TreeNode* tree, int depth, int& deepest, int& sum){
        
        // update the deepest node
        if (depth > deepest) {
            deepest = depth;
            sum = tree->val;
        }
        
        // sum up the total sum
        else if (depth == deepest)
            sum += tree->val;
        
        // go deeper
        if (tree->left)
            dfsSum(tree->left, depth+1, deepest, sum);
        if (tree->right)
            dfsSum(tree->right, depth+1, deepest, sum);
        
    }
    
    int deepestLeavesSum(TreeNode* root) {
     
        int sum = 0;
        int deepest = 0;
        dfsSum(root, 0, deepest, sum);
        
        return sum;
    }
};