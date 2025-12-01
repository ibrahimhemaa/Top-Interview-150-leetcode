class Solution {
public: 
    using ll=long long;
    long long maxRunTime(int n, vector<int>& batteries) {
        ll l=1,r=1e14;
        //may be my solution memories but this is best solution 
        while(l<=r){
            ll mid=(l+r)>>1;
            ll sum=0;
            for(ll i:batteries){
                sum+=min(i,mid);
            }
            if(sum/mid>=n){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        } 
        return l-1;
    }
};