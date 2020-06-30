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
    ListNode* partition(ListNode* head, int x) {
        
        ListNode* left = nullptr;
        ListNode* right = nullptr, *right_head;
        ListNode* move = head;
        
        while (move)
        {
            ListNode* next = move->next;
            
            if (move->val < x)
            {
                if (!left) 
                    head = left = move;
                
                else
                {
                    left->next = move;
                    left = left->next;
                }
            }
            
            else 
            {
                if (!right) 
                    right_head = right = move;
                
                else
                {
                    right->next = move;
                    right = right->next;
                }
            }
            
            move = next;
        }
        
        if (left) left->next = right_head;
        if (right) right->next = nullptr;
        
        return head;
    }
};