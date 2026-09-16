class Solution {
public:
void bfs(vector<vector<char>>& grid,vector<vector<int>>&
visited,int row,int col){
     int m=grid.size();
        int n=grid[0].size();
    visited[row][col]=1;
    queue<pair<int,int>> q;
    q.push({row,col});
    int dr[4]={-1,0,1,0};
    int dc[4]={0,-1,0,1};
    while(!q.empty()){
        auto x=q.front();
        q.pop();
          for(int i=0;i<4;i++){
             int newr=dr[i]+x.first;
             int newc=dc[i]+x.second;
             if(newr>=0&&newr<m&&newc>=0&&newc<n&&grid[newr][newc]=='1'&&!visited[newr][newc]){
                visited[newr][newc]=1;
                q.push({newr,newc});
             }
          }
    }
}
    int numIslands(vector<vector<char>>& grid) {
        // this is basically graph question
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j]&& grid[i][j]=='1'){
                    count++;
                    bfs(grid,visited,i,j);
                }
            }
        }
        return count;
    }
};