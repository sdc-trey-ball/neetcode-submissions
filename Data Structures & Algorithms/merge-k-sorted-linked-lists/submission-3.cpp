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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       // int at size 
       // while size
       // for loop inside
       ListNode* to_ret = new ListNode();
       ListNode* head_ref = to_ret;
       int size{static_cast<int>(lists.size())};
       while(size) {
            int min = 0;
            for(int i{1}; i < lists.size(); ++i) {
                if(!lists[i]) continue;
                if(lists[i]->val < lists[min]->val) {
                    min = i;
                }
            }
            to_ret->next = lists[min];
            lists[min] = lists[min]->next;
            to_ret = to_ret->next;
            if(!lists[min]){
                size--;
                lists.erase(lists.begin() + min);
            } 
       }
       return head_ref->next;
    }
};
