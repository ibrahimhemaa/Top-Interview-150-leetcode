class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans;
        vector<pair<int,int>>v;
        for(int i=0;i<nums.size();i++){
            if(!v.size()||v.back().second+1!=nums[i]){
                v.push_back({nums[i],nums[i]});
            }
            else{
                v.back().second=nums[i];
            }
        }
        for(auto &[x,y]:v){
            ans.push_back(to_string(x));
            if(x!=y){
                ans.back()+="->";
                ans.back()+=to_string(y);
            }
        }return ans;
    }
        
};