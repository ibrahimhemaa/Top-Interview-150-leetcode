class Solution {
public:
    vector<vector<vector<int>>>adj;
    
    int dijekstra(int n){
        vector<int>vis(n,0);
        vector<int>dist(n,1e9);
        int mndis=1e9;
        priority_queue<pair<int,int>>pq;//wieght,node have
        pq.push({0,0});
        while(pq.size()){
            auto node=pq.top();
            pq.pop();
            if(vis[node.second])continue;
            vis[node.second]=1;
            dist[node.second]=-node.first;

            for(auto edge:adj[node.second]){
                if((!vis[edge[0]]||dist[edge[0]]>edge[1]+dist[node.second])){
                   
                    pq.push({-(edge[1]+dist[node.second]),edge[0]});
                }
            }
        }
        if(dist[n-1]==(int)1e9)dist[n-1]=-1;
        return dist[n-1];
    }
    
    int minCost(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for(vector<int> &edge:edges){
            adj[edge[0]].push_back({edge[1],edge[2]});
            adj[edge[1]].push_back({edge[0],2*edge[2]});
        }
        return dijekstra(n);
    }
};