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
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
                
        vector<vector<int>> ans;
        if (!root) return ans;
        queue<node> q;
        q.push(node{root, 1});
        ans.push_back({root->val});
        while (!q.empty())
        {
            auto t = q.front();
            q.pop();
            
            if (t.n->left) 
            {
                ans.resize(t.depth + 1);
                q.push(node{t.n->left, t.depth + 1});
                if (t.depth % 2)
                    ans[t.depth].insert(ans[t.depth].begin(), t.n->left->val);
                else
                    ans[t.depth].push_back(t.n->left->val);
            }
            if (t.n->right) 
            {
                ans.resize(t.depth + 1);
                q.push(node{t.n->right, t.depth + 1});
                
                if (t.depth % 2)
                    ans[t.depth].insert(ans[t.depth].begin(), t.n->right->val);
                else
                    ans[t.depth].push_back(t.n->right->val);
            }
        }
        
        
        return ans;
    }
};