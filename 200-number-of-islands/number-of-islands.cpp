class Solution {
public:
    vector<vector<char>> grids;
    vector<vector<int>>visitednode;
    vector<int> dx={0,1,-1,0};
    vector<int> dy={1,0,0,-1};
    int valid(int i,int j,int &n,int &m){
        return i>=0&&j>=0&&i<n&&j<m&&grids[i][j]=='1'&&!visitednode[i][j];
    }
    void visitAdjcentIsland(int i,int j,int &n,int &m){
        visitednode[i][j]=1;
        for(int adj=0;adj<4;adj++){
            if(valid(i+dx[adj],j+dy[adj],n,m)){
                visitAdjcentIsland(i+dx[adj],j+dy[adj],n,m);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        
        grids=grid;
        
        int n=grid.size();
        int m=grid[0].size();
        int sum=0,island_number=0;
        visitednode.resize(n,vector<int>(m, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!valid(i,j,n,m))continue;
                ++island_number;
                visitAdjcentIsland(i,j,n,m);
            }            
        }
        return island_number;
    }
};