class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
          queue<pair<int,pair<int,int>>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
              
                    if(grid[i][j]==2){
                   
                      q.push({0,{i,j}});
                      visited[i][j]=1;
                    }
                
               
            }
        }
int dr[4]={-1,0,1,0};
    int dc[4]={0,-1,0,1};
    int prevtime=-1;
    int count=0;
    while(!q.empty()){
        auto x=q.front();
        int time=x.first;
        int row=x.second.first;
        int col=x.second.second;
        q.pop();
        for(int i=0;i<4;i++){
           int newr=row+dr[i];
           int newc=col+dc[i];
           if(newr>=0&&newr<m&&newc>=0
           &&newc<n&&grid[newr][newc]==1&&!visited[newr][newc]){
             visited[newr][newc]=1;
             q.push({time+1,{newr,newc}});
           }
           
        }
        // 1 minute done
      count=max(count,time);
    }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1&&!visited[i][j])
                return -1;
            }
        }
        return count;
    }
};