class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx=-1,ans=0;
        for(int i=prices.size()-1;i>=0;i--){
            ans=max(mx-prices[i],ans);
            mx=max(mx,prices[i]);
        }
        return ans;
    }
};