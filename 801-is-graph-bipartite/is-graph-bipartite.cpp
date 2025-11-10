class Solution {
public:
    bool check(vector<vector<int>>& graph, int start, vector<int>& color, int n) {
        queue<int> q;
        q.push(start);
        color[start] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto x : graph[node]) {
                if (color[x] == -1) {  // not colored
                    color[x] = !color[node];  // assign opposite color
                    q.push(x);
                } else if (color[x] == color[node]) {
                    return false;  // conflict
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (check(graph, i, color, n) == false)
                    return false;
            }
        }
        return true;
    }
};
