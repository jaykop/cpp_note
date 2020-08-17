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
        if (root && root->left)
        {
            Node* last = nullptr;
            queue<Node*> q;
            q.push(root);
            
            int count = 1, size = 1;
            
            while (!q.empty())
            {
                Node* n = q.front();
                q.pop();
                
                Node* left = n->left;
                Node* right = n->right;
                
                // has children
                if (left || right)
                {
                    // connect from last 
                    if (last)
                        last->next = left;
                    
                    left->next = right;
                    last = right;
                    
                    q.push(left);
                    q.push(right);
                    
                    // when count reaches 0,
                    // update last and size/count
                    
                    if (!--count)
                    {
                        size *= 2;
                        count = size;
                        last = nullptr;
                    }
                }
                
                // leaf nodes
                else
                {
                    // connect from last node and update it
                    if (last)
                    {
                        last->next = n;
                        last = last->next;
                    }
                    else
                        last = n;
                }
            }
        }
        
        return root;
    }
};