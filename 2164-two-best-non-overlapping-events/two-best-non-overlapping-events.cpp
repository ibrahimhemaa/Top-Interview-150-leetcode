class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        int n=events.size();
        int mx2event=0;
        vector<int>mxevent(n+1,0);
        for(int i=n-1;i>=0;i--){
            mx2event=max(mx2event,events[i][2]);
            mxevent[i]=mx2event;
        }
        for(int i=0;i<n;i++){
            int l=i+1,r=n-1;
            while(l<=r){
                int md=(l+r)>>1;
                if(events[md][0]>events[i][1]){
                    r=md-1;
                }
                else{
                    l=md+1;
                }
            }
            mx2event=max(mx2event,mxevent[r+1]+events[i][2]);
        }
        return mx2event;
    }
};