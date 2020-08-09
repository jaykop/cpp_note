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
    
    TreeNode* rec(const vector<int>& nums, int left, int right)
    {
        if (left == right)
            return nullptr;
        
        int mid = (left+right) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        
        node->left= rec(nums, left, mid);
        node->right = rec(nums, mid+1, right);
        
        return node;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        int left = 0, right = nums.size();        
        TreeNode* n = rec(nums, left, right);
        
        return n;
    }
};