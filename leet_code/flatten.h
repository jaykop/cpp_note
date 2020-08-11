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
    
    queue<TreeNode*> q;

    void rec(TreeNode* n)
    {
        q.push(n);
        
        if (n->left)
            rec(n->left);
        
        if (n->right)
            rec(n->right);
    }
    
    TreeNode* generateTree()
    {
        TreeNode* n = nullptr;
        
        if (!q.empty())
        {
            n = new TreeNode(q.front()->val);
            q.pop();
            n->right = generateTree();
        }   

        return n;
    }
    
    void flatten(TreeNode* root) {
        
        if (root)
        {
            rec(root);
            *root = *generateTree();
        }
    }
};