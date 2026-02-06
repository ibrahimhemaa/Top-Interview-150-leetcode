class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int mx=0,n=nums.size();
        for(int i=0;i<n;i++){
            long long x=1ll*k*nums[i];
            if(x>(int)1e9)x=1e9;
            int idx=upper_bound(nums.begin(),nums.end(),x)-nums.begin();
            mx=max(mx,idx-i);
        }
        return n-mx;
    }
};