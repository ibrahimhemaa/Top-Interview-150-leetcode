class Solution {
public:
    int trap(vector<int>& height) {
    int n=height.size();
    vector<int>suff(n+3),pref(n);
    int ans=0;
    for (int i = n-1; i >=0 ; --i) {
        suff[i]=max(height[i],suff[i+1]);
    }
    pref[0]=height[0];
    for (int i = 1; i < n; ++i) {
        pref[i]=max(pref[i-1],height[i]);
    }
    for (int i = 0; i <n ; ++i) {
        ans+=min(suff[i],pref[i])-height[i];
    }
    return ans;
}
};