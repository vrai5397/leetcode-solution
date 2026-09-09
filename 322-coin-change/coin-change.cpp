class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
       
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,1e9));
        int n=coins.size();
           for(int i = 0; i < n; i++)
            dp[i][0] = 0;
            for(int i=1;i<=amount;i++){
                  if(i%coins[0]==0)
                  dp[0][i]=i/coins[0];
            }
           for(int i=1;i<n;i++){
            for(int j=1;j<=amount;j++){
                int exclude=dp[i-1][j];
    int include=1e9;
    if(coins[i]<=j)
    include=1+dp[i][j-coins[i]];
    dp[i][j]=min(include,exclude);
            }
    }
      int ans=dp[coins.size()-1][amount];
      if(ans==1e9)
      return -1;
      return ans;
    }
};