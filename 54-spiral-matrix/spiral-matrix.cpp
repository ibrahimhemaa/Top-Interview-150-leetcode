class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        vector<pair<int,int>> dir={{0,1},{1,0},{0,-1},{-1,0}};
        int l=0,r=0,m=matrix.size(),n=matrix[0].size();
        int go=0;
        //0 go right 1 go down 2 left 3 up
        //no cycle
        vector<vector<int>>vis(m,vector<int>(n,0));
         auto can = [&](int i, int j) -> bool {
            return (i<m && j<n && i>=0 && j>=0 && !vis[i][j]);
         };
        ans.push_back(matrix[0][0]);
        vis[0][0]=1;
        while(ans.size()<n*m){
            int i=dir[go].first,j=dir[go].second;
            while(can(l+i,r+j)){
                vis[l+i][r+j]=1;
                ans.push_back(matrix[l+i][j+r]);
                l+=i,r+=j;
            }
            go+=1;
            go%=4;
        }
        return ans;
    }
};