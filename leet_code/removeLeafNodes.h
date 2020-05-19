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
        
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
     
        if (root) {

            stack<TreeNode**> s;
            queue<TreeNode**> q;
            
            //int count = 1;
            q.push(&root);
            if (root->val == target)
                s.push(&root);

            while (!q.empty())
            {
                TreeNode** t = q.front();
                q.pop();
                TreeNode** l = &((*t)->left);
                TreeNode** r = &((*t)->right);
                if (*l) {
                    q.push(l);
                    //count++;
                    if ((*l)->val == target)
                        s.push(l);
                }
                if (*r) {
                    q.push(r);
                    //count++;
                    if ((*r)->val == target)
                        s.push(r);
                }
            }
            
            //if (count == s.size())
            //    return nullptr;

            while (!s.empty())
            {
                TreeNode** t = s.top();
                s.pop();
                TreeNode** l = &((*t)->left);
                TreeNode** r = &((*t)->right);
                if (!(*l) && !(*r)) {
                    // delete *t;
                    *t = nullptr;
                }
            }
        }
        
        return root;
    }
};