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
/*
Output same preorder but add child null
think how to adapt this (may think divide and conquere) why i want get root from inorder vector and get divide to get(Recursion)
*/
class Solution {
public:
    unordered_map<int,int>map;
    //get root o(1);
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int &RootIndex,int left,int right){
        if(left>right)
            return nullptr;
        int pivot=map[preorder[RootIndex]];//find root
        TreeNode * newNode=new TreeNode(inorder[pivot]);
        ++RootIndex;
        newNode->left=build(preorder,inorder,RootIndex,left,pivot-1);
        newNode->right=build(preorder,inorder,RootIndex,pivot+1,right);
        return newNode;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int root=0;
        for(int i=0;i<inorder.size();i++){
            map[inorder[i]]=i;
        }
     return build(preorder,inorder,root,0,preorder.size()-1);

    }
};