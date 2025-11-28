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
    bool validhead(TreeNode* root,long long min,long long max){
        if(!root)
            return true;
        if(root->val<=min||root->val>=max)return 0;
                return validhead(root->left,min,root->val)&validhead(root->right,root->val,max);

    }
    bool isValidBST(TreeNode* root) {
        //each dir have same depth 
        return validhead(root->left,LLONG_MIN,root->val)&validhead(root->right,root->val,LLONG_MAX);
    }
};