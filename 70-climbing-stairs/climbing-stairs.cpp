class Solution {
public:
int solve(vector<int>& dp,int n){
    // base case
       if(n==0)
         return dp[0]= 1;
         if(n==1)
         return dp[1]=1;
         if(dp[n]!=-1)
         return dp[n];
        return dp[n]=solve(dp,n-1)+solve(dp,n-2);
}
    int climbStairs(int n) {
        // total ways
       vector<int> dp(n+1,-1);
       return solve(dp,n);
    }
};