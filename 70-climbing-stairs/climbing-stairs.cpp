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
       vector<int> dp(n+1,0);
       dp[0]=1;
       dp[1]=1;
       for(int i=2;i<=n;i++){
           dp[i]=dp[i-1]+dp[i-2];
       }
       return dp[n];
    }
};