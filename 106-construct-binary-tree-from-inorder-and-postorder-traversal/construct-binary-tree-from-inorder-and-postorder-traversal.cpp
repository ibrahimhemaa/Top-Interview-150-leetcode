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
    unordered_map<int,int>Root_Posintion;
    TreeNode *build(vector<int> &inorder, vector<int> &postorder,int& RootIndex,int left,int right){
        if(left>right)
            return nullptr;
        int pivot=Root_Posintion[postorder[RootIndex]];
        TreeNode *NewNode=new TreeNode(inorder[pivot]);
        --RootIndex;
        NewNode->right=build(inorder,postorder,RootIndex,pivot+1,right);
        NewNode->left=build(inorder,postorder,RootIndex,left,pivot-1);
        return NewNode;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++){
            Root_Posintion[inorder[i]]=i;
        }
        int rootindex=inorder.size()-1;
        return build(inorder,postorder,rootindex,0,inorder.size()-1);
    }
};