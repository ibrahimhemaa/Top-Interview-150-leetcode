class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int>countmeet(n,0);
        priority_queue<pair<long long,int>>pq;
        for(int i=0;i<n;i++)pq.push({0,-i});
        sort(meetings.begin(),meetings.end());
        for(auto &meet:meetings){
            vector<int>index;
            while(pq.size()&&-pq.top().first<=meet[0]){
                index.push_back(pq.top().second);
                pq.pop();
            }
            for(auto &i:index)pq.push({0,i});
            pair<long long,int>room=pq.top();
            pq.pop();
            
            countmeet[-room.second]++;
            pq.push({-(meet[1]+max(0ll,-room.first-meet[0])),room.second});
        }
        long long mx=*max_element(countmeet.begin(),countmeet.end());
        for(int i=0;i<n;i++){
            if(mx==countmeet[i])return i;
        }
        return 0;
    }
};