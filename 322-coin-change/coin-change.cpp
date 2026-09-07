class Solution {
public:
int solve(vector<int>& coins,int amount,int i,  vector<vector<int>>& dp){
    if(amount==0)
    return 0;
    if(i==0){
        if(amount%coins[i]==0)
        return dp[i][amount]=amount/coins[i];
        else return dp[i][amount]=1e9;
    }
    if(dp[i][amount]!=-1)
    return dp[i][amount];
    int exclude=solve(coins,amount,i-1,dp);
    int include=1e9;
    if(coins[i]<=amount){
        include=1+solve(coins,amount-coins[i],i,dp);
    }
    return dp[i][amount]=min(exclude,include);
}
    int coinChange(vector<int>& coins, int amount) {
        // pick not pick
        if(amount==0)
        return 0;
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int ans= solve(coins,amount,coins.size()-1,dp);
       
        if(ans==1e9)
        return -1;
        return ans;
        
      
    }
};