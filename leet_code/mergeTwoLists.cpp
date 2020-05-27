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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if (!l1 && l2) return l2;
        else if (l1 && !l2) return l1;
        else if (!l1 && !l2) return nullptr;
        
        ListNode* res = new ListNode();
        ListNode* move = res;
        
        while(l1 || l2)
        {
            if (l1 && l2)
            {
                if (l1->val < l2->val)
                {
                    move->val = l1->val;
                    l1 = l1->next;
                }
                else
                {
                    move->val = l2->val;
                    l2 = l2->next;
                }
            }
            
            else if (!l1 && l2)
            {
                move->val = l2->val;
                l2 = l2->next;
            }
            else if (l1 && !l2)
            {
                move->val = l1->val;
                l1 = l1->next;
            }
            if (l1 || l2)
            {
                move->next = new ListNode();
                move = move->next;
            }
        }
        
        return res;
    }
};