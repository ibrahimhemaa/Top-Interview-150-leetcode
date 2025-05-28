
//  * Definition for singly-linked list.


class Solution {
//     struct ListNode {
//         int val;
//         ListNode *next;
//         ListNode(int x) : val(x), next(NULL) {}
//     };
public:
    bool hasCycle(ListNode *head) {
       if(head==nullptr)return 0; 

        int cnt=0;
        ListNode *x=head;
        while(x->next!=nullptr && x!=nullptr){
            if(cnt==10002)return true;
            x=x->next;
            cnt++;
        }
        return false;
    }
};