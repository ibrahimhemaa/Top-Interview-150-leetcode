class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>>m(matrix.size(),vector<int>(matrix[0].size()));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                m[i][j]=matrix[i][j];
            }
        }
        auto valid=[&](int i,int j)->bool{
            return (i>=0 &&j>=0 && i<matrix.size()&&j<matrix[0].size());
        };
        vector<pair<int,int>>dir={{-1,0},{0,-1},{1,0},{0,1}};
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(m[i][j]==0){
                    
                    for(auto &[x,y]:dir){
                        int i1=i,j1=j;
                        while(valid(i1+x,j1+y)){
                            matrix[i1+x][j1+y]=0;
                            i1+=x,j1+=y;
                        }
                    }
                }
            }
        }
    }
};