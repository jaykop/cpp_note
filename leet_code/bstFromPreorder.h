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

    TreeNode* insert(TreeNode* root, int v) {

        if (!root)
            return new TreeNode(v);

        else if (root->val < v)
            root->right = insert(root->right, v);
        else
            root->left = insert(root->left, v);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {

        TreeNode* root = new TreeNode(preorder[0]);

        for (int i = 1; i < int(preorder.size()); i++) {
            insert(root, preorder[i]);
        }

        return root;
    }
};