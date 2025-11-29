/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    priority_queue<int>kth;
    void buildsmallestkth(TreeNode* root, int k){
        if(!root)return;
        if(kth.size()<k){
            kth.push(root->val);
        }
        else if(kth.size()==k && kth.top()>root->val){
            kth.pop();
            kth.push(root->val);
        }
        buildsmallestkth(root->right,k);
        buildsmallestkth(root->left,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        //easy solution 
        buildsmallestkth(root,k);
        return kth.top();
    }
};