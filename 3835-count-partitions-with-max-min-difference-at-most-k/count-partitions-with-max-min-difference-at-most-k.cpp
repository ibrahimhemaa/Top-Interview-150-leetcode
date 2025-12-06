class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
       const int mod=1e9+7,n=nums.size();
       int acc=1;
       vector<int>dp(n+1,0);
       dp[0]=1;
       deque<int>mnq,mxq;
       for(int l=0,r=0;r<n;++r){
            while(mxq.size()&&nums[r]>nums[mxq.back()])
                mxq.pop_back();
            mxq.push_back(r);
            while (mnq.size() && nums[r] < nums[mnq.back()])
                mnq.pop_back();
            mnq.push_back(r);
            while (nums[mxq.front()] - nums[mnq.front()] > k) {
                acc = (acc - dp[l++] + mod) % mod;
                if (mnq.front() < l)
                    mnq.pop_front();
                if (mxq.front() < l)
                    mxq.pop_front();
            }

            dp[r + 1] = acc;
            acc = (acc + dp[r + 1]) % mod;    
       } 
       return dp[n];
    }
};