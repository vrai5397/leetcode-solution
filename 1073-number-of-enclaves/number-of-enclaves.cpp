class Solution {
public:
  
int bfs(vector<vector<int>>& grid,vector<vector<int>>
& visited,int r,int c,int count){
      int m=grid.size();
        int n=grid[0].size();
    visited[r][c]=1;
    queue<pair<int,int>> q;
    q.push({r,c});
    bool touchboundary=false;
    int dr[4]={-1,0,1,0};
    int dc[4]={0,-1,0,1};
    while(!q.empty()){
        auto x=q.front();
        q.pop();
        if(x.first==0||x.first==m-1||x.second==0||x.second
        ==n-1)
        touchboundary=true;
        count++;
        for(int i=0;i<4;i++){
             int newr=dr[i]+x.first;
             int newc=dc[i]+x.second;
             if(newr>=0&&newr<m&&newc>=0&&newc<n&&grid[newr][newc]==1&&!visited[newr][newc]){
                visited[newr][newc]=1;
                q.push({newr,newc});
                
             }
          }

    }
    if(touchboundary)
    return 0;
    return count;
}
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
    
        vector<vector<int>> visited(m,vector<int>(n,0));
       int count=0;
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                if(!visited[i][j]&&grid[i][j]==1){
                  count+= bfs(grid,visited,i,j,0);
                }
            }
        }
      return count;
    }
};