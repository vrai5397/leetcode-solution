class Solution {
public:

    void bfs(vector<vector<char>>& grid,
             vector<vector<int>>& visited,
             int row, int col) {

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;

        q.push({row, col});
        visited[row][col] = 1;

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, -1, 0, 1};

        while(!q.empty()) {

            auto x = q.front();
            q.pop();

            for(int i = 0; i < 4; i++) {

                int newr = x.first + dr[i];
                int newc = x.second + dc[i];

                if(newr >= 0 && newr < m &&
                   newc >= 0 && newc < n &&
                   grid[newr][newc] == '1' &&
                   !visited[newr][newc]) {

                    visited[newr][newc] = 1;

                    q.push({newr, newc});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(
            m, vector<int>(n, 0)
        );

        int count = 0;

        for(int i = 0; i < m; i++) {

            for(int j = 0; j < n; j++) {

                if(grid[i][j] == '1' &&
                   !visited[i][j]) {

                    count++;

                    bfs(grid, visited, i, j);
                }
            }
        }

        return count;
    }
};