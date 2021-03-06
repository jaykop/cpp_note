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
    int sum = 0;
    TreeNode* bstToGst(TreeNode* root) {

        if (!root) return nullptr;

        // starts from rightdown side
        TreeNode* right = bstToGst(root->right);

        root->val += sum;
        sum = root->val;

        TreeNode* left = bstToGst(root->left);

        return root;
    }
};
