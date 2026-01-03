class Solution {
public:
    int numOfWays(int n) {
        //1*3 ->3 
        const int mod=1e9+7;
        int a=6,b=6;
        for(int i=2;i<=n;i++){
            int na=(2ll*a+2ll*b)%mod;
            int nb=(2ll*a+3ll*b)%mod;
            a=na,b=nb;
        }
        int ans=(1ll*a+1ll*b)%mod;
        return ans;
    }
};