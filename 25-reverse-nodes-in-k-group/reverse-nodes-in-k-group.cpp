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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int>vec;
        vector<int>ans;
        while(head!=nullptr){
            vec.push_back(head->val);
            head=head->next;
            if(vec.size()==k){
                for(int i=k-1;i>=0;i--)ans.push_back(vec[i]);
                vec.clear();
            }
        }
        for(auto &v:vec)ans.push_back(v);
        ListNode *ans2=new ListNode(0);
        ListNode *ans1=ans2;
        for(auto v:ans){
            ListNode *x=new ListNode(v);
            ans1->next=x;
            ans1=ans1->next;
        }
        ans2=ans2->next;
        return ans2;
    }
};