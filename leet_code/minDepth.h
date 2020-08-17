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
    
    struct Node
    {
        TreeNode* n;
        int depth;
    };
    
    int minDepth(TreeNode* root) {
        
        if (!root)
            return 0;
        
        else if (!root->left && !root->right)
            return 1;
            
        int res = -1;
        int depth = 1;
        
        queue<Node> q;
        q.push({root, 1});
        
        while (!q.empty())
        {
            Node n = q.front();
            q.pop();
            int nextDepth = n.depth+1;
            
            if (n.n->left || n.n->right)
            {
                if (n.n->left)
                    q.push({n.n->left, nextDepth});

                if (n.n->right)
                    q.push({n.n->right, nextDepth});
            }
            
            else
            {                
                if (res > n.depth || res == -1)
                    res = n.depth;
            }
        }
      
        return res;
    }
};