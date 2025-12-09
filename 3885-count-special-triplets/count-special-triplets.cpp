class Solution {
public:
    // using s=second;
    int specialTriplets(vector<int>& nums) {
        vector<unordered_map<int, int>> cnt(2);
        int ans=0;
        for(auto &i:nums){
            if(i%2==0 && cnt[1].count(i/2)){
                ans=(ans+cnt[1][i/2]) % 1000000007;
            }
            if (cnt[0].count(2 *i)) {
                cnt[1][i] = (cnt[1][i] + cnt[0][2 * i]) % 1000000007;
            }
            cnt[0][i]++;
        }
        
        return ans;
    }
};