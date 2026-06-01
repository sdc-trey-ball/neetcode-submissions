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
       // fast slow
       // get to end with count
       // is at hald so just find diff 
       ListNode* fast = head, *slow = head, *head_ref = head;
       int count = 0;
       while(fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
        count++;
       }
       int to_remove = ((count) * 2 - n);
       if(fast!=nullptr) to_remove++;
       cout << to_remove;
       if(to_remove <= 0) {
            return head->next;
       }
       if(to_remove <= count) {
          slow = head;
          count = 0; 
       }
       ListNode* prev = slow;
        while(count < to_remove) {
            prev = slow;
            slow= slow->next;
            count++;
        } 
        prev->next = slow->next;
        return head_ref;
    }
};
