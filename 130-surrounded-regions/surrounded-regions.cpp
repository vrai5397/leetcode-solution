class Solution {
public:
void bfs(vector<vector<char>>& board,vector<vector<int>>
& visited,int r,int c){
      int m=board.size();
        int n=board[0].size();
    visited[r][c]=1;
    queue<pair<int,int>> q;
    q.push({r,c});
     int dr[4]={-1,0,1,0};
    int dc[4]={0,-1,0,1};
    while(!q.empty()){
        auto x=q.front();
        q.pop();
         for(int i=0;i<4;i++){
             int newr=dr[i]+x.first;
             int newc=dc[i]+x.second;
             if(newr>=0&&newr<m&&newc>=0&&newc<n&&board[newr][newc]=='O'&&!visited[newr][newc]){
                visited[newr][newc]=1;
                q.push({newr,newc});
                
             }
          }

        
    }
}
    void solve(vector<vector<char>>& board) {
        // if o is not on edge then that region converted to x
        // the zero present on edge marked it visited and
        // left zero convert to x
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0||i==m-1||j==0||j==n-1){
                    if(board[i][j]=='O'&&!visited[i][j])
                    bfs(board,visited,i,j);
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'&&!visited[i][j])
                board[i][j]='X';
            }
        }
    }
};