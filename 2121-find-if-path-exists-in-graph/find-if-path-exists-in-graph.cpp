class Solution {
public:

    bool dfs(vector<vector<int>>& adj, int destination,
             int node, vector<int>& visited) {

        if(node == destination)
            return true;

        visited[node] = 1;

        for(auto x : adj[node]) {

            if(!visited[x]) {

                if(dfs(adj, destination, x, visited))
                    return true;
            }
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges,
                   int source, int destination) {

        vector<vector<int>> adj(n);

        for(int i = 0; i < edges.size(); i++) {

            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(n, 0);

        return dfs(adj, destination, source, visited);
    }
};