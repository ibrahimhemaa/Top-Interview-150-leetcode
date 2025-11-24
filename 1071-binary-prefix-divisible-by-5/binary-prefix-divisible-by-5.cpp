class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool>answer(nums.size());
        bool flag=0;
        int prefix=0;
        for(int i=0;i<nums.size();i++){
            prefix=((prefix<<1)+nums[i])%5;
            answer[i]=prefix==0;
        }
        return answer;
    }
};