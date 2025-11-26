class Solution {
public:
    vector<vector<bool>> vis;
    string s;
    vector<vector<char>> boards;

    bool isvalid(int r,int c,int n,int m,int idx){
        return r>=0 &&c>=0&&r<n&&c<m  && !vis[r][c] &&boards[r][c] == s[idx] ;
    }
    bool dfs(int idx,
             int r, int c,int n,int m)
    {
        if(idx == s.size()) return true;
        if(!isvalid(r,c,n,m,idx)) return false;

        vis[r][c] = true;

        bool found =
            dfs(idx+1, r+1, c, n,m) ||
            dfs( idx+1, r-1, c, n,m) ||
            dfs( idx+1, r, c+1, n,m) ||
            dfs( idx+1, r, c-1, n,m);

        vis[r][c] = false;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        s=word;
        boards=board;
        vis.resize(n, vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dfs(0, i, j,n,m))
                    return true;
            }
        }
        return false;
    }
};