class Solution {
public:
 vector<vector<int>> ans;
void dfs(vector<vector<int>>&adj
,vector<int>& helper,vector<int>& visited,
int node){
    if(node==adj.size()-1){
        helper.push_back(adj.size()-1);
        ans.push_back(helper);
        helper.pop_back();
        return;
    }
     // what can we do
     visited[node]=1;
     helper.push_back(node);
     for(auto x:adj[node]){
        if(!visited[x])
         dfs(adj,helper,visited,x);
     }
     helper.pop_back();
      visited[node]=0;
}
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& adj) {
       
        vector<int> helper;
        vector<int> visited(adj.size(),0);
      dfs(adj,helper,visited,0);
      return ans;
    }
};