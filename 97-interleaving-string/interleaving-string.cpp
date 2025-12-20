class Solution {
public:
    vector<vector<int>>dp;
    bool isInnterval(int i,int j,string &s1,string &s2,string &s3,int &n,int &m,int &k){
        if(i+j==k&&i==n&&j==m)return 1;
        if(i>=n&&j>=m)return 0;
        int &ret=dp[i][j];
        if(~ret)return ret;
        ret=0;
        if(i<n && s1[i]==s3[i+j]){
            ret|=isInnterval(i+1,j,s1,s2,s3,n,m,k);
        } 
        if(j<m && s2[j]==s3[i+j]){
            ret|=isInnterval(i,j+1,s1,s2,s3,n,m,k);
        } 
        return ret;
    }
    bool isInterleave(string s1, string s2, string s3) {
        s1="#"+s1;
        s2="#"+s2;
        s3="##"+s3;
        int n=s1.size(),m=s2.size(),k=s3.size();
        if(n+m!=k)return 0;
        dp.resize(n+2,vector<int>(m+2,-1));
        return (isInnterval(0,1,s1,s2,s3,n,m,k)|isInnterval(1,0,s1,s2,s3,n,m,k));

    }
};