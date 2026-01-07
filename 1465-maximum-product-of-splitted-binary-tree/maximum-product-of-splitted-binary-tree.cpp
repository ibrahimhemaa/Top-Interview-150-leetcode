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
    map<TreeNode*,int>mp;
    const int mod=1e9+7;
    long long sum,mxprod=0;
    int sumtree(TreeNode* root){
        if(!root)return 0;
        mp[root]=root->val+sumtree(root->right)+sumtree(root->left);
        return mp[root];
    }
    int maxsub(TreeNode* root){
        if(!root)return 0;
        
        if(root->right){
            long long prod=(1ll*mp[root->right]*(sum-mp[root->right]));
            mxprod=max(mxprod,prod);
        }
        if(root->left){
            long long prod=(1ll*mp[root->left]*(sum-mp[root->left]));
            mxprod=max(mxprod,prod);
        }
        maxsub(root->left);
        maxsub(root->right);
        return mxprod%mod;
    }
    int maxProduct(TreeNode* root) {
        sum=sumtree(root);
        return maxsub(root);
    }
};