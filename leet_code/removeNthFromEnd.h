/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        queue<ListNode*> q;
        ListNode* node = head;
        int count = 0;
        while (node)
        {
            if (q.size() == n + 1)
                q.pop();
            
            q.push(node);
            node = node->next;
            ++count;
        }
        
        // change head
        if (count == n)
            head = head->next;
        
        else 
        {
            ListNode* prev = q.front();
            
            if (q.size() > 2)
            {
                q.pop(); // prev
                q.pop(); // to delete
                prev->next = q.front();
            }
            
            else
            {
                q.front()->next = nullptr;
            }
        }
        
        return head;
    }
};