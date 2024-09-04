class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans;
        string s;
        if(nums.size())
            s+=to_string(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]+1 || i+1==nums.size()){
                if(i+1==nums.size() &&nums[i]==nums[i-1]+1 ){
                    s+="->";
                    s+=to_string(nums[i]);
                    ans.push_back(s);
                    s.clear();
                    break;
                }
                else if(stoi(s)!=nums[i-1]){
                    s+="->";
                    s+=to_string(nums[i-1]);
                    ans.push_back(s);
                }
                else ans.push_back(s);
                s=to_string(nums[i]);
            }
        }
        if(s.size())ans.push_back(s);
        return ans;
    }
};