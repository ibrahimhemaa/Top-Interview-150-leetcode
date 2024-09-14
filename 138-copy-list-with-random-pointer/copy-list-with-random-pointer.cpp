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
        if(!head)return nullptr;
        Node *co=head;
        unordered_map<Node *,Node *>mp;
        while(co)mp[co]=new Node(co->val),co=co->next;
        co=head;
        while(co)mp[co]->next=mp[co->next],mp[co]->random=mp[co->random],co=co->next;
        return mp[head];
    }
};