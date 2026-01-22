class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        vector<int> arr(nums.begin(), nums.end());
        int cnt=0;
        while(!is_sorted(arr.begin(),arr.end())){
            int minSum = 100000, idx = 0;
           for (int i = 0; i + 1 < arr.size(); i++) {
               if (arr[i] + arr[i+1] < minSum) {
                   minSum = arr[i] + arr[i+1];
                   idx = i;
               }
           }
           arr[idx] = minSum;
           arr.erase(arr.begin() + idx + 1);
           cnt++;
        }
        return cnt;
    }
};