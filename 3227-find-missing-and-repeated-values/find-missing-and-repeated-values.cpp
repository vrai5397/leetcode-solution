class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        int square=n*n;
        vector<int> visited(square+1,0);
        vector<int> ans;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                if(!visited[grid[i][j]])
                visited[grid[i][j]]=1;
                else if(visited[grid[i][j]])
                ans.push_back(grid[i][j]);
            }
        }
        for(int i=1;i<visited.size();i++){
            if(!visited[i])
            ans.push_back(i);
        }
        return ans;
    }
};