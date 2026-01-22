class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int cnt=0;
        while(!is_sorted(nums.begin(),nums.end())){
            int minSum = 100000, idx = 0;
           for (int i = 0; i + 1 < nums.size(); i++) {
               if (nums[i] + nums[i+1] < minSum) {
                   minSum = nums[i] + nums[i+1];
                   idx = i;
               }
           }
           nums[idx] = minSum;
           nums.erase(nums.begin() + idx + 1);
           cnt++;
        }
        return cnt;
    }
};