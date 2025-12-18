class Solution {
public:
    using ll=long long;
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n=prices.size();
        vector<ll>pref(n,0);
        for(int i=0;i<n;i++){
            pref[i]=1ll*strategy[i]*prices[i];
            if(i){
                pref[i]+=pref[i-1];
            }
        }
        ll ans=pref[n-1];
        ll cur1=0;
        for(int i=k/2;i<n;i++){
            cur1+=prices[i];
            if(i>=k-1){//2 3 
                if(i>k-1)cur1-=prices[i-k/2];
                ans=max(ans,pref[n-1]-pref[i]+(i-k>-1?pref[i-k]:0)+cur1);
            }
            
        }
        return ans;
    }
};