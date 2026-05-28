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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            ListNode* fin = new ListNode();
            if(list1==nullptr ) return list2;
            if(list2==nullptr ) return list1;
            ListNode* to_ret = fin;
            while(list1 != nullptr && list2 != nullptr) {
                if(list1->val <= list2->val) {
                    fin->next = list1;
                    list1 = list1->next;
                } else {
                    fin->next = list2;
                    list2 = list2->next;
                }
                fin = fin->next; 
                cout << (fin->val) << endl;
            }
            if(list1 == nullptr) {
                fin->next = list2;
            } else {
                fin->next = list1;
            }
           return to_ret->next; 
    }
};
