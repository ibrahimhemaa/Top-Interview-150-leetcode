class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int>mp;
        int ok=0;
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]]){
                ok|=((i+1-mp[nums[i]])<=k);
            }
            mp[nums[i]]=i+1;
        }
        return ok;
    }
};