class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int ans=1,back=points[0][1];
        for(int i=1;i<points.size();i++){
            if(back<points[i][0]){
                back=points[i][1];
                ans++;       
            }else {
                back=min(back,points[i][1]);}
        }
        return ans;
    }
};