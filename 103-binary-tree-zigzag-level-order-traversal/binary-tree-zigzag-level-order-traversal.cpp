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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)return {};
        vector<vector<int>>ans;
        queue<TreeNode *>q;
        q.push(root);
        while(q.size()){
            int sz=q.size();
            vector<int>v;
            for(int i=0;i<sz;i++){
                TreeNode* node = q.front(); q.pop();
                v.push_back(node->val);
                if(node->right)q.push(node->right);
                if(node->left)q.push(node->left);
                
                
            }
            
            ans.push_back(v);
        }
        for(int i=0;i<ans.size();i++){
            if(i%2==0){
                reverse(ans[i].begin(),ans[i].end());
            }
        }
        return ans;
    }
};