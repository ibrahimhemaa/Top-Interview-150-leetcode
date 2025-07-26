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
    bool balance(TreeNode *right,TreeNode *left){
        if(right==nullptr &&left==nullptr)//baseCase of Tree
            return true;
        if(left==nullptr||right==nullptr||left->val!=right->val)//case of any nodes in right subTree not equal left subTree
            return false;
        return balance(right->left,left->right)&balance(right->right,left->left);         
    }
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr)
            return true;
        return balance(root->right,root->left);    
    }
};