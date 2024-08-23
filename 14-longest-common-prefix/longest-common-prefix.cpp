class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        map<string,int>mp;
        string ans="";
        for(int i=0;i<n;i++){
            string s;
            for(int j=0;j<strs[i].size();j++){
                s+=strs[i][j];
                mp[s]++;
            }
        }
        for(auto &[x,y]:mp){
            if(y==n){
                if(x.size()>ans.size())ans=x;
            }
        }
        return ans;
    }
};