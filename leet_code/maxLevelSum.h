#pragma once
#include <map>

using namespace std;

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

    // key: level, 
    // val: sum
    map<int, int> sum_table;

    // recursive function that records the sum so far by depth
    void calculate(TreeNode* tree, int depth,
        map<int, int>& sum_table) {

        // sum the val to the rcord table
        sum_table[depth] += tree->val;
        // spread to its children
        if (tree->left)
            calculate(tree->left, depth + 1, sum_table);
        if (tree->right)
            calculate(tree->right, depth + 1, sum_table);
    }

    int maxLevelSum(TreeNode* root) {

        calculate(root, 1, sum_table);
        int max_level = 1, max_sum = sum_table[1];

        // get the largest value
        for (auto& it : sum_table) {
            if (it.second > max_sum) {
                max_level = it.first;
                max_sum = it.second;
            }
        }

        // return the level
        return max_level;
    }
};