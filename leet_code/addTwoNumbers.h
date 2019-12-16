/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // cases
        // 0. check both are not null
        if (!l1) return l2;
        else if (!l2) return l1;

        ListNode *toReturn = nullptr, *move = nullptr, *last = nullptr;

        bool go_over = false;

        // if any one of both are not null, keep looping thru
        while (l1 || l2 || go_over) {

            // check pointer valid, get values
            int l1_val = 0, l2_val = 0;
            if (l1) l1_val = l1->val;
            if (l2) l2_val = l2->val;

            // add two digits
            int sum = l1_val + l2_val;
            if (go_over) sum += 1;
            if (sum > 9) go_over = true;
            else go_over = false;

            move = new ListNode(sum % 10);
            
            // very first iteration
            if (!toReturn) toReturn = move;
            else last->next = move;
            
            last = move;
            move = move->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        return toReturn;
    }
};