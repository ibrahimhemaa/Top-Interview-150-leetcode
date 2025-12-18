class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i,int j,vector<vector<int>>& triangle){
        if(i==triangle.size()||j==triangle[i].size())return 0;
        int &ret=dp[i][j];
        if(ret!=10000000)return ret;
        ret=triangle[i][j]+min(solve(i+1,j,triangle),solve(i+1,j+1,triangle));
        return ret;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        dp.resize(n,vector<int>(n,10000000));
        return solve(0,0,triangle);
    }
};