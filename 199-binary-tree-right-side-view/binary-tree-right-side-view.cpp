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
    vector<int>ans;
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(!root)return {};
        ans.push_back(root->val);
        vector<int>r=rightSideView(root->right);
        vector<int>l=rightSideView(root->left);
        for(auto &i:r)ans.push_back(i);
        for(int i=r.size();i<l.size();i++)ans.push_back(l[i]);
        return ans;
    }
};