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
    
    void recursive(TreeNode* t, vector<int>& v, int maxSoFar)
    {
        TreeNode* l = t->left;
        TreeNode* r = t->right;
        if (l)
        {
            int copied = maxSoFar;
            if(l->val >= copied)
            {
                copied = l->val;
                v.push_back(copied);
            }
            recursive(l, v, copied);
        }
        if (r)
        {
            int copied = maxSoFar;
            if(r->val >= copied)
            {
                copied = r->val;
                v.push_back(copied);
            }
            recursive(r, v, copied);
        }
    }
    
    int goodNodes(TreeNode* root) {
        
        vector<int> v;
        v.push_back(root->val);
        recursive(root, v, root->val);
        return v.size();
    }
};

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
    
    void recursive(TreeNode* t, int& count, int maxSoFar)
    {
        TreeNode* l = t->left;
        TreeNode* r = t->right;
        if (l)
        {
            int copied = maxSoFar;
            if(l->val >= copied)
            {
                copied = l->val;
                count++;
            }
            recursive(l, count, copied);
        }
        if (r)
        {
            int copied = maxSoFar;
            if(r->val >= copied)
            {
                copied = r->val;
                count++;
            }
            recursive(r, count, copied);
        }
    }
    
    int goodNodes(TreeNode* root) {
        
        int count = 1;
        recursive(root, count, root->val);
        return count;
    }
};