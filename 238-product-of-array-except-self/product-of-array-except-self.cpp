class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sum=1;
        int cnt=0,n=nums.size(); 
        vector<int>ans(n,0);
        for(auto &i:nums)sum*=i,cnt+=(i==0);
        if(cnt){
            if(cnt==1){
                sum=1;
                for(int i=0;i<n;i++){
                    if(nums[i]==0)cnt=i;
                    else sum*=nums[i];
                }
                ans[cnt]=sum;
            }
            return ans;
        }
        for(int i=0;i<n;i++)ans[i]=(sum/nums[i]);
        return ans;
    }
};