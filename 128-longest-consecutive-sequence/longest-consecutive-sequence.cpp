class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int cnt=0,ans=0,brev=-2e9;
        set<int>s;
        for(auto &i:nums)s.insert(i);
        for(auto &i:s){
            if(i==brev+1){
                brev++,cnt++;
            }
            else{
                ans=max(ans,cnt);
                cnt=1;
                brev=i;
            }
        }
        ans=max(ans,cnt);
        return ans;
    }
};