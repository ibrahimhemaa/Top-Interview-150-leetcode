class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>>mat(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mat[i][j]+=(matrix[i][j]=='1')+(j &&matrix[i][j]=='1' ?mat[i][j-1]:0);
            }
        }
        int ans=0;
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                if(!mat[i][j])continue;
                int currWidth = mat[i][j];
                for(int k=i;k<n&&mat[k][j];++k)currWidth=min(currWidth,mat[k][j]),ans=max(ans,currWidth*(k - i + 1));
                currWidth = mat[i][j];
                for(int k=i;k>=0&&mat[k][j];--k)currWidth=min(currWidth,mat[k][j]),ans=max(ans,currWidth*(i-k + 1));
            }
        }
        return ans;
    }
};