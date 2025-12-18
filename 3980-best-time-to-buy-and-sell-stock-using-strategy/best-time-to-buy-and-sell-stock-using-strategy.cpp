class Solution {
public:
    using ll=long long;
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n=prices.size();
        vector<vector<ll>>pref(n,vector<ll>(2,0));
        for(int i=0;i<n;i++){
            pref[i][0]=1ll*strategy[i]*prices[i];//cur pref
            pref[i][1]=prices[i];//sell pref
            if(i){
                pref[i][0]+=pref[i-1][0];
                pref[i][1]+=pref[i-1][1];
            }
        }
        ll ans=pref[n-1][0];
        for(int i=k-1;i<n;i++){
            ans=max(ans,pref[n-1][0]-pref[i][0]+(i-k>-1?pref[i-k][0]:0)+pref[i][1]-pref[i-k/2][1]);
        }
        return ans;
    }
};