class Solution {
public:
bool bfs(vector<vector<int>>& adj,
vector<int>& color,int node){
    color[node]=0;
    queue<int> q;
    q.push(node);
    while(!q.empty()){
        auto x=q.front();
        q.pop();
        for(auto y:adj[x]){
           if(color[y]==-1){
              color[y]=1-color[x];
              q.push(y);
           }
           else if(color[x]==color[y])
           return false;
        }
    }
    return true;
}
    bool isBipartite(vector<vector<int>>& adj) {
        // adj is given
        int n=adj.size();
        // give blue and red
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
              if(color[i]==-1){
                if(!bfs(adj,color,i))
                return false;
              }
        }
       
return true;
    }
};