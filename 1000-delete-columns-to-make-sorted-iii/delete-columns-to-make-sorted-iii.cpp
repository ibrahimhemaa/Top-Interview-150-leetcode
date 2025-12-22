class Solution {
public:
    vector<vector<int>>dp,valid;
    int maxlexi(vector<string>& strs,int &m,int i,int prev){
        if(i==m)return 0;
        int &ret=dp[i][prev+1];
        if(~ret)return ret;
        ret=0;
        //leave
        ret=max(ret,maxlexi(strs,m,i+1,prev));
        //pick
        if(~prev){
            // bool validindx=1;
            // for(string word:strs){100*100*100
            //     validindx&=(word[prev]<=word[i]);
            // }
            cout<<i<<' '<<prev+1<<' '<<valid[i][prev+1]<<'\n';
            if(valid[i][prev])ret=max(ret,1+maxlexi(strs,m,i+1,i));
        }
        else{
            ret=max(ret,1+maxlexi(strs,m,i+1,i));
        }
        return ret;
    }
    int minDeletionSize(vector<string>& strs) {
        int m=strs[0].size();

        dp.resize(m+1,vector<int>(m+2,-1));
        valid.resize(m+1,vector<int>(m+2,0));

        // for(auto &word:strs){
            for(int c=0;c<m;c++){
                for(int nexc=c+1;nexc<m;nexc++){
                    int validstep=1;
                    for(auto &word:strs)validstep&=(word[c]<=word[nexc]);
                    // cout<<c<<' '<<nexc<<' '<<validstep<<'\n';
                    valid[nexc][c]=validstep;
                }
            }
        // }
        return m-maxlexi(strs,m,0,-1);
    }
};