class Solution {
public:
    vector<vector<int>>mnsum;
    vector<int>suff1,suff2;
    int sol(int i,int j,int &n,int &m,string &s1,string &s2){
        if(i>=n&&j>=m)return 0;
        if(i==n||j==m)return ((m-i+n-j)*97)+suff1[i]+suff2[j];
        
        int &ret=mnsum[i][j];
        if(~ret)return ret;
        ret=sol(i+1,j,n,m,s1,s2)+(97+(s1[i]-'a'));
        ret=min(ret,sol(i,j+1,n,m,s1,s2)+(97+(s2[j]-'a')));
        if(s1[i]==s2[j]){
            ret=min(ret,sol(i+1,j+1,n,m,s1,s2));
        }
        return ret;
    }
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        mnsum.resize(n,vector<int>(m,-1));
        suff1.resize(n+1,0);
        suff2.resize(m+1,0);
        for(int i=n-1;i>=0;i--)suff1[i]=suff1[i+1]+(s1[i]-'a');
        for(int i=m-1;i>=0;i--)suff2[i]=suff2[i+1]+(s2[i]-'a');
        return sol(0,0,n,m,s1,s2);
    }
};