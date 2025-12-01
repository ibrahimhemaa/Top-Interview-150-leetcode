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
    //shift all linked list greater than or equal x to right 
    //do two vector ans do list Node 
    ListNode* partition(ListNode* head, int x) {
        vector<ListNode *>v;
        ListNode *answer=new ListNode(-1);
        ListNode *ans=answer;

        while(head!=nullptr){
            ListNode* nxt = head->next; 
            head->next=nullptr;
            if(head->val<x)
            {
                ans->next=head;
                ans=ans->next;
            }
            else {
                v.push_back(head);
            }
             head=head->next;
             head=nxt;
        }
        for(ListNode* node:v){
            ans->next=node;
            ans=ans->next;
        }
        
        return answer->next;
    }
};