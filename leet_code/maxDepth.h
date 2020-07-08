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
    
    struct node
    {
        TreeNode* n;
        int depth;
    };
    
    int maxDepth(TreeNode* root) {
        
        if (!root) return 0;
        
        int ans = 1;
        queue<node> q;
        q.push(node{root, ans});
        while (!q.empty())
        {
            auto t = q.front();
            q.pop();
            
            if (t.n->left) 
            {
                q.push(node{t.n->left, t.depth + 1});
                ans = t.depth + 1;
            }
            if (t.n->right) 
            {
                q.push(node{t.n->right, t.depth + 1});
                ans = t.depth + 1;
            }
        }
        
        return ans;
    }
};