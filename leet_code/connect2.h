/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        // tree has at least level 2
        if (root)
        {
            Node* last = nullptr;
            int count = 1, size = 0;
            queue<Node*> q;
            q.push(root);
            
            while (!q.empty())
            {
                Node* n = q.front();
                q.pop();
                
                // connect from last 
                if (last)
                    last->next = n;
                
                last = n;
                --count;
                
                Node* left = n->left;
                Node* right = n->right;
                
                // has children
                if (left || right)
                {
                    if (left)
                    {
                        ++size;
                        q.push(left);
                    }

                    if (right)
                    {
                        ++size;
                        q.push(right);
                    }
                }
                
                if (!count)
                {
                    last = nullptr;
                    count = size;
                    size = 0;
                }
            }
        }
        
        return root;
        
    }
};