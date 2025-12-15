class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans=0;
        int last=prices[0],cnt=0;
        for(auto &price:prices){
            if(price+1==last)++cnt;
            else{
                ans+=(1ll*cnt*(cnt+1)/2);
                cnt=1;
            }
            last=price;
        }
        ans+=(1ll*cnt*(cnt+1)/2);;
        return ans;
    }
};