class Solution {
public:
    set<vector<int>>ans;
    void solve(vector<int>candidates,int target,int index=0,int sum=0,vector<int>v={}){
        if(sum>=target){
            if(sum==target){
                sort(v.begin(),v.end());

                ans.insert(v);
            }
            return;
        }
        for(int i=index;i<candidates.size();i++){
            if(candidates[i]<=target-sum){
                v.push_back(candidates[i]);
                solve(candidates,target,i,sum+candidates[i],v);
                v.pop_back();
            }
            else{
                break;
            }
        }

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        solve(candidates,target);
        vector<vector<int>>v;
        for(auto x:ans)v.push_back(x);
        return v;
    }
};