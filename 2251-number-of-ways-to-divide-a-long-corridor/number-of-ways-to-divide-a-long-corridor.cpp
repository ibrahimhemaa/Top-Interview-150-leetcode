class Solution {
public:
    int mod=1e9+7;
    // int fastpower(int base,int number){
    //     if(number==0)return 1;
    //     int ret=(fastpower(base,number/2)%mod);
    //     ret=((1ll*ret*ret)%mod);
    //     if(number&1){
    //         ret=((1ll*ret*base)%mod);
    //     }
    //     return ret;
    // }
    int numberOfWays(string corridor) {
        int numofseat=0;
        for(auto &c:corridor)numofseat+=(c=='S');
        if(numofseat==0||numofseat&1)return 0;
        if(numofseat==2)return 1;
        int cntseet=0,cntplant=0;
        int ans=1;
        for(auto&c:corridor){
            if(c=='S'){
                if(cntplant){  
                    ans=((1ll*ans*(cntplant+1))%mod);
                }
                cntplant=0;
                ++cntseet;
            }
            else{
                if(cntseet&&cntseet%2==0){
                    cntplant++;
                }
            }
        }
        // for(auto &i:betweenTwoseet)cout<<i<<' ';
        return ans;
    }
};