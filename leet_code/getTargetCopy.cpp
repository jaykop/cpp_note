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
    
    deque<bool> guide;
    
    void find(TreeNode* tree, deque<bool> sample, TreeNode* target)
    {
        if (tree->val == target->val) {
            guide = sample;
            return;
        }
        else 
        {
            if (tree->left) {
                sample.push_back(true);
                find(tree->left, sample, target);
                sample.pop_back();
            }
            if (tree->right) {
                sample.push_back(false);
                find(tree->right, sample, target);
            }
        }
    }
    
    void follow(TreeNode* tree, deque<bool> guide, 
                TreeNode* target, TreeNode*& toReturn)
    {
        if (target->val == tree->val) {
            toReturn = tree;
        }
        
        else if (guide.front()) 
        {
            guide.pop_front();
            follow(tree->left, guide, target, toReturn);
        }
        
        else {
            guide.pop_front();
            follow(tree->right, guide, target, toReturn);
        }
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
		// best answer found
        // return orig == nullptr ? nullptr :
    // orig == targ ? clone : 
      // getTargetCopy(orig->left, clone->left, targ) ?: getTargetCopy(orig->right, clone->right, targ);
        
        TreeNode* toReturn = nullptr;
        find(original, guide, target);
        follow(cloned, guide, target, toReturn);
        return toReturn;
    }
};