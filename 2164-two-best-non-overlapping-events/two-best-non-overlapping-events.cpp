class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        int n=events.size();
        int mx2event=0;
        vector<int>mxevevt(n,0);
        for(int i=n-1;i>=0;i--){
            mxevevt[i]=events[i][2];
            if(i!=n-1)mxevevt[i]=max(mxevevt[i],mxevevt[i+1]);
        }
        for(int i=0;i<n;i++){
            int l=i+1,r=n-1;
            int next=-1;
            while(l<=r){
                int md=(l+r)>>1;
                if(events[md][0]>events[i][1]){
                    r=md-1;
                    next=md;
                }
                else{
                    l=md+1;
                }
            }
            if(~next) mx2event=max(mx2event,mxevevt[next]+events[i][2]);
            else mx2event=max(mx2event,events[i][2]);
            cout<<r<<' '<<l<<'\n';
        }
        return mx2event;
    }
};