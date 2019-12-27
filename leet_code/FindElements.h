/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
public:
    set<int> table;
    void recover(TreeNode* tree) {
    
        // get current val 
        // and record the val on the table
        int x = tree->val;
        table.insert(x);
        
        // recover subtrees in seep first search method
        if (tree->left) {
            tree->left->val = 2*x+1;
            recover(tree->left);
        }
        if (tree->right){
            tree->right->val = 2*x+2;
            recover(tree->right);
        }
    }
    
    FindElements(TreeNode* root) {
        
        // init the root val
        if (root) {
            root->val = 0;
            recover(root);
        }
    }
    
    bool find(int target) {
        // if not found the target on the table
        if (table.find(target) == table.end())
            return false;
        return true;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */