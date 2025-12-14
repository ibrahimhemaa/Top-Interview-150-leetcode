class Solution {
public:
    
    int numberOfWays(string corridor) {
        int mod=1e9+7;
        int cntseet=0,cntplant=0;
        int ans=1;
        for(auto&c:corridor){
            if(c=='S'){  
                ans=((1ll*ans*(cntplant+1))%mod);
                cntplant=0;
                ++cntseet;
            }
            else{
                if(cntseet&&cntseet%2==0){
                    cntplant++;
                }
            }
        }
        if(cntseet==0||cntseet&1)ans=0;
        return ans;
    }
};