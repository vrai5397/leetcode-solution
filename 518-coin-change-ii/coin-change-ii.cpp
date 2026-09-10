class Solution {
public:
int solve(vector<int>& coins,int amount,int i,vector<vector<int>>& dp){
    // base case
    // we can exclude or include the coin

    if(i==0){
        if(amount%coins[i]==0)
        return 1;
        return 0;
    }
    if(dp[i][amount]!=-1)
    return dp[i][amount];
    int exclude=solve(coins,amount,i-1,dp);
    int include=0;
    if(coins[i]<=amount)
     include=solve(coins,amount-coins[i],i,dp);

    return dp[i][amount]=exclude+include;

}
    int change(int amount, vector<int>& coins) {
        // count the number of combination
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
       return solve(coins,amount,coins.size()-1,dp);
    }
};