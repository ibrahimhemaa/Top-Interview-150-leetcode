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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans=new ListNode(0);
        ListNode *curr=ans;
        int over=0;
        while(l1!=nullptr ||l2!=nullptr || over){
            over+=(l1!=nullptr?l1->val:0);
            over+=(l2!=nullptr?l2->val:0);
            ListNode* cur=new ListNode(over%10);
            curr->next=cur;
            curr=curr->next;
            l1=(l1!=nullptr?l1->next:nullptr);
            l2=(l2!=nullptr?l2->next:nullptr);
            over/=10;
        }
        ans=ans->next;
        return ans;
    }
};