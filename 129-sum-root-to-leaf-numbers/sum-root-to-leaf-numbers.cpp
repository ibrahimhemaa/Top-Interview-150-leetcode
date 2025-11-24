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
//do to operation of sum 
//first accumulate (prifex sum of leaf )
class Solution {
public:
    int sumleafs(TreeNode * root,int sum){
        if(!root)return 0;
        if(!root->right&&!root->left)
            return 10*sum+root->val;
        int sumsub=0;
        if(root->right){
            sumsub+=sumleafs(root->right,sum*10+root->val);
        }    
        if(root->left){
            sumsub+=sumleafs(root->left,sum*10+root->val);
        }
        return sumsub;
    }
    int sumNumbers(TreeNode* root) {
        if(!root)return 0;
         if(!root->right&&!root->left)return root->val;
        return sumleafs(root->left,root->val)+sumleafs(root->right,root->val);
    }
};