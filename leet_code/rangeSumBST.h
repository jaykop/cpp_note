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
    int dfs(TreeNode* root, int L, int R) {

        int sum = 0;
        int val = root->val;
        if (L <= val && val <= R)
            sum += val;
        if (root->left)
            sum += dfs(root->left, L, R);
        if (root->right)
            sum += dfs(root->right, L, R);

        return sum;
    }

    int rangeSumBST(TreeNode* root, int L, int R) {

        return dfs(root, L, R);
    }
};