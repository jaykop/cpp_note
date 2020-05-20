#pragma once
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
    void inOrder(TreeNode* root, deque<int>& v)
    {
        TreeNode* l = root->left;
        TreeNode* r = root->right;
        if (l)
            inOrder(l, v);
        v.emplace_back(root->val);
        if (r)
            inOrder(r, v);
    }
    TreeNode* newTree(deque<int>& v)
    {
        if (v.empty()) return nullptr;

        int val = v.front();
        v.pop_front();
        TreeNode* t = new TreeNode(
            val,
            nullptr,
            newTree(v));

        return t;
    }

    TreeNode* increasingBST(TreeNode* root) {

        deque<int> values;
        inOrder(root, values);
        return newTree(values);
    }
};