#pragma once
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

    int rangeSumBST(TreeNode* root, int L, int R) {
        
        if (!root) return 0;
        
        int val = root->val;
        int sum = val;

        if (L <= val && val <= R)
            sum += val + rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);

        return sum;
    }
};