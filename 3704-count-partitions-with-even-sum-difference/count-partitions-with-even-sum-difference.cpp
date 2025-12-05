class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum=0,sum2=0,ans=0;
        for(auto &i:nums){
            sum+=i;
        }
        for(auto &i:nums){
            sum-=i;
            sum2+=i;
            if(sum!=0)ans+=(sum%2==sum2%2);
        }                
        return ans;
    }
};