class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int mx=0,l=0,r=nums.size()-1;
        while(l<r)mx=max(mx,nums[l++]+nums[r--]);
        return mx;
    }
};