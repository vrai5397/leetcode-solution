class Solution {
public:
int mod=1e9+7;
int solve(vector<vector<int>>& grid, int& k,int i,int j,int sum,
vector<vector<vector<int>>>& dp){
     // base case
     int n=grid.size();
     int m=grid[0].size();
     if(i>=n||j>=m)
     return 0;
     if(i==n-1&&j==m-1&&(sum+grid[n-1][m-1])%k==0)
     return 1;
     if(dp[i][j][sum]!=-1)
     return dp[i][j][sum];
     // down or right i+1,j+1
     int right=solve(grid,k,i+1,j,(sum+grid[i][j])%k,dp);
      int down=solve(grid,k,i,j+1,(sum+grid[i][j])%k,dp);
      return dp[i][j][sum]=(right+down)%mod;


}
    int numberOfPaths(vector<vector<int>>& grid, int k) {
         int n=grid.size();
     int m=grid[0].size();
vector<vector<vector<int>>> dp(
    n, vector<vector<int>>(m, vector<int>(k, -1))
);

         int ans=solve(grid,k,0,0,0,dp);
         return ans;
    }
};