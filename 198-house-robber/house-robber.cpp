class Solution {
public:
    vector<int>num;
    vector<int>dp;
    int max_money(int index){
        if(index>=num.size())return 0;
        //take,leave
        int &ret=dp[index];
        if(~ret)return ret;
        ret=max(max_money(index+2)+num[index],max_money(index+1));

        return ret;
    }
    int rob(vector<int>& nums) {
        num=nums;
        dp.resize(nums.size()+1,-1);
        return max_money(0);
    }
};