class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1||k==1)return 0;
        sort(nums.begin(),nums.end());
        int mn=1e5;
        for(int i=k-1;i<n;i++){
            mn=min(mn,nums[i]-nums[i-(k-1)]);
        }
        return mn;
    }
};