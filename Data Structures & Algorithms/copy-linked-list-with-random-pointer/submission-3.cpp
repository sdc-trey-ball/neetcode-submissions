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
        if(head ==nullptr) return head;
       unordered_map<Node *, Node *> node_copies{{nullptr, nullptr}};
       auto cur = head;
       while(cur) {
            node_copies[cur] = new Node(cur->val);
            cur = cur->next;
       }
       cur = head;
       while(cur){
            auto temp = node_copies[cur];
            temp->next = node_copies[cur->next];
            temp->random = node_copies[cur->random];
            cur = cur->next;
       }
       return node_copies[head];
    }
};
