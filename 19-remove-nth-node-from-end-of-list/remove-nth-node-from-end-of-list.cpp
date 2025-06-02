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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<int>v,v2;
        // n--;
    
        while(head!=nullptr)v.push_back(head->val),head=head->next;
        n=v.size()-n;
        for(int i=0;i<v.size();i++){
            if(i==n)continue;
            v2.push_back(v[i]);
        }
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