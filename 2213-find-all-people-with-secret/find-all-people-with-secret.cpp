class Solution {
public:
    vector<int>vis,people,dist;
    vector<vector<pair<int,int>>>adj;
    priority_queue<vector<int>>pq;
    void dijikstra(){
        while(pq.size()){
            auto t=pq.top();
            pq.pop();
            if(vis[t[1]])continue;
            vis[t[1]]=1;
            people.push_back(t[1]);
            for(auto &[y,time]:adj[t[1]]){
                if(dist[y]>time && time>=-t[0]){
                    dist[y]=time;
                    pq.push({-time,y});
                }
            }
        }
        
    }
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        
        vis.resize(n+1,0);
        dist.resize(n+1,100001);

        adj.resize(n+1);
        int mn=100001;
        for(auto &v:meetings){
            adj[v[0]].push_back({v[1],v[2]});
            adj[v[1]].push_back({v[0],v[2]});
            if(!v[0]||!v[1])mn=min(mn,v[2]);

        }
        if(mn==100001)mn=0;
        dist[firstPerson]=0;
        pq.push({0,firstPerson});
        pq.push({-mn,0});
        dijikstra();
        return people;

    }
};