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
    ListNode* deleteDuplicates(ListNode* head) {
                
        ListNode* move = head;
        ListNode* ans = nullptr, *ans_head = nullptr, *ans_prev = nullptr;
        
        while (move)
        {
            if (!ans) ans_head = ans = move;
            else 
            {
                if (move->val == ans->val)
                {
                    while (move->next && move->val == move->next->val)
                        move = move->next;
                    
                    ans = ans_prev;
                    if (ans) ans->next = nullptr;
                    else ans_head = nullptr;
                }
                else
                {
                    ans_prev = ans;
                    ans->next = move;
                    ans = move;
                }
            }
            
            move = move->next;
        }
        
        if (ans) ans->next = nullptr;
        return ans_head;
    }
};