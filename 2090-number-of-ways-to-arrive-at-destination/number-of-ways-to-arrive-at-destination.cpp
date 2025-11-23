class Solution {
public:
    const long long INF = 1e18;
    int mod = 1e9 + 7;

    int countPaths(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(V);
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            long long w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        vector<long long> dist(V, INF);
        vector<int> ways(V, 0);

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            // if (d > dist[node]) continue;

            for (auto &p : adj[node]) {
                int nxt = p.first;
                long long w = p.second;

                if (d + w < dist[nxt]) {
                    dist[nxt] = d + w;
                    ways[nxt] = ways[node];
                    pq.push({dist[nxt], nxt});
                } 
                else if (d + w == dist[nxt]) {
                    ways[nxt] = (ways[nxt] + ways[node]) % mod;
                }
            }
        }

        return ways[V-1];
    }
};
