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
    int getDecimalValue(ListNode* head) {
        
        int sum = 0;
        while (head->next) {
            
            sum += head->val;
            sum *= 2;
            head = head->next;
        }
        
        sum += head->val;
        return sum;
    }
};