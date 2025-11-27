class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1, 1e9);
        dist[k] = 0;

        // Bellman-Ford: n-1 relaxations
        for(int i = 1; i <= n-1; i++){
            for(auto &edge : times){
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];

                if(dist[u] != 1e9 && dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                }
            }
        }

        // check unreachable nodes
        for(int i=1;i<=n;i++){
            if(dist[i] == 1e9)
                return -1;
        }

        // return the maximum time (not dist[n])
        int ans = 0;
        for(int i=1;i<=n;i++){
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};
