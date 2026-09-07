class Solution {
public:
bool solve(vector<int>& arr,int sum,int i,vector<vector<int>>& dp){
      // base case
      if(sum==0)
      return true;
      if(i==0){
          return dp[i][sum]=arr[0]==sum;
      }
      if(dp[i][sum]!=-1)
      return dp[i][sum];
      int exclude=solve(arr,sum,i-1,dp);
      int include=false;
      if(arr[i]<=sum)
      include=solve(arr,sum-arr[i],i-1,dp);
      
      return dp[i][sum]=include||exclude;
  }
    bool canPartition(vector<int>& nums) {
        int totalsum=0;
        for(auto x:nums)
        totalsum+=x;
        if(totalsum%2!=0)
        return false;
        int sum=totalsum/2;
        vector<vector<int>> dp(nums.size(),vector<int>(sum+1,-1));
        return solve(nums,sum,nums.size()-1,dp);
    }
};