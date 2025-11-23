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
//divide && 
    bool leafsum(TreeNode * root,int totalsum){
        if(!root->left && !root->right){
            return root->val==totalsum;
        }
        bool flag=false;
        if(root->right)
            flag|=leafsum(root->right,totalsum-root->val);
        if(root->left)
            flag|=leafsum(root->left,totalsum-root->val);
        return flag;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        //may check dfs
        if(!root)return false;
        return leafsum(root,targetSum);
    }
};