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
    ListNode* reverseKGroup(ListNode* head, int k) {
       ListNode* first_head = head;
       ListNode* prev_head = nullptr;
       ListNode* temp = nullptr; 
       ListNode* search = head;
       ListNode* reved = nullptr;
       while(true) {
            bool to_break = false;
            temp = search;
            for(int i{0}; i < k; ++i) {
                if(search == nullptr){to_break = true; break;}
                search = search->next;
            }
            if(to_break) break;
            reved = reverse(head, search);
            if(prev_head) prev_head->next = reved;
            else first_head = reved;
            prev_head = head;
            head = search;
       } 
       if(prev_head)prev_head->next = temp; 
       return first_head;
    }

    ListNode* reverse(ListNode* start, ListNode* stop_at) {
        ListNode* prev = nullptr;
        while(start != stop_at) {
            auto temp = start->next;
            start->next = prev;
            prev = start;
            start = temp;
        } 
        return prev;
    } 
};
