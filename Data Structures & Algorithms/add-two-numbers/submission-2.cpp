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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode * to_process = l1;
       ListNode * prev = nullptr;
        while(l2 && l1) {
            int val = l1->val + l2->val;
            cout << val << ' ' << endl;
            if(val >= 10) {
                l1->val = val % 10;
                if(l1->next) {
                    l1->next->val++;
                } else {
                    l1->next = new ListNode(1);
                }
            } else {
                l1->val = val;
            }
            prev = l1;
            l1 = l1->next;
            l2 = l2->next;
        } 
        while(l1) {
            if(l1->val >=10) {
                l1->val%=10;
                if(l1->next) {
                    l1->next->val++;
                } else {
                    l1->next = new ListNode(1);
                }
            }
            l1 = l1->next;
        }
        if(l2) {
            l1 = prev;
            l1->next = l2;
        }

       return to_process;
    }
};
