/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return head;
       // iterate throuh running count of 'index'
       // if next has not been visited, add to   
       Node * to_ret = new Node(0); 
       auto new_head = to_ret;
       unordered_map<Node *, Node *> traversed{};
       while(head) {
            to_ret->val = head->val;
            to_ret->next = head->next == nullptr ? nullptr : new Node(0);
            to_ret->random = head->random == nullptr ? nullptr : head->random; // replace after
            traversed[head] = to_ret;
            head = head->next;
            to_ret = to_ret->next;
            
       }
        for(auto n : traversed) {
            if(!(n.first->random)) continue;
            auto to_rand = traversed.find(n.first->random);
            n.second->random = to_rand->second;
        }
        return new_head;
    }
};
