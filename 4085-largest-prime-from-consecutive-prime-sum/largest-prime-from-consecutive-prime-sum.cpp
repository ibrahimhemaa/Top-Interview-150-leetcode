class Solution {
public:
    int N=4e5;
    vector<int>prime;
    vector<int>pref;
    vector<int>ans;
    void init(){
        prime.resize(N+1,1);
        for(int i=2;i*i<N;i++){
            if(!prime[i])continue;
            for(int j=i*i;j<N;j+=i){
                prime[j]=0;
            }
        }
        for (int i = 2; i < N; ++i) {
            if(prime[i])pref.push_back(i);
        }
    }
    void build(){
        ans.push_back(2);
        for(int i=1;i<pref.size();i++){
    
            if(pref[i-1]>N)
                pref[i]=pref[i-1];
            else
                pref[i]=pref[i]+pref[i-1];
            if(pref[i]>N)continue;
            if(prime[pref[i]]){
                ans.push_back(pref[i]);
            }
        }
    }
    int largestPrime(int n) {
        if(n==1)return 0;
        N=n+1;
        init();
        build();
        int l=0,r=ans.size()-1;
        while(l<=r){
            int mid=(l+r)>>1;
            if(ans[mid]==n)return n;
            if(ans[mid]>n){
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans[r];
    }
};