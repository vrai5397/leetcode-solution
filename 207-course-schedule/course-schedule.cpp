class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // no of the vertex will be from 0 to numCourses
        vector<vector<int>> adj(numCourses);
        for(auto edge:prerequisites){
            adj[edge[0]].push_back(edge[1]);

        }
         queue<int> q;
        vector<int> ans;
       
    vector<int> indeg(numCourses,0);
     for(int i=0;i<numCourses;i++){
         for(auto x:adj[i])
         indeg[x]++;
     }
     
     for(int i=0;i<indeg.size();i++){
     if(indeg[i]==0)
     q.push(i);
     }
     while(!q.empty()){
         int node=q.front();
         ans.push_back(node);
         q.pop();
         for(auto x:adj[node]){
             indeg[x]--;
             if(indeg[x]==0)
             q.push(x);
         }
     }
    if(ans.size()==numCourses)
    return true;
    return false;
    }
};