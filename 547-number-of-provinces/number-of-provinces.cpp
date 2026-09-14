class Solution {
public:
void bfs(vector<vector<int>>& adj,int node,vector<int>
& visited){
   queue<int> q;
   q.push(node);
   visited[node]=1;
   while(!q.empty()){
       int currnode=q.front();
       q.pop();
       for(auto x:adj[currnode]){
           if(!visited[x]){
            visited[x]=1;
           q.push(x);
           }
       }
   }

}
    int findCircleNum(vector<vector<int>>& isConnected) {
        // 1 1 0   // 1 2 
        // 1 1 0
        // 0 0 1
         int n=isConnected.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int u=i;
                int v=j;
                if(isConnected[i][j]==1){
                adj[i].push_back(j);
                adj[j].push_back(i);
                }
            }
        }
        vector<int> visited(n,0);
        int count=0;
       for(int i=0;i<n;i++){
          if(!visited[i]){
              count++;
              bfs(adj,i,visited);
          }
       } 
       return count;
    }
};