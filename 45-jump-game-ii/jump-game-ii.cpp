class Solution {
public:
    int jump(vector<int>& nums) { 
        int n=nums.size();
        int dp[n+7];
        for(int i=0;i<n+5;i++){
            dp[i]=-1;
        }
        dp[n-1]=1;
        function<int(int)> slv = [&](int i) -> int{
            if(i==n-1)return 0;
            if(i>=n || nums[i]==0)return 100000000;
            int &ret=dp[i];
            if(~ret)return ret;
            ret=100000000;
            for(int i1=1;i1<=nums[i];i1++){
                ret=min(ret,slv(i+i1)+1);
            }
            return ret;
        };
        return slv(0);
    }
};