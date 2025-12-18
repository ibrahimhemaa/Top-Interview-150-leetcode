class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,10000000));
        dp[0][0]=triangle[0][0];
        for(int i=1;i<n;i++){
            for(int j=0;j<triangle[i].size();j++){
                dp[i][j]=dp[i-1][j]+triangle[i][j];
                if(j){
                    dp[i][j]=min(dp[i-1][j-1]+triangle[i][j],dp[i][j]);
                }
            }
            if(i==n-1){
                for(int j=0;j<triangle[i].size();j++)dp[n-1][n-1]=min(dp[i][j],dp[n-1][n-1]);
            }
        }
        return dp[n-1][n-1];
    }
};