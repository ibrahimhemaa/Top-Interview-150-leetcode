class Solution {
public:
    using ll=long long;
    ll N=1e18;
    vector<vector<vector<ll>>>maxprofit;
    ll solve(vector<int>& prices,int &n,int i,int k,int state){
        if(k==0)return 0;
        if(i==n)return (state?-N:0);
        ll &ret=maxprofit[i][k][state];
        if(ret!=-1)return ret;
        ret=-N;
        //leave
        ret=max(ret,solve(prices,n,i+1,k,state));
        //pick
        if(!state && k){
            ret=max(ret,prices[i]+solve(prices,n,i+1,k,1));
            ret=max(ret,-prices[i]+solve(prices,n,i+1,k,2));
        }
        else{
            if(state==1){
                ret=max(ret,-prices[i]+solve(prices,n,i+1,k-1,0));
            }
            else{
                ret=max(ret,prices[i]+solve(prices,n,i+1,k-1,0));
            }
        }
        return ret;
    }
    long long maximumProfit(vector<int>& prices, int k) { 
        int n=prices.size();
        maxprofit.assign(n+1,vector<vector<ll>>(k+1,vector<ll>(3,-1)));
        return solve(prices,n,0,k,0);
      
    }
};