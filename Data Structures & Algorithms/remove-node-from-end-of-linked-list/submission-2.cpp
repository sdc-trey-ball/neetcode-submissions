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
       //want to be n ahead
        ListNode* dummy = new ListNode(0, head);
        ListNode* lead = head, *trail = dummy;
        while(n >0) {
            lead = lead->next;
            n--;
        }
        while(lead) {
            lead = lead->next;
            trail = trail->next;
        }
        trail->next = trail->next->next;
        return dummy->next;
    }
};
