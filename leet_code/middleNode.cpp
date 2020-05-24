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
    ListNode* middleNode(ListNode* head) {
        
        ListNode* run = head;
        ListNode* half = head;
        int count_run = 0, count_half = 0;
        while(run->next!= nullptr)
        {
            run = run->next;
            count_run++;
            if (!((count_run+1) % 2))
            {
                half = half->next;   
                count_half++;
            }
        }
        
        return half;
    }
};