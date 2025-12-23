class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        int n=events.size();
        int mx2event=0;
        vector<int>mxevent(n,0);
        for(int i=n-1;i>=0;i--){
            mx2event=max(mx2event,events[i][2]);
            mxevent[i]=mx2event;
        }
        for(int i=0;i<n;i++){
            int l=i+1,r=n-1;
            while(l<=r){
                if(events[(l+r)>>1][0]>events[i][1]){
                    r=((l+r)>>1)-1;
                }
                else{
                    l=((l+r)>>1)+1;
                }
            }
            if(r+1!=n) mx2event=max(mx2event,mxevent[r+1]+events[i][2]);
            else mx2event=max(mx2event,events[i][2]);
        }
        return mx2event;
    }
};