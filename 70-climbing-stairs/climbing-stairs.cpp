class Solution {
public:
 int climbStairss(int n,vector<int>& dp) {
        if(n==0||n==1)
        return 1;
        if(dp[n]!=-1)
        return dp[n];
       int method1=climbStairss(n-1,dp);
       int method2=climbStairss(n-2,dp);
       return dp[n]=method1+method2; 
    }
    int climbStairs(int n) {
       vector<int> dp(n+1,-1);
       return climbStairss(n,dp);
    }
};