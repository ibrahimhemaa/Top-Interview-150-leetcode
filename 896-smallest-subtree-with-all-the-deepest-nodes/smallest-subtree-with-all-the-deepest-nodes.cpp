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
    TreeNode *ans=nullptr;
    int dpl=0;
    int dfs(TreeNode* root,int depth){
        if(!root)return depth;
        int ld=dfs(root->left,depth+1);
        int rd=dfs(root->right,depth+1);
        int currLevel= max(ld, rd);
        if(currLevel>=dpl){
            dpl=currLevel;
            if(ld==dpl && rd==dpl){
                ans=root;
            }
            
        }
        return currLevel;

    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        dfs(root,0);
        return ans;
    }
};