class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n=prices.size();
        long long ans=0;
        int last=prices[0],cnt=0;
        for(int i=0;i<n;i++){
            if(prices[i]+1==last)++cnt;
            else{
                ans+=(1ll*cnt*(cnt+1)/2);
                cnt=1;
            }
            last=prices[i];
        }
        ans+=(1ll*cnt*(cnt+1)/2);;
        return ans;
    }
};