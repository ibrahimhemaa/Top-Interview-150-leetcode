class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx=-1,ans=0;
        for(int i=prices.size()-1;i>=0;i--){
            if(mx>prices[i])ans=max(mx-prices[i],ans);
            else mx=prices[i];
        }
        return ans;
    }
};