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
    bool hasCycle(ListNode* head) {
        ListNode* slow = head, *fast = head; 
        int i = 0;
        while(fast != nullptr) {
            cout << slow->val << " " << fast->val << endl;
            if(i % 2 !=0) slow = slow->next;
            fast = fast->next;
            if(slow == fast) return true;
            i++;
        }
        return false;
    }
};
