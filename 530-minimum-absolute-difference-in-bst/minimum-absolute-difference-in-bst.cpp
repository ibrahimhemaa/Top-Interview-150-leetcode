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
    vector<int>mn;
    void dfs(TreeNode* root){
        if(!root)return;
        mn.push_back(root->val);
        dfs(root->right);
        dfs(root->left);
        return;
    }
    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        sort(mn.begin(),mn.end());
        int mindiff=1e9;
        int prevval=-1;
        for(auto &i:mn){
            if(~prevval){
                mindiff=min(mindiff,i-prevval);
            }
            prevval=i;
        }
        return mindiff;
    }
};