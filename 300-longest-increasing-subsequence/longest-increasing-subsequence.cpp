class Solution {
public:
    const int N=2502;
    vector<vector<int>> dp;
    int max_increase_subsequence(int ind,int prev,vector<int>& nums){
        if(ind==nums.size())return 0;
        int &ret=dp[ind][prev+1];
        if(~ret)return ret;
        ret=0;
        if(prev==-1||nums[ind]>nums[prev]){
            ret=max(ret,1+max_increase_subsequence(ind+1,ind,nums));
        }
        ret=max(ret,max_increase_subsequence(ind+1,prev,nums));
        return ret;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        dp.assign(n, vector<int>(n+1, -1));

        return max_increase_subsequence(0,-1,nums);
    }
};