class Solution {
public:
    using ll= long long;
    int minSubarray(vector<int>& nums, int p) {
        ll prefsum=0,suff=0;
        int n=nums.size();
        int ans=n;
        for(auto i:nums)suff+=i;
        unordered_map<int,int>mp;
        mp[0]=-1;
        for(int i=0;i<n;i++){
            prefsum+=nums[i];
            suff-=nums[i];
            mp[prefsum%p]=i;
            int rem = (p - suff % p) % p;
           if(mp.find(rem)!=mp.end()){
            ans=min(ans,i-mp[rem]);
           }
        }
        if(ans==n)ans=-1;
        return ans;
    }
};