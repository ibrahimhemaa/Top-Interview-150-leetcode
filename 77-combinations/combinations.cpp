class Solution {
public:
    void backtrack(int n,int k,vector<vector<int>>&ans,vector<int>v={},int index=1){
        if(v.size()==k){
            ans.push_back(v);
            return;
        }
        for(int i=index;i<=n;i++){
            v.push_back(i);
            backtrack(n,k,ans,v,i+1);
            v.pop_back();
        }
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        backtrack(n,k,ans);
        return ans;
    }
};