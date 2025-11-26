class Solution {
public:
    bool isvalid(int r,int c,int n,int m){
        return r>=0 &&c>=0&&r<n&&c<m;
    }
    bool dfs(vector<vector<char>>& board, string& word, int idx,
             int r, int c, vector<vector<bool>>& vis)
    {
        if(idx == word.size()) return true;
        if(!isvalid(r,c,board.size(),board[0].size())||vis[r][c]||board[r][c] != word[idx]) return false;

        vis[r][c] = true;

        bool found =
            dfs(board, word, idx+1, r+1, c, vis) ||
            dfs(board, word, idx+1, r-1, c, vis) ||
            dfs(board, word, idx+1, r, c+1, vis) ||
            dfs(board, word, idx+1, r, c-1, vis);

        vis[r][c] = false;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m,false));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dfs(board, word, 0, i, j, vis))
                    return true;
            }
        }
        return false;
    }
};