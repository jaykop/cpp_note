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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if (p && q)
        {
            queue<TreeNode*> cnt;
            cnt.push(p);
            cnt.push(q);
            
            while (!cnt.empty())
            {
                auto np = cnt.front(); cnt.pop();
                auto nq = cnt.front(); cnt.pop();
                if ((!np && !nq) || ((np && nq) && (np->val == nq->val)))
                {
                    if (nq && np) 
                    {
                        cout<< np->val << " " << nq->val << "\n";
                        cnt.push(nq->left);
                        cnt.push(np->left);
                        cnt.push(nq->right);
                        cnt.push(np->right);
                    }
                }
                else 
                    return false;
            }
            
            return true;
        }
        
        else if (!p && !q) return true;
        
        return false;
    }
};