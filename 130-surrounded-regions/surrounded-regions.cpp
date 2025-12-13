class Solution {
public:
    vector<vector<char>> boards;
    vector<vector<int>>vis;
    vector<int> dx={0,1,-1,0};
    vector<int> dy={1,0,0,-1};
    int valid(int i,int j,int &n,int &m){
        return i>=0&&j>=0&&i<n&&j<m&&boards[i][j]=='O'&&!vis[i][j];
    }
    void dfs(int i,int j,int &n,int &m){
        vis[i][j]=1;
        for(int adj=0;adj<4;adj++){
            if(valid(i+dx[adj],j+dy[adj],n,m)){
                dfs(i+dx[adj],j+dy[adj],n,m);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size(),m=board[0].size();
        boards=board;
        vis.resize(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(valid(i,0,n,m)){
                dfs(i,0,n,m);
            }
            if(valid(n-i-1,m-1,n,m)){
                dfs(n-i-1,m-1,n,m);
            }
        }
        for(int i=0;i<m;i++){
            if(valid(0,i,n,m)){
                dfs(0,i,n,m);
            }
            if(valid(n-1,m-i-1,n,m)){
                dfs(n-1,m-i-1,n,m);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j])board[i][j]='X';
            }
        }
    }
};