class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>mp;
        int sz=nums.size();
        sz/=2;
        sz++;
        for(auto &i:nums){
            mp[i]++;
            if(mp[i]==sz){
                return i;
            }
        }
        return -1;
    }
};