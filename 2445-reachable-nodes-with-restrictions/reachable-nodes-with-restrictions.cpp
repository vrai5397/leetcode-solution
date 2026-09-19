class Solution {
public:
void dfs(vector<vector<int>>& adj,vector<int>&
visited,vector<int>& isrestricted,int node){
   if(isrestricted[node]==1)
   return;

    visited[node]=1;
    for(auto x:adj[node]){
        if(!visited[x])
        dfs(adj,visited,isrestricted,x);
    }
}
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        // suited fro dfs
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
           vector<int> isrestricted(n, 0);

        for(auto x : restricted) {
            isrestricted[x] = 1;
        }
        
        vector<int> visited(n,0);
        dfs(adj,visited,isrestricted,0);
        
        int count=0;
        for(auto x:visited){
            if(x==1)
            count++;
        }
       
return count;
    }
};