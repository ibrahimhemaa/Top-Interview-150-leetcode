class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0;
        int l=0,r=height.size()-1;
        while(l<r){
            int mn=min(height[l],height[r]);
            ans=max(ans,(r-l)*mn);
            if(height[l]==mn)l++;
            else r--;
        }
        return ans;
    }
};