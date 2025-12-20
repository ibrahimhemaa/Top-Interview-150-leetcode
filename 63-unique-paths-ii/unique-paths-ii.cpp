class Solution {
public:
    vector<vector<int>>number_paths;
    int uniquePaths(int i,int j,int &n,int &m ,vector<vector<int>>& obstacleGrid){
        if(i>=n ||j>=m||obstacleGrid[i][j])return 0;
        int &number_path=number_paths[i][j];
        if(~number_path)return number_path;
        number_path=uniquePaths(i+1,j,n,m,obstacleGrid)+uniquePaths(i,j+1,n,m,obstacleGrid);
        return number_path;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size(),m=obstacleGrid[0].size();
        number_paths.resize(n,vector<int>(m,-1));
        number_paths[n-1][m-1]=1;
        return uniquePaths(0,0,n,m,obstacleGrid); 
    }
};