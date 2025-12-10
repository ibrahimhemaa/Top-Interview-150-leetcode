class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int n=complexity.size();
        for(int i=1;i<n;i++){
            if(complexity[i]<=complexity[0])return 0;
        }
        const int mod=1e9+7;
        int ans=1;
        n--;
        while(n>1){

            ans=(1ll*ans*n)%mod;
            --n;
        }
        return ans;
    }
};