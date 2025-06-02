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
    ListNode* deleteDuplicates(ListNode* head) {
        map<int,int>freq;
        vector<int>v;
        while(head!=nullptr){
            int x=head->val; 
            if(!freq[x]){
                freq[x]++;
                v.push_back(x);
            }
            else{
                if(freq[x]==1){
                    v.pop_back();
                }
                freq[x]++;
            }
            head=head->next;
        }
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