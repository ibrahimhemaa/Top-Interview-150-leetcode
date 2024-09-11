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
        ListNode *ans=new ListNode(0);
        ListNode *cur=ans;
        while(list1!=nullptr || list2!=nullptr){
            if(list1==nullptr){
                ListNode *element=new ListNode(list2->val);
                list2=list2->next;
                cur->next=element;
                cur=cur->next;
            }
            else if(list2==nullptr){
                ListNode *element=new ListNode(list1->val);
                list1=list1->next;
                cur->next=element;
                cur=cur->next;
            }
            else{
                if(list1->val>list2->val){
                    ListNode *element=new ListNode(list2->val);
                    list2=list2->next;
                    cur->next=element;
                    cur=cur->next;
                }
                else{
                    ListNode *element=new ListNode(list1->val);
                    list1=list1->next;
                    cur->next=element;
                    cur=cur->next;
                }
            }
        }
        ans=ans->next;
        return ans;
    }
};