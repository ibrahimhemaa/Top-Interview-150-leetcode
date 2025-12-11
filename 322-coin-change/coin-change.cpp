class Solution {
public:
    vector<int> dp;
    int step_change(vector<int>& coins,int amount,int count=0){
        if(!amount)return count;
        int &ret=dp[amount];
        if(~ret)return ret;
        ret=1e9;
        for(int i=0;i<coins.size();i++){
            if(coins[i]<=amount){
               ret=min(step_change(coins,amount-coins[i])+1,ret);
            }
        }
        return ret;
    }
    int coinChange(vector<int>& coins, int amount) {
        dp.resize(amount+1,-1);
        int ans=step_change(coins,amount);
        return (ans>10000?-1:ans);
    }
};