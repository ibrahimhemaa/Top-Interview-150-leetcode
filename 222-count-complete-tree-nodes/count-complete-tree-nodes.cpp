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
    int dfs(TreeNode* root){
        if(!root)return 0;
        int cnt=1;
        if(root->right){
            cnt+=dfs(root->right);
        }
        if(root->left){
            cnt+=dfs(root->left);
        }
        return cnt;
    }
    int countNodes(TreeNode* root) {
        return dfs(root);
    }
};