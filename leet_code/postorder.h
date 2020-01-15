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
    
    void dfs(Node* tree, vector<int>& list){
        
        if (!tree) return;
        for (const auto& c : tree->children)
            dfs(c, list);
        list.push_back(tree->val);
    }
    
    vector<int> postorder(Node* root) {
                
        vector<int> list;
        //dfs(root, list);
        vector<Node*> q;
        q.push_back(root);
        
        while (!q.empty()){
            
            Node* x = q.back();
            q.pop_back();
            if (!x) continue;
            int size = int(x->children.size());
            for (int i = 0; i < size; i++) {
                auto c = x->children[i];
                q.push_back(c);
            }
            list.push_back(x->val);
        }
        reverse(list.begin(), list.end());
        return list;
    }
};