class Solution {
public:
    int mxspain(vector<int>&bar){
        int mxstreak=1,streak=1;
        for(int i=0;i<bar.size()-1;i++){
            if(bar[i+1]-bar[i]==1)++streak;
            else streak=1;
            mxstreak=max(mxstreak,streak);
        }
        ++mxstreak;
        return mxstreak*mxstreak;
    }
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(vBars.begin(), vBars.end());
        sort(hBars.begin(), hBars.end());
        return min(mxspain(hBars),mxspain(vBars));
    }
};