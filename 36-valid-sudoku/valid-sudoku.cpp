class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //check each col && each row all unique
        for(int i=0;i<9;i++){
            map<char,int>row,col;
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    if(row[board[i][j]])return false;
                    row[board[i][j]]++;
                    
                }
                if(board[j][i]!='.'){
                    if(col[board[j][i]])return false;
                    col[board[j][i]]++;
                }
            }
        }
        //check boundry 
        //
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                map<char,int>box;
                for(int i1=i;i1<i+3;i1++){
                    for(int j1=j;j1<j+3;j1++){
                        if(board[i1][j1]!='.'){
                            if(box[board[i1][j1]]){

                                return false;
                            }
                            box[board[i1][j1]]++;
                        }
                    }
                }
            }
        }
        return true; 
    }
};