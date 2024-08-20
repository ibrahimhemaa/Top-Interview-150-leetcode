class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int>mp;
        for(auto &i:nums)mp[i]++;
        int i=0;
        for(auto &[x,y]:mp){
            for(int j=0;j<min(2,y);j++)nums[i++]=x;
        }
        return i;
    }
};