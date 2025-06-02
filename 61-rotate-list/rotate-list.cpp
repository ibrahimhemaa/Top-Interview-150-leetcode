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
    ListNode* rotateRight(ListNode* head, int k) {
        deque<int>v,v2;
        if(k==0){
            return head;
        }
        while(head!=nullptr){
            v.push_back(head->val);
            head=head->next;
        }
        if(v.size()==0){
            return head;
        }
        k%=(v.size());
        while(k--){
            v2.push_front(v.back());
            v.pop_back();
        }
        // reverse(v2.)
        for(auto i:v)v2.push_back(i);
        ListNode* ans=new ListNode(0);
        ListNode*cur=ans;
        for(auto i:v2){
            ListNode *x=new ListNode(i);
            cur->next=x;
            cur=cur->next;
        }
        ans=ans->next;
        return ans;
    }
};