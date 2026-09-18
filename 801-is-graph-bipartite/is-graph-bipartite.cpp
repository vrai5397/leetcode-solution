class Solution {
public:
bool bfs(vector<vector<int>>&graph,
vector<int>& color,int node){
     queue<int> q;
     q.push(node);
     color[node]=0;// blue color
     while(!q.empty()){
        auto x=q.front();
        q.pop();
        for(auto y:graph[x]){
            if(color[y]==-1){
                // not visited
                color[y]=1-color[x];
                q.push(y);
            }
            else if(color[x]==color[y])
            return false;

            
        }
     }
     return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        // if color the graph using two color
        // it is bipartite
        int n=graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<graph.size();i++){
            if(color[i]==-1){
            if(!bfs(graph,color,i))
            return false;
            }
        }
        return true;
    }
};