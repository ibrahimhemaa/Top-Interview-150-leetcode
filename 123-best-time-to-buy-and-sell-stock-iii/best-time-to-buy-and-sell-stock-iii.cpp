class Solution {
public:
    vector<vector<vector<int>>>dp;
    int solve(vector<int>& prices,int &n,int i,int k,int state){
        if(i==n)return (!state?0:-1e9);
        int &ret=dp[i][k][state];
        if(ret!=(int)-1e9)return ret;
        ret=max(ret,solve(prices,n,i+1,k,state));
        if(!state && k){
            ret=max(ret,-prices[i]+solve(prices,n,i+1,k,1));
        }
        else if(k){
            ret=max(ret,prices[i]+solve(prices,n,i+1,k-1,0));
        }
        return ret;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        dp.resize(n+1,vector<vector<int>>(3,vector<int>(2,-1e9)));
        return solve(prices,n,0,2,0);
    }
};