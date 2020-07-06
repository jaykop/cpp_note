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
    ListNode* reverseBetween(ListNode* head, int m, int n) {

        if (n <= m) return head;
        int count = 1;
        ListNode* move = head, * start = nullptr, * end = nullptr;
        stack<ListNode*> reverse;

        while (move)
        {
            // save the range
            if (m <= count && count <= n)
                reverse.push(move);

            ++count;

            if (count == m)
                start = move;

            move = move->next;

            if (count == n + 1)
                end = move;
        }
        if (m > count) return head;

        move = start;

        if (!move)
        {
            move = reverse.top();
            reverse.pop();
            if (m == 1) head = move;
        }

        while (!reverse.empty())
        {
            auto node = reverse.top();
            reverse.pop();
            move->next = node;
            move = node;
        }
        move->next = end;

        return head;
    }
};