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
    void reorderList(ListNode* head) {
       // slow fast to find halfway
       // reverse from middle then draw  
       ListNode *s = head, *f = head, *first = head;
       while(f && f->next != nullptr) {
            s = s->next;
            f = f->next->next;
       } 
       if(f)s = s->next;
        ListNode *prev = nullptr;
        while(s) {
            auto temp = s->next;
            s->next = prev;
            prev = s;
            s = temp;
        } 
        ListNode* temp = nullptr, *second = prev;
        auto to_ret = first;
        int i = 0;
        while(true) {
            if(i % 2 == 0) { //first point to second;
                if(first == nullptr) break;
                temp = first->next; 
                first->next = second;
                first = temp;
            } else {
                if(second == nullptr) break;
                temp = second->next; 
                second->next = first;
                second = temp;
            }
            //cout << temp->val << ' ';
            i++;
        }
        head = to_ret;
     
    }
};
