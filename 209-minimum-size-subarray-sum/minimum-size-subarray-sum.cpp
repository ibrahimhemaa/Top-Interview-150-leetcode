class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=200000,l=0,r=0,sum=0,n=nums.size();
        while(r<n){
            sum+=nums[r];
            while(sum>=target)ans=min(ans,r-l+1),sum-=nums[l],l++;
            r++;
        }
        return (ans==200000?0:ans);
    }
};