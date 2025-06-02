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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right)return head;
        vector<int>v;
        while(head!=nullptr){
            v.push_back(head->val);
            head=head->next;
        }
        while(left<right)swap(v[left-1],v[right-1]),left++,right--;
        //want return all linkedlist
        ListNode* ans=new ListNode(0);
        ListNode*cur=ans;
        for(auto i:v){
            ListNode *x=new ListNode(i);
            cur->next=x;
            cur=cur->next;
        }
        ans=ans->next;
        return ans;

    }
};