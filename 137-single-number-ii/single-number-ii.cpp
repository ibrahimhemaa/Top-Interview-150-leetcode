class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int>mp;
        for(auto &i:nums)mp[i]++;
        for(auto &[x,cnt]:mp){
            if(cnt%3)return x;
        }
        return 0;
    }
};