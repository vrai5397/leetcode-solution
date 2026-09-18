class Solution {
public:
int bfs(vector<vector<pair<int,int>>>& adj,
vector<int>& visited,int node,int count){
    queue<int> q;
    q.push(node);
    visited[node]=1;
    while(!q.empty()){
        auto x=q.front();
        q.pop();
        for(auto y:adj[x]){
            int p=y.first;
            int direction=y.second;
            if(!visited[p]){
              
               q.push(p);
               visited[p]=1;
               count+=direction;
            }
        }
    }
    return count;
}
    int minReorder(int n, vector<vector<int>>& connections) {
    // for given direction we should have 1
    // for false direction we should have 0
    vector<vector<pair<int,int>>> adj(n);
    vector<int> visited(n,0);
    for(int i=0;i<connections.size();i++){
        int u=connections[i][0];
        int v=connections[i][1];
        adj[u].push_back({v,1});
        adj[v].push_back({u,0});
    }
return bfs(adj,visited,0,0);
    }
};