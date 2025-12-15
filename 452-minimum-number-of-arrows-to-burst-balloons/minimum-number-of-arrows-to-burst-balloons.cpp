class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int ans=1,back=0;
        sort(points.begin(),points.end());
        pair<int,int>v={points[0][0],points[0][1]};
        for(int i=1;i<points.size();i++){
            if(v.second<points[i][0]){
                 v={points[i][0],points[i][1]};ans++;       
            }
            else v.second=min(v.second,points[i][1]);
        }
        return ans;
    }
};