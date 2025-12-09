class Solution {
public:
    // using s=second;
    int specialTriplets(vector<int>& nums) {
        unordered_map<int,int>right,left;
        for(auto &i:nums)right[i]++;
        int ans=0;
        for(auto &i:nums){
            right[i]--;
            int need=2*i;
            ans=(ans+(1ll*right[need]*left[need])%1000000007)%1000000007;
            left[i]++;
        }
        return ans;
    }
};