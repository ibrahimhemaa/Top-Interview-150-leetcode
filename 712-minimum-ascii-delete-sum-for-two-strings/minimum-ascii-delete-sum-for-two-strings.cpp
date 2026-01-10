class Solution {
public:
    vector<vector<int>>mnsum;
    int sol(int i,int j,int &n,int &m,string &s1,string &s2){
        if(i>=n&&j>=m)return 0;
        if(i==n||j==m){
            int ans=((m-i+n-j)*97);
            while(i!=n)ans+=(s1[i++]-'a');
            while(j!=m)ans+=(s2[j++]-'a');
            return ans;
        }
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
        return sol(0,0,n,m,s1,s2);
    }
};