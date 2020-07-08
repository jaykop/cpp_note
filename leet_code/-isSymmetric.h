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
    
    bool rec(TreeNode* t1, TreeNode* t2)
    {
        if (!t1 && !t2) return true;
        if (!t1 || !t2) return false;
        if (t1->val != t2->val) return false;
        
        return rec(t1->left, t2->right) && rec(t2->left, t1->right);
    }
    
    bool isSymmetric(TreeNode* root) {
        
        if (!root) return true;
        return rec(root, root);
        
//         queue<TreeNode*> q;
//         q.push(root);
//         q.push(root);
//         while (!q.empty())
//         {
//             auto n1 = q.front(); q.pop();
//             auto n2 = q.front(); q.pop();
            
//             if (!n1 && !n2) continue; 
//             if (!n1 || !n2) return false;
//             if (n1->val != n2->val) return false;
            
//             q.push(n1->left);
//             q.push(n2->right);
//             q.push(n1->right);
//             q.push(n2->left);
//         }
        
//         return true;
    }
};