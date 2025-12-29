class Solution {
public:
    unordered_map<string, bool> dp;
    map<string,vector<char>>mp;
    bool pyramidpattern(vector<string>& allowed,string bottom,string carry="",int i=0){
        //check all bottom
        if(bottom.size()==1)return 1;
        if (i == 0 && dp.count(bottom))
            return dp[bottom];
        if (i == bottom.size() - 1) {
            bool res = pyramidpattern(allowed,carry);
            return dp[bottom] = res;   
        }

        int ret=0;
        string s=bottom.substr(i,2);
        for(char c:mp[s]){
            carry.push_back(c);
            ret|=pyramidpattern(allowed,bottom,carry,i+1);
            carry.pop_back();
        }
        if(i==0)dp[bottom]=ret;
        return ret;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for(auto &s:allowed){
            mp[s.substr(0,2)].push_back(s[2]);
        }
        return pyramidpattern(allowed,bottom);
    }
};