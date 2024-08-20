class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>re;
        k%=n;
        for(int i=n-k;i<n;i++)re.push_back(nums[i]);
        for(int i=0;i<n-k;i++)re.push_back(nums[i]);
        for(int i=0;i<n;i++)nums[i]=re[i];
    }
};