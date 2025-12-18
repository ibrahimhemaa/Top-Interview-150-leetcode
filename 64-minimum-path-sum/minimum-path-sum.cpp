class Solution {
public:
    vector<vector<int>>dp;
    
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),10000000));
        dp[0][0]=grid[0][0];
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(i){
                    dp[i][j]=min(dp[i][j],grid[i][j]+dp[i-1][j]);
                }
                if(j){
                    dp[i][j]=min(dp[i][j],grid[i][j]+dp[i][j-1]);
                }
            }
        }
        return dp[grid.size()-1][grid[0].size()-1];
    }
};