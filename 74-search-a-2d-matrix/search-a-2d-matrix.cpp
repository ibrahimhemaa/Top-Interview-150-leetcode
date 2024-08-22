class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int>v;
        bool okk=false;
        for(int i=0;i<matrix.size();i++){
            bool  ok=false;
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==target){
                    ok=true;break;
                }
                
            }
            if(ok){
                    okk=true;break;
                }
        }
        return okk;
    }
};