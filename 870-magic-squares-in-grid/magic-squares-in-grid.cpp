class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int row_size=grid.size(),column_size=grid[0].size();
        if(row_size<3 || column_size<3)return 0;
        int count_magics=0;
        for(int i=0;i<row_size;i++){
            for(int j=0;j<column_size;j++){
                if(row_size-i>=3 && column_size-j>=3){
                    set<int>num;
                    for(int row=i;row<i+3;row++){
                        for(int col=j;col<j+3;col++){
                            if(grid[row][col]<1 || grid[row][col]>9)break;
                            num.insert(grid[row][col]);
                        }
                        if(num.size()!=((row-i+1)*3))break;
                    }
                    bool flag=true;
                    int row_sum=grid[i][j]+grid[i][j+1]+grid[i][j+2],col_sum=grid[i][j]+grid[i+1][j]+grid[i+2][j];
                    for(int row=i+1;row<i+3;row++){
                        int sum=0;
                        for(int col=j;col<j+3;col++)sum+=grid[row][col];
                        flag&=(sum==row_sum);
                    }
                    for(int col=j+1;col<j+3;col++){
                        int sum=0;
                        for(int row=i;row<i+3;row++)sum+=grid[row][col];
                        flag&=(sum==row_sum);
                    }
                    count_magics+=(flag&&num.size()==9&&grid[i][j]+grid[i+2][j+2]==grid[i+2][j]+grid[i][j+2]);
                }
            }
        }
        return count_magics;
    }
};