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
#include <vector>
using namespace std;

 struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    
};

class Solution {
public:

    void inOrder(TreeNode* tree, vector<int>& array) {

        if (tree->left)
            inOrder(tree->left, array);

        array.emplace_back(tree->val);

        if (tree->right)
            inOrder(tree->right, array);
    }

    TreeNode* buildTree(vector<int>& array, int l, int r)
    {
        if (l > r )
            return nullptr;

        int mid = (r + l) / 2;

        TreeNode* root = new TreeNode(array[mid],
            buildTree(array, l, mid -1),
            buildTree(array, mid + 1, r));

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {

        vector<int> a;
        inOrder(root, a);

        return buildTree(a, 0, int(a.size()) - 1);
    }
};