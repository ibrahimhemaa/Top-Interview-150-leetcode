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
   
    map<int,int>mx;
    
    int mxlevel(TreeNode* root,int level=1){
        if(!root)return 0;
        mx[level]+=root->val;
        
        mxlevel(root->left,level+1);
        mxlevel(root->right,level+1);
        return 0;
    }
    int maxLevelSum(TreeNode* root) {
         
         mxlevel(root);
         int mxlev=1;
         int mxsum=-1e9-2;
         for(auto &[level,sum]:mx){
            if(sum>mxsum){
                mxsum=sum;
                mxlev=level;}
         }
         return mxlev;
        // return ;
    }
};