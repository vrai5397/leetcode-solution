class Solution {
public:
void bfs(vector<vector<int>>& image,  vector<vector<int>> &visited,int r, int c, int color,int originalcolor){
     int m=image.size();
        int n=image[0].size();
    visited[r][c]=1;
    queue<pair<int,int>> q;
    q.push({r,c});
    int dr[4]={-1,0,1,0};
    int dc[4]={0,-1,0,1};
    while(!q.empty()){
        auto x=q.front();
        q.pop();
        image[x.first][x.second]=color;
        for(int i=0;i<4;i++){
           int newr=dr[i]+x.first;
           int newc=dc[i]+x.second;
           if(newr>=0&&newr<m&&newc>=0&&newc<n&&image[newr][newc]==originalcolor&&!visited[newr][newc]){
            
              visited[newr][newc]=1;
              q.push({newr,newc});
           }
        }
    }
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        int originalcolor=image[sr][sc];
        bfs(image,visited,sr,sc,color,originalcolor);
        return image;
    }
};