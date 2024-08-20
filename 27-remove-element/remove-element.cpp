class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        int l=0,r=n-1;
        int k=n;
        for(auto &i:nums)k-=(i==val);
        while(l<r){
            if(nums[r]==val)r--;
            else if(nums[l]==val)swap(nums[l],nums[r]),l++,r--;
            else l++;
        }
        return k;
    }
};