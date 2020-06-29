#pragma once
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

        if (!head) return nullptr;

        ListNode* move = head;
        ListNode* cut = nullptr;
        int count = 0;
        while (move->next)
        {
            if (move->val == move->next->val)
            {
                ++count;
                if (count == 1)
                    cut = move;
            }
            else
            {
                if (cut)
                {
                    cut->next = move->next;
                    cut = nullptr;
                    count = 0;
                }
            }
            move = move->next;
        }
        if (cut) cut->next = move->next;
        return head;
    }
};