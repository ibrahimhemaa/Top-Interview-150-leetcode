class Solution {
public:
    vector<int>dp;
    int solve(string &s,vector<string>& wordDict,int n,int i,string word=""){
        if(word==s)return 1;
        int &ret=dp[i];
        if(~ret)return ret;
        ret=0;
        for(auto w:wordDict){
            if(n-i+1>=w.size()&&s.substr(i,w.size())==w){
                ret|=solve(s,wordDict,n,i+w.size(),word+w);
            }
        }
        return ret;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        dp.resize(n+1,-1);
        return solve(s,wordDict,n,0);
    }
};