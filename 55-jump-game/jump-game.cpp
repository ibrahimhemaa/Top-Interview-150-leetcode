class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        if(n==1)return true;
        int ans=0;
        for(;i<n;i++){
            ans=max(nums[i],ans-1);
            if(!ans && i!=n-1){
                return (i==n-1);
            }
        }
        return true;
    }
};