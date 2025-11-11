class Solution {
public:
 bool dfs(vector<vector<int>>& adj, vector<int>& visited, vector<int>& pathvisited, int node, vector<int>& check) {
        visited[node] = 1;
        pathvisited[node] = 1;

        for (auto x : adj[node]) {
            if (!visited[x]) {
                if (dfs(adj, visited, pathvisited, x, check)) {
                    check[node] = 0;
                    return true;  // cycle found
                }
            } else if (pathvisited[x]) {
                check[node] = 0;
                return true;  // cycle found
            }
        }

        check[node] = 1;  // safe node
        pathvisited[node] = 0;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int V=adj.size();
        vector<int> visited(V, 0), pathvisited(V, 0), check(V, 0);
        vector<int> safenode;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(adj, visited, pathvisited, i, check);
            }
        }

        for (int i = 0; i < V; i++) {
            if (check[i] == 1)
                safenode.push_back(i);
        }

        return safenode;
    }
};