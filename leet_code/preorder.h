/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    void dfs(vector<int>& v, Node* tree){
        
        if (!tree)
            return;
        
        v.push_back(tree->val);
        for (Node* child : tree->children)
            dfs(v, child);

    }
    vector<int> preorder(Node* root) {
        // vector<int> v;
        // dfs(v, root);
        // return v;
        
        vector<int> list;
        stack<Node*> q;
        q.push(root);
        while (!q.empty()){
            
            Node* x = q.top();
            q.pop();
            if (!x) continue;
            int size = int(x->children.size());
            for (int i = size - 1; i >= 0; i--)
                q.push(x->children[i]);
            list.push_back(x->val);
        }
        
        return list;
    }
};