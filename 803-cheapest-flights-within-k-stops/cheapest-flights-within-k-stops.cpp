class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // we have to make pair of {{stops,{node,cost}}}
       vector<vector<pair<int,int>>> adj(n);
        for(auto edge:flights){
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];
            adj[u].push_back({v,wt});
        }
        queue<pair<int,pair<int,int>>> q;
        vector<int> dist(n,INT_MAX);
        q.push({0,{src,0}});
        dist[src]=0;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stops=it.first;
            int node=it.second.first;
            int cost=it.second.second;
            if(stops>k) continue;
            for(auto x:adj[node]){
               int adjnode=x.first;
               int wt=x.second;
               if(wt+cost<dist[adjnode]&&stops<=k){
                     dist[adjnode]=wt+cost;
                     q.push({stops+1,{adjnode,dist[adjnode]}});
               }
            }
        }
        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];
    }
};